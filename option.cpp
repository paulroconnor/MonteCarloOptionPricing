// option.cpp

#include "Option.h"
#include <cmath>
#include <random>

Option::Option(
    float S,  // Asset Price
    float K,  // Strike Price
    float r,  // Growth Rate
    float v,  // Volatility
    float Y,  // Years To Maturity
    long N// Number of Simulations
)
{
    AssetPrice = S;
    StrikePrice = K;
    GrowthRate = r;
    Volatility = v;
    YearsToMaturity = Y;
    NumberOfSimulations = N;
}



// Getting Variables -----------------------------------------------------

float Option::getAssetPrice()
{
    return AssetPrice;
}

float Option::getStrikePrice()
{
    return StrikePrice;
}

float Option::getGrowthRate()
{
    return GrowthRate;
}

float Option::getVolatility()
{
    return Volatility;
}

float Option::getYearsToMaturity()
{
    return YearsToMaturity;
}

long Option::getNumberOfSimulations()
{
    return NumberOfSimulations;
}