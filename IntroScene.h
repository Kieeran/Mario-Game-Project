#pragma once
#include "Game.h"
#include "Textures.h"
#include "Scene.h"
#include "GameObject.h"
#include "Brick.h"
#include "Mario.h"
#include "Goomba.h"
//#include "Koopas.h"

class CIntroScene : public CScene
{
protected:
	// A play scene has to have player, right? 
	LPGAMEOBJECT player;

	vector<LPGAMEOBJECT> objects;

	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);

	void _ParseSection_ASSETS(string line);
	void _ParseSection_OBJECTS(string line);

	void LoadAssets(LPCWSTR assetFile);

public:
	CIntroScene(int id, LPCWSTR filePath);	//init function

	void AddObject(LPGAMEOBJECT object, int index = ADD_OBJECT_BEGIN)
	{
		if (index == ADD_OBJECT_BEGIN)
			objects.insert(objects.begin(), object);
		else if (index == ADD_OBJECT_BACK)
			objects.push_back(object);
		else
			objects.insert(objects.begin() + index, object);
	}

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();

	LPGAMEOBJECT GetPlayer() { return player; }

	void Clear();
	void PurgeDeletedObjects();

	static bool IsGameObjectDeleted(const LPGAMEOBJECT& o);
};
typedef CIntroScene* LPINTROSCENE;