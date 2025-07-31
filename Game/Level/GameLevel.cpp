#include "GameLevel.h"
#include "Actor/Player.h"
#include "Actor/Enemy.h"
#include "Utils/Utils.h"

// �� ������ �� ����� ���� �� (���⼭ static�� private��)
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
	// �÷��̾� �߰�
	AddActor(new Player());

	// �׽�Ʈ �뵵
	//AddActor(new Enemy());

	// Ÿ�̸� ����
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

	// �� ����
	enemySpawnTimer.Tick(deltaTime);

	// Ÿ�� �ƿ� Ȯ��
	if (!enemySpawnTimer.IsTimeout())
	{
		return;
	}

	// Ÿ�̸� ����
	enemySpawnTimer.Reset();
	enemySpawnTimer.SetTargetTime(Utils::Random(2.0f, 3.0f));

	// �� ���� ����
	// �迭 ���� �� �ε��� ���� ���ϱ�
	static int length = sizeof(enemyType) / sizeof(enemyType[0]);
	int index = Utils::Random(0, length - 1);

	// ���� ������ y ��ġ �� �������� ���ؼ� �� ����
	int yPosition = Utils::Random(1, 10);
	AddActor(new Enemy(enemyType[index], yPosition));
}

void GameLevel::Render()
{
	super::Render();
}