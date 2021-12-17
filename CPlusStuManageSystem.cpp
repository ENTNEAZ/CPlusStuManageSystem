//有新生来报到，要逐个录入其信息，
//如：学生姓名，性别，专业，出生日期，家庭地址，英语入学成绩。
//要求设计链表来实现，并统计学生人数。文本界面为：
//1. 新增学生信息 
//2. 删除学生信息
//3. 导入学生信息（已经保存于的文件信息）
//4. 学生信息搜索（按姓名）
//5. 学生信息统计（按专业或性别或年龄---年龄要自动计算）
//6. 按英语成绩排序
//7. 学生信息保存
//8. 退出
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

#include "StuClass.h"
#include "censusAll.h"
#include "change.h"
#include "del.h"
#include "Utils.h"
#include "search.h"

using namespace std;

void menu();									//菜单
void add();										//1.增加		
void search();									//2.查询(已支持模糊查询)
void change();									//3.修改	
void del();										//4.删除													
void censusAll();								//5.学生信息统计（按专业或性别或年龄---年龄要自动计算）	
void printAll(bool reverse);					//6.输出全部学生信息							
void sort(bool output = false);					//7.排序(按照英语成绩排序)
void load(bool output);							//8.导入
void save(bool output);							//9.导出（学生信息保存）

void changeStu_Id();							//通过查询学生学号修改学生信息
void changeStu_Name();							//通过查询学生姓名修改学生信息
void delStu_Id();								//通过查询学生学号删除学生信息
void delStu_Name();								//通过查询学生姓名删除学生信息
void screenField();								//按照专业筛选
void screenSex();								//按照性别筛选
void screenAge();								//按照年龄筛选
void exchange(Stu* item1, Stu* item2);			//交换对象

bool birthdayJudge(int year, int month, int day);	//判断出生日期格式
bool isLeap(int year, int month, int day);			//判断是否为闰年
bool sexJudge(std::string sex);						//判断性别格式
bool isExist(int id, bool output);					//判断是否已存在

void menu() //菜单
{
	while (true)
	{
		system("cls");//清屏
		cout << "----------------------------学生基本信息管理系统----------------------------" << endl;
		cout << endl;
		cout << "\t\t\t    0.导入学生信息（默认已自动导入）" << endl;
		cout << "\t\t\t    1.新增学生信息 " << endl;
		cout << "\t\t\t    2.查询学生信息 " << endl;
		cout << "\t\t\t    3.修改学生信息 " << endl;
		cout << "\t\t\t    4.删除学生信息 " << endl;
		cout << "\t\t\t    5.学生信息统计菜单" << endl;
		cout << "\t\t\t    6.学生成绩排序 " << endl;
		cout << "\t\t\t    7.学生信息总览 " << endl;
		cout << "\t\t\t    8.学生信息储存 " << endl;
		cout << "\t\t\t    9.保存并安全退出" << endl;
		cout << endl;
		cout << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "使用注意事项" << endl;
		cout << "进行“增加”、“修改”、“删除”操作后，务必将信息储存，否则不会保存在文件内！" << endl;
		cout << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << endl;
		
		int userChoice;
		cout << "请输入序号：";
		cin >> userChoice;

		switch (userChoice)
		{
		case 0:
			load(true);
			break;
		case 1:
			add();
			break;
		case 2:
			search();
			break;
		case 3:
			change();
			break;
		case 4:
			del();
			break;
		case 5:
			censusAll();
			break;
		case 6:
			sort(true);
			break;
		case 7:
			printAll(false);
			break;
		case 8:
			save(true);
			break;
		case 9:
			save(true);
			return;
			break;
		default:
			cout << "无法识别，请重新输入" << endl;
			system("pause");
		}
	}
}

void add()//增加 
{
	int id;

	cout << "输入学号：";
	cin >> id;

	if (isExist(id, true))
	{
		system("pause");
		return;//已经存在此人 返回菜单
	}
	else
	{
		string name, sex, field, address;
		float E_grade;
		int year, month, day;

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
		cout << endl;
		Stu* toAdd = nullptr;
		toAdd = new Stu(id, name, sex, field, year, month, day, address, E_grade);
		toAdd->printStu();

		cout << "添加成功" << endl;
		system("pause");
		return;
	}
}

bool isExist(int id, bool output) 
{
	Stu* item = Stu::head;
	while (item != nullptr) 
	{
		if (item->getId() == id) 
		{
			if (output) 
			{
				item->printStu();
				cout << "学号已存在，请重新输入" << endl;
			}
			return true;
		}
		item = item->getNext();
	}
	return false;
}

void load(bool output = false) //导入
{
	ifstream file;
	string name, sex, field, address;
	float E_grade;
	int id, year, month, day;
	bool haveNext = true;
	file.open("information.txt");

	while (file.good() && !(file.peek() == EOF))
	{
		file >> id;
		file.ignore();

		file >> name;
		file >> sex;
		file >> field;

		file >> year;
		file >> month;
		file >> day;
		file.ignore();

		file >> address;
		file >> E_grade;
		file.ignore();

		Stu* toAdd = nullptr;
		toAdd = new Stu(id, name, sex, field, year, month, day, address, E_grade);
	}
	file.close();

	if (output)
	{
		cout << "导入成功" << endl;
		system("pause");
	}
	return;
}

void save(bool output = false)//文件存放
{
	ofstream file;
	Stu* item = Stu::head;
	file.open("information.txt");
	while (item != NULL && file.good())
	{
		file << item->getId() << endl;
		file << item->getName() << endl;
		file << item->getSex() << endl;
		file << item->getField() << endl;
		file << item->getYear() << endl;
		file << item->getMonth() << endl;
		file << item->getDay() << endl;
		file << item->getAddress() << endl;
		file << item->getE_grade() << endl;

		item = item->getNext();
	}

	file.close();

	if (output)
	{
		cout << "导出成功" << endl;
		system("pause");
	}
	return;
}

void sort(bool output)
{
	Stu* item = Stu::head;
	Stu* end = nullptr;
	if (item == nullptr || item->getNext() == nullptr)
	{
		cout << "排序成功，已按照英语成绩进行排序" << endl;
		system("pause");
		return;//一个都没有或者就一个
	}

	while (Stu::head->getNext() != end)
	{
		item = Stu::head;//复位
		for (; item->getNext() != end; item = item->getNext())
		{
			if (item->getE_grade() < item->getNext()->getE_grade())
			{
				exchange(item, item->getNext());//调用交换函数
				// exchange后
				// 冒泡原理中指针变化了（原本是第几个 现在这种对象指针在交换过程中 原本冒泡排序中指向第n个的不应该变的指针变成指向第n+1个 无形中出错）
				// （但又要保证没有错误）
				// 为了消除这个变化
				// 当前指针向前一位
				// 
				// 若想没有下面语句 则需要比较的是 item 和 item->before()
				// 或者优化为其他算法
				item = item->getBefore();
			}
		}
		end = (end == nullptr)?Stu::last:end->getBefore();
	}
	cout << "排序成功，已按照英语成绩进行排序" << endl;
	system("pause");
	return;
}

void exchange(Stu* item1,Stu* item2)// 交换两个对象
{ 
	if (item1->getBefore() == nullptr)//这是head 
	{ 
		Stu::head = item2;
	}
	else//不是head
	{
		item1->getBefore()->setNext(item2);
	}
	item2->setBefore(item1->getBefore());

	if (item2->getNext() == nullptr)//这是last
	{ 
		Stu::last = item1;
	}
	else//不是last
	{
		item2->getNext()->setBefore(item1);
	}

	item1->setNext(item2->getNext());
	item2->setNext(item1);
	item1->setBefore(item2);

}
	
Stu* Stu::last = nullptr;
Stu* Stu::head = nullptr;

int main() 
{
	system("color F0");
	load(false);
	menu();
	return 0;
}