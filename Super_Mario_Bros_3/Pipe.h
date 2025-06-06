#pragma once
#include "GameObject.h"
class CPipe : public CGameObject
{
protected:
	int width, height, spriteId;
public:
	CPipe(float x, float y, int width, int height, int spriteId);
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 1; }
};
