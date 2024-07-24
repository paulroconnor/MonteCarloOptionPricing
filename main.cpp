// Main.cpp

#include <iostream>
#include "Option.h"

int main(int argc, const char * argv[]) {

    Option option(100, 100, 0.05, 0.15, 1, 1000000);

    std::cout << "Asset Price           : $" << option.getAssetPrice() << std::endl
              << "Strike Price          : $" << option.getStrikePrice() << std::endl 
              << "Growth Rate           : "  << option.getGrowthRate() << std::endl
              << "Volatility            : "  << option.getVolatility() << std::endl
              << "Years To Maturity     : "  << option.getYearsToMaturity() << std::endl
              << "Number of Simulations : "  << option.getNumberOfSimulations() << std::endl;

    option.priceEuropeanOptions();

    std::cout << "European Call Option Price: $" << option.getEuropeanCall() << std::endl;
    std::cout << "European Put Option Price: $" << option.getEuropeanPut() << std::endl;

    return 0;
}