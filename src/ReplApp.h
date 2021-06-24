#pragma once

#include <iostream>

class ReplApp
{
public:
    ReplApp(std::istream& input, std::ostream& output);

    int run();

private:
    std::istream& _in;
    std::ostream& _out;
};
