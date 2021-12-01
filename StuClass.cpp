#include <iostream>
#include <iomanip>

#include "StuClass.h"


Stu::Stu(int id, string name, string sex, string field, int year, int month, int day, string address, float E_grade) 
{
	this->id = id;
	this->name = name;
	this->sex = sex;
	this->field = field;
	this->year = year;
	this->month = month;
	this->day = day;
	this->address = address;
	this->gradeOfEnglish = E_grade;
	this->before = Stu::last;
	Stu::last = this;
	if (this->before != nullptr) 
	{//如果是nullptr 那就是没有元素 这是第一个元素
		this->before->setNext(this);
	}
	else 
	{
		Stu::head = this;
	}
	this->next = nullptr;
}

void Stu::printStu() 
{
	cout << "学号:" << std::left << setw(12) << this->id;
	cout << "姓名:" << std::left << setw(10) << this->name;
	cout << "性别:" << std::left << setw(5) << this->sex;
	cout << "专业:" << std::left << setw(15) << this->field;
	cout << "出生日期:" << std::left << setw(4) << this->year << "-" << std::right << setw(2) << this->month << "-" << std::right << setw(2) << this->day << std::right << setw(15);
	cout << "家庭地址:" << std::left << setw(24) << this->address;
	cout << "英语入学成绩:" << std::left << setw(3) << this->gradeOfEnglish;
	cout << endl;
}

void Stu::changeInformation(int id, string name, string sex, string field, int year, int month, int day, string address, float E_grade) 
{
	this->id = id;
	this->name = name;
	this->sex = sex;
	this->field = field;
	this->year = year;
	this->month = month;
	this->day = day;
	this->address = address;
	this->gradeOfEnglish = E_grade;
}

void Stu::delStu() 
{
	if (this->before != nullptr) {//如果是nullptr 那就是没有元素 这是第一个元素
		this->before->setNext(this->next);
	}
	else 
	{ //操作的是head
		Stu::head = this->next;
	}

	if (this->next != nullptr) 
	{
		this->next->setBefore(this->before);
	}
	else 
	{ //操作的是last
		Stu::last = this->before;
	}
	delete this;
}

int Stu::getId() 
{
	return this->id;			//获取该对象的id
}

string Stu::getName() 
{
	return this->name;			//获取该对象的name
}

string Stu::getSex() 
{
	return this->sex;			//获取该对象的sex
}

string Stu::getField() 
{
	return this->field;			//获取该对象的field
}

int Stu::getYear() 
{
	return this->year;			//获取该对象的year
}

int Stu::getMonth() 
{
	return this->month;			//获取该对象的month
}

int Stu::getDay() 
{
	return this->day;			//获取该对象的day
}

string Stu::getAddress() 
{
	return this->address;		//获取该对象的address
}

float Stu::getE_grade() 
{
	return this->gradeOfEnglish;//获取该对象的gradeOfEnglish
}

Stu* Stu::getBefore() 
{
	return this->before;
}

Stu* Stu::getNext() 
{
	return this->next;
}

void Stu::setNext(Stu* item) 
{
	this->next = item;
}

void Stu::setBefore(Stu* item) 
{
	this->before = item;
}

