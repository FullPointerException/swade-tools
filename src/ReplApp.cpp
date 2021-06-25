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
    _out << "Welcome to SWADE Tools:" << std::endl;

    bool running = true;
    bool isMain = true;
    while(running)
    {
        _out << "> ";
        std::string rawInput;
        getline(_in, rawInput);

        std::string parsedInput = InputSanitizer::sanitize(rawInput);
        _out << "PARSED: " << parsedInput << std::endl;

        if(isMain)
        {
            if( (parsedInput == std::string("q")) || (parsedInput == std::string("quit")) )
            {
                running = false;
            }
            else if( (parsedInput == std::string("h")) || (parsedInput == std::string("help")) )
            {
                _out << "Available commands:" << std::endl;
                _out << "\tgenerators\t\tGenerate various things from tables" << std::endl;
                _out << "\th, help\t\t\tDisplay list of available commands" << std::endl;
                _out << "\tq, quit\t\t\tExit the application" << std::endl;
            }
            else if( (parsedInput == std::string("generators")))
            {
                _out << "Select Generator:" << std::endl;
                isMain = false;
            }
            else
            {
                _out << "Invalid command '" << rawInput << "'." << std::endl;
                _out << "Try \"help\" for a list of commands." << std::endl;
            }
        }
        else
        {
            if( (parsedInput == std::string("q")) || (parsedInput == std::string("quit")) )
            {
                _out << "SWADE Tools:" << std::endl;
                isMain = true;
            }
            else if( (parsedInput == std::string("h")) || (parsedInput == std::string("help")) )
            {
                _out << "Available commands:" << std::endl;
                _out << "\ttrade goods" << std::endl;
                _out << "\th, help\t\t\tDisplay list of available commands" << std::endl;
                _out << "\tq, quit\t\t\tReturn to the main menu" << std::endl;
                _out << "\texit\t\t\tExit the application" << std::endl;
            }
            else if(parsedInput == std::string("trade goods"))
            {
                _out << "Trade Goods" << std::endl;
            }
            else if(parsedInput == std::string("exit"))
            {
                running = false;
            }
            else if( (parsedInput == std::string("generators")))
            {
                _out << "Select Generator:" << std::endl;
                isMain = false;
            }
            else
            {
                _out << "Invalid command '" << rawInput << "'." << std::endl;
                _out << "Try \"help\" for a list of commands." << std::endl;
            }
        }
    }

    return 0;
}
