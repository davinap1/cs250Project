/*
	Pham, Davina

	Project: Grade Report
	CS A250
	Fall 2023
*/

#include "Student.h"

#include <iomanip>
#include <iostream>

using namespace std;

void Student::setStudent(const Student& otherStudent)
{
	studentID = otherStudent.studentID;
	firstName = otherStudent.firstName;
	lastName = otherStudent.lastName;
	tuitionWasPaid = otherStudent.tuitionWasPaid;
	numberOfCourses = otherStudent.numberOfCourses;
	coursesCompleted = otherStudent.coursesCompleted;
	numberOfCourses = static_cast<int>(coursesCompleted.size());
}

void Student::setStudentInfo(int id, const string& first, 
	const string& last, bool tuitionPaid, const
	multimap<Course, char>& completedCourses)
{
	studentID = id;
	firstName = first;
	lastName = last;
	tuitionWasPaid = tuitionPaid;
	numberOfCourses = static_cast<int>(completedCourses.size());
	coursesCompleted = completedCourses;
}

void Student::addCourse(const Course& course, char grade)
{
	coursesCompleted.insert(pair<Course, char>(course, grade));
	numberOfCourses = static_cast<int>(coursesCompleted.size());
}

int Student::getID() const 
{
	return studentID; 
}

string Student::getFirstName() const 
{ 
	return firstName;
}

string Student::getLastName() const 
{ 
	return lastName;
}

void Student::getName(string& firstName, 
	string& lastName) const
{
	firstName = this->firstName;
	lastName = this->lastName;
}

int Student::getNumberOfCourses() const 
{ 
	return numberOfCourses;
}

double Student::getUnitsCompleted() const
{
	double totalUnits = 0.0;
	for (const auto& pair : coursesCompleted)
	{
		totalUnits += pair.first.getCourseUnits();
	}
	return totalUnits;
}

multimap<Course, char> Student::getCoursesCompleted() const
{
	return coursesCompleted;
}

bool Student::isTuitionPaid() const 
{ 
	return tuitionWasPaid;
}

bool Student::isCourseCompleted(const string& coursePrefix,
	int courseNumber) const
{
	if (coursesCompleted.empty()) { return false; }
	for (const auto& pair : coursesCompleted)
	{
		const Course& course = pair.first;
		if (course.getCoursePrefix() == coursePrefix &&
			course.getCourseNumber() == courseNumber)
		{
			return true;
		}

	}
	return false;
}

double Student::calculateGPA() const
{
	double totalPoints = 0.0;
	double totalUnits = 0.0;

	for (const auto& pair : coursesCompleted) {
		const Course& course = pair.first;
		char grade = pair.second;

		double gradePoints = 0.0;

		if (grade == 'A') {
			gradePoints = 4.00;
		}
		else if (grade == 'B') {
			gradePoints = 3.00;
		}
		else if (grade == 'C') {
			gradePoints = 2.00;
		}
		else if (grade == 'D') {
			gradePoints = 1.00;
		}

		totalPoints += gradePoints * course.getCourseUnits();
		totalUnits += course.getCourseUnits();
	}

	double gpa = (totalUnits != 0.0) ? (totalPoints / totalUnits) : 0.0;
	return gpa;
}

double Student::billingAmount(double tuitionRate) const
{
	double billing = static_cast<double>(numberOfCourses) * tuitionRate;
	return billing;
}

void Student::printStudent() const
{
	cout << studentID << " - " << lastName
		<< ", " << firstName << endl;
}

void Student::printStudentInfo(double tuitionRate) const
{
	cout << "Student Name: " << lastName << ", " << firstName << endl
		<< "Student ID: " << studentID << endl 
		<< "Number of courses completed: " << getNumberOfCourses()
		<< endl << endl << "CourseNo  Units  Grade" << endl;
	
	for (const auto& pair : coursesCompleted)
	{
		const Course& course = pair.first;
		char grade = pair.second;

		cout << course.getCoursePrefix() << " " 
			<< course.getCourseNumber()<< "    " 
			<< course.getCourseUnits()
			<< "      " << grade << endl;
	}
	cout << endl << "Total number of credit hours: " 
		<< fixed << setprecision(0) << getUnitsCompleted() << endl;
	if (!tuitionWasPaid)
	{
		cout << 
			" *** Grades are being held for not paying the tuition. *** " 
			<< endl << "Amount Due: $" 
			<< fixed << setprecision(2) << billingAmount(tuitionRate)
			<< endl << endl
			<< "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" 
			<< endl << endl;
	}
	else
	{
		cout << "Current Term GPA: "
			<< fixed << setprecision(2) << calculateGPA() 
			<< endl << endl
			<< "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" 
			<< endl << endl;
	}
	
}


