#pragma once

#include "Actor/Actor.h"

/*
* Todo: �÷��̾ �߻��ϴ� ź��
* - ȭ�� ���� �̵�
*  - �ӷ�(������, �� ����), �� ����
*/

class PlayerBullet : public Actor
{
	RTTI_DECLARATIONS(PlayerBullet, Actor)

public:
	PlayerBullet(const Vector2& position);

	virtual void Tick(float deltaTime) override;

private:
	// �ʴ� 30ĭ
	float moveSpeed = 30.0f;

	// ��ǥ�� �����̱� ������ ���� �� ����� ���� float ���� ����
	float yPosition = 0.0f;
};