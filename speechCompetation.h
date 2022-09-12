#ifndef SPEECHCOMPETATION_H
#define SPEECHCOMPETATION_H
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<deque>
#include<numeric>
#include<fstream>
#include<string>
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
	//抽签
	void draw();
	//打分
	void setScore();
	//开始比赛
	void startCompetation();
	//显示往届成绩
	void showInfo();
	//保存成绩信息
	void saveData();
	//读取文档
	void loadData();
	//退出
	void exitCompetation();
	//析构
	~speechCompetation();
	
public:
	vector<int> v1;
	vector<int> v2;
	vector<int> vHonor;
	vector<string> vInfo;
	map<int,person> mPerson;
	int index;
	int numSpeech;
};

#endif
