#include <iostream>

#include "ReplApp.h"

int main(int argc, char** argv)
{
    ReplApp app(std::cin, std::cout);

    int result = app.run();

    return result;
}