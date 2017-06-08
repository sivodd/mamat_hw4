#ifndef COURSE_H
#define COURSE_H

class Course {
protected:
	int CourseNumber;
	char* CourseName;
	int NumOfHW;
	int HwWeight;
	int ExamGrade;
	int* Hwgardes = (int*)malloc(NumOfHW*sizeof(int));
public:
	//constractor
	Course(int CourseNumber, char* CourseName, int NumOfHW, int HwWeight);
	Course(); //sivan
	//destructor
	~Course();

	//operations
	int getNum();
	char* getName();
	int getExamGrade();
	int gethwGrade(int HwNum);
	int gerHwNum();
	float getHwWeight();
	float getHwAvarge();
	int getCourseGrade();
	bool setExamGrade(int Examgrade);
	bool setHwGrade(int HwNum, int HwGrade);

};

#endif // !COURSE_H

