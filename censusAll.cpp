#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;


void censusAll();		//学生信息统计（按专业或性别或年龄---年龄要自动计算）	//done
void printAll();		//输出全部学生信息	


void screenField();		//按照专业筛选
void screenSex();		//按照性别筛选
void screenAge();		//按照年龄筛选

class Stu {
public:
	static Stu* last;
	static Stu* head;
	Stu(int id, string name, string sex, string field, int year, int month, int day, string address, float E_grade) {
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
		if (this->before != nullptr) {//如果是nullptr 那就是没有元素 这是第一个元素
			this->before->setNext(this);
		}
		else {
			Stu::head = this;
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
		if (this->before != nullptr) {//如果是nullptr 那就是没有元素 这是第一个元素
			this->before->setNext(this->next);
		}
		else { //操作的是head
			Stu::head = this->next;
		}

		if (this->next != nullptr) {
			this->next->setBefore(this->before);
		}
		else { //操作的是last
			Stu::last = this->before;
		}
		delete this;
	}
	int getId() {
		return this->id;			//获取该对象的id
	}
	string getName() {
		return this->name;			//获取该对象的name
	}
	string getSex() {
		return this->sex;			//获取该对象的sex
	}
	string getField() {
		return this->field;			//获取该对象的field
	}
	int getYear() {
		return this->year;			//获取该对象的year
	}
	int getMonth() {
		return this->month;			//获取该对象的month
	}
	int getDay() {
		return this->day;			//获取该对象的day
	}
	string getAddress() {
		return this->address;		//获取该对象的address
	}
	float getE_grade() {
		return this->gradeOfEnglish;//获取该对象的gradeOfEnglish
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
			printAll();
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

void printAll()
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