#include <iostream>
#include <ctime>
#include <string>
#include "StuClass.h"

using namespace std;


void screenField();					//����רҵɸѡ
void screenSex();					//�����Ա�ɸѡ
void screenAge();					//��������ɸѡ
void printAll(bool reverse);		//���ȫ��ѧ����Ϣ

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
			printAll(false);
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

void printAll(bool reverse)
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