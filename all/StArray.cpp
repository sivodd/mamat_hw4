#include "StArray.h"
#include <string>

//*************************************************************************************
//* Function name : constractor
//* Description   : creat a StArray class
//* Parameters    : none 
//* Return value  : pointer to the StArray class
//*************************************************************************************
StArray::StArray()
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		students[i] = NULL;
	}
	NumOfStudents = 0;
}

//*************************************************************************************
//* Function name : destructor
//* Description   : free all StArray memory
//* Parameters    : none
//* Return value  : none
//*************************************************************************************
StArray :: ~StArray(){
    for (int i=0; i<MAX_STUDENT_NUM;i++){
        if (students[i]!=NULL)
            delete students[i];
    }
}

//operations

//*************************************************************************************
//* Function name : addStudent
//* Description   : creat and add a new student to StArray
//* Parameters    : int student_id - student id number
//*					char* student_name - pointer to string that contain the student name
//* Return value  : true/false
//*************************************************************************************
bool StArray :: addStudent(int student_id, char* student_name)
{
	//if there is no place to new student
	if (NumOfStudents == MAX_STUDENT_NUM)
		return false;
	Student* new_student = new Student(student_name, student_id);
	int i = 0;
	//finding the fisrt empty place in the array
	while (students[i] != NULL)
	{
		i++;
	}
	students[i] = new_student;
	NumOfStudents++;
	return true;
}

//*************************************************************************************
//* Function name : addEE_Course
//* Description   : create a new ee course and add it to the student with the appropriate id
//* Parameters    : int student_id - student id number
//*					int course_num  - course number
//*					char* course_name - pointer to string that contain the course name
//*					int NumOfHw - number of Hw in the given course
//*					float hwWeight - HW weight in the final grade
//* Return value  : true/false
//*************************************************************************************
bool StArray :: addEE_Course(int student_id, int course_num, char* course_name, int NumOfHw, float hwWeight)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		//if - true if students[i] is the given student
		if ((students[i] != NULL)&&(student_id == students[i]->getID()))
		{
			EE_Course* ee_course = new EE_Course(course_num, course_name, NumOfHw, hwWeight);
			if (students[i]->addEE_Course(ee_course))
				return true;
			//delet if the function addEE_Course failed
			delete ee_course;
			return false;
		}
	}
	//if the student doesnt exsit in the system
	return false;
}

//*************************************************************************************
//* Function name : addCS_Course
//* Description   : create a new ee course and add it to the student with the appropriate id
//* Parameters    : int student_id - student id number
//*					int course_num  - course number
//*					char* course_name - pointer to string that contain the course name
//*					int NumOfHw - number of Hw in the given course
//*					float hwWeight - HW weight in the final grade
//*					bool takef - flag that represent if the HW are TAKEF or MAGEN
//*					char* book - pointer to string that contain the course's book name
//* Return value  : true/false
//*************************************************************************************
bool StArray :: addCS_Course(int student_id, int course_num, char* course_name, int NumOfHw,
	float hwWeight,bool takef, char* book)
{
		for (int i = 0; i < MAX_STUDENT_NUM; i++)
		{
			//if - true if students[i] is the given student
			if ((students[i] != NULL)&&(student_id == students[i]->getID()))
			{
				CS_Course* cs_course = new CS_Course(book, takef,course_num, course_name, NumOfHw, hwWeight);
				if (students[i]->addCS_Course(cs_course))
					return true;
				//delet if the function addEE_Course failed
				delete cs_course;
				return false;
			}
		}
		//if the student doesnt exsit in the system
		return false;
}

//*************************************************************************************
//* Function name : setHwGrade
//* Description   : update the grade of a student's HW in the given course 
//* Parameters    : int student_id - student id number
//*					int course_num - course number
//*					int Hw_num - hw number
//*					int hw_grade - score of the homework
//* Return value  : true -  if the update succeeded, false if: There is no student with this ID / 
//*					the student dont have the given course / the course have fewer homework than the
//*					given number of homework
//*************************************************************************************
bool StArray ::setHwGrade(int student_id, int course_num, int Hw_num, int hw_grade)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		//if - true if students[i] is the given student
		if ((students[i]!=NULL)&&(student_id == students[i]->getID()))
		{
			EE_Course* ee_course= students[i]->getEE_Course(course_num);
			//if: true if the given course is an ee_course and the given student have this course
			if ((ee_course != NULL)&& (Hw_num <= ee_course->getHwNum()))
			{
				bool res = ee_course->setHwGrade(Hw_num, hw_grade);
				return res;
			}
			CS_Course* cs_course= students[i]->getCS_Course(course_num);
			//if: true if the given course is an cs_course and the given student have this course
			if ((cs_course != NULL) && (Hw_num <= cs_course->getHwNum()))
			{
				bool res = cs_course->setHwGrade(Hw_num, hw_grade);
				return res;
			}
			//false - if the student doesnt have the course
			return false;
		}
	}
	//false - if the given student doesnt exsit in the system
	return false;
}

//*************************************************************************************
//* Function name : setExamGrade
//* Description   : update the exam grade of a student in the given course 
//* Parameters    : int student_id - student id number
//*					int course_num - course number
//*					int examGrade - test score
//* Return value  : true- if the update succeeded, false - if the student or course does not exist in
//*					the system
//*************************************************************************************
bool StArray :: setExamGrade(int student_id, int course_num, int examGrade)
{
	for (int i = 0; i < MAX_STUDENT_NUM; i++)
	{
		if ((students[i] != NULL) && (student_id == students[i]->getID()))
		{
			EE_Course* ee_course = students[i]->getEE_Course(course_num);
			//if - true if the given course is an ee_course and the student have it
			if (ee_course != NULL)
			{
				bool res = ee_course->setExamGrade(examGrade);
				return res;
			}
			CS_Course* cs_course = students[i]->getCS_Course(course_num);
			//if - true if the given course is an cs_course and the student have it
			if (cs_course != NULL)
			{
				bool res = cs_course->setExamGrade(examGrade);
				return res;
			}
			return false; //if the student dont have the given course
		}
	}
	return false; //if the student dont exsit in the system
}

//*************************************************************************************
//* Function name : setFactor
//* Description   : update the factor value to the given course , for all the students in the system
//* Parameters    : int course_num - course number
//*					int Factor - factor value
//* Return value  : true - is the update succeeded, false- if all students do not have this course 
//*************************************************************************************
bool StArray :: setFactor(int course_num, int Factor)
{
	bool change = false;
	int i = 0;
	while (students[i] != NULL)
	{
		EE_Course* ee_course = students[i]->getEE_Course(course_num);
		i++;
		if (ee_course == NULL) //true if students[i] doesnt have the given course
			continue;
		ee_course->setFactor(Factor);
		change = true;
	}
	return change; //false if all the students dont have the given course
}

//*************************************************************************************
//* Function name : printStudent
//* Description   : print the student details 
//* Parameters    : int student_id - student id number
//* Return value  : true - if the student exist in the system and false otherwise
//*************************************************************************************
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

//*************************************************************************************
//* Function name : printAll
//* Description   : print all the students in the system
//* Parameters    : none
//* Return value  : none
//*************************************************************************************
void StArray :: printAll()
{
	int i = 0;
	while (students[i] != NULL)
	{
		students[i]->print();
		i++;
	}
}

//*************************************************************************************
//* Function name : resetStArray
//* Description   : delete all the students and their courses from the system 
//* Parameters    : none
//* Return value  : none
//*************************************************************************************
void StArray::resetStArray()
{
	int i = 0;
	while (students[i] != NULL)
	{
		delete students[i];
		students[i] = NULL;
		i++;
	}
	NumOfStudents=0;
}
