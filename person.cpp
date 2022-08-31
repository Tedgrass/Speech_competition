#include"person.h"

//构造函数
person::person(int id,string name,float score){
	this->m_id = id;
	this->m_name = name;
	this->m_score = score;
}

//析构
person::~person(){
	
}
