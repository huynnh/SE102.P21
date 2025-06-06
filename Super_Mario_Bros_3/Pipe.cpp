#include "Pipe.h"

CPipe::CPipe(float x, float y, int width, int height, int spriteId) : CGameObject(x, y) {
	this->spriteId = spriteId;
	this->width = width;
	this->height = height;
}

void CPipe::Render() {
	CSprites* s = CSprites::GetInstance();
	s->Get(spriteId)->Draw(x, y);
};

void CPipe::GetBoundingBox(float& l, float& t, float& r, float& b) {
	l = x - width / 2;
	t = y - height / 2;
	r = l + width;
	b = t + height;
}