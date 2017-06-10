#include "string.h"
#include "Student.h"

//constructor
Student ::Student(char *PersonName, int personID) :
        Person(PersonName,personID)
{
	int i = 0;
	for (i = 0; i < MAX_COURSE_NUM; i++)
	{
		CS_Courses[i] = NULL;
		EE_Courses[i] = NULL;
	}
	NumOfEE_Courses = 0;
	NumOfCS_Courses = 0;
}

//destructor
Student ::~Student() {
	for (int i = 0; i < MAX_COURSE_NUM; i++)
	{
		if (EE_Courses[i] != NULL)
			delete EE_Courses[i];
		if (CS_Courses[i] != NULL)
			delete CS_Courses[i];
	}
}

//operations
int Student :: getCourseCnt() const {
    int sum_of_courses=NumOfEE_Courses+NumOfCS_Courses;
    return sum_of_courses;
}
bool Student :: addEE_Course(EE_Course* ee_course){
    if (NumOfEE_Courses+1>MAX_COURSE_NUM) //can we assume that we don't get a course that already exists?
        return false;
    else {
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


bool Student :: addCS_Course(CS_Course* cs_course){
    if (NumOfCS_Courses+1>MAX_COURSE_NUM) //can we assume that we don't get a course that already exists?
        return false;
    else {
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


bool Student :: remCourse(int CourseNum){
    for (int i=0; i<MAX_COURSE_NUM; i++) {
        if (CS_Courses[i]->getNum()==CourseNum) {
            NumOfCS_Courses--;
			delete CS_Courses[i];
			CS_Courses[i]=NULL;
            return true;
        }
        if (EE_Courses[i]->getNum()==CourseNum){
            NumOfEE_Courses--;
            delete EE_Courses[i];
            EE_Courses[i]=NULL;
            return true;
        }
    }
    return false;
}

EE_Course* Student :: getEE_Course(int ee_courseNum) const {
    for (int i=0;i<MAX_COURSE_NUM;i++){
        if ((EE_Courses[i]!=NULL)&&(EE_Courses[i]->getNum()==ee_courseNum))
            return EE_Courses[i];
    }
    return NULL;
}


CS_Course*  Student :: getCS_Course(int cs_courseNum) const {
    for (int i=0;i<MAX_COURSE_NUM;i++){
        if ((CS_Courses[i]!=NULL)&&(CS_Courses[i]->getNum()==cs_courseNum))
            return CS_Courses[i];
    }
    return NULL;
}


int Student :: getAvg() const {
    int avg_grade=0;
    int sum_of_grades=0;
    int num_of_courses=getCourseCnt();
	if (num_of_courses == 0)
		return 0;
    for (int i=0;i<MAX_COURSE_NUM;i++){
		if (EE_Courses[i] != NULL)
			sum_of_grades += EE_Courses[i]->getCourseGrade();
		if (CS_Courses[i]!= NULL)
			sum_of_grades+=CS_Courses[i]->getCourseGrade();
    }
    avg_grade=(int)((float(sum_of_grades)/float(num_of_courses))+0.5);
    return avg_grade;
}

void Student::print() const {
	//printf("Student Name: %s", *PersonName);
	cout << "Student Name: " << PersonName << endl;
	cout << "Student ID: " << PersonID << endl;
	cout << "Average Grade: " << getAvg() << endl << endl;
	cout << "EE Courses:" << endl;
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (EE_Courses[i] != NULL) {
			char* EE_course_name = EE_Courses[i]->getName();
			cout << EE_Courses[i]->getNum() << " " << EE_course_name << " " <<
				EE_Courses[i]->getCourseGrade() << endl;
			delete[] EE_course_name;
		}
	}
	cout << endl;
	cout << "CS Courses:" << endl;
	for (int i = 0; i < MAX_COURSE_NUM; i++) {
		if (CS_Courses[i] != NULL) {
			char* CS_course_name = CS_Courses[i]->getName();
			cout << CS_Courses[i]->getNum() << " " << CS_course_name << " " <<
				CS_Courses[i]->getCourseGrade() << endl << endl;
			delete[] CS_course_name;
		}
	}
}