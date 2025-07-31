#include "Enemy.h"
#include "Utils/Utils.h"
#include "Engine.h"
#include "Level/Level.h"
#include "Actor/EnemyBullet.h"

Enemy::Enemy(const char* image, int yPosition) : Actor(image)
{
	// �̵� ������ ���ϱ� ���� ����
	int random = Utils::Random(1, 10);

	// ¦Ȧ ��
	if (random % 2 == 0)
	{
		// ȭ�� ������ ������ �����ǵ��� ��ġ / �̵� ���� ����
		direction = MoveDirection::Left;
		xPosition = static_cast<float>(Engine::Get().Width()) - width;
	}
	else
	{
		// ȭ�� ���� ������ �����ǵ��� ��ġ / �̵� ���� ����
		direction = MoveDirection::Right;
		xPosition = 0.0f;
	}

	// ������ ��ġ ����
	position.x = static_cast<int>(xPosition);
	position.y = yPosition;

	// �߻� ���� �ð� ����
	timer.SetTargetTime(Utils::Random(1.0f, 3.0f));
}

void Enemy::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// �¿� �̵�
	float dir = (direction == MoveDirection::Left) ? -1.0f : 1.0f;

	// �̵� ó�� (��ӵ� �, �̵��Ÿ� = �ӵ� * �ð�; �ӵ� : ������ * ����)
	xPosition = xPosition + (moveSpeed * dir) * deltaTime;

	// ȭ�� �ۿ� ������� Ȯ��
	if (xPosition < 0.0f || (int)xPosition > Engine::Get().Width() - width)
	{
		Destroy();
		return;
	}

	// �ȹ������ ��ġ ����
	SetPosition(Vector2((int)xPosition, position.y));

	// �ð� �� �Ŀ� ź�� �߻�
	timer.Tick(deltaTime);
	if (!timer.IsTimeout())
	{
		return;
	}

	// �� ź�� ���� ��û
	owner->AddActor(new EnemyBullet(Vector2(position.x + width / 2, position.y + 1), Utils::Random(10.0f, 20.0f)));

	// Ÿ�̸� ���� ����
	timer.Reset();
	timer.SetTargetTime(Utils::Random(1.0f, 3.0f));
}