#ifndef SPEECHCOMPETATION_H
#define SPEECHCOMPETATION_H
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include "person.h"
using namespace std;

class speechCompetation{
public:
	//构造
	speechCompetation();
	//欢迎界面
	void welcome();
	//准备12名参赛选手
	void personPrepare();
	//开始比赛
	void startCompetation();
	//析构
	~speechCompetation();
public:
	vector<int> v1;
	vector<int> v2;
	vector<int> vHonor;
	map<int,person> mPerson;
};

#endif
