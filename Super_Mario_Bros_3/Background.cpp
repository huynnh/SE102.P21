#include "Background.h"

void CBackground::Render()
{
	CSprites* s = CSprites::GetInstance();
	s->Get(this->spriteId)->Draw(x, y);
}

void CBackground::GetBoundingBox(float& l, float& t, float& r, float& b)
{

}