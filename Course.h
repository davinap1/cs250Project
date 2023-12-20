/*
	Pham, Davina

	Project: Grade Report
	CSA250
	Fall 2023
*/

#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course
{
public:
	Course(): coursePrefix("N/A"), courseNumber(0), courseUnits(0) {}
	Course(const std::string& prefix, int number, int units);

	std::string getCoursePrefix() const;
	int getCourseNumber() const;
	int getCourseUnits() const;

	void setCourseInfo(const std::string& prefix, int number,
		int units);

	bool operator<(const Course& otherCourse) const; 

private:
	std::string coursePrefix;
	int courseNumber;
	int courseUnits;
};

#endif