#pragma once
#include <iostream>

using namespace std;

class Stu {
public:
	static Stu* last;
	static Stu* head;
	Stu(int id, string name, string sex, string field, int year, int month, int day, string address, float E_grade);
								//��Ĺ��캯��
	void printStu();
								//����ö������Ϣ
	void changeInformation(int id, string name, string sex, string field, int year, int month, int day, string address, float E_grade);
								//�޸ĸö������Ϣ
	void delStu();
								//ɾ���ö���

	int getId();				//��ȡ�ö���ġ�ѧ�š�
	string getName();			//��ȡ�ö���ġ�������
	string getSex();			//��ȡ�ö���ġ��Ա�
	string getField();			//��ȡ�ö���ġ�רҵ��
	int getYear();				//��ȡ�ö�����������еġ��ꡱ
	int getMonth();				//��ȡ�ö�����������еġ��¡�
	int getDay();				//��ȡ�ö�����������еġ��ա�
	string getAddress();		//��ȡ�ö���ġ���ͥ��ַ��
	float getE_grade();			//��ȡ�ö���ġ�Ӣ��ɼ���
	Stu* getBefore();			//��ȡ�ö����ǰָ��
	Stu* getNext();				//��ȡ�ö���ĺ�ָ��

	void setNext(Stu* item);	//���øö����ǰָ��
	void setBefore(Stu* item);	//���øö���ĺ�ָ��

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