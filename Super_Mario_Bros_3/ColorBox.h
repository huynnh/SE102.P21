#pragma once
#include "GameObject.h"

class CColorBox : public CGameObject
{
protected:
	int width, height, spriteId;
public:
	CColorBox(float x, float y, int width, int height, int spriteId) : CGameObject(x, y) 
	{
		this->width = width;
		this->height = height;
		this->spriteId = spriteId;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 1; }
	int IsDirectionColliable(float nx, float ny);
};