#include <ctime>
#include <string>
#ifdef DEBUG

bool birthdayJudge(int year, int month, int day);
bool isLeap(int year, int month, int day);


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

bool sexJudge(std::string sex)//�ж�������Ա��Ƿ�Ϊ���С���Ů��
{
	if (sex == "��" || sex == "Ů")
	{
		return true;
	}
	return false;
}