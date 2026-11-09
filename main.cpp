#include <iostream>
#include "Course.h"

int main(){
    Course course("Pipyauvedenie");

    course.addTopic("Vyshivanie");
    course.addTopic("Plavanie v geyzere");
    course.addTopic("Realnee chem vasha shaverma");

    std::cout << course.getName() << std::endl;
    std::cout << course.getTopics().size() << std::endl;

    return 0;
}