using namespace std;
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<fstream>
#include"person.h"
#include"speechCompetation.h"


void personPrepare(vector<person> &v1) {
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++)
	{
		string name = "选手";
		name += nameseed[i];
		v1.push_back(person(i+1,name,0));
	}
}

void printPerson(const person &p) {
	cout << "选手编号：" << p.m_id << "\t" << "姓名：" << p.m_name << "\t" << "分数：" << p.m_score << "\t" << endl;
}

void setScore(person& p) {
	deque<int> vScore;
	float sum=0.0;
	for (int i = 0; i < 10; i++)
	{
		int score = rand() % 41 + 60;
		vScore.push_back(score);
	}
	vScore.pop_back();
	vScore.pop_front();
	for (deque<int>::iterator it = vScore.begin(); it != vScore.end();it++) {
		sum += *it;
	}
	p.m_score = (sum / vScore.size());
}

bool comparePerson(const person &p1,const person &p2) {
	if (p1.m_score > p2.m_score) {
		return true;
	}
	else
	{
		return false;
	}
}

void savePerson(const vector<person> &v1){
	fstream fs;
	fs.open("比赛记录.csv",ios::out);
	int num =v1.size() / 3;
	fs<<num<<"届比赛记录如下,姓名,得分"<<endl;
	for(int i=0;i<num;i++){
		fs<<"第"<<i+1<<"届演讲比赛排名如下"<<endl;
		fs<<"冠军：,"<<v1[i*3+0].m_name<<","<<v1[i*3+0].m_score<<endl;
		fs<<"亚军：,"<<v1[i*3+1].m_name<<","<<v1[i*3+1].m_score<<endl;
		fs<<"季军：,"<<v1[i*3+2].m_name<<","<<v1[i*3+2].m_score<<endl;
	}	
	fs.close();
}

class speechCompetation {
public:
	
	speechCompetation(){
		fstream fs;
		fs.open("比赛记录.csv",ios::in);
		string num;
		getline(fs,num);
		this->numofCom = num[0]-48;
		for(int i=0;i<4*this->numofCom;i++){
			//TODO
			string temp;
			getline(fs,temp);
			if((i+4)%4==0) continue;
			for(int i=11;i<12;i++){
				//TODO
				cout<<temp[i]<<endl;
			}
			for(int i=12;i<temp.size();i++){
				//TODO
				cout<<temp[i]<<endl;
			}
		}
		fs.close();
	}

	void competationStart() {
		vector<person> participants;
		personPrepare(participants);
		cout << "本届演讲比赛开始" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "第一轮参赛选手出厂顺序如下：" << endl;
		random_shuffle(participants.begin(), participants.end());
		for_each(participants.begin(), participants.end(), printPerson);
		cout << "----------------------------------------" << endl;
		cout << "-------------比赛进行中-----------------" << endl;
		cout << "----------------------------------------" << endl;
		system("pause");
		cout << "----------------------------------------" << endl;
		for_each(participants.begin(), participants.end(), setScore);
		cout << "第一组排名顺序如下：" << endl;
		sort(participants.begin(), participants.begin() + 6,comparePerson);
		for_each(participants.begin(), participants.begin() + 6,printPerson);
		cout << "-----------------------------------------" << endl;
		cout << "第二组排名顺序如下：" << endl;
		sort(participants.begin() + 6, participants.end(), comparePerson);
		for_each(participants.begin() + 6, participants.end(), printPerson);
		cout << "----------------------------------------" << endl;
		cout << "-------------第二轮比赛进行中-----------" << endl;
		cout << "----------------------------------------" << endl;
		system("pause");
		participants.erase(participants.begin() + 9, participants.end());
		participants.erase(participants.begin() + 3, participants.begin()+6);
		for_each(participants.begin(), participants.end(), setScore);
		sort(participants.begin(), participants.end(), comparePerson);
		for_each(participants.begin(), participants.end(), printPerson);
		
		cout << "----------------------------------------" << endl;
		cout << "比赛结束，名次如下：" << endl;
		cout << "冠军是：" << participants[0].m_name << "\t得分：" << participants[0].m_score<<endl;
		cout << "亚军是：" << participants[1].m_name << "\t得分：" << participants[1].m_score<<endl;
		cout << "季军是：" << participants[2].m_name << "\t得分：" << participants[2].m_score<<endl;
		cout << "----------------------------------------" << endl;
		
		for (vector<person>::iterator it = participants.begin(); it != participants.end()-3;it++) {
			this->Honor.push_back(*it);
		}
		this->numofCom++;
		savePerson(this->Honor);
	}
	
	void lookup() {
		
		if (this->numofCom == 0) return ;
		for (int i = 0; i < this->numofCom; i++)
		{
			cout << "第" << i+1 << "届演讲比赛名次如下：" << endl;
			cout << "冠军是：" << this->Honor[0 + i * 3].m_name << "\t得分：" << this->Honor[0 + i * 3].m_score << endl;
			cout << "亚军是：" << this->Honor[1 + i * 3].m_name << "\t得分：" << this->Honor[1 + i * 3].m_score << endl;
			cout << "季军是：" << this->Honor[2 + i * 3].m_name << "\t得分：" << this->Honor[2 + i * 3].m_score << endl;
		}
	}
	
	void clearall() {
		cout << "是否清空比赛记录？" << endl;
		int choice;
		cin >> choice;
		if (choice) {
			this->Honor.clear();
			savePerson(this->Honor);
			this->numofCom=0;
		}
	
	}
public:
	vector<person> Honor;
	int numofCom;
};


int main() {
	speechCompetation sc;
	int choice;
	while (true) {
		sc.welcome();
		cout << "请做出你的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "退出比赛程序" << endl;
			system("pause");
			return 0;
		case 1:
			//开始比赛
			system("pause");
			system("cls");
			break;
		case 2:
			//查看往届记录
			system("pause");
			system("cls");
			break;
		case 3:
			//清空比赛记录
			system("pause");
			system("cls");
			break;
			default:
				break;
		}
	}
}
