#include "Koopas.h"

CKoopas::CKoopas(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = KOOPAS_GRAVITY;
	shell_start = -1;
	SetState(KOOPAS_STATE_WALKING);
}

void CKoopas::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == KOOPAS_STATE_SHELL)
	{
		left = x - KOOPAS_BBOX_WIDTH / 2;
		top = y - KOOPAS_BBOX_HEIGHT_SHELL / 2;
		right = left + KOOPAS_BBOX_WIDTH;
		bottom = top + KOOPAS_BBOX_HEIGHT_SHELL;
	}
	else if (state == KOOPAS_STATE_SHELL_MOVING_RIGHT || state == KOOPAS_STATE_SHELL_MOVING_LEFT)
	{
		left = x - KOOPAS_BBOX_WIDTH / 2;
		top = y - KOOPAS_BBOX_HEIGHT_SHELL / 2;
		right = left + KOOPAS_BBOX_WIDTH;
		bottom = top + KOOPAS_BBOX_HEIGHT_SHELL;
	}
	else
	{
		left = x - KOOPAS_BBOX_WIDTH / 2;
		top = y - KOOPAS_BBOX_HEIGHT / 2;
		right = left + KOOPAS_BBOX_WIDTH;
		bottom = top + KOOPAS_BBOX_HEIGHT;
	}
}

void CKoopas::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CKoopas::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CKoopas*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CKoopas::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) 
{
	vy += ay * dt;
	vx += ax * dt;

	if (state == KOOPAS_STATE_SHELL && GetTickCount64() - shell_start > KOOPAS_SHELL_TIMEOUT) {
		SetState(KOOPAS_STATE_REVIVING);
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CKoopas::Render() 
{
	int aniId = ID_ANI_KOOPAS_WALKING;
	if (state == KOOPAS_STATE_SHELL)
	{
		aniId = ID_ANI_KOOPAS_SHELL;
	}
	else if (state == KOOPAS_STATE_SHELL_MOVING_RIGHT || state == KOOPAS_STATE_SHELL_MOVING_LEFT)
	{
		aniId = ID_ANI_KOOPAS_SHELL;
	}
	else if (state == KOOPAS_STATE_REVIVING)
	{
		SetState(KOOPAS_STATE_WALKING);
		aniId = ID_ANI_KOOPAS_WALKING;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CKoopas::SetState(int state) 
{
	CGameObject::SetState(state);
	switch (state)
	{
		case KOOPAS_STATE_WALKING:
			vx = -KOOPAS_WALKING_SPEED; 
			break;
		case KOOPAS_STATE_SHELL:
			shell_start = GetTickCount64();
			vx = 0;
			break;
		case KOOPAS_STATE_SHELL_MOVING_RIGHT:
			vx = KOOPAS_WALKING_SPEED * 2;
			break;
		case KOOPAS_STATE_SHELL_MOVING_LEFT:
			vx = -KOOPAS_WALKING_SPEED * 2;
			break;
	}
}