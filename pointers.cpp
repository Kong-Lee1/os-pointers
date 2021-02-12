// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <cctype>
#include <algorithm>
using namespace std;

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);
string toString(int x);

int main(int argc, char **argv)
{
    //Student * student = (struct Student*) malloc(sizeof(struct Student));
    Student *student;
    double average;


    string errorMessage;
    string IDMessage;
    string firstNameMessage;
    string lastNameMessage;
    string numAssignmentsMessage;
    string gradeMessage;


    errorMessage = "Sorry, I cannot understand your answer \n";
    IDMessage = "Please enter the student's id number: ";
    firstNameMessage = "Please enter the student's first name: ";
    lastNameMessage = "Please enter the student's last name: ";
    numAssignmentsMessage = "Please enter how many assignments were graded: ";
    gradeMessage = "Please enter grade for assignment ";

    // Sequence of user input -> store in fields of `student`
    student[0].id = promptInt(IDMessage, 0, 999999999);

    student[0].f_name = new char[128];
    student[0].l_name = new char[128];

    std::cout << firstNameMessage;
    std::cin >> student[0].f_name;
    //std:cout << student[0].f_name;
    //std::cout << student->f_name;


    std::cout << lastNameMessage;
    std::cin >> student[0].l_name;

    int numAssignmentsInt;
    std::cout << numAssignmentsMessage;

    while(true){
        

        std::cin >> student[0].n_assignments;

        if(!cin){
            
            std::cout << errorMessage;
            std::cout << numAssignmentsMessage;
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        else break;

        //std::cout << numAssignmentsMessage;
        
        //std::cout << numAssignmentsMessage;
    
    }
    
    //std::cin >> student[0].n_assignments;
    //student[0].n_assignments = ;


    //std::cout << student[0].n_assignments;
    //std::cout << "hello";

    //std::cout << student[0].n_assignments;
  
    if (student[0].n_assignments < 0 || student[0].n_assignments < 134217728 || !isdigit(student[0].n_assignments)){

        //std::cout << student[0].n_assignments;
        std::cout << errorMessage;
        std::cout << numAssignmentsMessage;
        std::cin >> student[0].n_assignments;

    }
 
    int i;
    double grades_array [student[0].n_assignments];
    student[0].grades = new double[student[0].n_assignments];

    //std::cout << student[0].n_assignments;
    for (i = 0; i < student[0].n_assignments; i++){

        string intString;

        intString = i;

        grades_array[i] = promptDouble(gradeMessage + toString(i+1) + ":", 0.0, 999.999999);
        
    }

    student[0].grades = grades_array;


    // Call `CalculateStudentAverage(???, ???)`
    // Output `average`

    calculateStudentAverage(student[0].grades, &average);

    std::cout << "\n";
    std::cout << "Student: " << student[0].f_name << student[0].l_name << " " << "[" << student[0].id << "]";
    std::cout << "\n";
    std::cout << "  Average grade: " << round(average);
    std::cout << "\n";
    
    return 0;
    
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int

    int studentID;
    string errorMessage;

    errorMessage = "Sorry I cannot understand your answer \n";

    std::cout << message;
    std::cin >> studentID;

    if (studentID < min || studentID > max || isdigit(studentID)){

        std::cout << errorMessage;
        std::cout << message;
        std::cin >> studentID;
    }
    else{
        return studentID;
    }

    return studentID;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double gradePercent;
    string errorMessage;

    errorMessage = "Sorry I cannot understand your answer \n";

    std::cout << message;
    std::cin >> gradePercent;
    

    if (gradePercent < min || gradePercent > max || isdigit(gradePercent)){

        std::cout << errorMessage;
        std::cout << message;
        std::cin >> gradePercent;
        
    }
    else{

        return gradePercent;

    }

    return gradePercent;

}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade

    int i;

    int counter = 0;

    for (i = 0; i < sizeof(object); i++){

        std::cout << ((double*)object)[i];
        *avg += ((double*)object)[i];

        if(((double*)object)[i] > sizeof(double)){

            counter = counter + 1;
        }
    }
        *avg = *avg/(counter);

    return;
}

string toString(int x){

    stringstream ss;

    ss << x;

    return ss.str();
}

