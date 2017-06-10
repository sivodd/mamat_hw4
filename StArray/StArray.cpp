#include "StArray.h"
#include <string>

//constractor
StArray::StArray()
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		students[i] = NULL;
	}
	//students[MAX_STUDENT_NUM] = { NULL };
	NumOfStudents = 0;
}
//destructor
StArray :: ~StArray()
{
	delete[]students;
}

//operations
bool StArray :: addStudent(int student_id, char* student_name)
{
	if (NumOfStudents == MAX_STUDENT_NUM)
		return false;
	Student* new_student = new Student(student_name, student_id);
	if (new_student == NULL)
		return false;
	int i = 0;
	while (students[i] != NULL)
	{
		i++;
	}
	students[i] = new_student;
	return true;
}
bool StArray :: addEE_Course(int student_id, int course_num, char* course_name, int NumOfHw, float hwWeight)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if ((students[i] != NULL)&&(student_id == students[i]->getID()))
		{
			EE_Course* ee_course = new EE_Course(course_num, course_name, NumOfHw, hwWeight);
			if (students[i]->addEE_Course(ee_course))
				return true;
			delete ee_course;
			return false;
		}
	}
	return false;
}

bool StArray :: addCS_Course(int student_id, int course_num, char* course_name, int NumOfHw,
	float hwWeight,bool takef, char* book)
{
		for (int i = 0; i < MAX_STUDENT_NUM; i++)
		{
			if ((students[i] != NULL)&&(student_id == students[i]->getID()))
			{
				CS_Course* cs_course = new CS_Course(book, takef,course_num, course_name, NumOfHw, hwWeight);
				if (students[i]->addCS_Course(cs_course))
					return true;
				delete cs_course;
				return false;
			}
		}
		return false;
}

bool StArray ::setHwGrade(int student_id, int course_num, int Hw_num, int hw_grade)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if ((students[i]!=NULL)&&(student_id == students[i]->getID()))
		{
			EE_Course* ee_course= students[i]->getEE_Course(course_num);
			if ((ee_course != NULL)&&(Hw_num<= ee_course->getHwNum()))
			{
				ee_course->setHwGrade(Hw_num, hw_grade);
				return true;
			}
			CS_Course* cs_course= students[i]->getCS_Course(course_num);
			if ((cs_course != NULL) && (Hw_num <= cs_course->getHwNum()))
			{
				cs_course->setHwGrade(Hw_num, hw_grade);
				return true;
			}
			return false;
		}
	}
	return false;
}

bool StArray :: setExamGrade(int student_id, int course_num, int examGrade)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if ((students[i] != NULL) && (student_id == students[i]->getID()))
		{
			EE_Course* ee_course = students[i]->getEE_Course(course_num);
			if (ee_course != NULL)
			{
				ee_course->setExamGrade(examGrade);
				return true;
			}
			CS_Course* cs_course = students[i]->getCS_Course(course_num);
			if (cs_course != NULL)
			{
				cs_course->setExamGrade(examGrade);
				return true;
			}
			return false;
		}
	}
	return false;
}

bool StArray :: setFactor(int course_num, int Factor)
{
	bool change = false;
	int i = 0;
	while (students[i] != NULL)
	{
		EE_Course* ee_course = students[i]->getEE_Course(course_num);
		i++;
		if (ee_course == NULL)
			continue;
		ee_course->setFactor(Factor);
		change = true;
	}
	return change;
}

bool StArray :: printStudent(int student_id)
{
	int i = 0;
	while (students[i] != NULL)
	{
		if (students[i]->getID() == student_id)
		{
			students[i]->print();
			return true;
		}
		i++;
	}
	return false;
}
void StArray :: printAll()
{
	int i = 0;
	while (students[i] != NULL)
	{
		students[i]->print();
		i++;
	}
}

void StArray::resetStArray()
{
	int i = 0;
	while (students[i] != NULL)
	{
		delete students[i];
		students[i] = NULL;
		i++;
	}
}
