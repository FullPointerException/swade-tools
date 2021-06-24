#include "ReplApp.h"

#include <iostream>
#include "InputSanitizer.h"

ReplApp::ReplApp(std::istream& input, std::ostream& output)
    : _in(input)
    , _out(output)
{

}

int ReplApp::run()
{
    _out << "Welcome to SWADE Tools: " << std::endl;

    bool running = true;
    while(running)
    {
        _out << "> ";
        std::string rawInput;
        _in >> rawInput;

        std::string parsedInput = InputSanitizer::sanitize(rawInput);

        if( (parsedInput == std::string("q")) || (parsedInput == std::string("quit")) )
        {
            running = false;
        }
        else if( (parsedInput == std::string("h")) || (parsedInput == std::string("help")) )
        {
            _out << "Available commands:" << std::endl;
            _out << "\th, help\t\t\tDisplay list of available commands" << std::endl;
            _out << "\tq, quit\t\t\tExit the application" << std::endl;
        }
        else
        {
            _out << "Invalid command '" << rawInput << "'." << std::endl;
            _out << "Try \"help\" for a list of commands." << std::endl;
        }
    }

    return 0;
}
