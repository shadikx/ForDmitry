
#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>
#include <Windows.h>
#include <stdio.h>

using namespace std;

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



enum Cell 
{
	CROSS = 'X',
	ZERO = '0',
	EMPTY = '_'
};

struct Coord
{
	size_t y;
	size_t x;
};

enum Progress
{
	IN_PROGRESS,
	WON_HUMAN,
	WON_AI,
	DRAW
};

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

#pragma pack(push, 1)
struct Field {
	Cell** ppField = nullptr;
	const size_t SIZE = 3;
	Progress progress = IN_PROGRESS;
	Cell human;
	Cell ai;
	size_t turn = 0;
};
#pragma pack(pop)

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

Progress getWon(const Field & f);

inline void clear() {
	system("cls");
}

int32_t getRandomNum(int32_t min, int32_t max)
{
	const static auto seed = chrono::system_clock::now().time_since_epoch().count();
	static mt19937_64 generator(seed);
	uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void initField(Field & f)
{
	f.ppField = new Cell * [f.SIZE];
	for (size_t y = 0; y < f.SIZE; y++)
	{
		f.ppField[y] = new Cell[f.SIZE];
	}

	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			f.ppField[y][x] = EMPTY;
		}
	}

	if (getRandomNum(0, 1000) > 500)
	{
		f.human = CROSS;
		f.ai = ZERO;
		f.turn = 0;
	}
	else
	{
		f.human = ZERO;
		f.ai = CROSS;
		f.turn = 1;
	}
}

void deinitField(Field & f)
{
	for (size_t y = 0; y < f.SIZE; y++)
	{
		delete [] f.ppField[y];
	}
	delete [] f.ppField;
	
}

void drawField(const Field& f)
{
	cout << "     ";
	for (size_t x = 0; x < f.SIZE; x++)
	{
		cout << x + 1 << "   ";
	}
		cout << endl;

	for (size_t y = 0; y < f.SIZE; y++)
	{
		cout << " " << y + 1 << " | ";
		for (size_t x = 0; x < f.SIZE; x++)
		{
			cout << static_cast<char> (f.ppField[y][x]) << " | ";
		}
		cout << endl << endl;
	}

	cout << endl << " Human: " << static_cast<char> (f.human) << endl;
	cout << " Computer: " << static_cast<char> (f.ai) << endl;
}

void congrats(const Field & f)
{
	
	cout << endl;
	if (f.progress == WON_AI)
	{
		
		cout << " ||| Computer won!!! ||| " << endl;
	}
	else if (f.progress == WON_HUMAN)
	{
		
		cout << " ||| Human won!! ||| " << endl;
	}
	else if (f.progress == DRAW)
	{
		
		cout << " ||| DRAW! ||| " << endl;
	}
}

Coord getHumanCoord(const Field & f)
{
	Coord c{0};
	cout << endl;
	do {
		cout << " Enter x: ";
		cin >> c.x;
		cout << " Enter y: ";
		cin >> c.y; 

	} while (c.x == 0 || c.y == 0 || c.x > 3 || c.y > 3
		|| f.ppField[c.y-1][c.x-1] != EMPTY);

	c.x--;
	c.y--;

	return c;
}
Coord getAICoord(Field & f)
{
	//  one step to win

	for (size_t y = 0; y < f.SIZE; y++)
	{

		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == EMPTY)
			{
				f.ppField[y][x] = f.ai; 
				if (getWon(f) == WON_AI)
				{
					f.ppField[y][x] = EMPTY;
					return { y, x };
				}
				f.ppField[y][x] = EMPTY;
			}
		}
	} 

	//  one step to lose

	for (size_t y = 0; y < f.SIZE; y++)
	{

		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == EMPTY)
			{
				f.ppField[y][x] = f.human;
				if (getWon(f) == WON_HUMAN)
				{
					f.ppField[y][x] = EMPTY;
					return { y, x };
				}
				f.ppField[y][x] = EMPTY;
			}
		}
 	}
		
	// Центр кухни

	if (f.ppField[1][1] == EMPTY)
	{
		return {1, 1};
	}

	// Углы 

	Coord arr[4] = {0};
	size_t num = 0;
	if (f.ppField[0][0] == EMPTY)
	{
		arr[num++] = { 0, 0 };
	}

	if (f.ppField[0][2] == EMPTY)
	{
		arr[num++] = { 0, 2 };
	}

	if (f.ppField[2][0] == EMPTY)
	{
		arr[num++] = { 2, 0 };
	}

	if (f.ppField[2][2] == EMPTY)
	{
		arr[num++] = { 2, 2 };
	}

	if (num > 0)
	{
		const size_t index = getRandomNum(0, 1000) % num;
		return arr[index];
	}

	// Стены

	num = 0;
	if (f.ppField[0][1] == EMPTY)
	{
		arr[num++] = { 0, 1 };
	}

	if (f.ppField[1][0] == EMPTY)
	{
		arr[num++] = { 1, 0 };
	}

	if (f.ppField[2][1] == EMPTY)
	{
		arr[num++] = { 2, 1 };
	}

	if (f.ppField[1][2] == EMPTY)
	{
		arr[num++] = { 1, 2 };
	}

	if (num > 0)
	{
		const size_t index = getRandomNum(0, 1000) % num;
		return arr[index];
	}
}

Progress getWon(const Field& f)
{
	//проверка горизонталей на выигрыш								
	for (size_t y = 0; y < f.SIZE; y++)
	{
		if (f.ppField[y][0] == f.ppField[y][1] && f.ppField[y][0] == f.ppField[y][2])
		{
			if (f.ppField[y][0] == f.human)
				return WON_HUMAN;
			if (f.ppField[y][0] == f.ai)
				return WON_AI;
		}
	}

	//проверка вертикалей 
	for (size_t x = 0; x < f.SIZE; x++)
	{
		if (f.ppField[0][x] == f.ppField[1][x] && f.ppField[0][x] == f.ppField[2][x])
		{
			if (f.ppField[0][x] == f.human)
				return WON_HUMAN;
			if (f.ppField[0][x] == f.ai)
				return WON_AI;
		}
	}
	//проверка диагоналей
	if (f.ppField[0][0] == f.ppField[1][1] && f.ppField[0][0] == f.ppField[2][2])
	{
		if (f.ppField[1][1] == f.human)
			return WON_HUMAN;
		if (f.ppField[1][1] == f.ai)
			return WON_AI;
	}

	if (f.ppField[2][0] == f.ppField[1][1] && f.ppField[1][1] == f.ppField[0][2])
	{
		if (f.ppField[1][1] == f.human)
			return WON_HUMAN;
		if (f.ppField[1][1] == f.ai)
			return WON_AI;
	}


	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == EMPTY)
			{
				return IN_PROGRESS;
			}
		}
	}

	return DRAW;
}

// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

int main()

{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));

	Field f;
	initField(f);

	clear();
	drawField(f);

	do {
		if (f.turn % 2 == 0)
		{
			Coord c = getHumanCoord(f);
			f.ppField[c.y][c.x] = f.human;
		}

		else
		{
			Coord c = getAICoord(f);
			f.ppField[c.y][c.x] = f.ai;
		}

		clear();
		drawField(f);

		f.turn++;
		f.progress = getWon(f);
	} while (f.progress == IN_PROGRESS);

	congrats(f);

	deinitField(f);

	


	return 0;
}

