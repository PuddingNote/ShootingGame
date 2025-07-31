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

	// 이벤트 함수
	virtual void BeginPlay();			// 초기화 목적으로 처음에 1번만 호출
	virtual void Tick(float deltaTime);	// 프레임 마다 호출
	virtual void Render();				// 그리기 함수
	
	inline bool HasBeganPlay() const { return hasBeganPlay; }

	// 위치 설정/값 읽는 함수
	void SetPosition(const Vector2& newPosition);
	Vector2 Position() const;

	// 문자열 길이 반환
	int Width() const;

	// Sorting Order 설정
	void SetSortingOrder(unsigned int sortingOrder);

	// Ownership 설정
	void SetOwner(Level* newOwner);
	Level* GetOwner();

	// 충돌 확인 요청 함수 (간단한 AABB 로직)
	bool TestIntersect(const Actor* const other);

	// 객체 삭제 함수
	void Destroy();

	// 게임 종료 요청 함수
	void QuitGame();

protected:
	Vector2 position;				// 개체의 위치
				
	char* image = nullptr;			// 그릴 값
	int width = 0;					// 문자열 길이

	Color color;					// 텍스트 색상 값

	bool hasBeganPlay = false;		// BeginPlay 호출 확인

	unsigned int sortingOrder = 0;	// 정렬 순서

	bool isActive = true;			// 액터가 활성 상태인지 알려주는 변수
	bool isExpired = false;			// 삭제 요청됐는지 알려주는 변수

	Level* owner = nullptr;			// 소유 레벨
};