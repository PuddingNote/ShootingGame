#pragma once

#include "Core.h"
#include "Input.h"
#include <Windows.h>

// ���� ���� ����ü
struct EngineSettings
{
	int width = 0;
	int height = 0;
	float framerate = 0.0f;
};

class Level;
class Engine_API Engine
{
public:
	Engine();
	virtual ~Engine();

	void Run();
	void Quit();
	virtual void CleanUp();	// �޸� ���� �Լ�

	void AddLevel(Level* newLevel);

	static Engine& Get();	// �̱��� ���� �Լ�

	int Width() const;
	int Height() const;

private:
	void BeginPlay();
	void Tick(float deltaTime = 0.0f);	// Update()
	void Render();

	void LoadEngineSettings();	// ���� ���� �ε� �Լ�

protected:
	bool isQuit = false;		// ���� ���� �÷���

	Level* mainLevel = nullptr;	// ���� ����

	Input input;				// �Է� ������

	EngineSettings settings;	// ���� ����

	static Engine* instance;	// �̱��� ����
};