#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
using namespace std;

class person{
public:
	//构造函数
	person();
	//析构函数
	~person();
public:
	int m_id;
	string m_name;
	double m_score[2]={0,0};
};

#endif
