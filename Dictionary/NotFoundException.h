#pragma once
#include <stdexcept> 
#include <string> 
using namespace std;
class NotFoundException : public exception
{
public:
    NotFoundException(const string& message = "") : exception(("Element not found: " + message).c_str()) {}
};
