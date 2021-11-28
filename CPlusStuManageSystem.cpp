﻿#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#define DEBUG 0//让edited 和 original不工作

using namespace std;

//void menu();			//菜单
void add();				//增加													//done
void del();				//删除													//done
void change();			//修改													//done
void search();			//查找													//done
void censusAll();		//学生信息统计（按专业或性别或年龄---年龄要自动计算）	//done
void printAll();		//输出全部学生信息										//done
void sort(bool output = false);
void load(bool output);//导入
void save(bool output);//导出（学生信息保存）

void screenField();		//按照专业筛选
void screenSex();		//按照性别筛选
void screenAge();		//按照年龄筛选

bool birthdayJudge(int year, int month, int day);
bool isLeap(int year, int month, int day);
bool sexJudge(std::string sex);
bool isExist(int id, bool output);

class Stu {
public:
	static Stu* last;
	static Stu* head;
	Stu(int id, string name, string sex, string field, int year, int month, int day, string address, float E_grade){
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

void menu() //菜单
{
	int userChoice;

	while (true)
	{
		system("cls");//清屏

		cout << endl;
		cout << endl;
		cout << endl;
		cout << "----------------------------学生基本信息管理系统----------------------------" << endl;
		cout << endl;
		cout << endl;
		cout << "0.导入学生信息（默认已自动导入）" << endl;
		cout << "1.新增学生信息 " << endl;
		cout << "2.查询学生信息 " << endl;
		cout << "3.修改学生信息 " << endl;
		cout << "4.删除学生信息 " << endl;
		cout << "5.学生信息统计 " << endl;
		cout << "6.学生成绩排序 " << endl;
		cout << "7.学生信息总览 " << endl;
		cout << "8.学生信息储存 " << endl;
		cout << "9.保存并安全退出" << endl;
		cout << endl;
		cout << endl;
		cout << "使用注意事项" << endl;
		cout << "进行“增加”、“修改”、“删除”操作后，务必将信息储存，否则不会保存在文件内！" << endl;
		cout << endl;
		cout << endl;
		cout << "-----------------------------------------------------------------------------" << endl;

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
			printAll();
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
		toAdd = new Stu(id, name, sex, field, year, month, day, address, E_grade);
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
	return false;
}

void del() {
	int id;
	Stu* item = Stu::head;
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
		item = item->getNext();
	}
	cout << "学号不存在！返回至菜单:" << endl;
	system("pause");
	return;
}

void change(){
	int id;
	Stu* item = Stu::head;
	cout << "请输入要修改学生的学号：";
	cin >> id;

	while (item != nullptr) {
		if (item->getId() == id) {

			item->printStu();

			char name[15], sex[5], field[30], address[100];
			float E_grade;
			int year, month, day;

			cout << "开始修改" << endl;

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

void search()
{
	Stu* item = Stu::head;
	string inputName;

	cout << "输入要查询学生的姓名:";
	cin >> inputName;

	cout << "下面是数据库内有关" << inputName << "的信息" << endl;
	cout << endl;

	while (item != NULL)
	{
		if (item->getName() ==  inputName)
		{
			item->printStu();
			//防止重名 继续执行
			item = item->getNext();
		}
		else {
			item = item->getNext();
		}
	}
	cout << "以上是数据库内有关" << inputName << "的信息" << endl;
	cout << endl;
	system("pause");
	return;
}

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

void exchange(Stu* item1,Stu* item2) { // 交换两个东西
	if (item1->getBefore() == nullptr) { //这是head
		Stu::head == item2;
	}
	else {
		item1->getBefore()->setNext(item2);
	}
	item2->setBefore(item1->getBefore());

	if (item2->getNext() == nullptr) { //这是last啊
		Stu::last = item1;
	}
	else {
		item2->getNext()->setBefore(item1);
	}
	item1->setNext(item2->getNext());
	item2->setNext(item1);
	item1->setBefore(item2);

}

void load(bool output = false) //
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



	
Stu* Stu::last = nullptr;
Stu* Stu::head = nullptr;


int main() {
	
	return 0;
}