#include "QuestionBox.h"

CQuestionBox::CQuestionBox(float x, float y) : CGameObject(x, y)
{
	SetState(ID_ANI_QUESTION_BOX_IDLE);
	vy = 0;
	ay = 0;
	previousY = y;
	isBouncing = false;
}

void CQuestionBox::StartBounce()
{
	ay = QUESTION_BOX_GRAVITY;
	vy = -QUESTION_BOX_SPEED;
	isBouncing = true;
}

void CQuestionBox::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (isBouncing)
	{
		vy += ay * dt;
		y += vy * dt;
	}

	if (y >= previousY && isBouncing)
	{
		y = previousY;
		vy = 0;
		ay = 0;
		isBouncing = false;
	}
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CQuestionBox::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (GetState() == ID_ANI_QUESTION_BOX_IDLE)
	{
		animations->Get(ID_ANI_QUESTION_BOX_IDLE)->Render(x, y);
	}
	else if (GetState() == ID_ANI_QUESTION_BOX_CLOSE)
	{
		animations->Get(ID_ANI_QUESTION_BOX_CLOSE)->Render(x, y);
	}
	
	//RenderBoundingBox();
}

void CQuestionBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - QUESTION_BOX_BBOX_WIDTH / 2;
	t = y - QUESTION_BOX_BBOX_HEIGHT / 2;
	r = l + QUESTION_BOX_BBOX_WIDTH;
	b = t + QUESTION_BOX_BBOX_HEIGHT;
}

void CQuestionBox::SetState(int state)
{
	CGameObject::SetState(state);
}