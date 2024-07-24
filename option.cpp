// Option.cpp

#include "Option.h"
#include <cmath>
#include <random>
#include <vector>

Option::Option(
    float S,  // Asset Price
    float K,  // Strike Price
    float r,  // Growth Rate
    float v,  // Volatility
    float Y,  // Years To Maturity
    long N    // Number of Simulations
)
{
    AssetPrice = S;
    StrikePrice = K;
    GrowthRate = r;
    Volatility = v;
    YearsToMaturity = Y;
    NumberOfSimulations = N;
}

// Generate Asset Price Path ---------------------------------------------

std::vector<float>* Option::generateAssetPath()
{
    float timeStep = 1 / TRADING_DAYS_PER_YEAR;
    float sqrtTimeStep = sqrt(timeStep);
    int timeToMaturity = static_cast<int>(std::round(getYearsToMaturity() * TRADING_DAYS_PER_YEAR));  // round double to int

    // Set up random normally distributed number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<float> d(0, 1);
    double z;

    // Create empty vector to store prices
    std::vector<float>* pricePath = new std::vector<float>(timeToMaturity);
    (*pricePath)[0] = static_cast<float>(getAssetPrice());

    for (int t = 1; t <= timeToMaturity - 1; t++)
    {
        z = d(gen);
        (*pricePath)[t] = (*pricePath)[t - 1] * exp(getGrowthRate() * timeStep + 0.5 * getVolatility() * sqrtTimeStep * z);
    };
    
    return pricePath;
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