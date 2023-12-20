/*
    Pham, Davina

    Project: Grade Report
    CSA250
    Fall 2023
*/

#include "StudentList.h"

#include <iostream>

using namespace std;

StudentList::StudentList(const StudentList& other) : 
    first(nullptr), last(nullptr), count(0)
{
    if (&other != this)
    {
        Node* otherCurrent = other.first;
        while (otherCurrent != nullptr)
        {
            addStudent(otherCurrent->getStudent());
            otherCurrent = otherCurrent->getNext();
        }
        count = other.count;
    }
}

StudentList& StudentList::operator=(const StudentList& otherStudent)
{
    if (this == &otherStudent)
    {
        cerr << "Attempted assignment to itself." << endl;
    }
    else
    {
        if (otherStudent.count == 0)
        {
            this->clearStudentList();
        }
        else if (count == 0)
        {
            this->copyCallingObjIsEmpty(otherStudent);
        }
        else if (count == otherStudent.count)
        {
            this->copyObjectsSameLength(otherStudent);
        }
        else if (count > otherStudent.count)
        {
            this->copyCallingObjLonger(otherStudent);
        }
        else
        {
            this->copyCallingObjShorter(otherStudent);
        }
    }
    return *this;
}

void StudentList::copyCallingObjIsEmpty(const StudentList& emptyList)
{
    Node* currentEmpty = emptyList.first;
    while (currentEmpty != nullptr)
    {
        this->addStudent(currentEmpty->getStudent());
        currentEmpty = currentEmpty->getNext();
    }
}

void StudentList::copyObjectsSameLength(const StudentList& sameList)
{
    Node* currentSame = sameList.first;
    Node* current = first;
    while (current != nullptr)
    {
        current->setStudent(currentSame->getStudent());
        current = current->getNext();
        currentSame = currentSame->getNext();
    }

}

void StudentList::copyCallingObjLonger(const StudentList& shorterList)
{
    Node* current = first;
    Node* currentShorter = shorterList.first;
    while (currentShorter != nullptr)
    {
        current->setStudent(currentShorter->getStudent());
        if (currentShorter->getNext() != nullptr)
        {
            current = current->getNext();
        }
        currentShorter = currentShorter->getNext();
    }
    current->setNext(nullptr);
    current = current->getNext();
    delete current;
    current = nullptr;
}

void StudentList::copyCallingObjShorter(const StudentList& longerList)
{
    Node* current = first;
    Node* currentLonger = longerList.first;

    while (current->getNext() != nullptr)
    {
        current->setStudent(currentLonger->getStudent());
        currentLonger = currentLonger->getNext();
        current = current->getNext();
    }
    current->setStudent(currentLonger->getStudent());
    currentLonger = currentLonger->getNext();

    while (currentLonger != nullptr)
    {
        Node* newNode = new Node(currentLonger->getStudent(), nullptr);
        current->setNext(newNode);
        current = newNode;
        currentLonger = currentLonger->getNext();
        last = newNode; 
    }
    count = longerList.count;
}