#include <iostream>
#include "Course.h"
#include "Professor.h"

int main(){
    Professor prof("Novozsh");
    Course course("Pipyauvedenie", &prof);

    course.addTopic("Vyshivanie");
    course.addTopic("Plavanie v geyzere");
    course.addTopic("Realnee chem vasha shaverma");

    std::cout << course.getName() << std::endl;
    std::cout << course.getProfessor()->getName() << std::endl;
    std::cout << course.getTopics().size() << std::endl;

    return 0;
}