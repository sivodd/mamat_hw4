#include "EE_Course.h"
#include <string>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
//constractor
EE_Course:: EE_Course(int CourseNumber, char* CourseName, int NumOfHW, float HwWeight):
		Course (CourseNumber, CourseName, NumOfHW, HwWeight) 
{
			Factor = 0;
}

//destructor
EE_Course :: ~EE_Course()
{}

//operations
int EE_Course::getFactor()const
{
	return Factor;
}

bool EE_Course::setFactor(int factor)
{
	Factor = factor;
	return true;
}

int EE_Course::getCourseGrade() const {
	int HwAV = getHwAvarge();
	int grade = (int)((1 - HwWeight)*ExamGrade + HwWeight*HwAV + Factor + 0.5);
	return grade;
}