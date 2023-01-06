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


int �ƶ�(char move)
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
			cout << "��ɵ��ȥ��һ����������" << endl;
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
			cout << date << ": " << point << " �� \n" << endl;
		}
		f.close();


		cout << "����c�����Ķ��˼�¼" << endl;
		char choice = _getch();
		if (choice == 'c')
		{
			fstream clear;
			clear.open("ScoreBoard.txt", ios::out);
			clear << "";
			cout << "����ɹ�" << endl;
			system("pause");
			clear.close();
		}
	}

	mm.Check(Map);
	isFull = mm.canMove;
	return mm.GG;
}

void ���ع��()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
	CursorInfo.bVisible = false; //���ؿ���̨���
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
}

int main() {
	system("color F4");
	SetConsoleTitle(LPCWSTR(L"2048 Biny�Ĵ󼦰�"));
	���ع��();

	int GG = 0;
	int reset = 0;
	char choice;
	MAP m_Map;
	m_Map.��ͼ��ʼ��(Map);
	while (true)
	{
		if (reset == 1 || GG == 1)
		{
			GG = 0;
			reset = 0;
			m_Map.��ͼ��ʼ��(Map);
		}
		reset = m_Map.��ʾ��ͼ(GG, Map, 0);
		choice = _getch();
		GG = �ƶ�(choice);
		m_Map.�������(GG, Map, isFull);
		system("cls");
	}	

	system("pause");
	return 0;
}