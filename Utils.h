#pragma once
#include <iostream>

#include "StuClass.h"

bool birthdayJudge(int year, int month, int day);	//判断出生日期格式
bool isLeap(int year, int month, int day);			//判断是否为闰年
bool sexJudge(std::string sex);						//判断性别格式