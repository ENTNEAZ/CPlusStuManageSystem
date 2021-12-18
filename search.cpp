#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "StuClass.h"

using namespace std;

void search();
void search_Id();
void search_Name();

void search()//(已支持模糊查询)
{
	system("cls");
	cout << "----------------------------查询界面----------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "按学号查询输入  1" << endl;
	cout << "按姓名查询输入  2" << endl;
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
		search_Id();
		break;
	case 2:
		search_Name();
		break;
	case 3:
		return;
		break;
	default:
		cout << "输入有误，重新输入" << endl;
		system("pause");
		return;
	}
}

void search_Id()
{
	Stu* item = Stu::head;

	int inputId;
	cout << "请输入要查询学生的学号";
	cin >> inputId;

	cout << endl;
	cout << "下面是数据库内有关" << inputId << "的信息" << endl;
	cout << endl;

	while (item != NULL)
	{
		if (item->getId() == inputId)
		{
			item->printStu();
		}
		item = item->getNext();
	}
	cout << "以上是数据库内有关" << inputId << "的信息" << endl;
	cout << endl;
	system("pause");
	return;
}

void search_Name()
{
	Stu* item = Stu::head;
	string inputName;

	cout << "请输入要查询学生的姓名(已支持模糊查询)";
	cin >> inputName;

	cout << endl;
	cout << "下面是数据库内有关" << inputName << "的信息" << endl;
	cout << endl;

	while (item != NULL)
	{
		size_t found = item->getName().find(inputName);
		if (found != string::npos)
		{
			item->printStu();
		}
		item = item->getNext();
	}
	cout << "以上是数据库内有关" << inputName << "的信息" << endl;
	cout << endl;
	system("pause");
	return;
}