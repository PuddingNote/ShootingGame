#pragma once

#include "Core.h"
#include <vector>
#include "RTTI.h"

class Actor;
class Engine_API Level : public RTTI
{
	RTTI_DECLARATIONS(Level, RTTI)

public:
	Level();
	virtual ~Level();
	
	// Level�� Actor�� �߰��� �� ���
	void AddActor(Actor* newActor);

	// ���� ���� �Լ�
	void DestroyActor(Actor* destroyedActor);

	// ���� �̺�Ʈ �Լ�
	virtual void BeginPlay();
	virtual void Tick(float deltaTime);
	virtual void Render();

	// �߰� �� ���� ��û�� ���͸� ó���ϴ� �Լ�
	void ProcessAddAndDestroyActors();

private:
	void SortActorsBySortingOrder();

protected:
	// ������ ��ġ�� ��� Actor�� �����ϴ� �迭
	std::vector<Actor*> actors;

	// �߰� ��û�� ���͸� �����ϴ� �迭
	std::vector<Actor*> addRequestedActors;

	// ���� ��û�� ���͸� �����ϴ� �迭
	std::vector<Actor*> destroyRequestedActors;
};