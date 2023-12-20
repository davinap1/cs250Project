/*
	Pham, Davina

	Project: Grade Report
	CS A250
	Fall 2023
*/

#include "Course.h"

using namespace std;

Course::Course(const string& prefix, int number, int units)
{
	coursePrefix = prefix;
	courseNumber = number;
	courseUnits = units;
}

void Course::setCourseInfo(const string& prefix, int number, int units)
{
	coursePrefix = prefix;
	courseNumber = number;
	courseUnits = units;
}
int Course::getCourseNumber() const 
{ 
	return courseNumber;
}

string Course::getCoursePrefix() const
{ 
	return coursePrefix;
}
int Course::getCourseUnits() const 
{ 
	return courseUnits;
}

bool Course::operator<(const Course& otherCourse) const
{
	if (coursePrefix < otherCourse.coursePrefix) { return true; }
	else if (coursePrefix == otherCourse.coursePrefix)
	{
		return courseNumber < otherCourse.courseNumber;
	}
	return false;
}
