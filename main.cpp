#include <iostream>
#include "Course.h"
#include "Professor.h"
#include "Student.h"
#include "BudgetStudent.h"
#include "PaidStudent.h"

int main(){
    BudgetStudent alice("Alice", 1500);
    PaidStudent bob("Bob", 200000);
    Professor prof("Ivanov");
    Course oop("OOP", &prof);

    oop.enrollStudent(&alice);
    oop.enrollStudent(&bob);
    oop.enrollStudent(&alice);

    std::cout << oop.getName() << " (Prof. " << oop.getProfessor()->getName() << ")\n";
    std::cout << "Students: " << oop.getStudentCount() << "\n";
    for(const Student* s : oop.getStudents()){
        std::cout << " - " << s->getName() << " (" << s->getStatus() << ")\n";}
        
    return 0;
}