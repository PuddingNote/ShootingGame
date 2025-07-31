#pragma once

#include "Core.h"
#include "Math/Vector2.h"
#include "Math/Color.h"
#include "RTTI.h"

class Level;
class Engine_API Actor : public RTTI
{
	friend class Level;
	RTTI_DECLARATIONS(Actor, RTTI)

public:
	Actor(
		const char* image = "",
		Color color = Color::White,
		const Vector2& position = Vector2::Zero
	);
	virtual ~Actor();

	// �̺�Ʈ �Լ�
	virtual void BeginPlay();			// �ʱ�ȭ �������� ó���� 1���� ȣ��
	virtual void Tick(float deltaTime);	// ������ ���� ȣ��
	virtual void Render();				// �׸��� �Լ�
	
	inline bool HasBeganPlay() const { return hasBeganPlay; }

	// ��ġ ����/�� �д� �Լ�
	void SetPosition(const Vector2& newPosition);
	Vector2 Position() const;

	// ���ڿ� ���� ��ȯ
	int Width() const;

	// Sorting Order ����
	void SetSortingOrder(unsigned int sortingOrder);

	// Ownership ����
	void SetOwner(Level* newOwner);
	Level* GetOwner();

	// �浹 Ȯ�� ��û �Լ� (������ AABB ����)
	bool TestIntersect(const Actor* const other);

	// ��ü ���� �Լ�
	void Destroy();

	// ���� ���� ��û �Լ�
	void QuitGame();

protected:
	Vector2 position;				// ��ü�� ��ġ
				
	char* image = nullptr;			// �׸� ��
	int width = 0;					// ���ڿ� ����

	Color color;					// �ؽ�Ʈ ���� ��

	bool hasBeganPlay = false;		// BeginPlay ȣ�� Ȯ��

	unsigned int sortingOrder = 0;	// ���� ����

	bool isActive = true;			// ���Ͱ� Ȱ�� �������� �˷��ִ� ����
	bool isExpired = false;			// ���� ��û�ƴ��� �˷��ִ� ����

	Level* owner = nullptr;			// ���� ����
};