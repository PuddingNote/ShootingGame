#pragma once

#include "Level/Level.h"
#include "Utils/Timer.h"
#include "Math/Vector2.h"
/*
* Todo: ���� ������ å��
* - �浹 ó�� : �÷��̾�-�� ź�� ������ �浹 / ��-�÷��̾� ź���� �浹 ó��(AABB)
* - ���� ���� : �÷��̾ ���� ���ָ� 1���� ȹ��
* - ���� ���� : �÷��̾ ������ ���� ����
* - ���� ��ǥ
*/

class GameLevel : public Level
{
	RTTI_DECLARATIONS(GameLevel, Level)

public:
	GameLevel();
	~GameLevel();

	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Render() override;
	
private:
	void SpawnEnemies(float deltaTime);
	void ProcessCollisionPlayerBulletAndEnemy();
	void ProcessCollisionPlayerAndEnemyBullet();

private:
	// �� ������ �ð� ����� ���� Ÿ�̸�
	Timer enemySpawnTimer;

	// ���� ����
	int score = 0;

	// �÷��̾��� ���� ó���� ���� ����
	bool isPlayerDead = false;

	// �÷��̾� ���� ��ġ
	Vector2 playerDeadPosition;
};