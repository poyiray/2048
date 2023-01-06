#include "Map.h"
#include "logic.h"

void MAP::地图初始化(int(&Map)[Map_Size][Map_Size])
{
	for (int i = 0; i < Map_Size; i++)
	{
		for (int j = 0; j < Map_Size; j++)
		{
			Map[i][j] = 0;
		}
	}
	srand((int)time(NULL));
	int index = 0;
	while (index != 2)
	{
		int first = rand() % 4;
		int second = rand() % 4;
		if (Map[first][second] == 0)
		{
			if (rand() % 3 == 1)
			{
				Map[first][second] = 4;
				index++;
			}
			else
			{
				Map[first][second] = 2;
				index++;
			}
		}
	}
}

int MAP::显示地图(int GG, int (&Map)[Map_Size][Map_Size], int totalPoint)
{
	for (int i = 0; i < Map_Size; i++)
	{
		for (int j = 0; j < Map_Size; j++)
		{
			if (Map[i][j] == 0)
			{
				cout << "_" << "\t";
			}
			else
			{
				cout << Map[i][j] << "\t";
			}
		}
		cout << endl << endl;
	}
	if (GG == 1)
	{
		cout << "\n游戏结束\n游戏总分为: " << totalPoint << "\t\t按v查看战绩" << endl;
		MoveMent mm;
		mm.ScoreBoard(totalPoint);
		Sleep(1000);
		system("pause");
		return 1;
	}
}

void MAP::随机生成(int GG, int(&Map)[Map_Size][Map_Size], int canMove)
{
	bool 是否继续 = true;

	if (canMove == 0)
	{
		return;
	}
	while (是否继续)
	{
		int first = rand() % 4;
		int second = rand() % 4;
		if (Map[first][second] == 0)
		{
			if (rand() % 3 == 1)
			{
				Map[first][second] = 4;
				是否继续 = false;
			}
			else
			{
				Map[first][second] = 2;
				是否继续 = false;
			}
		}
	}
}
