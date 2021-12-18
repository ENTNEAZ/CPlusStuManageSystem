#include <iostream>
#include <ctime>
#include <string>
#include "StuClass.h"
#include "Utils.h"

using namespace std;

void change();
void changeStu_Id();
void changeStu_Name();

void change()
{
	cout << "----------------------------修改界面----------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "搜寻学号修改输入  1" << endl;
	cout << "搜寻姓名修改输入  2" << endl;
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
		changeStu_Id();
		break;
	case 2:
		changeStu_Name();
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

void changeStu_Id()
{
	Stu* item = Stu::head;

	int id;
	cout << "请输入要修改学生的学号：";
	cin >> id;

	while (item != nullptr)
	{
		if (item->getId() == id)
		{

			item->printStu();

			char name[15], sex[5], field[30], address[100];
			float E_grade;
			int id, year, month, day;

			cout << "开始修改" << endl;

			cout << "输入学号 ";
			cin >> id;

			cout << "输入姓名: ";
			cin >> name;

			cout << "输入性别: ";
			cin >> sex;

			cout << "输入专业: ";
			cin >> field;

			cout << "请输入出生年份: ";
			cin >> year;

			cout << "请输入出生月份: ";
			cin >> month;

			cout << "请输入出生日期: ";
			cin >> day;

			cout << "输入家庭地址: ";
			cin >> address;

			cout << "输入英语入学成绩：";
			cin >> E_grade;

			if (!birthdayJudge(year, month, day))
			{
				cout << "日期输入有误，返回至菜单" << endl;
				system("pause");
				return;
			}

			if (!sexJudge(sex))
			{
				cout << "性别输入不符实际，返回至菜单" << endl;
				system("pause");
				return;
			}

			item->changeInformation(id, name, sex, field, year, month, day, address, E_grade);
			cout << endl;
			cout << "该学生信息已修改" << endl;
			cout << endl;
			item->printStu();
			system("pause");
			return;
		}
		item = item->getNext();
	}
	cout << "学号不存在！返回至菜单:" << endl;
	system("pause");
	return;
}

void changeStu_Name()
{
	Stu* item = Stu::head;

	string name;
	cout << "请输入要修改学生的姓名：";
	cin >> name;

	while (item != nullptr)
	{
		if (item->getName() == name)
		{

			item->printStu();

			string name, sex, field, address;
			float E_grade;
			int id, year, month, day;

			cout << "开始修改" << endl;

			cout << "输入学号 ";
			cin >> id;

			cout << "输入姓名: ";
			cin >> name;

			cout << "输入性别: ";
			cin >> sex;

			cout << "输入专业: ";
			cin >> field;

			cout << "请输入出生年份: ";
			cin >> year;

			cout << "请输入出生月份: ";
			cin >> month;

			cout << "请输入出生日期: ";
			cin >> day;

			cout << "输入家庭地址: ";
			cin >> address;

			cout << "输入英语入学成绩：";
			cin >> E_grade;

			if (!birthdayJudge(year, month, day))
			{
				cout << "日期输入有误，返回至菜单" << endl;
				system("pause");
				return;
			}

			if (!sexJudge(sex))
			{
				cout << "性别输入不符实际，返回至菜单" << endl;
				system("pause");
				return;
			}

			item->changeInformation(id, name, sex, field, year, month, day, address, E_grade);
			cout << endl;
			cout << "该学生信息已修改" << endl;
			cout << endl;
			item->printStu();
			system("pause");
			return;
		}
		item = item->getNext();
	}
	cout << "姓名不存在！返回至菜单:" << endl;
	system("pause");
	return;
}