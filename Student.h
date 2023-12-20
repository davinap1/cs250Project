/*
	Pham, Davina

	Project: Grade Report
	CSA250
	Fall 2023
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"

#include <map>

class Student
{
private:
	int studentID;
	int numberOfCourses;

	std::string firstName;
	std::string lastName;
	std::multimap<Course, char> coursesCompleted;

	bool tuitionWasPaid;

public:
	Student() : studentID(0), firstName("N/A"), lastName("N/A"),
		numberOfCourses(0), tuitionWasPaid("false") {}

	void setStudent(const Student& otherStudent);
	void setStudentInfo(int id, const std::string& first, 
		const std::string& last, bool tuitionPaid, 
		const std::multimap<Course, char>& completedCourses);
	void addCourse(const Course& course, char grade);

	int getID() const;
	int getNumberOfCourses() const;
	void getName(std::string& firstName, 
		std::string& lastName) const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::multimap<Course, char> getCoursesCompleted() const;

	bool isTuitionPaid() const;
	bool isCourseCompleted(const std::string& coursePrefix,
		int courseNumber) const;

	double getUnitsCompleted() const;
	double calculateGPA() const;
	double billingAmount(double tuitionRate) const;

	void printStudent() const;
	void printStudentInfo(double tuitionRate) const;

	~Student() {}
};

#endif