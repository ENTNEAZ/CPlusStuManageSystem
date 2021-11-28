#ifdef DEBUG



////��������������Ҫ���¼������Ϣ��
//�磺ѧ���������Ա�רҵ���������ڣ���ͥ��ַ��Ӣ����ѧ�ɼ���
//Ҫ�����������ʵ�֣���ͳ��ѧ���������ı�����Ϊ��
//1. ����ѧ����Ϣ 
//2. ɾ��ѧ����Ϣ
//3. ����ѧ����Ϣ���Ѿ������ڵ��ļ���Ϣ��
//4. ѧ����Ϣ��������������
//5. ѧ����Ϣͳ�ƣ���רҵ���Ա������---����Ҫ�Զ����㣩
//6. ��Ӣ��ɼ�����
//7. ѧ����Ϣ����
//8. �˳�

//�����ֲ� 
//main()
//		load()							Ĭ���Զ�������Ϣ 
//		menu()							����˵� 	
//			0.	load()					�ֶ�������Ϣ 
//			1.	add()					���� 
//					isExist()			���� 
//					birthdayJudge()		���������ж� 
//						isLeap()		�����ж� 
//					addRaw()			����Ϣ�������� 
//			2.	search()				���� 
//			3.	change()				�޸�		
//					birthdayJudge()		�������ڸ�ʽ�ж� 
//						isLeap()		�����ж� 
//					sexJudge()			�Ա��ʽ�ж�
//			4.	del()					ɾ�� 
//					printStu()			��ӡѧ����Ϣ
//			5.	searchAll()				��Ϣͳ�ƣ�����ɸѡ��ӡ��ȫ����ӡ��
//					screenField()		����ָ��רҵ��ӡ��Ϣ
//						printStu() 		��ӡѧ����Ϣ
//					screenSex()			����ָ���Ա��ӡ��Ϣ
//						printStu() 		��ӡѧ����Ϣ
//					screenAge()			����ָ�������ӡ��Ϣ��������ݸ�ѧ����Ϣ�е�����Զ����㣩
//						printStu() 		��ӡѧ����Ϣ
//			6.	sort()					����Ӣ��ɼ����򣨲���ð��ѭ����
//			7.	save()					��������Ϣ�����ļ�
//			8.	save()					��������Ϣ�����ļ��󷵻����������������� 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};

struct Stu {
	int id;						//ѧ�� 
	char name[15];				//���� 
	char sex[5];				//�Ա� 
	char field[30];				//רҵ 
	struct Date birthday;		//�������� 
	char address[100];			//��ͥ��ַ 
	float E_grade;				//Ӣ����ѧ�ɼ� 
	struct Stu* next;
};

struct Stu* head = NULL;
struct Stu* last = NULL;

void menu();				//�˵�														
void load(bool output);		//����ѧ����Ϣ												0.done
void add();					//����ѧ����Ϣ												1.done 
void search();				//ѧ����Ϣ��ѯ(������)											2.done
void change();				//�޸�ѧ����Ϣ������ûҪ��д���Լ��ӵģ�							3.done
void del();					//ɾ��ѧ����Ϣ												4.done
void searchAll();			//ѧ����Ϣͳ�ƣ���רҵ���Ա������---����Ҫ�Զ����㣩				5.done
void sort(bool output);		//����														6.done
void printAll();			//���ȫ����Ϣ												7.done
void save(bool output);		//ѧ����Ϣ����												8.done

void addRaw(int id, char name[], char sex[], char field[], int year, int month, int day, char address[], float E_grade);//��ֵ												
void printStu(struct Stu* stu);						//���ѧ����Ϣ
void screenField();									//����רҵɸѡѧ��
void screenSex();									//�����Ա�ɸѡѧ��
void screenAge();									//��������ɸѡѧ��
void updateLast();									//����lastָ��

bool isExist(int id, bool output);					//�������ѧ���Ƿ��Ѵ���
bool birthdayJudge(int year, int month, int day);	//�ж�����ĳ��������Ƿ�����
bool isLeap(int year, int month, int day);			//�·�Ϊ2ʱ��������ж��Ƿ����꣬Ȼ���ж�����ĳ��������Ƿ�����
bool sexJudge(char sex[]);							//�ж�������Ա��Ƿ�Ϊ���С���Ů��


void menu() //�˵�
{
	int userChoice;

	while (true)
	{
		system("cls");//����

		cout << endl;
		cout << endl;
		cout << endl;
		cout << "----------------------------ѧ��������Ϣ����ϵͳ----------------------------" << endl;
		cout << endl;
		cout << endl;
		cout << "0.����ѧ����Ϣ��Ĭ�����Զ����룩" << endl;
		cout << "1.����ѧ����Ϣ " << endl;
		cout << "2.��ѯѧ����Ϣ " << endl;
		cout << "3.�޸�ѧ����Ϣ " << endl;
		cout << "4.ɾ��ѧ����Ϣ " << endl;
		cout << "5.ѧ����Ϣͳ�� " << endl;
		cout << "6.ѧ���ɼ����� " << endl;
		cout << "7.ѧ����Ϣ���� " << endl;
		cout << "8.ѧ����Ϣ���� " << endl;
		cout << "9.���沢��ȫ�˳�" << endl;
		cout << endl;
		cout << endl;
		cout << "ʹ��ע������" << endl;
		cout << "���С����ӡ������޸ġ�����ɾ������������ؽ���Ϣ���棬���򲻻ᱣ�����ļ��ڣ�" << endl;
		cout << endl;
		cout << endl;
		cout << "-----------------------------------------------------------------------------" << endl;

		cout << "��������ţ�";
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
			searchAll();
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
			cout << "�޷�ʶ������������" << endl;
			system("pause");
		}
	}
}

void add()//���� 
{
	int id;

	cout << "����ѧ�ţ�";
	cin >> id;

	if (isExist(id, true))
	{
		system("pause");
		return;//�Ѿ����ڴ��� ���ز˵�
	}
	else
	{
		char name[15], sex[5], field[30], address[100];
		float E_grade;
		int year, month, day;

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

		addRaw(id, name, sex, field, year, month, day, address, E_grade);
		cout << "��ӳɹ�" << endl;
		system("pause");
		return;
	}
}

bool birthdayJudge(int year, int month, int day)
{
	time_t  t;
	time(&t);

	if (year <= localtime(&t)->tm_year + 1900 && month >= 1 && month <= 12 && day >= 1 && day <= 31)
	{
		switch (month)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			if (day <= 30)//��Щ��С��
			{
				return true;
			}
			return false;
			break;
		case 2:
			return isLeap(year, month, day);//�ж�2�µ����������Ƿ�����
			break;
		default:
			return true;//��Щ�±�������31��
		}
	}
	return false;//���ڲ��ڷ�Χ��
}

bool isLeap(int year, int month, int day)//�����жϣ�����2��29�죬ƽ��2��28�죩
{
	int four;
	int hundred1;
	int hundred4;

	four = year % 4;
	hundred1 = year % 100;
	hundred4 = year % 400;

	if ((hundred4 == 0) || (four == 0 && hundred1 != 0))//���꣨�ܱ�400�������ܱ�4���������ܱ�100������
	{
		if (day <= 29)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else//ƽ��
	{
		if (day <= 28)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool sexJudge(char sex[])//�ж�������Ա��Ƿ�Ϊ���С���Ů��
{
	if (strcmp(sex, "��") == 0 || strcmp(sex, "Ů") == 0)
	{
		return true;
	}
	return false;
}

void addRaw(int id, char name[], char sex[], char field[], int year, int month, int day, char address[], float E_grade) //��ֵ
{
	struct Stu* toAdd = new struct Stu;

	if (toAdd == NULL)
	{
		cout << "�ڴ治�㣡�޷����" << endl;
		system("pause");
		return;
	}

	toAdd->id = id;
	strcpy(toAdd->name, name);
	strcpy(toAdd->sex, sex);
	strcpy(toAdd->field, field);
	toAdd->birthday.year = year;
	toAdd->birthday.month = month;
	toAdd->birthday.day = day;
	strcpy(toAdd->address, address);
	toAdd->E_grade = E_grade;
	toAdd->next = NULL;

	if (head == NULL) {
		head = toAdd;
		last = head;//lastָ�����һ��Ԫ��
	}
	else {
		last->next = toAdd;
		last = last->next;
	}
	return;
}

bool isExist(int id, bool output = false)//���� outputΪ�Ƿ�����Ѿ����ڵ���Ϣ
{
	if (head == NULL)
	{
		return false;
	}

	struct Stu* item = head;

	while (item != NULL)
	{
		if (item->id == id)
		{
			if (output) {
				cout << "ѧ�� :  " << item->id << "���� :  " << item->name << "�Ա� :  " << item->sex << "רҵ :  " << item->field << endl;
				cout << "ѧ���Ѵ��ڣ�����������" << endl;
				cout << endl;
			}
			return true;
		}
		else
			item = item->next;
	}
	return false;
}

void search()//��ѯ 
{
	struct Stu* item = head;
	char inputName[15];

	cout << "����Ҫ��ѯѧ��������:";
	cin >> inputName;

	inputName[14] = '\0';//��ֹ�û�������� ����û��\0
	cout << "���������ݿ����й�" << inputName << "����Ϣ" << endl;
	cout << endl;

	while (item != NULL)
	{
		if (strcmp(item->name, inputName) == 0)
		{
			printStu(item);
			//��ֹ���� ����ִ��
			item = item->next;
		}
		else {
			item = item->next;
		}
	}
	cout << "���������ݿ����й�" << inputName << "����Ϣ" << endl;
	cout << endl;
	system("pause");
	return;
}

void change()//�޸� 
{
	struct Stu* item;
	int id;
	cout << "����Ҫ�޸�ѧ����ѧ��:";
	cin >> id;

	item = head;

	while (item != NULL)
	{
		if (item->id == id)
		{
			printStu(item);
			cout << "��ʼ�޸�" << endl;

			cout << "��������: ";
			cin >> item->name;

			cout << "�����Ա�: ";
			cin >> item->sex;

			cout << "����רҵ: ";
			cin >> item->field;

			cout << "������������: ";
			cin >> item->birthday.year;

			cout << "����������·�: ";
			cin >> item->birthday.month;

			cout << "�������������: ";
			cin >> item->birthday.day;

			cout << "�����ͥ��ַ: ";
			cin >> item->address;

			cout << "����Ӣ����ѧ�ɼ���";
			cin >> item->E_grade;

			cout << "-----------------------------------------------" << endl;

			if (birthdayJudge(item->birthday.year, item->birthday.month, item->birthday.day))
			{
				return;
			}
			cout << endl;

			cout << "�޸ĺ���Ϊ" << endl;
			printStu(item);

			cout << endl;
			system("pause");
			return;
		}
		else
			item = item->next;
	}
	cout << "ѧ�Ų����ڣ��������˵�" << endl;
	system("pause");
	return;
}

void del()//ɾ�� 
{
	int id;
	struct Stu* needToDel, * beforeDel;
	beforeDel = NULL;

	cout << "����Ҫɾ��ѧ����ѧ��:";
	cin >> id;

	needToDel = head;

	while (needToDel != NULL)
	{
		if (needToDel->id == id)
		{
			printStu(needToDel);
			if (needToDel == last) {
				last = beforeDel;//ָ��ǰ���
			}
			if (beforeDel == NULL)
			{
				head = needToDel->next;
				delete needToDel;
			}
			else
			{
				beforeDel->next = needToDel->next;
				delete needToDel;
			}
			cout << "��ѧ����Ϣ��ɾ��" << endl;
			system("pause");
			return;
		}
		else
		{
			beforeDel = needToDel;
			needToDel = needToDel->next;

		}
	}
	cout << "ѧ�Ų����ڣ��������˵�:" << endl;
	system("pause");
	return;
}

void searchAll()//��Ϣͳ�ƣ�ɸѡ���ƶ�רҵ���Ա�����䣩
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

void screenField()//����רҵɸѡ������������ѧ��
{
	struct Stu* item = head;
	char findField[30] = { 0 };
	int count = 0;
	findField[29] = '\0';

	cout << "������Ҫɸѡ����רҵ��" << endl;
	cin >> findField;

	cout << endl << "���������ݿ��е���Ϣ��" << endl;

	while (item != NULL)
	{
		if (strcmp(item->field, findField) == 0)
		{
			printStu(item);
			count++;
		}
		item = item->next;
	}

	cout << endl;
	cout << "����������ѧ����" << count << "��" << endl;
	cout << "----------------------------------------------------------" << endl;
	system("pause");
	return;
}

void screenSex()//�����Ա�ɸѡ������������ѧ��
{
	struct Stu* item = head;
	char findSex[5] = { 0 };
	int count = 0;
	findSex[4] = '\0';

	cout << "������Ҫɸѡ�����Ա�";
	cin >> findSex;

	cout << endl << "���������ݿ��е���Ϣ��" << endl;

	while (item != NULL)
	{
		if (strcmp(item->sex, findSex) == 0)
		{
			printStu(item);
			count++;
		}
		item = item->next;
	}

	cout << endl;
	cout << "����������ѧ����" << count << "��" << endl;
	cout << "----------------------------------------------------------" << endl;
	system("pause");
	return;
}

void screenAge()//��������ɸѡ������������ѧ��
{
	struct Stu* item = head;
	int findAge;
	int count = 0;

	time_t  t;
	time(&t);

	cout << "������Ҫɸѡ�������䣺";
	cin >> findAge;

	cout << endl << "���������ݿ��е���Ϣ��" << endl;

	while (item != NULL)
	{
		if ((localtime(&t)->tm_year + 1900) - item->birthday.year == findAge)
		{
			printStu(item);
			count++;
		}
		item = item->next;
	}

	cout << endl;
	cout << "����������ѧ����" << count << "��" << endl;
	cout << "----------------------------------------------------------" << endl;
	system("pause");
	return;
}

void printAll()
{
	struct Stu* item = head;
	cout << endl << "���������ݿ��������˵���Ϣ��" << endl;

	while (item != NULL)
	{
		printStu(item);
		item = item->next;
	}

	cout << endl;
	system("pause");
	return;
}

void sort(bool output = false)//����Ӣ��ɼ�����
{
	struct Stu* prePoint, * curPoint, * nextPoint, * end, * tempPoint;//preǰһ�� cur��ǰ�� next��һ�� end����ѭ������(�Ż�ð��)
	end = NULL;
	prePoint = NULL;
	curPoint = head;

	if (curPoint == NULL || curPoint->next == NULL)
	{
		cout << "����ɹ����Ѱ���Ӣ��ɼ���������" << endl;
		system("pause");
		return;//һ����û�л��߾�һ��
	}

	//����������
	nextPoint = curPoint->next;//��ʼ������ָ�� 

	while (head->next != end)
	{
		prePoint = NULL;
		curPoint = head;
		nextPoint = curPoint->next;//����forѭ�����Լ���ָ����и�λ

		for (; nextPoint != end; prePoint = prePoint == NULL ? head : prePoint->next, curPoint = curPoint->next, nextPoint = nextPoint->next)
		{	//�ж��Ƿ񵽴����λ�� ; 

			if (curPoint->E_grade < nextPoint->E_grade) //�Ӵ�С
			{
				if (prePoint != NULL)
				{
					prePoint->next = nextPoint;
					curPoint->next = nextPoint->next;
					nextPoint->next = curPoint;
				}
				else //pre��NULL˵����������head
				{
					head = nextPoint;
					curPoint->next = nextPoint->next;
					head->next = curPoint;
				}
				tempPoint = curPoint;//��ʱnextPoint��ǰһ�curPoint���һ��  ����nextPoint, curPoint
				curPoint = nextPoint;
				nextPoint = tempPoint;
			}
		}
		end = curPoint;//һ��ѭ������ ���һ���Ѿ��ź� end��ǰһ�� (ð��ԭ��)
	}

	if (output)
	{
		cout << "����ɹ����Ѱ���Ӣ��ɼ���������" << endl;
		system("pause");
	}

}

void printStu(struct Stu* stu) //���ѧ����Ϣ
{
	cout << endl;
	cout << "ѧ��:" << std::left << setw(12) << stu->id;
	cout << "����:" << std::left << setw(10) << stu->name;
	cout << "�Ա�:" << std::left << setw(5) << stu->sex;
	cout << "רҵ:" << std::left << setw(15) << stu->field;
	cout << "��������:" << std::left << setw(4) << stu->birthday.year << "-" << std::right << setw(2) << stu->birthday.month << "-" << std::right << setw(2) << stu->birthday.day << std::right << setw(15);
	cout << "��ͥ��ַ:" << std::left << setw(24) << stu->address;
	cout << "Ӣ����ѧ�ɼ�:" << std::left << setw(3) << stu->E_grade;
	cout << endl;
	cout << endl;
	cout << endl;

	return;
}

void load(bool output = false) //
{
	ifstream file;
	char name[15], sex[5], field[30], address[100];
	float E_grade;
	int id, year, month, day;
	bool haveNext = true;
	file.open("information.txt");

	while (file.good() && !(file.peek() == EOF))
	{
		file >> id;
		file.ignore();

		file.getline(name, 15);
		file.getline(sex, 5);
		file.getline(field, 30);

		file >> year;
		file >> month;
		file >> day;
		file.ignore();

		file.getline(address, 100);
		file >> E_grade;
		file.ignore();

		addRaw(id, name, sex, field, year, month, day, address, E_grade);
	}
	file.close();

	if (output)
	{
		cout << "����ɹ�" << endl;
		system("pause");
	}
	return;
}

void save(bool output = false)//�ļ����
{
	ofstream file;
	struct Stu* item = head;
	file.open("information.txt");

	while (item != NULL && file.good())
	{
		file << item->id << endl;
		file << item->name << endl;
		file << item->sex << endl;
		file << item->field << endl;
		file << item->birthday.year << endl;
		file << item->birthday.month << endl;
		file << item->birthday.day << endl;
		file << item->address << endl;
		file << item->E_grade << endl;

		item = item->next;
	}

	file.close();

	if (output)
	{
		cout << "�����ɹ�" << endl;
		system("pause");
	}
	return;
}

void updateLast() {
	Stu* item = head;
	while (item->next != NULL)
	{
		item = item->next;
	}
	last = item;
}
int main(int argc, char* argv[])
{
	load();
	menu();
	return 0;
}

#endif // 0