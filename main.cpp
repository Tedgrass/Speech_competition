using namespace std;
#include<iostream>
#include"person.h"
#include"speechCompetation.h"

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
			sc.exitCompetation();
			break;
		case 1:
			//开始比赛
			sc.startCompetation();
			break;
		case 2:
			//查看往届记录
			sc.showInfo();
			system("pause");
			system("cls");
			break;
		case 3:
			//清空比赛记录
			sc.clead();
			system("pause");
			system("cls");
			break;
			default:
				break;
		}
	}
}
