#include "Course.h"
#include <string>

//constractor
Course :: Course(int courseNumber, char* courseName, int numOfHW, float hwWeight)
{
	CourseNumber = courseNumber;
	CourseName = new char[strlen(courseName) + 1];
	strcpy(CourseName, courseName);
	NumOfHW = numOfHW;
	HwWeight = hwWeight;
	Hwgardes = new int[NumOfHW];
    for(int i=0; i<numOfHW;i++)
    {
        Hwgardes[i]=0;
    }
}
Course::Course()
{
	CourseNumber = NULL;
	CourseName = NULL;
	NumOfHW = NULL;
	HwWeight = NULL;
}

//destructor
Course :: ~Course()
{
	delete[]CourseName;
	delete[]Hwgardes;
}

//operations
int Course::getNum() const {
	return CourseNumber;
}

char* Course::getName() const {
	char* dup_name = new char[strlen(CourseName) + 1];
//	if (dup_name == NULL)
//		return NULL;
	strcpy(dup_name, CourseName);
	return dup_name;
}

int Course::getExamGrade() const {
	return ExamGrade;
}

int Course::gethwGrade(int HwNum) const  {
	return *(Hwgardes+HwNum);
}

int Course::getHwNum() const {
	return NumOfHW;
}

float Course::getHwWeight() const {
	return HwWeight;
}

float Course::getHwAvarge() const {
	int sum = 0;
	int i;
	if (NumOfHW == 0)
		return 0;
	for (i = 0; i < NumOfHW; i++)
	{
		sum+= Hwgardes[i];
	}
	return (float(sum)/float(NumOfHW));
}

int Course::getCourseGrade() const {
	int HwAv = getHwAvarge();
	int grade = (int)((1 - HwWeight)*ExamGrade + HwWeight*getHwAvarge() + 0.5);
	return grade;
}

bool Course::setExamGrade(int Examgrade) {
	if ((Examgrade < 0) || (Examgrade > 100))
		return false;
	ExamGrade = Examgrade;
	return true;
}

bool Course::setHwGrade(int HwNum, int HwGrade) {
	Hwgardes [HwNum] = HwGrade;
	return true; //omer
}