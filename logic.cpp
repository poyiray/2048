#include "logic.h"
#include "Map.h"

void MoveMent::MoveDown(int(&Map)[Map_Size][Map_Size])
{
	for (int index = 0; index < 3; index++)
	{
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (Map[j - 1][i] != 0 && Map[j][i] == 0)
				{
					Map[j][i] = Map[j - 1][i];
					Map[j - 1][i] = 0;
					canMove++;
				}
			}
		}
	}
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (Map[j][i] == Map[j - 1][i] && Map[j][i] != 0)
			{
				Map[j][i] *= 2;
				Map[j - 1][i] = 0;
				canMove++;
			}
		}
	}

	for (int index = 0; index < 3; index++)
	{
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (Map[j - 1][i] != 0 && Map[j][i] == 0)
				{
					Map[j][i] = Map[j - 1][i];
					Map[j - 1][i] = 0;
					canMove++;
				}
			}
		}
	}
}

void MoveMent::Check(int(&Map)[Map_Size][Map_Size])
{
	totalPoint = 0;
	ifFull = 0;
	bool canAdd = false;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Map[i][j] != 0)
			{
				totalPoint += Map[i][j];
				ifFull++;
			}
		}
	}

	//Down
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (Map[j][i] == Map[j - 1][i])
			{
				canAdd = true;
			}
		}
	}

	//Left
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Map[i][j] == Map[i][j + 1])
			{
				canAdd = true;
			}
		}
	}

	//Right
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (Map[i][j] == Map[i][j - 1])
			{
				canAdd = true;
			}
		}
	}

	//Up
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Map[j + 1][i] == Map[j][i])
			{
				canAdd = true;
			}
		}
	}

	if (canAdd == false && ifFull == 16)
	{
		MAP m;
		GG = 1;
		system("cls");
		m.ÏÔÊ¾µØÍ¼(GG, Map, totalPoint);
	}
}

void MoveMent::MoveUp(int(&Map)[Map_Size][Map_Size])
{
	for (int index = 0; index < 3; index++)
	{
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Map[j + 1][i] != 0 && Map[j][i] == 0)
				{
					Map[j][i] = Map[j + 1][i];
					Map[j + 1][i] = 0;
					canMove++;
				}
			}
		}
	}

	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Map[j + 1][i] == Map[j][i] && Map[j][i])
			{
				Map[j][i] *= 2;
				Map[j + 1][i] = 0;
				canMove++;
			}
		}
	}

	for (int index = 0; index < 3; index++)
	{
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Map[j + 1][i] != 0 && Map[j][i] == 0)
				{
					Map[j][i] = Map[j + 1][i];
					Map[j + 1][i] = 0;
					canMove++;
				}
			}
		}
	}
}

void MoveMent::MoveRight(int(&Map)[Map_Size][Map_Size])
{
	for (int index = 0; index < 3; index++)
	{
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (Map[i][j - 1] != 0 && Map[i][j] == 0)
				{
					Map[i][j] = Map[i][j - 1];
					Map[i][j - 1] = 0;
					canMove++;
				}
			}
		}
	}

	for (int i = 0; i <= 3; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (Map[i][j] == Map[i][j - 1] && Map[i][j] != 0)
			{
				Map[i][j] *= 2;
				Map[i][j - 1] = 0;
				canMove++;
			}
		}
	}

	for (int index = 0; index < 3; index++)
	{
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (Map[i][j - 1] != 0 && Map[i][j] == 0)
				{
					Map[i][j] = Map[i][j - 1];
					Map[i][j - 1] = 0;
					canMove++;
				}
			}
		}
	}
}

void MoveMent::MoveLeft(int(&Map)[Map_Size][Map_Size])
{
	for (int index = 0; index < 3; index++)
	{
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Map[i][j + 1] != 0 && Map[i][j] == 0)
				{
					Map[i][j] = Map[i][j + 1];
					Map[i][j + 1] = 0;
					canMove++;
				}
			}
		}
	}

	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Map[i][j] == Map[i][j + 1] && Map[i][j])
			{
				Map[i][j] *= 2;
				Map[i][j + 1] = 0;
				canMove++;
			}
		}
	}

	for (int index = 0; index < 3; index++)
	{
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (Map[i][j + 1] != 0 && Map[i][j] == 0)
				{
					Map[i][j] = Map[i][j + 1];
					Map[i][j + 1] = 0;
					canMove++;
				}
			}
		}
	}
}

void MoveMent::ScoreBoard(int totalPoint)
{
	time_t nowTime;
	struct tm * p;
	time(&nowTime);
	p = localtime(&nowTime);

	ofstream of;
	of.open("ScoreBoard.txt", ios::app);
	of << p->tm_year + 1900 << "/" << p->tm_mon + 1 << "/" << p->tm_mday << " " << totalPoint << endl;
	of.close();
}

