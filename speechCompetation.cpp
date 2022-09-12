#include"speechCompetation.h"

//构造
speechCompetation::speechCompetation(){
	
	this->numSpeech=0;
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
	//清空比赛记录
	this->v1.clear();
	this->v2.clear();
	this->mPerson.clear();
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

//抽签
void speechCompetation::draw(){
	cout<<"第"<<this->index<<"轮比赛抽签顺序如下："<<endl;
	if(this->index==1){
		//TODO
		random_shuffle(this->v1.begin(),this->v1.end());
		for(vector<int>::iterator it=this->v1.begin();it!=this->v1.end();it++){
			cout<<*it<<" ";
		}
		cout<<endl;
	}else{
		random_shuffle(this->v2.begin(),this->v2.end());
		for(vector<int>::iterator it=this->v2.begin();it!=this->v2.end();it++){
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}

//显示往届成绩
void speechCompetation::showInfo(){
	if(this->numSpeech==0){
		//TODO
		cout<<"无记录！"<<endl;
		return;
	}
	for(int i=0;i<this->numSpeech;i++){
		//TODO
		vector<string>::iterator it = this->vInfo.begin()+3*i;
		cout<<"第"<<i+1<<"届演讲比赛成绩如下："<<endl;
		cout<<"冠军："<<(*it)<<endl;
		cout<<"亚军："<<*(it+1)<<endl;
		cout<<"季军："<<*(it+2)<<endl;
	}
}

//打分
void speechCompetation::setScore(){
	vector<int> vTemp;
	map<double,int,greater<double>> mTemp;
	int num=1;
	//确认比赛人员
	if(this->index==1){
		//TODO
		vTemp=this->v1;
	}else{
		vTemp=this->v2;
	}
	//对组内人员进行打分
	for(vector<int>::iterator it=vTemp.begin();it!=vTemp.end();it++,num++){
		deque<double> dTemp;
		double scoreTemp;
		for(int i=0;i<10;i++){
			//TODO
			scoreTemp=(rand()%400)/10.0+61.0;
			dTemp.push_back(scoreTemp);
		}
		sort(dTemp.begin(),dTemp.end());
		dTemp.pop_back();
		dTemp.pop_front();
		scoreTemp = accumulate(dTemp.begin(),dTemp.end(),0.0)/dTemp.size();
		mTemp.insert(make_pair(scoreTemp,*it));
		this->mPerson.at(*it).m_score[this->index-1]=scoreTemp;	
		if(num%6==0){
			map<double,int,greater<double>>::iterator mit = mTemp.begin();
			cout<<"第"<<num/6<<"组比赛已完成，成绩如下："<<endl;
			for(int i=0;i<6;i++,mit++){
				//TODO
				if(i<3 && this->index==1){
					//TODO
					v2.push_back(mit->second);
				}
				if(i<3 && this->index==2){
					//TODO
					vHonor.push_back(mit->second);
					this->vInfo.push_back(this->mPerson.at(mit->second).m_name);
				}
				cout<<"编号：\t"<<mit->second<<"\t";
				cout<<"姓名：\t"<<this->mPerson.at(mit->second).m_name<<"\t";
				cout<<"分数：\t"<<this->mPerson.at(mit->second).m_score[this->index-1]<<endl;
			}
			mTemp.clear();
		}
	}
}

//比赛开始
void speechCompetation::startCompetation(){
//比赛人员准备
	this->personPrepare();
//第一轮比赛开始
	this->index=1;
	//1、抽签
	this->draw();
	//2、打分
	this->setScore();
//第二轮比赛开始
	this->index=2;
	//1、抽签
	this->draw();
	//2、打分
	this->setScore();
//保存比赛结果
	this->saveData();
	this->numSpeech++;
	system("pause");
	system("cls");
}

//保存成绩信息
void speechCompetation::saveData(){
	fstream fs;
	fs.open("Honor.csv",ios::out);
	for(vector<int>::iterator it=this->vHonor.begin();it!=this->vHonor.end();it++){
		//TODO
		fs<<this->mPerson.at(*it).m_name<<",";
	}
	fs.close();
}

//读取文档
void speechCompetation::loadData(){
	fstream fs;
	fs.open("Honor.csv",ios::in);
	string str;
	fs.close();
}

//退出
void speechCompetation::exitCompetation(){
	cout << "退出比赛程序" << endl;
	system("pause");
	exit(0);
}

//析构
speechCompetation::~speechCompetation(){
	
}
