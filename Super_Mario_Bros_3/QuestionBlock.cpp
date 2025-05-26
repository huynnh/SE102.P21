#include "QuestionBlock.h"

void CQuestionBlock::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_QUESTION_BLOCK)->Render(x, y);
	//RenderBoundingBox();
}

void CQuestionBlock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - QUESTION_BLOCK_BBOX_WIDTH / 2;
	t = y - QUESTION_BLOCK_BBOX_HEIGHT / 2;
	r = l + QUESTION_BLOCK_BBOX_WIDTH;
	b = t + QUESTION_BLOCK_BBOX_HEIGHT;
}