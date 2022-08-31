#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
using namespace std;

class person{
public:
	//构造函数
	person(int,string,float);
	//析构函数
	~person();
public:
	int m_id;
	string m_name;
	float m_score;
};

#endif
