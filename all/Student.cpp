#include "string.h"
#include "Student.h"

// *************************************************************************************
//* Function name : Student
//* Description   : constructor for Student class
//* Parameters    : personName - a string of a persons name
//                  personID - a num representing the persons ID
//* Return value  : None.
//*************************************************************************************
Student ::Student(char *PersonName, int personID) :
        Person(PersonName,personID)
{
//  initiate all cells in array to null.
	int i = 0;
	for (i = 0; i < MAX_COURSE_NUM; i++)
	{
		CS_Courses[i] = NULL;
		EE_Courses[i] = NULL;
	}
//  initiating the counter to 0.
	NumOfEE_Courses = 0;
	NumOfCS_Courses = 0;
}

// *************************************************************************************
//* Function name : ~Student
//* Description   : destructor for student class, frees all dynamic memory for person.
//* Parameters    : None.
//* Return value  : None.
//*************************************************************************************
Student ::~Student() {
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
//      delete all courses in both arrays.
		if (EE_Courses[i] != NULL)
			delete EE_Courses[i];
		if (CS_Courses[i] != NULL)
			delete CS_Courses[i];
	}
}

//operations
// *************************************************************************************
//* Function name : getCourseCnt
//* Description   : Returns the sum of cs and ee courses a student is taking.
//* Parameters    : None.
//* Return value  : Number of all courses in both faculties.
//*************************************************************************************
int Student :: getCourseCnt() const {
    int sum_of_courses=NumOfEE_Courses+NumOfCS_Courses;
    return sum_of_courses;
}

// *************************************************************************************
//* Function name : addEE_Course
//* Description   : Given a pointer to a course adds it to the student.
//* Parameters    : ee_course - a pointer to a EE course.
//* Return value  : true / false.
//*************************************************************************************
bool Student :: addEE_Course(EE_Course* ee_course){
//  if the num of courses isn't at its max
    if (NumOfEE_Courses+1>MAX_COURSE_NUM)
        return false;
    else {
//      find an empty cell and add the course to the array
        for (int i = 0; i < MAX_COURSE_NUM; i++) {
            if (EE_Courses[i] == NULL) {
                EE_Courses[i] = ee_course;
                NumOfEE_Courses++;
                return true;
            }
        }
    }
    return false; //not suppose to get to this line
}

// *************************************************************************************
//* Function name : addCS_Course
//* Description   : Given a pointer to a course adds it to the student.
//* Parameters    : cs_course- a pointer to a CS course.
//* Return value  : true / false.
//*************************************************************************************
bool Student :: addCS_Course(CS_Course* cs_course){
//      find an empty cell and add the course to the array
    if (NumOfCS_Courses+1>MAX_COURSE_NUM)
        return false;
    else {
//      find an empty cell and add the course to the array
        for (int i = 0; i < MAX_COURSE_NUM; i++) {
            if (CS_Courses[i] == NULL) {
                CS_Courses[i] = cs_course;
                NumOfCS_Courses++;
                return true;
            }
        }
    }
    return false; //not suppose to get to this line
}

// *************************************************************************************
//* Function name : remCourse
//* Description   : Given a course number removes the course, frees it's memory.
//* Parameters    : CourseNum - a number to a course.
//* Return value  : true / false.
//*************************************************************************************
bool Student :: remCourse(int CourseNum){
//  iterate over both arrays and find the course with the relevant number
    for (int i=0; i<MAX_COURSE_NUM; i++) {
        if (CS_Courses[i]->getNum()==CourseNum) {
//          subtract one off the course counter
            NumOfCS_Courses--;
//          free the course memory
			delete CS_Courses[i];
			CS_Courses[i]=NULL;
            return true;
        }
        if (EE_Courses[i]->getNum()==CourseNum){
//          subtract one off the course counter
            NumOfEE_Courses--;
//          free the course memory
            delete EE_Courses[i];
            EE_Courses[i]=NULL;
            return true;
        }
    }
    return false;
}

// *************************************************************************************
//* Function name : getEE_Course
//* Description   : Returns a pointer to a course given it's number.
//* Parameters    : ee_courseNum - a number of an EE course.
//* Return value  : EE_Course* - a pointer to a EE course if found.
//*************************************************************************************
EE_Course* Student :: getEE_Course(int ee_courseNum) const {
//  iterate over all EE_courses and find the course number
    for (int i=0;i<MAX_COURSE_NUM;i++){
        if ((EE_Courses[i]!=NULL)&&(EE_Courses[i]->getNum()==ee_courseNum))
            return EE_Courses[i];
    }
    return NULL;
}

// *************************************************************************************
//* Function name : getCS_Course
//* Description   : Returns a pointer to a course given it's number.
//* Parameters    : ee_courseNum - a number of a CS course.
//* Return value  : CS_Course* - a pointer to a CS course if found.
//*************************************************************************************
CS_Course*  Student :: getCS_Course(int cs_courseNum) const {
//  iterate over all CS_courses and find the course number
    for (int i=0;i<MAX_COURSE_NUM;i++){
        if ((CS_Courses[i]!=NULL)&&(CS_Courses[i]->getNum()==cs_courseNum))
            return CS_Courses[i];
    }
    return NULL;
}

// *************************************************************************************
//* Function name : getAvg
//* Description   : Returns the average of a student.
//* Parameters    : None.
//* Return value  : A Rounded average of the student
//*************************************************************************************
int Student :: getAvg() const {
    int avg_grade=0;
    int sum_of_grades=0;
    int num_of_courses=getCourseCnt();
	if (num_of_courses == 0)
		return 0;
//  iterate over all courses and sum up the courses grades
    for (int i=0;i<MAX_COURSE_NUM;i++){
		if (EE_Courses[i] != NULL)
			sum_of_grades += EE_Courses[i]->getCourseGrade();
		if (CS_Courses[i]!= NULL)
			sum_of_grades+=CS_Courses[i]->getCourseGrade();
    }
//  calculate the average grade
    avg_grade=(int)((float(sum_of_grades)/float(num_of_courses))+0.5);
    return avg_grade;
}

// *************************************************************************************
//* Function name : print
//* Description   : Prints out the students details and all his courses details.
//* Parameters    : None.
//* Return value  : None.
//*************************************************************************************
void Student::print() const {
	cout << "Student Name: " << PersonName << endl;
	cout << "Student ID: " << PersonID << endl;
	cout << "Average Grade: " << getAvg() << endl << endl;
	cout << "EE Courses:" << endl;
//  iterates over EE all courses and prints their name, num and grade.
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (EE_Courses[i] != NULL) {
			char* EE_course_name = EE_Courses[i]->getName();
			cout << EE_Courses[i]->getNum() << " " << EE_course_name << ": " <<
				EE_Courses[i]->getCourseGrade() << endl;
//          free the name copy that getName created
			delete[] EE_course_name;
		}
	}
	cout << endl;
	cout << "CS Courses:" << endl;
//  iterates over EE all courses and prints their name, num and grade.
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (CS_Courses[i] != NULL) {
			char* CS_course_name = CS_Courses[i]->getName();
			cout << CS_Courses[i]->getNum() << " " << CS_course_name << ": " <<
				CS_Courses[i]->getCourseGrade() << endl;
//          free the name copy that getName created
			delete[] CS_course_name;
		}
	}
	cout << endl;
}