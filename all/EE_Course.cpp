#include "EE_Course.h"

//*************************************************************************************
//* Function name : constractor
//* Description   : crate a EE_Course class
//* Parameters    : int CourseNumber - course number
//*					char* CourseName - pointer to the string that contain the course name
//*					int NumOfHW - number of HW there is in the course
//*					float HwWeight - HW weight in the final grade calculation
//* Return value  : pointer to ee_course
//*************************************************************************************
EE_Course:: EE_Course(int CourseNumber, char* CourseName, int NumOfHW, float HwWeight):
		Course (CourseNumber, CourseName, NumOfHW, HwWeight) 
{
			Factor = 0;
}

//*************************************************************************************
//* Function name : destructor
//* Description   : free all the ee_course memory
//* Parameters    : none
//* Return value  : none
//*************************************************************************************
EE_Course :: ~EE_Course()
{}

//operations

//*************************************************************************************
//* Function name : getFactor
//* Description   : return the factor size
//* Parameters    : none
//* Return value  : int - factor
//*************************************************************************************
int EE_Course::getFactor()const
{
	return Factor;
}

//*************************************************************************************
//* Function name : setFactor
//* Description   : update the factor size
//* Parameters    : int factor  
//* Return value  : true
//*************************************************************************************
bool EE_Course::setFactor(int factor)
{
	Factor = factor;
	return true;
}

//*************************************************************************************
//* Function name : getCourseGrade
//* Description   : calculte the final garde
//* Parameters    : none
//* Return value  : int - return the final garde
//*************************************************************************************
int EE_Course::getCourseGrade() const {
	int grade = 0;
	//if there is no homeworks even if HwWeight is not 0 the exam weight is 100% (+factor)
	if (NumOfHW == 0)
		grade = ExamGrade + Factor;
	//if there is homeworks
	else
		grade = (int)((1 - HwWeight)*ExamGrade + HwWeight*getHwAvarge() + Factor + 0.5);
	//correct the score to a proper value
	if (grade < 0)
		return 0;
	if (grade > 100)
		return 100;
	return grade;
}