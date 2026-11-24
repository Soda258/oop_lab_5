#pragma once

#include "Student.h"

class PaidStudent : public Student{
    public:
        PaidStudent(const std::string& name, int tuition);
        std::string getStatus() const;
        int getTuition() const;
    private:
        int tuition_;
};