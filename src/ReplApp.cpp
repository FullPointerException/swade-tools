#include "ReplApp.h"

#include <iostream>
#include "AppState.h"
#include "InputSanitizer.h"

ReplApp::ReplApp(std::istream& input, std::ostream& output)
    : _in(input)
    , _out(output)
{

}



int ReplApp::run()
{
    _out << "Welcome to SWADE Tools" << std::endl;

    AppState state(_out);
    while(state.running())
    {
        _out << state.prompt() << std::endl;

        _out << "> ";
        std::string rawInput;
        getline(_in, rawInput);

        std::string parsedInput = InputSanitizer::sanitize(rawInput);

        if(parsedInput.empty())
        {
            // Noop
        }
        else
        {
            state.execute(parsedInput);
        }
    }

    return 0;
}
