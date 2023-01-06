#include "Map.h"
#include "logic.h"
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include<ctime>

int isFull = 0;
int Map[Map_Size][Map_Size] = 
{
	//{4,2,4,2},
	//{2,4,2,4},
	//{4,2,4,2},
	//{2,4,2,4}
};


int 移动(char move)
{
	MoveMent mm;
	if (move == 'w')
	{
		mm.MoveUp(Map);
	}

	if(move == 'a')
	{
		mm.MoveLeft(Map);
	}

	if (move == 'd')
	{
		mm.MoveRight(Map);
	}

	if (move == 's')
	{
		mm.MoveDown(Map);
	}

	if (move == 'v')
	{
		fstream check;
		check.open("ScoreBoard.txt", ios::in);
		char buf2;
		check >> buf2;
		if (check.eof() || !check.is_open())
		{
			cout << "臭傻逼去开一局再来这里" << endl;
			system("pause");
			return 0;
		}
		check.close();

		fstream f;
		f.open("ScoreBoard.txt", ios::in);
		cout << endl;
		string point;		
		string date;
		while (f >> date && f >> point )
		{
			cout << date << ": " << point << " 分 \n" << endl;
		}
		f.close();


		cout << "输入c清除你的丢人记录" << endl;
		char choice = _getch();
		if (choice == 'c')
		{
			fstream clear;
			clear.open("ScoreBoard.txt", ios::out);
			clear << "";
			cout << "清除成功" << endl;
			system("pause");
			clear.close();
		}
	}

	mm.Check(Map);
	isFull = mm.canMove;
	return mm.GG;
}

void 隐藏光标()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
}

int main() {
	system("color F4");
	SetConsoleTitle(LPCWSTR(L"2048 Biny的大鸡巴"));
	隐藏光标();

	int GG = 0;
	int reset = 0;
	char choice;
	MAP m_Map;
	m_Map.地图初始化(Map);
	while (true)
	{
		if (reset == 1 || GG == 1)
		{
			GG = 0;
			reset = 0;
			m_Map.地图初始化(Map);
		}
		reset = m_Map.显示地图(GG, Map, 0);
		choice = _getch();
		GG = 移动(choice);
		m_Map.随机生成(GG, Map, isFull);
		system("cls");
	}	

	system("pause");
	return 0;
}