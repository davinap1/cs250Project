/*
	Pham, Davina

	Project: Grade Report
	CS A250
	Fall 2023
*/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <iostream>
#include <fstream> 

#include "Student.h"

class Node
{
public:
	Node() : student(Student()), next(nullptr) {}
	Node(Student theStudent, Node* newNext)
		: student(theStudent), next(newNext) {}

	Node* getNext() const { return next; }
	Student& getStudent() { return student; }
	void setStudent(const Student& theStudent) 
	{ student = theStudent; }
	void setNext(Node* newNext){ next = newNext; }
	~Node() {}

private:
	Student student;
	Node* next; 
};

class StudentList
{
public:
	StudentList();
	StudentList(const StudentList& other);
	StudentList& operator=(const StudentList& otherStudent);

	int getNoOfStudents() const;

	void addStudent(const Student& newStudent);
	void addNewCourse(int studentID); 
	void printStudentByID(int idNumber, double tuitionRate) const;
	void printStudentByName(const std::string& lastName) const;
	void printStudentsByCourse(const std::string& coursePrefix,
		int courseNumber) const;
	void printAllStudents(double tuitionRate) const;
	void clearStudentList();
	void printStudentsToFile(std::ofstream& outfile,
		double tuitionRate) const;
	void printStudentsOnHold(double tuitionRate) const; 

	~StudentList();

private:
	Node* first;
	Node* last;
	int count;

	void copyCallingObjIsEmpty(const StudentList& emptyList);
	void copyObjectsSameLength(const StudentList& sameList);
	void copyCallingObjLonger(const StudentList& shorterList);
	void copyCallingObjShorter(const StudentList& longerList);
};

#endif