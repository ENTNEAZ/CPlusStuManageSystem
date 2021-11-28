#include <iostream>
#include <string>
#include <iomanip>
#define DEBUG 0//让edited 和 original不工作
using namespace std;

bool birthdayJudge(int year, int month, int day);
bool isLeap(int year, int month, int day);
bool sexJudge(std::string sex);

bool isExist(int id, bool output);
void add();
void del();

class Stu {
public:
	static Stu* last;
	static Stu* head;
	Stu(int id, string name, string sex, string field, int year, int month, int day, string address, float E_grade) :id(id), name(name), sex(sex), field(field), year(year), month(month), day(day), address(address), gradeOfEnglish(E_grade) {
		this->before = Stu::last;
		Stu::last = this;
		if (this->before != nullptr) {//如果是nullptr 那就是没有元素 这是第一个元素
			this->before->setNext(this->next);
		}
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
		if (Stu::last == this) {
			Stu::last = this->before;
		}
		if (Stu::head == this) {
			Stu::head == this->next;
		}
		delete this;
	}
	int getId() {
		return this->id;
	}
	Stu* getBefore() {
		return this->before;
	}
	Stu* getNext() {
		return this->next;
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
		char name[15], sex[5], field[30], address[100];
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

		Stu* toAdd = nullptr;
		toAdd = new Stu(id,name,sex,field,year,month,day,address,E_grade);
		cout << "添加成功" << endl;
		system("pause");
		return;
	}
}

bool isExist(int id, bool output) {
	Stu* item = Stu::head;
	while (item != nullptr) {
		if (item->getId() == id) {
			if (output) {
				item->printStu();
				cout << "学号已存在，请重新输入" << endl;
			}
			return true;
		}
		item = item->getNext();
	}
}

void del(int id) {
	Stu* item = Stu::head;
	int id;
	cout << "请输入要删除学生的学号：";
	cin >> id;

	while (item != nullptr) {
		if (item->getId() == id) {
			item->printStu();
			item->delStu();
			cout << "该学生信息已删除" << endl;
			system("pause");
			return;
		}
	}
	cout << "学号不存在！返回至菜单:" << endl;
	system("pause");
	return;

}

int main() {
	Stu::last = nullptr;
	Stu::head = nullptr;
	return 0;
}