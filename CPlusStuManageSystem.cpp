#include <iostream>
#include <string>
#include <iomanip>
#define DEBUG 0//让edited 和 original不工作
using namespace std;


class Stu {
public:
	static Stu* last;
	static Stu* head;
	Stu(int id, string name, string sex, string field, int year, int month, int day, string address, float E_grade) :id(id), name(name), sex(sex), field(field), year(year), month(month), day(day), address(address), gradeOfEnglish(E_grade) {
		this->before = Stu::last;
		Stu::last = this;
		this->before->setNext(this->next);
		this->next = nullptr;
	}
	void printStu() {
		cout << "学号:" << std::left << setw(12) << this->id;
		cout << "姓名:" << std::left << setw(10) << this->name;
		cout << "性别:" << std::left << setw(5) << this->sex;
		cout << "专业:" << std::left << setw(15) << this->field;
		cout << "出生日期:" << std::left << setw(4) << this->year << "-" << std::right << setw(2) << this->month << "-" << std::right << setw(2) << this->day << std::right << setw(15);
		cout << "家庭地址:" << std::left << setw(24) << this->address;
		cout << "英语入学成绩:" << std::left << setw(3) << this->gradeOfEnglish;
		cout << endl;
	}
	void changeInformation(int id, string name, string sex, string field, int year, int month, int day, string address, float E_grade) {
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
	void delStu() {
		this->before->setNext(this->next);
		this->next->setBefore(this->before);
		delete this;
	}
	void setNext(Stu* item) {
		this->next = item;
	}
	void setBefore(Stu* item) {
		this->before = item;
	}


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


int main() {
	Stu::last = nullptr;
	Stu::head = nullptr;
	return 0;
}