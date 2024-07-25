// Main.cpp

#include <iostream>
#include "Option.h"

int main(int argc, const char * argv[]) {

    Option option(100, 100, 0.05, 0.15, 1, 100000);

    option.printInputs();

    option.priceEuropeanOptions();

    option.priceAsianOptions();

    return 0;
}