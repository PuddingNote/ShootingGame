#pragma once

#include "Core.h"
#include "Math/Vector2.h"
#include "RTTI.h"

enum class Color : int
{
	Blue = 1,
	Green = 2,
	Red = 4,
	White = Red | Green | Blue,
	Intensity = 8
};

class Level;
class Engine_API Actor : public RTTI
{
	friend class Level;
	RTTI_DECLARATIONS(Actor, RTTI)

public:
	Actor(
		const char image = ' ',
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

	// Sorting Order ����
	void SetSortingOrder(unsigned int sortingOrder);

	// Ownership ����
	void SetOwner(Level* newOwner);
	Level* GetOwner();

	// ���� ���� ��û �Լ�
	void QuitGame();

private:
	Vector2 position;				// ��ü�� ��ġ
	
	char image = ' ';				// �׸� ��
	Color color;					// �ؽ�Ʈ ���� ��

	bool hasBeganPlay = false;		// BeginPlay ȣ�� Ȯ��

	unsigned int sortingOrder = 0;	// ���� ����

	Level* owner = nullptr;			// ���� ����
};