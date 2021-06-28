#include "AppState.h"

#include <iostream>

AppState::AppState(std::ostream& out)
    : _out(out)
    , _running(true)
    , _state(State::SELECT_TOOL)
{

}

bool AppState::running() const
{
    return _running;
}

std::string AppState::prompt() const
{
    switch(_state)
    {
        case State::SELECT_TOOL:
        {
            return std::string("Select a tool:");
        }
        case State::SELECT_GENERATOR:
        {
            return std::string("Select a generator:");
        }
        case State::ITEM_GENERATOR:
        {
            return std::string("TODO:");
        }
    }
    return std::string("");
}

void AppState::execute(const std::string& command)
{
    switch(_state)
    {
        case State::SELECT_TOOL:
        {
            executeSelectTool(command);
            break;
        }
        case State::SELECT_GENERATOR:
        {
            executeSelectGenerator(command);
            break;
        }
        case State::ITEM_GENERATOR:
        {
            executeItemGenerator(command);
            break;
        }
    }
}

void AppState::quit()
{
    switch(_state)
    {
        case State::SELECT_TOOL:
        {
            exit();
            break;
        }
        case State::SELECT_GENERATOR:
        {
            _state = State::SELECT_TOOL;
            break;
        }
        case State::ITEM_GENERATOR:
        {
            _state = State::SELECT_GENERATOR;
            break;
        }
    }
}

void AppState::exit()
{
    _running = false;
}

void AppState::goToSelectTool()
{
    _state = State::SELECT_TOOL;
}

void AppState::goToSelectGenerator()
{
    _state = State::SELECT_GENERATOR;
}

void AppState::goToItemGenerator()
{
    _state = State::ITEM_GENERATOR;
}

void AppState::executeSelectTool(const std::string& command)
{
    if( (command == std::string("q")) || (command == std::string("quit")) )
    {
        quit();
    }
    else if(command == std::string("exit"))
    {
        exit();
    }
    else if( (command == std::string("h")) || (command == std::string("help")) )
    {
        _out << "Available commands:" << std::endl;
        _out << "\tgenerators\t\tGenerate various things from tables" << std::endl;
        _out << "\th, help\t\t\tDisplay list of available commands" << std::endl;
        _out << "\tq, quit\t\t\tExit the application" << std::endl;
        _out << "\texit\t\t\tExit the application" << std::endl;
    }
    else if( (command == std::string("generators")))
    {
        goToSelectGenerator();
    }
    else
    {
        // TODO move out
        _out << "Invalid command '" << command << "'." << std::endl;
        _out << "Try \"help\" for a list of commands." << std::endl;
    }
}

void AppState::executeSelectGenerator(const std::string& command)
{
    if( (command == std::string("q")) || (command == std::string("quit")) )
    {
        quit();
    }
    else if( (command == std::string("h")) || (command == std::string("help")) )
    {
        _out << "Available commands:" << std::endl;
        _out << "\t1, Magic Item\t\tGenerate a random magic item using the rules from "
                "the fantasy compansion" << std::endl;
        _out << "\th, help\t\t\tDisplay list of available commands" << std::endl;
        _out << "\tq, quit\t\t\tReturn to the main menu" << std::endl;
        _out << "\texit\t\t\tExit the application" << std::endl;
    }
    else if(command == std::string("trade goods"))
    {
        _out << "Trade Goods" << std::endl;
    }
    else if(command == std::string("exit"))
    {
        exit();
    }
    else
    {
        // TODO move out
        _out << "Invalid command '" << command << "'." << std::endl;
        _out << "Try \"help\" for a list of commands." << std::endl;
    }
}

void AppState::executeItemGenerator(const std::string& command)
{

}
