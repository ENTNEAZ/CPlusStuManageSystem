#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "StuClass.h"

using namespace std;

void search();
void search_Id();
void search_Name();

void search()//(��֧��ģ����ѯ)
{
	system("cls");
	cout << "----------------------------��ѯ����----------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "��ѧ�Ų�ѯ����  1" << endl;
	cout << "��������ѯ����  2" << endl;
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
		search_Id();
		break;
	case 2:
		search_Name();
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

void search_Id()
{
	Stu* item = Stu::head;

	int inputId;
	cout << "������Ҫ��ѯѧ����ѧ��";
	cin >> inputId;

	cout << endl;
	cout << "���������ݿ����й�" << inputId << "����Ϣ" << endl;
	cout << endl;

	while (item != NULL)
	{
		if (item->getId() == inputId)
		{
			item->printStu();
		}
		item = item->getNext();
	}
	cout << "���������ݿ����й�" << inputId << "����Ϣ" << endl;
	cout << endl;
	system("pause");
	return;
}

void search_Name()
{
	Stu* item = Stu::head;
	string inputName;

	cout << "������Ҫ��ѯѧ��������(��֧��ģ����ѯ)";
	cin >> inputName;

	cout << endl;
	cout << "���������ݿ����й�" << inputName << "����Ϣ" << endl;
	cout << endl;

	while (item != NULL)
	{
		size_t found = item->getName().find(inputName);
		if (found != string::npos)
		{
			item->printStu();
		}
		item = item->getNext();
	}
	cout << "���������ݿ����й�" << inputName << "����Ϣ" << endl;
	cout << endl;
	system("pause");
	return;
}