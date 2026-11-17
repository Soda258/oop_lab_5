#include <iostream>
#include "Course.h"
#include "Professor.h"
#include "Student.h"

int main(){
    Professor prof1("Novozsh");
    Professor prof2("Tromifor");


    Course course1("Pipyauvedenie", &prof1);
    Course course2("Marazm", &prof2);

    course1.addTopic("Vyshivanie");
    course1.addTopic("Plavanie v geyzere");
    course1.addTopic("Realnee chem vasha shaverma");

    course2.addTopic("Matematika");
    course2.addTopic("Avtomatovedenie");
    course2.addTopic("Otmena");

    Student stud("GIPER AFANASIY");
    stud.enroll(&course1);
    stud.enroll(&course2);

    std::cout << "    1. Professory" << std::endl;
    std::cout << "Professor: " << prof1.getName() << " | Kurs: " << course1.getName() << std::endl;
    std::cout << "Professor: " << prof2.getName() << " | Kurs: " << course2.getName() << std::endl;

    std::cout << "\n    2.Student Info" << std::endl;
    std::cout << "Student: " << stud.getName() << std::endl;
    std::cout << "Enrolled (" << stud.getCourses().size() << "):" << std::endl;
    for(const Course* c : stud.getCourses()){
        std::cout << " - " << c->getName() << std::endl;}

    std::cout << "\n    3.Topics count" << std::endl;
    std::cout << "Kurs " << course1.getName() << ": " << course1.getTopics().size() << std::endl;
    std::cout << "Kurs " << course2.getName() << ": " << course2.getTopics().size() << std::endl;


    return 0;
}