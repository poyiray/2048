#include <windows.h>
#include <stdio.h>
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
#define Map_Size 4

class MAP
{
public:
	void ��ͼ��ʼ��(int(&Map)[Map_Size][Map_Size]);
	int ��ʾ��ͼ(int GG, int(&Map)[Map_Size][Map_Size], int totalPoint);
	void �������(int GG, int(&Map)[Map_Size][Map_Size], int canMove);
};