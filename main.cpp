// Main.cpp

#include <iostream>
#include "Option.h"

int main(int argc, const char * argv[]) {

    Option option(100, 100, 0.05, 0.15, 1, 10000);

    option.printInputs();

    option.priceEuropeanOptions();

    return 0;
}