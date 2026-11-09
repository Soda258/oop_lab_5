#include <iostream>
#include "Course.h"
#include "Professor.h"
#include "Student.h"

int main(){
    Professor prof("Novozsh");
    Course course("Pipyauvedenie", &prof);

    course.addTopic("Vyshivanie");
    course.addTopic("Plavanie v geyzere");
    course.addTopic("Realnee chem vasha shaverma");

    std::cout << "Course: " << course.getName() << std::endl;
    std::cout << "Professor: " << course.getProfessor()->getName() << std::endl;
    std::cout << "Topics num: " << course.getTopics().size() << std::endl;

    Student stud("GIPER AFANASIY");
    stud.enroll(&course);
    stud.enroll(&course);

    std::cout << stud.getName() << std::endl;
    std::cout << stud.getCourses().size() << std::endl;
    for(const Course* c : stud.getCourses()){std::cout << ", " << c->getName() << std::endl;}

    return 0;
}