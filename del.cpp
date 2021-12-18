#include <iostream>
#include <ctime>
#include <string>
#include "StuClass.h"

using namespace std;


void del();
void delStu_Id();
void delStu_Name();

void del()
{
	system("cls");
	cout << "----------------------------ɾ������----------------------------" << endl;
	cout << endl;
	cout << endl;
	cout << "��Ѱѧ��ɾ������  1" << endl;
	cout << "��Ѱ����ɾ������  2" << endl;
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
		delStu_Id();
		break;
	case 2:
		delStu_Name();
		break;
	case 3:
		return;
		break;
	default:
		cout << "����������������" << endl;
		system("pause");
	}
}

void delStu_Id()
{
	Stu* item = Stu::head;
	int id;

	cout << "������Ҫɾ��ѧ����ѧ�ţ�";
	cin >> id;

	cout << endl;
	while (item != nullptr)
	{
		if (item->getId() == id)
		{
			item->printStu();
			item->delStu();
			cout << "��ѧ����Ϣ��ɾ��" << endl;
			system("pause");
			return;
		}
		item = item->getNext();
	}
	cout << "ѧ�Ų����ڣ��������˵�:" << endl;
	system("pause");
	return;
}

void delStu_Name()
{
	Stu* item = Stu::head;
	string iname;

	cout << "������Ҫɾ��ѧ����������";
	cin >> iname;

	cout << endl;
	while (item != nullptr)
	{
		if (item->getName() == iname)
		{
			item->printStu();
			item->delStu();
			cout << "��ѧ����Ϣ��ɾ��" << endl;
			system("pause");
			return;
		}
		item = item->getNext();
	}
	cout << "���������ڣ��������˵�:" << endl;
	system("pause");
	return;
}