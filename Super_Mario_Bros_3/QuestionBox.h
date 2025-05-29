#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_QUESTION_BOX_IDLE 12000
#define ID_ANI_QUESTION_BOX_CLOSE 12100

#define QUESTION_BOX_STATE_IDLE 100
#define QUESTION_BOX_STATE_CLOSE 200

#define QUESTION_BOX_GRAVITY 0.005f
#define QUESTION_BOX_SPEED 0.5f

#define QUESTION_BOX_WIDTH 16
#define QUESTION_BOX_BBOX_WIDTH 16
#define QUESTION_BOX_BBOX_HEIGHT 16

class CQuestionBox : public CGameObject 
{
protected:
	float previousY, ay;
	bool isBouncing;
public:
	CQuestionBox(float x, float y);
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void StartBounce();
	void SetState(int state);
};