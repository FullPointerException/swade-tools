#include "InputSanitizer.h"
#include <algorithm>

std::string InputSanitizer::sanitize(const std::string& original)
{
    std::string output = original;

    std::string::iterator new_end = std::remove_if(output.begin(), output.end(),
        [](unsigned char c){return std::isspace(c);});
    output.erase(new_end, output.end());

    std::transform(output.begin(), output.end(), output.begin(),
        [](unsigned char c){return std::tolower(c);});

    return output;
}
