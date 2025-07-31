#include "GameLevel.h"
#include "Actor/Player.h"
#include "Actor/Enemy.h"
#include "Utils/Utils.h"

// 적 생성할 때 사용할 글자 값 (여기서 static은 private임)
static const char* enemyType[] =
{
	";:^:;",
	"zZwZz",
	"oO@Oo",
	"<-=->",
	")qop("
};

GameLevel::GameLevel()
{
	// 플레이어 추가
	AddActor(new Player());

	// 테스트 용도
	//AddActor(new Enemy());

	// 타이머 설정
	enemySpawnTimer.SetTargetTime(Utils::Random(2.0f, 3.0f));
}

GameLevel::~GameLevel()
{
}

void GameLevel::BeginPlay()
{
	super::BeginPlay();
}

void GameLevel::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// 적 생성
	enemySpawnTimer.Tick(deltaTime);

	// 타임 아웃 확인
	if (!enemySpawnTimer.IsTimeout())
	{
		return;
	}

	// 타이머 정리
	enemySpawnTimer.Reset();
	enemySpawnTimer.SetTargetTime(Utils::Random(2.0f, 3.0f));

	// 적 생성 로직
	// 배열 길이 및 인덱스 랜덤 구하기
	static int length = sizeof(enemyType) / sizeof(enemyType[0]);
	int index = Utils::Random(0, length - 1);

	// 적을 생성할 y 위치 값 랜덤으로 구해서 적 생성
	int yPosition = Utils::Random(1, 10);
	AddActor(new Enemy(enemyType[index], yPosition));
}

void GameLevel::Render()
{
	super::Render();
}