#include "InputSanitizer.h"
#include <algorithm>

std::string InputSanitizer::sanitize(const std::string& original)
{

    auto firstChar = std::find_if(original.begin(), original.end(),
        [](unsigned char c){ return !std::isspace(c);});
    auto lastChar = std::find_if(original.rbegin(), original.rend(),
        [](unsigned char c){ return !std::isspace(c);});
    std::string output(firstChar, lastChar.base());

    std::transform(output.begin(), output.end(), output.begin(),
        [](unsigned char c){return std::tolower(c);});

    return output;
}
