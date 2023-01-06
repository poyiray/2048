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
	void 地图初始化(int(&Map)[Map_Size][Map_Size]);
	int 显示地图(int GG, int(&Map)[Map_Size][Map_Size], int totalPoint);
	void 随机生成(int GG, int(&Map)[Map_Size][Map_Size], int canMove);
};