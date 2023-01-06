#include<iostream>
#include<fstream>
using namespace std;
#define Map_Size 4
class MoveMent
{
public:
	int GG = 0;
	int ifFull = 0;
	int totalPoint = 0;
	int canMove = 0;
	void Check(int(&Map)[Map_Size][Map_Size]);
	void MoveUp(int(&Map)[Map_Size][Map_Size]);
	void MoveRight(int(&Map)[Map_Size][Map_Size]);
	void MoveDown(int(&Map)[Map_Size][Map_Size]);
	void MoveLeft(int(&Map)[Map_Size][Map_Size]);
	void ScoreBoard(int totalPoint);
};