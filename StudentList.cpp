/*
    Pham, Davina

    Project: Grade Report
    CS A250
    Fall 2023
*/

#include "StudentList.h"

#include<iomanip>

using namespace std;

StudentList::StudentList() : first(nullptr), 
    last(nullptr), count(0) {}

StudentList::~StudentList() 
{
    clearStudentList();
}

int StudentList::getNoOfStudents() const
{
    return count;
}

void StudentList::addStudent(const Student& newStudent) 
{
    Node* newNode = new Node(newStudent, nullptr);

    if (count == 0) 
    {
        first = newNode;
        last = newNode;
    }
    else 
    {
        last->setNext(newNode);
        last = newNode;
    }
    count++;
}

void StudentList::printStudentByID(int idNumber, 
    double tuitionRate) const 
{
    Node* current = first;
    bool found = false;

    while (current != nullptr) 
    {
        if (current->getStudent().getID() == idNumber) 
        {
            current->getStudent().printStudentInfo(tuitionRate);
            found = true;
        }

        current = current->getNext();
    }
    if (!found) 
    {
        cout << "No students with ID " << idNumber
            << " found in the list." << endl << endl;
    }
}

void StudentList::printStudentByName(const string& lastName) const 
{
    Node* current = first;
    bool found = false;

    while (current != nullptr) 
    {
        if (current->getStudent().getLastName() == lastName) 
        {
            current->getStudent().printStudent();
            found = true;
        }

        current = current->getNext();
    }
    if (!found) 
    {
        cout << "No students with last name " 
            << lastName << " is on the list." << endl;
    }
}

void StudentList::printStudentsByCourse(const string& coursePrefix,
    int courseNumber) const 
{
    Node* current = first;
    bool found = false;

    while (current != nullptr)
    {
        if (current->getStudent().isCourseCompleted
            (coursePrefix, courseNumber)) 
        {
            current->getStudent().printStudent();
            found = true;
        }

        current = current->getNext();
    }
    if (!found) 
    {
        cout << "No students enrolled in " << 
            coursePrefix << " " << courseNumber << endl;
    }
}

void StudentList::printAllStudents(double tuitionRate) const 
{
    Node* current = first;

    while (current != nullptr) {
        current->getStudent().printStudentInfo(tuitionRate);
        current = current->getNext();
    }
}

void StudentList::printStudentsToFile(ofstream& outfile, 
    double tuitionRate) const
{
    Node* current = first; 
    while (current != nullptr)
    {
        const Student& student = current->getStudent(); 

        outfile << "Student Name: " << student.getFirstName() << " " 
            << student.getLastName() << endl;

        outfile << "Student ID: " << student.getID() << endl;

        outfile << "Number of courses enrolled: "
            << student.getNumberOfCourses() << endl << endl;

        outfile << "CourseNo  Units  Grade" << endl;

        const multimap<Course, char>& 
            studentCoursesCompleted = student.getCoursesCompleted();

        for (const auto& pair : studentCoursesCompleted)
        {
            const Course& course = pair.first;
            char grade = pair.second;

            outfile << course.getCoursePrefix() << " " << 
                course.getCourseNumber() << "    " << 
                course.getCourseUnits()
                << "      " << grade << endl;
        }
        outfile << "Total number of credit hours: " << 
            student.getUnitsCompleted() << endl;
        
        outfile << "Current Term GPA" << student.calculateGPA() << endl;
        outfile << endl;
        outfile
            << "- *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"
            << endl << endl;
   
        current = current->getNext();
    }
}

void StudentList::printStudentsOnHold(double tuitionRate) const {
    Node* current = first;
    bool onHold = false;
    while (current != nullptr) {
        const Student& student = current->getStudent();

        if (!student.isTuitionPaid()) {
            student.printStudent();
            cout << "    Amount Due: $" << fixed << setprecision(2) 
                << student.billingAmount(tuitionRate) << endl;
            onHold = true;
        }
        current = current->getNext();
    }
    if (!onHold) {
        cout << "There are no students on hold." << endl;
    }
}

void StudentList::addNewCourse(int studentID)
{
    Node* current = first;  
    bool found = false;

    while (current != nullptr)
    {
        if (current->getStudent().getID() == studentID)
        {
            found = true;
            Student& student = current->getStudent(); 

            string enteredFirstName, enteredLastName;
            cout << "Enter first name: ";
            cin >> enteredFirstName;

            cout << "Enter last name: ";
            cin >> enteredLastName;

            if (enteredFirstName == student.getFirstName() 
                && enteredLastName == student.getLastName())
            {
                string courseAddedPrefix;
                int courseAddedNumber;
                int courseAddedUnits = 0; 
                char addedGrade;
                                
                cout << "Enter course prefix: ";
                cin >> courseAddedPrefix;

                cout << "Enter course number: ";
                cin >> courseAddedNumber;
                                                   
                cout << "Enter course units: "; 
                while (!(cin >> courseAddedUnits))
                {
                    cout << 
                        "Error: Enter a valid integer for course units." 
                        << endl;
                    cin.clear();  
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                    cout << "Enter course units: "; 
                }
           
                cout << "Enter grade: ";
                cin >> addedGrade;

                Course newCourse(courseAddedPrefix, 
                    courseAddedNumber,courseAddedUnits);

                student.addCourse(newCourse, addedGrade);

                current->setStudent(student); 
         
                if (student.isCourseCompleted(courseAddedPrefix, 
                    courseAddedNumber))
                {
                    cout << "Course added successfully." << endl;
                }
                else
                {
                    cout << "Failed to add the course." << endl;
                }
            }
            else
            {
                cout << "Error: Name does not match." << endl;
            }
        }
        current = current->getNext(); 
    }
    if (!found)
    {
        cout << "No students with ID " << studentID 
            << " found in the list." << endl;
    }
}

void StudentList::clearStudentList()
{
    while (first != nullptr) 
    {
        Node* temp = first;
        first = first->getNext();
        delete temp;
    }
    last = nullptr;
    count = 0;
}

