#include "ColorBox.h"

void CColorBox::Render()
{
	CSprites* s = CSprites::GetInstance();
	s->Get(this->spriteId)->Draw(x, y);
}

void CColorBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - width / 2;
	t = y - height / 2;
	r = l + width;
	b = t + height;
}

int CColorBox::IsDirectionColliable(float nx, float ny) {
	if (nx == 0 && ny == -1) {
		return 1;
	}
	else 
	{
		return 0;
	}
}