#include <iostream>
#include <ctime>
#include <string>
#include "StuClass.h"
#include "Utils.h"

using namespace std;

void change();
void changeStu_Id();
void changeStu_Name();

void change()
{
	cout << "----------------------------�޸Ľ���----------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "��Ѱѧ���޸�����  1" << endl;
	cout << "��Ѱ�����޸�����  2" << endl;
	cout << endl;
	cout << "�ص����˵�����    3" << endl;
	cout << endl;
	cout << endl;
	cout << "----------------------------------------------------------------" << endl;

	int userChoice;
	cout << "����ѡ�� " << endl;
	cin >> userChoice;
	switch (userChoice)
	{
	case 1:
		changeStu_Id();
		break;
	case 2:
		changeStu_Name();
		break;
	case 3:
		return;
		break;
	default:
		cout << "����������������" << endl;
		system("pause");
		return;
	}

}

void changeStu_Id()
{
	Stu* item = Stu::head;

	int id;
	cout << "������Ҫ�޸�ѧ����ѧ�ţ�";
	cin >> id;

	while (item != nullptr)
	{
		if (item->getId() == id)
		{

			item->printStu();

			char name[15], sex[5], field[30], address[100];
			float E_grade;
			int id, year, month, day;

			cout << "��ʼ�޸�" << endl;

			cout << "����ѧ�� ";
			cin >> id;

			cout << "��������: ";
			cin >> name;

			cout << "�����Ա�: ";
			cin >> sex;

			cout << "����רҵ: ";
			cin >> field;

			cout << "������������: ";
			cin >> year;

			cout << "����������·�: ";
			cin >> month;

			cout << "�������������: ";
			cin >> day;

			cout << "�����ͥ��ַ: ";
			cin >> address;

			cout << "����Ӣ����ѧ�ɼ���";
			cin >> E_grade;

			if (!birthdayJudge(year, month, day))
			{
				cout << "�����������󣬷������˵�" << endl;
				system("pause");
				return;
			}

			if (!sexJudge(sex))
			{
				cout << "�Ա����벻��ʵ�ʣ��������˵�" << endl;
				system("pause");
				return;
			}

			item->changeInformation(id, name, sex, field, year, month, day, address, E_grade);
			cout << endl;
			cout << "��ѧ����Ϣ���޸�" << endl;
			cout << endl;
			item->printStu();
			system("pause");
			return;
		}
		item = item->getNext();
	}
	cout << "ѧ�Ų����ڣ��������˵�:" << endl;
	system("pause");
	return;
}

void changeStu_Name()
{
	Stu* item = Stu::head;

	string name;
	cout << "������Ҫ�޸�ѧ����������";
	cin >> name;

	while (item != nullptr)
	{
		if (item->getName() == name)
		{

			item->printStu();

			string name, sex, field, address;
			float E_grade;
			int id, year, month, day;

			cout << "��ʼ�޸�" << endl;

			cout << "����ѧ�� ";
			cin >> id;

			cout << "��������: ";
			cin >> name;

			cout << "�����Ա�: ";
			cin >> sex;

			cout << "����רҵ: ";
			cin >> field;

			cout << "������������: ";
			cin >> year;

			cout << "����������·�: ";
			cin >> month;

			cout << "�������������: ";
			cin >> day;

			cout << "�����ͥ��ַ: ";
			cin >> address;

			cout << "����Ӣ����ѧ�ɼ���";
			cin >> E_grade;

			if (!birthdayJudge(year, month, day))
			{
				cout << "�����������󣬷������˵�" << endl;
				system("pause");
				return;
			}

			if (!sexJudge(sex))
			{
				cout << "�Ա����벻��ʵ�ʣ��������˵�" << endl;
				system("pause");
				return;
			}

			item->changeInformation(id, name, sex, field, year, month, day, address, E_grade);
			cout << endl;
			cout << "��ѧ����Ϣ���޸�" << endl;
			cout << endl;
			item->printStu();
			system("pause");
			return;
		}
		item = item->getNext();
	}
	cout << "���������ڣ��������˵�:" << endl;
	system("pause");
	return;
}