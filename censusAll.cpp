#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;


void censusAll();		//ѧ����Ϣͳ�ƣ���רҵ���Ա������---����Ҫ�Զ����㣩	//done
void printAll();		//���ȫ��ѧ����Ϣ	


void screenField();		//����רҵɸѡ
void screenSex();		//�����Ա�ɸѡ
void screenAge();		//��������ɸѡ

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
		if (this->before != nullptr) {//�����nullptr �Ǿ���û��Ԫ�� ���ǵ�һ��Ԫ��
			this->before->setNext(this);
		}
		else {
			Stu::head = this;
		}
		this->next = nullptr;
	}
	void printStu() {
		cout << "ѧ��:" << std::left << setw(12) << this->id;
		cout << "����:" << std::left << setw(10) << this->name;
		cout << "�Ա�:" << std::left << setw(5) << this->sex;
		cout << "רҵ:" << std::left << setw(15) << this->field;
		cout << "��������:" << std::left << setw(4) << this->year << "-" << std::right << setw(2) << this->month << "-" << std::right << setw(2) << this->day << std::right << setw(15);
		cout << "��ͥ��ַ:" << std::left << setw(24) << this->address;
		cout << "Ӣ����ѧ�ɼ�:" << std::left << setw(3) << this->gradeOfEnglish;
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
		if (this->before != nullptr) {//�����nullptr �Ǿ���û��Ԫ�� ���ǵ�һ��Ԫ��
			this->before->setNext(this->next);
		}
		else { //��������head
			Stu::head = this->next;
		}

		if (this->next != nullptr) {
			this->next->setBefore(this->before);
		}
		else { //��������last
			Stu::last = this->before;
		}
		delete this;
	}
	int getId() {
		return this->id;			//��ȡ�ö����id
	}
	string getName() {
		return this->name;			//��ȡ�ö����name
	}
	string getSex() {
		return this->sex;			//��ȡ�ö����sex
	}
	string getField() {
		return this->field;			//��ȡ�ö����field
	}
	int getYear() {
		return this->year;			//��ȡ�ö����year
	}
	int getMonth() {
		return this->month;			//��ȡ�ö����month
	}
	int getDay() {
		return this->day;			//��ȡ�ö����day
	}
	string getAddress() {
		return this->address;		//��ȡ�ö����address
	}
	float getE_grade() {
		return this->gradeOfEnglish;//��ȡ�ö����gradeOfEnglish
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
		cout << "----------------------------ѧ����Ϣͳ��ϵͳ----------------------------" << endl;
		cout << endl;
		cout << endl;
		cout << "1.����רҵɸѡ" << endl;
		cout << "2.�����Ա�ɸѡ" << endl;
		cout << "3.��������ɸѡ" << endl;
		cout << "4.���ȫ��ѧ����Ϣ" << endl;
		cout << endl;
		cout << "5.�������˵�" << endl;
		cout << endl;
		cout << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << endl;

		cout << "���������:";
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
			cout << "�޷�ʶ�����������룡" << endl;
			system("pause");
		}
	}
}

void screenField()
{
	Stu* item = Stu::head;
	string findField;
	int count = 0;

	cout << "������Ҫɸѡ����רҵ��" << endl;
	cin >> findField;

	cout << endl << "���������ݿ��е���Ϣ��" << endl;

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
	cout << "����������ѧ����" << count << "��" << endl;
	cout << "----------------------------------------------------------" << endl;
	system("pause");
	return;
}

void screenSex()//�����Ա�ɸѡ������������ѧ��
{
	Stu* item = Stu::head;
	string findSex;
	int count = 0;

	cout << "������Ҫɸѡ�����Ա�" << endl;
	cin >> findSex;

	cout << endl << "���������ݿ��е���Ϣ��" << endl;

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
	cout << "����������ѧ����" << count << "��" << endl;
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

	cout << "������Ҫɸѡ�������䣺";
	cin >> findAge;

	cout << endl << "���������ݿ��е���Ϣ��" << endl;

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
	cout << "����������ѧ����" << count << "��" << endl;
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
	cout << "����������ѧ����" << count << "��" << endl;
	cout << "----------------------------------------------------------" << endl;
	system("pause");
	return;
}