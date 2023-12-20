/*
    Pham, Davina

    Project: Grade Report
    CSA250
    Fall 2023
*/

#include "StudentList.h"
#include "StudentList.h"
#include "InputHandler.h"
#include "OutputHandler.h"

using namespace std;

const std::string FILE_NAME = "student_data.txt";

void displayMenu();
void processChoice(StudentList& studentList, double tuitionRate);
    
    int main()
    {
        StudentList studentList;
        double tuitionRate = 0.0;

        readStudentData(FILE_NAME, studentList, tuitionRate);
        //studentList.printAllStudents(tuitionRate);

        processChoice(studentList, tuitionRate);
        return 0;
    }

    void displayMenu()
    {
        cout << "*** MAIN MENU ***" << endl;
        cout << "\nSelect one of the following:\n\n"
            << "    1: Print all students\n"
            << "    2: Print student information\n"
            << "    3: Search student by last name\n"
            << "    4: Search student by course\n"
            << "    5: Print student on hold\n"
            << "    6: Print student to file\n"
            << "    7: Add student course to file\n"
            << "    8: To exit\n" << endl;
    }

    void processChoice(StudentList& studentList, double tuitionRate)
    {
        string userInput;
        bool continueLoop = true;

        while (continueLoop)
        {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> userInput;
            cout << endl;

            if (userInput == "1")
            {
                studentList.printAllStudents(tuitionRate);
            }
            else if (userInput == "2")
            {
                int studentId;
                cout << "Enter student ID: ";
                cin >> studentId;
                cout << endl; 
                studentList.printStudentByID(studentId, tuitionRate);
            }
            else if (userInput == "3")
            {
                string lastName;
                cout << "Please enter the student's last name: ";
                cin >> lastName;
                cout << endl;
                studentList.printStudentByName(lastName);
                cout << endl;
            }
            else if (userInput == "4")
            {
                string coursePrefix;
                int courseNumber;
                cout << "Please enter the course prefix: ";
                cin >> coursePrefix;
                cout << "Please enter the course number: ";
                cin >> courseNumber;
                cout << endl;
                studentList.printStudentsByCourse(coursePrefix, courseNumber);
                cout << endl;
            }
            else if (userInput == "5")
            {
                studentList.printStudentsOnHold(tuitionRate);
                cout << endl;
            }
            else if (userInput == "6")
            {
                printAllStudentsToFile(studentList, tuitionRate);
                cout << endl;                
            }
            else if (userInput == "7")
            {
                int studentID; 
                cout << "Enter student ID: ";
                cin >> studentID;

                studentList.addNewCourse(studentID); 
                cout << endl;
            }
            else if (userInput == "8")
            {
                cout << "Thank you for using the OCC Gradebook. Good-bye!\n";
                continueLoop = false;
            }
            else
            {
                cout << "Invalid choice. Please enter a number between 1 and 7.\n";
                cout << endl;
            }
            system("pause");
            cout << endl;
        }
    }


