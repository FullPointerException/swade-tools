#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include "InputSanitizer.h"


TEST_CASE("Sanitizes Inputs")
{
    SECTION("Mixed case")
    {
        std::string original("aBcDeF");
        std::string sanitized = InputSanitizer::sanitize(original);

        REQUIRE(sanitized == std::string("abcdef"));
    }

    SECTION("Beginning white space")
    {
        std::string original(" command");
        std::string sanitized = InputSanitizer::sanitize(original);

        REQUIRE(sanitized == std::string("command"));
    }

    SECTION("Ending white space")
    {
        std::string original("command ");
        std::string sanitized = InputSanitizer::sanitize(original);

        REQUIRE(sanitized == std::string("command"));
    }

    SECTION("Leaves midstring white space")
    {
        std::string original(" one two ");
        std::string sanitized = InputSanitizer::sanitize(original);

        REQUIRE(sanitized == std::string("one two"));
    }

    SECTION("All space string is ok")
    {
        REQUIRE(InputSanitizer::sanitize(std::string("   ")) == std::string(""));
    }

    SECTION("Empty string is ok")
    {
        REQUIRE(InputSanitizer::sanitize(std::string("")) == std::string(""));
    }
}
