#include "Course.h"
#include <string.h>

//*************************************************************************************
//* Function name : Course constractor
//* Description   : create a course class
//* Parameters    : courseNumber - the course number (int)
//					courseName - the course name
//					numOfHW - num of HW there is u=in the course
//					hwWeight - the HW weight in the final grade calculation 
//* Return value  : pointer to the course class
//*************************************************************************************
Course :: Course(int courseNumber, char* courseName, int numOfHW, float hwWeight)
{
	CourseNumber = courseNumber;
	CourseName = new char[strlen(courseName) + 1];
	strcpy(CourseName, courseName);
	NumOfHW = numOfHW;
	HwWeight = hwWeight;
	ExamGrade = 0;
	Hwgardes = new int[NumOfHW];
    for(int i=0; i<numOfHW;i++)
    {
        Hwgardes[i]=0;
    }
}

//*************************************************************************************
//* Function name : Course destructor
//* Description   : free the course memory
//* Parameters    : none
//* Return value  : none
//*************************************************************************************
Course :: ~Course()
{
	delete[]CourseName;
	delete[]Hwgardes;
}

//operations

//*************************************************************************************
//* Function name : getNum
//* Description   : return the course number
//* Parameters    : none
//* Return value  : int - course number 
//*************************************************************************************
int Course::getNum() const {
	return CourseNumber;
}

//*************************************************************************************
//* Function name : getName
//* Description   : copy the course name and return a pointer to the duplicate string
//* Parameters    : none
//* Return value  : char* - pointer string that contain the course name
//*************************************************************************************
char* Course::getName() const {
	char* dup_name = new char[strlen(CourseName) + 1];
//	if (dup_name == NULL)
//		return NULL;
	strcpy(dup_name, CourseName);
	return dup_name;
}

//*************************************************************************************
//* Function name : getExamGrade
//* Description   : return the exam garde
//* Parameters    : none
//* Return value  : int - exam grade
//*************************************************************************************
int Course::getExamGrade() const {
	return ExamGrade;
}

//*************************************************************************************
//* Function name : gethwGrade
//* Description   : return the garde of the given HW
//* Parameters    : int HwNum - HW number
//* Return value  : int - the garde of the given HW
//*************************************************************************************
int Course::gethwGrade(int HwNum) const  {
	if (NumOfHW < HwNum)
		return 0;
	return Hwgardes[HwNum];
}

//*************************************************************************************
//* Function name : getHwNum
//* Description   : return how many HW there is in the course
//* Parameters    : none
//* Return value  : int - number of HW in the course
//*************************************************************************************
int Course::getHwNum() const {
	return NumOfHW;
}

//*************************************************************************************
//* Function name : getHwWeight
//* Description   : return the HW weight in the final grade calculation
//* Parameters    : none
//* Return value  : float - HW weight in the final grade calculation (between 0-1)
//*************************************************************************************
float Course::getHwWeight() const {
	return HwWeight;
}

//*************************************************************************************
//* Function name : getHwAvarge
//* Description   : calculate the HW avarge
//* Parameters    : none
//* Return value  : float - HW avarge
//*************************************************************************************
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

//*************************************************************************************
//* Function name : getCourseGrade
//* Description   : calculate the final garde and round the number
//* Parameters    : none
//* Return value  : int- final grade in the course
//*************************************************************************************
int Course::getCourseGrade() const {
	float HwAv = getHwAvarge();
	int grade = (int)((1 - HwWeight)*ExamGrade + HwWeight*HwAv + 0.5);
	return grade;
}

//*************************************************************************************
//* Function name : setExamGrade
//* Description   : update the exam grade
//* Parameters    : int Examgrade - the exam garde 
//* Return value  : bool - true- if the update succeeded and false if not
//*************************************************************************************
bool Course::setExamGrade(int Examgrade) {
	if ((Examgrade < 0) || (Examgrade > 100))
		return false;
	ExamGrade = Examgrade;
	return true;
}

//*************************************************************************************
//* Function name : setHwGrade
//* Description   : update the grade of the given HW number
//* Parameters    : int HwNum - HW number
//*					int HwGrade - HW garde
//* Return value  : true
//*************************************************************************************
bool Course::setHwGrade(int HwNum, int HwGrade) {
	if (NumOfHW == 0)
		return false;
	Hwgardes [HwNum] = HwGrade;
	return true; 
}