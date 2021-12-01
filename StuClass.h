#pragma once
#include <iostream>
using namespace std;
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