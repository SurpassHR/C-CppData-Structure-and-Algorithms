#include "service.h"
#include <iostream>

const std::string MSG = "service " + Service::NAME + " ready";

int main()
{
    std::cout << MSG << std::endl;
    return 0;
}