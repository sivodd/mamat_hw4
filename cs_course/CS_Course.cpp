#include "CS_Course.h"
#include <string>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//constractor
CS_Course ::CS_Course(char* book,bool isTakef, int CourseNumber, char* CourseName, int NumOfHW, float HwWeight):
		Course (CourseNumber, CourseName, NumOfHW, HwWeight) ,IsTakef (isTakef)
{
	Book = new char[strlen(book) + 1]; 
	if (Book!=NULL)
		strcpy(Book, book);
}

//destructor
CS_Course :: ~CS_Course()
{
	free(Book);
}

//operations
bool CS_Course::isTakef() const
{
	return IsTakef;
}

char* CS_Course::getBook() const
{
	char* dupName = new char[strlen(Book) + 1];
	if (dupName == NULL)
		return NULL;
	strcpy(dupName, Book);
	return dupName;
}

bool CS_Course::setTakef(bool binary)
{
	IsTakef = binary;
	return true;
}

void CS_Course::setBook(char* name)
{
	if (name == NULL)
		return;
	char* temp = new char[strlen(name) + 1];
	if (temp == NULL)
		return;
	delete Book;//if there is a book name already
	Book = temp;
	strcpy(Book, name);
}

int CS_Course::getCourseGrade() const
{
	int HwAv = getHwAvarge();
	if ((IsTakef == 1) || ((IsTakef == 0)&&(ExamGrade<HwAv)))
		return Course::getCourseGrade();
	return ExamGrade;
}