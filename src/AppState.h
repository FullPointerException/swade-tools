#pragma once

#include <string>


class AppState
{
public:
    explicit AppState(std::ostream& out);

    bool running() const;
    std::string prompt() const;
    void execute(const std::string& command);

    void quit();
    void exit();

    void goToSelectTool();
    void goToSelectGenerator();
    void goToItemGenerator();

private:
    enum class State
    {
        SELECT_TOOL,
        SELECT_GENERATOR,
        ITEM_GENERATOR
    };

private:
    void executeSelectTool(const std::string& command);
    void executeSelectGenerator(const std::string& command);
    void executeItemGenerator(const std::string& command);

private:
    std::ostream& _out;
    bool _running;
    State _state;
};
