#include <iostream>
#include <ctime>
#include <string>
#include "StuClass.h"

using namespace std;


void screenField();					//按照专业筛选
void screenSex();					//按照性别筛选
void screenAge();					//按照年龄筛选
void printAll(bool reverse);		//输出全部学生信息

void censusAll()
{
	int userChoice;

	while (true)
	{
		system("cls");
		cout << endl;
		cout << "----------------------------学生信息统计系统----------------------------" << endl;
		cout << endl;
		cout << endl;
		cout << "1.按照专业筛选" << endl;
		cout << "2.按照性别筛选" << endl;
		cout << "3.按照年龄筛选" << endl;
		cout << "4.输出全部学生信息" << endl;
		cout << endl;
		cout << "5.返回主菜单" << endl;
		cout << endl;
		cout << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << endl;

		cout << "请输入序号:";
		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
			screenField();
			break;
		case 2:
			screenSex();
			break;
		case 3:
			screenAge();
			break;
		case 4:
			printAll(false);
			break;
		case 5:
			return;
			break;
		default:
			cout << "无法识别，请重新输入！" << endl;
			system("pause");
		}
	}
}

void screenField()
{
	Stu* item = Stu::head;
	string findField;
	int count = 0;

	cout << "请输入要筛选出的专业：" << endl;
	cin >> findField;

	cout << endl << "以下是数据库中的信息：" << endl;

	while (item != NULL)
	{
		if (item->getField() == findField)
		{
			item->printStu();
			count++;
		}
		item = item->getNext();
	}

	cout << endl;
	cout << "符合条件的学生有" << count << "个" << endl;
	cout << "----------------------------------------------------------" << endl;
	system("pause");
	return;
}

void screenSex()//按照性别筛选出符合条件的学生
{
	Stu* item = Stu::head;
	string findSex;
	int count = 0;

	cout << "请输入要筛选出的性别：" << endl;
	cin >> findSex;

	cout << endl << "以下是数据库中的信息：" << endl;

	while (item != NULL)
	{
		if (item->getSex() == findSex)
		{
			item->printStu();
			count++;
		}
		item = item->getNext();
	}

	cout << endl;
	cout << "符合条件的学生有" << count << "个" << endl;
	cout << "----------------------------------------------------------" << endl;
	system("pause");
	return;
}

void screenAge()
{
	Stu* item = Stu::head;
	int findAge;
	int count = 0;

	time_t  t;
	time(&t);

	cout << "请输入要筛选出的年龄：";
	cin >> findAge;

	cout << endl << "以下是数据库中的信息：" << endl;

	while (item != NULL)
	{
		if ((localtime(&t)->tm_year + 1900) - item->getYear() == findAge)
		{
			item->printStu();
			count++;
		}
		item = item->getNext();
	}

	cout << endl;
	cout << "符合条件的学生有" << count << "个" << endl;
	cout << "----------------------------------------------------------" << endl;
	system("pause");
	return;
}

void printAll(bool reverse)
{
	Stu* item = Stu::head;
	int count = 0;

	while (item != NULL)
	{
		item->printStu();
		count++;
		item = item->getNext();
	}

	cout << endl;
	cout << "符合条件的学生有" << count << "个" << endl;
	cout << "----------------------------------------------------------" << endl;
	system("pause");
	return;
}