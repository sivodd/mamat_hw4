#include "Course.h"
#include <string>
//constractor
Course :: Course(int CourseNumber, char* CourseName, int NumOfHW, int HwWeight)
{
	CourseNumber = CourseNumber;
	CourseName = CourseName;
	NumOfHW = NumOfHW;
	HwWeight = HwWeight;
}

//destructor
Course :: ~Course()
{
	free(Hwgardes);
}

//operations
int Course::getNum(){
	return CourseNumber;
}

char* Course::getName() {
	return strdup(CourseName);
}

int Course::getExamGrade() {
	return ExamGrade;
}

int Course::gethwGrade(int HwNum) {
	return *(Hwgardes+HwNum);
}

int Course::gerHwNum() {
	return NumOfHW;
}

float Course::getHwWeight() {
	return HwWeight;
}

float Course::getHwAvarge() {
	int sum = 0;
	for (int i = 0; i < NumOfHW; i++)
	{
		sum+= *(Hwgardes+i);
	}
	return (float)(sum / NumOfHW);
}

int Course::getCourseGrade() {
	int grade = round((1 - HwWeight)*ExamGrade + HwWeight*getHwAvarge());
	return grade;
}

bool Course::setExamGrade(int Examgrade) {
	if ((Examgrade < 0) || (Examgrade > 100))
		return false;
	ExamGrade = Examgrade;
	return true;
}

bool Course::setHwGrade(int HwNum, int HwGrade) {
	*(Hwgardes+HwNum) = HwGrade;
}