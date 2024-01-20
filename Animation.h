#pragma once

#include <Windows.h>
#include <unordered_map>

#include "Sprites.h"
#include "AnimationFrame.h"

using namespace std;

class CAnimation
{
	ULONGLONG lastFrameTime;
	int defaultTime;
	int currentFrame;
	vector<LPANIMATION_FRAME> frames;

	bool doneRenderOnce;
public:
	CAnimation(int defaultTime = 100)
	{
		this->defaultTime = defaultTime;
		lastFrameTime = -1;
		currentFrame = -1;
		doneRenderOnce = false;
	}
	void Add(int spriteId, DWORD time = 0);
	void Render(float x, float y);
	void RenderOnce(float x, float y);

	int GetCurrentFrame() { return currentFrame; }
	int GetFramesSize() { return frames.size(); }

	bool GetDoneRenderOnce() { return doneRenderOnce; }
	void SetDoneRenderOnce(bool d) { doneRenderOnce = d; }
};

typedef CAnimation* LPANIMATION;