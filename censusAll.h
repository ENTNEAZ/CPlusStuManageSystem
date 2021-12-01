#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void censusAll();		//学生信息统计（按专业或性别或年龄---年龄要自动计算）	//done

void screenField();		//按照专业筛选
void screenSex();		//按照性别筛选
void screenAge();		//按照年龄筛选

class Stu {
public:
	static Stu* last;
	static Stu* head;
	Stu(int id, string name, string sex, string field, int year, int month, int day, string address, float E_grade);
	void printStu();
	void changeInformation(int id, string name, string sex, string field, int year, int month, int day, string address, float E_grade);
	void delStu();
	int getId();
	string getName();
	string getSex();
	string getField();
	int getYear();
	int getMonth();
	int getDay();
	string getAddress();
	float getE_grade();
	Stu* getBefore();
	Stu* getNext();

	void setNext(Stu* item);
	void setBefore(Stu* item);


private:
	int id;
	string name;
	string sex;
	string field;
	int year;
	int month;
	int day;
	string address;
	float gradeOfEnglish;

	Stu* before;
	Stu* next;

};