#include <iostream>
#include <ctime>
#include <string>
#include "StuClass.h"

using namespace std;


void del();
void delStu_Id();
void delStu_Name();

void del()
{
	system("cls");
	cout << "----------------------------删除界面----------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "搜寻学号删除输入  1" << endl;
	cout << "搜寻姓名删除输入  2" << endl;
	cout << endl;
	cout << "回到主菜单输入    3" << endl;
	cout << endl;
	cout << endl;
	cout << "----------------------------------------------------------------" << endl;

	int userChoice;
	cout << "输入选择： " << endl;
	cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		delStu_Id();
		break;
	case 2:
		delStu_Name();
		break;
	case 3:
		return;
		break;
	default:
		cout << "输入有误，重新输入" << endl;
		system("pause");
	}
}

void delStu_Id()
{
	Stu* item = Stu::head;
	int id;

	cout << "请输入要删除学生的学号：";
	cin >> id;

	cout << endl;
	while (item != nullptr)
	{
		if (item->getId() == id)
		{
			item->printStu();
			item->delStu();
			cout << "该学生信息已删除" << endl;
			system("pause");
			return;
		}
		item = item->getNext();
	}
	cout << "学号不存在！返回至菜单:" << endl;
	system("pause");
	return;
}

void delStu_Name()
{
	Stu* item = Stu::head;
	string iname;

	cout << "请输入要删除学生的姓名：";
	cin >> iname;

	cout << endl;
	while (item != nullptr)
	{
		if (item->getName() == iname)
		{
			item->printStu();
			item->delStu();
			cout << "该学生信息已删除" << endl;
			system("pause");
			return;
		}
		item = item->getNext();
	}
	cout << "姓名不存在！返回至菜单:" << endl;
	system("pause");
	return;
}