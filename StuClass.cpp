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
	{//�����nullptr �Ǿ���û��Ԫ�� ���ǵ�һ��Ԫ��
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
	cout << "ѧ��:" << std::left << setw(12) << this->id;
	cout << "����:" << std::left << setw(10) << this->name;
	cout << "�Ա�:" << std::left << setw(5) << this->sex;
	cout << "רҵ:" << std::left << setw(15) << this->field;
	cout << "��������:" << std::left << setw(4) << this->year << "-" << std::right << setw(2) << this->month << "-" << std::right << setw(2) << this->day << std::right << setw(15);
	cout << "��ͥ��ַ:" << std::left << setw(24) << this->address;
	cout << "Ӣ����ѧ�ɼ�:" << std::left << setw(3) << this->gradeOfEnglish;
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
	if (this->before != nullptr) {//�����nullptr �Ǿ���û��Ԫ�� ���ǵ�һ��Ԫ��
		this->before->setNext(this->next);
	}
	else 
	{ //��������head
		Stu::head = this->next;
	}

	if (this->next != nullptr) 
	{
		this->next->setBefore(this->before);
	}
	else 
	{ //��������last
		Stu::last = this->before;
	}
	delete this;
}

int Stu::getId() 
{
	return this->id;			//��ȡ�ö����id
}

string Stu::getName() 
{
	return this->name;			//��ȡ�ö����name
}

string Stu::getSex() 
{
	return this->sex;			//��ȡ�ö����sex
}

string Stu::getField() 
{
	return this->field;			//��ȡ�ö����field
}

int Stu::getYear() 
{
	return this->year;			//��ȡ�ö����year
}

int Stu::getMonth() 
{
	return this->month;			//��ȡ�ö����month
}

int Stu::getDay() 
{
	return this->day;			//��ȡ�ö����day
}

string Stu::getAddress() 
{
	return this->address;		//��ȡ�ö����address
}

float Stu::getE_grade() 
{
	return this->gradeOfEnglish;//��ȡ�ö����gradeOfEnglish
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

