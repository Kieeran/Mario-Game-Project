#include <iostream>
#include <fstream>
#include "AssetIDs.h"
#include "debug.h"

#include "WorldMapScene.h"
#include "Utils.h"
#include "Textures.h"
#include "Sprites.h"


#include "Platform.h"
#include "Card.h"
#include "Map.h"
#include "DancingShrub.h"
#include "WorldMapObjects.h"

#include "Hud.h"

#include "WorldMapKeyEventHandler.h"

using namespace std;

CWorldMapScene::CWorldMapScene(int id, LPCWSTR filePath) :CScene(id, filePath)
{
	player = NULL;
	key_handler = new CWorldMapKeyEventHandler(this);
}

void CWorldMapScene::_ParseSection_SPRITES(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 6) return; // skip invalid lines

	int ID = atoi(tokens[0].c_str());	//atoi: convert string to integer
	int l = atoi(tokens[1].c_str());
	int t = atoi(tokens[2].c_str());
	int r = atoi(tokens[3].c_str());
	int b = atoi(tokens[4].c_str());
	int texID = atoi(tokens[5].c_str());

	LPTEXTURE tex = CTextures::GetInstance()->Get(texID);
	if (tex == NULL)
	{
		DebugOut(L"[ERROR] Texture ID %d not found!\n", texID);
		return;
	}

	CSprites::GetInstance()->Add(ID, l, t, r, b, tex);
}

void CWorldMapScene::_ParseSection_ASSETS(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 1) return;

	wstring path = ToWSTR(tokens[0]);

	LoadAssets(path.c_str());
}

void CWorldMapScene::_ParseSection_ANIMATIONS(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 3) return; // skip invalid lines - an animation must at least has 1 frame and 1 frame time

	//DebugOut(L"--> %s\n",ToWSTR(line).c_str());

	LPANIMATION ani = new CAnimation();

	int ani_id = atoi(tokens[0].c_str());
	for (int i = 1; i < tokens.size(); i += 2)	// why i += 2 ?  sprite_id | frame_time  
	{
		int sprite_id = atoi(tokens[i].c_str());
		int frame_time = atoi(tokens[i + 1].c_str());
		ani->Add(sprite_id, frame_time);
	}

	CAnimations::GetInstance()->Add(ani_id, ani);
}

/*
	Parse a line in section [OBJECTS]
*/
void CWorldMapScene::_ParseSection_OBJECTS(string line)
{
	vector<string> tokens = split(line);

	// skip invalid lines - an object set must have at least id, x, y
	if (tokens.size() < 2) return;

	int object_type = atoi(tokens[0].c_str());
	float x = (float)atof(tokens[1].c_str());
	float y = (float)atof(tokens[2].c_str());

	CGameObject* obj = NULL;

	switch (object_type)
	{
	case OBJECT_TYPE_MAP: obj = new CMap(x, y); break;
	case OBJECT_TYPE_DANCING_SHRUB: obj = new CDancingShrub(x, y); break;
	case OBJECT_TYPE_HUD: obj = new CHud(x, y); break;
	case OBJECT_TYPE_WORLD_MAP_OBJECTS:
	{

		//	if (player != NULL)
		//	{
		//		//DebugOut(L"[ERROR] MARIO object was created before!\n");
		//		return;
		//	}

		int objectType = atoi(tokens[3].c_str());
		obj = new CWorldMapObjects(x, y, objectType);

		if (objectType == MARIO)
		{
			player = (CWorldMapObjects*)obj;
		}

		break;
	}
	//case OBJECT_TYPE_PLATFORM:
	//{
	//	float cell_width = (float)atof(tokens[3].c_str());
	//	float cell_height = (float)atof(tokens[4].c_str());
	//	int length = atoi(tokens[5].c_str());
	//	int sprite_begin = atoi(tokens[6].c_str());
	//	int sprite_middle = atoi(tokens[7].c_str());
	//	int sprite_end = atoi(tokens[8].c_str());
	//	obj = new CPlatform(
	//		x, y,
	//		cell_width, cell_height, length,
	//		sprite_begin, sprite_middle, sprite_end
	//	);
	//	break;
	//}
	//case OBJECT_TYPE_PORTAL:
	//{
	//	float r = (float)atof(tokens[3].c_str());
	//	float b = (float)atof(tokens[4].c_str());
	//	int scene_id = atoi(tokens[5].c_str());
	//	obj = new CPortal(x, y, r, b, scene_id);
	//}
	//break;

	default:
		DebugOut(L"[ERROR] Invalid object type: %d\n", object_type);
		return;
	}

	// General object setup
	obj->SetPosition(x, y);
	objects.push_back(obj);
}

void CWorldMapScene::LoadAssets(LPCWSTR assetFile)
{
	DebugOut(L"[INFO] Start loading assets from : %s \n", assetFile);

	ifstream f;
	f.open(assetFile);

	int section = ASSETS_SECTION_UNKNOWN;

	char str[MAX_SCENE_LINE];
	while (f.getline(str, MAX_SCENE_LINE))		//get the info of every line of the file text until the end
	{
		string line(str);						//line = the line contain info

		if (line[0] == '#') continue;	// skip comment lines	

		if (line == "[SPRITES]") { section = ASSETS_SECTION_SPRITES; continue; };
		if (line == "[ANIMATIONS]") { section = ASSETS_SECTION_ANIMATIONS; continue; };
		if (line[0] == '[') { section = SCENE_SECTION_UNKNOWN; continue; }

		//
		// data section
		//
		switch (section)
		{
		case ASSETS_SECTION_SPRITES: _ParseSection_SPRITES(line); break;
		case ASSETS_SECTION_ANIMATIONS: _ParseSection_ANIMATIONS(line); break;
		}
	}

	f.close();

	DebugOut(L"[INFO] Done loading assets from %s\n", assetFile);
}

void CWorldMapScene::Load()
{
	DebugOut(L"[INFO] Start loading scene from : %s \n", sceneFilePath);

	ifstream f;
	f.open(sceneFilePath);

	// current resource section flag
	int section = SCENE_SECTION_UNKNOWN;

	char str[MAX_SCENE_LINE];
	while (f.getline(str, MAX_SCENE_LINE))
	{
		string line(str);

		if (line[0] == '#') continue;	// skip comment lines	
		if (line == "[ASSETS]") { section = SCENE_SECTION_ASSETS; continue; };
		if (line == "[OBJECTS]") { section = SCENE_SECTION_OBJECTS; continue; };
		if (line[0] == '[') { section = SCENE_SECTION_UNKNOWN; continue; }

		//
		// data section
		//
		switch (section)
		{
		case SCENE_SECTION_ASSETS: _ParseSection_ASSETS(line); break;
		case SCENE_SECTION_OBJECTS: _ParseSection_OBJECTS(line); break;
		}
	}

	f.close();

	DebugOut(L"[INFO] Done loading scene  %s\n", sceneFilePath);
}

void CWorldMapScene::Update(DWORD dt)
{
	vector<LPGAMEOBJECT> coObjects;
	for (size_t i = 1; i < objects.size(); i++)
	{
		coObjects.push_back(objects[i]);
	}

	for (size_t i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(dt, &coObjects);
	}

	// skip the rest if scene was already unloaded (Mario::Update might trigger PlayScene::Unload)
	if (player == NULL) return;

	CGame::GetInstance()->SetCamPos(-8.0f, -8.0f);

	PurgeDeletedObjects();
}

void CWorldMapScene::Render()
{
	CGame* g = CGame::GetInstance();
	ID3D10RenderTargetView* pRenderTargetView = g->GetRenderTargetView();
	ID3D10Device* pD3DDevice = g->GetDirect3DDevice();
	pD3DDevice->ClearRenderTargetView(pRenderTargetView, D3DXCOLOR(0.0f / 255, 0.0f / 255, 0.0f / 255, 0.0f));

	for (int i = 0; i < objects.size(); i++)
		objects[i]->Render();
}

void CWorldMapScene::Clear()
{
	vector<LPGAMEOBJECT>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++)
	{
		delete (*it);
	}
	objects.clear();
}

void CWorldMapScene::Unload()
{
	for (int i = 0; i < objects.size(); i++)
		delete objects[i];

	objects.clear();
	player = NULL;

	DebugOut(L"[INFO] Scene %d unloaded! \n", id);
}

bool CWorldMapScene::IsGameObjectDeleted(const LPGAMEOBJECT& o) { return o == NULL; }

void CWorldMapScene::PurgeDeletedObjects()
{
	vector<LPGAMEOBJECT>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++)
	{
		LPGAMEOBJECT o = *it;
		if (o->IsDeleted())
		{
			delete o;
			*it = NULL;
		}
	}

	// NOTE: remove_if will swap all deleted items to the end of the vector
	// then simply trim the vector, this is much more efficient than deleting individual items
	objects.erase(
		std::remove_if(objects.begin(), objects.end(), CWorldMapScene::IsGameObjectDeleted),
		objects.end());
}