#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

extern HANDLE handle;
extern int width;
extern int height;
const int BOARD_SIZE = 8;
const int TEAM_SIZE = 16;

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
