#pragma once
#include <iostream>

using namespace std;

class Stu {
public:
	static Stu* last;
	static Stu* head;
	Stu(int id, string name, string sex, string field, int year, int month, int day, string address, float E_grade);
								//类的构造函数
	void printStu();
								//输出该对象的信息
	void changeInformation(int id, string name, string sex, string field, int year, int month, int day, string address, float E_grade);
								//修改该对象的信息
	void delStu();
								//删除该对象

	int getId();				//获取该对象的“学号”
	string getName();			//获取该对象的“姓名”
	string getSex();			//获取该对象的“性别”
	string getField();			//获取该对象的“专业”
	int getYear();				//获取该对象出生日期中的“年”
	int getMonth();				//获取该对象出生日期中的“月”
	int getDay();				//获取该对象出生日期中的“日”
	string getAddress();		//获取该对象的“家庭地址”
	float getE_grade();			//获取该对象的“英语成绩”
	Stu* getBefore();			//获取该对象的前指针
	Stu* getNext();				//获取该对象的后指针

	void setNext(Stu* item);	//设置该对象的前指针
	void setBefore(Stu* item);	//设置该对象的后指针

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