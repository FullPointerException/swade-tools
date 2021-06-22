#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Stub.h"


TEST_CASE("Stub")
{
    Stub stub;
    REQUIRE(stub.stub() == 1);
}