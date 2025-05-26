#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_QUESTION_BLOCK 12000

#define QUESTION_BLOCK_WIDTH 16
#define QUESTION_BLOCK_BBOX_WIDTH 16
#define QUESTION_BLOCK_BBOX_HEIGHT 16

class CQuestionBlock : public CGameObject {
public:
	CQuestionBlock(float x, float y) : CGameObject(x, y) {}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};