#include <iostream>
#include <string>
#include <vector>

#include "Course.h"
#include "Professor.h"
#include "Student.h"
#include "BudgetStudent.h"
#include "PaidStudent.h"

int main(){

    Professor Ivanov("Ivanov");
    Professor Petrova("Petrova");

    Course oop("OOP", &Ivanov);
    Course math("Math", &Petrova);
    Course physics("Physics", &Ivanov);

    oop.addTopic("Classes and objects");
    oop.addTopic("Constructors");
    oop.addTopic("Rule of three");

    math.addTopic("Limits");
    math.addTopic("Derivatives");

    physics.addTopic("Mechanics");
    physics.addTopic("Thermodynamics");
    physics.addTopic("Electromagnetism");

    BudgetStudent Alice("Alice", 1500);
    PaidStudent   Bob("Bob", 200000);
    BudgetStudent Gleb("Gleb", 1200);

    Alice.enroll(&oop);
    Alice.enroll(&math);
    Bob.enroll(&physics);
    Gleb.enroll(&oop);
    Gleb.enroll(&physics);

    oop.enrollStudent(&Alice);
    oop.enrollStudent(&Gleb);
    math.enrollStudent(&Alice);
    physics.enrollStudent(&Bob);
    physics.enrollStudent(&Gleb);

    oop.enrollStudent(&Alice);

    std::cout << "=== Students ===\n";
    BudgetStudent* budgetStudents[] = {&Alice, &Gleb};
    PaidStudent* paidStudents[] = {&Bob};
    int totalTuition = 0;
    for (BudgetStudent* s : budgetStudents){
        std::cout << s->getName() << " (" << s->getStatus() << "), tuition: " << s->getTuition() 
                << ", scholarship: " << s->getScholarship() << "\n";
        totalTuition+=s->getTuition();
        for (const Course* c : s->getCourses()){
            std::cout << "  " << c->getName() << "\n";}}

    for (PaidStudent* s : paidStudents){
        std::cout << s->getName() << " (" << s->getStatus() << "), tuition: " << s->getTuition() << "\n";
            totalTuition+=s->getTuition();
        for (const Course* c : s->getCourses()){
            std::cout << "  " << c->getName() << "\n";}
    }

    std::cout << "\n=== Courses ===\n";
    Course* courses[] = {&oop, &math, &physics};
    for (Course* c : courses) {
        std::cout << c->getName()
                  << " (Prof. " << c->getProfessor()->getName() << ")\n";
        std::cout << "  Topics: " << c->getTopics().size() << "\n";
        for (const std::string& t : c->getTopics())
            std::cout << "   - " << t << "\n";
        std::cout << "  Students: " << c->getStudentCount() << "\n";
        for (const Student* s : c->getStudents())
            std::cout << "   - " << s->getName() << "\n";
    }

    std::cout << "\n=== Summary ===\n";
    std::cout << "Total tuition: " << totalTuition << "\n";

    std::cout << "\n=== Scholarships ===\n";
    std::cout << "Alice: " << Alice.getScholarship() << "\n";
    std::cout << "Gleb: " << Gleb.getScholarship() << "\n";

    return 0;
}