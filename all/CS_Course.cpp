#include "CS_Course.h"
#include <string.h>

//*************************************************************************************
//* Function name : constractor
//* Description   : create a CS_Course class
//* Parameters    : char* book - pointer to a string that contain the courae book
//*					bool isTakef - flag if the HW are TAKEF or MAGEN
//*					int CourseNumber - course number
//*					char* CourseName -  pointer to a string that contain the courae name
//*					int NumOfHW - number of HW
//*					float HwWeight - the HW weight in the final grade claculation
//* Return value  : 
//*************************************************************************************
CS_Course ::CS_Course(char* book,bool isTakef, int CourseNumber, char* CourseName, int NumOfHW, float HwWeight):
		Course (CourseNumber, CourseName, NumOfHW, HwWeight) ,IsTakef (isTakef)
{
	Book = new char[strlen(book) + 1]; 
	if (Book!=NULL)
		strcpy(Book, book);
}

//*************************************************************************************
//* Function name : destructor
//* Description   : free the course memory
//* Parameters    : none
//* Return value  : none
//*************************************************************************************
CS_Course :: ~CS_Course()
{
	delete []Book;
}
//operations

//*************************************************************************************
//* Function name : isTakef
//* Description   : return the flag if the HW are TAKEF or MAGEN
//* Parameters    : none
//* Return value  : return the flag if the HW are TAKEF or MAGEN
//*************************************************************************************
bool CS_Course::isTakef() const
{
	return IsTakef;
}

//*************************************************************************************
//* Function name : getBook
//* Description   : duplicate the string that contain the course book
//* Parameters    : none
//* Return value  : pointer to the duplicate string of the course name
//*************************************************************************************
char* CS_Course::getBook() const
{
	char* dupName = new char[strlen(Book) + 1];
	strcpy(dupName, Book);
	return dupName;
}

//*************************************************************************************
//* Function name : setTakef
//* Description   : update the flag that represent if the HW are TAKEF or MAGEN
//* Parameters    : bool binary - true/false
//* Return value  : true
//*************************************************************************************
bool CS_Course::setTakef(bool binary)
{
	IsTakef = binary;
	return true;
}

//*************************************************************************************
//* Function name : setBook
//* Description   : Update the course book (copy the name)
//* Parameters    : char* name - pointer to the string that contain the book name
//* Return value  : none
//*************************************************************************************
bool CS_Course::setBook(char* name)
{
	if (name == NULL)
		return false;
	char* temp = new char[strlen(name) + 1];
	delete Book;///if there is a book name already
	Book = temp;
	strcpy(Book, name);
	return true;
}

//*************************************************************************************
//* Function name : getCourseGrade
//* Description   : calculate the final grade
//* Parameters    : none
//* Return value  : int - final grade
//*************************************************************************************
int CS_Course::getCourseGrade() const
{
    float HwAv = getHwAvarge();
	if ((IsTakef == 1) || ((IsTakef == 0)&&(ExamGrade<HwAv)))
		return Course::getCourseGrade();
	return ExamGrade;
}