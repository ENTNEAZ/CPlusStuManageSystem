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
			if (day <= 30)//这些是小月
			{
				return true;
			}
			return false;
			break;
		case 2:
			return isLeap(year, month, day);//判断2月的天数输入是否有误
			break;
		default:
			return true;//这些月本来就有31天
		}
	}
	return false;//日期不在范围里
}

bool isLeap(int year, int month, int day)//闰年判断（闰年2月29天，平年2月28天）
{
	int four;
	int hundred1;
	int hundred4;

	four = year % 4;
	hundred1 = year % 100;
	hundred4 = year % 400;

	if ((hundred4 == 0) || (four == 0 && hundred1 != 0))//闰年（能被400整除或能被4整除但不能被100整除）
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
	else//平年
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

bool sexJudge(std::string sex)//判断输入的性别是否为“男”或“女”
{
	if (sex == "男" || sex == "女")
	{
		return true;
	}
	return false;
}