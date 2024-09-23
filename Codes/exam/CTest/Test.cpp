#include "CExample.h"
#include "CTest.h"

/* CExample(int) constructor called!100
 * CExample(int) constructor called!1000
 * CTest::CTest() called!
 * CTest::CTest() called! */
int main(int argc, char* argv[]) {
    CTest cobj;
    CTest cobj1;
    return 0;
}