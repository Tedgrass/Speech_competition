#include"speechCompetation.h"

//构造
speechCompetation::speechCompetation(){
	this->personPrepare();
}
//欢迎界面
void speechCompetation::welcome(){
	
	cout << "*******************************" << endl;
	cout << "******* 欢迎参加演讲比赛*******" << endl;
	cout << "******	1.开始演讲比赛	*******" << endl;
	cout << "******	2.查看往届记录	*******" << endl;
	cout << "******	3.清空比赛记录	*******" << endl;
	cout << "******	0.退出比赛程序	*******" << endl;
	cout << "*******************************" << endl;	
}

//准备12名选手
void speechCompetation::personPrepare() {
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++)
	{
		person p;
		p.m_name = "选手";
		p.m_name += nameseed[i];
		p.m_id = 10000 + i;
		this->v1.push_back(p.m_id);
		this->mPerson.insert(make_pair(p.m_id,p));
	}
}

//比赛开始
void speechCompetation::startCompetation(){
//第一轮比赛开始
	//1、抽签
	
	//2、打分
	
	//3、展示分数
	
//第二轮比赛开始
	//1、抽签
	
	//2、打分
	
	//3、展示分数
	
}
//析构
speechCompetation::~speechCompetation(){
	
}
