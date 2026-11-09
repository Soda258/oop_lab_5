#include <string>
#pragma once

class Professor{
    public:
        std::string name_;
        explicit Professor(const std::string &name);
        const std::string& getName() const;
};