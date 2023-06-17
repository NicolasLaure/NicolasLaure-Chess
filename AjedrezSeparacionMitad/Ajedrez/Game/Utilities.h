#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

extern HANDLE handle;
extern int width;
extern int height;
extern const int BOARD_SIZE;
extern const int TEAM_SIZE;

enum class Colors
{
	White,
	Black
};

struct Vector2
{
	int x{};
	int y{};
};

int PromptInput(int min, int max);
