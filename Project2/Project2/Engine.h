#pragma once
#include<conio.h>
#include<iostream>

using namespace std;
class CPlayer;
class CMap;
class CUtility;
class CMonster;

//#define LEFT  75
//#define RIGHT 77
//#define UP    72 
//#define DOWN  80 

class CEngine
{
public:
	CEngine();
	~CEngine();
public:
	//CPlayer* m_pPlayer;
	CMap* m_map;
	//CUtility* m_Utility;
public:
	void Init(CPlayer* _pPlayer ,CMonster* _pMonster ,CMap* _pMap);
	void Run();
	void Render();
	void Tick(int _KeyInput); //Update�ǹ�( �𸮾󿡼� Tick�̶�� �θ�)
	int Input();

	bool bIsRunning = true;
};