// Option.h

#ifndef _MONTECARLOOPTIONPRICING_OPTION_H
#define _MONTECARLOOPTIONPRICING_OPTION_H

#include <iostream>
#include <vector>

class Option {
public:

    const float TRADING_DAYS_PER_YEAR = 252;

    Option(
        float,  // Asset Price
        float,  // Strike Price
        float,  // Growth Rate
        float,  // Volatility
        float,  // Years To Maturity
        long    // Number of Simulations
        );
    
    void priceEuropeanOptions();

    std::vector<float>* generateAssetPath();

    float getAssetPrice();
    float getStrikePrice();
    float getGrowthRate();
    float getVolatility();
    float getYearsToMaturity();
    long getNumberOfSimulations();

    double getEuropeanCall();
    double getEuropeanPut();

private:

    float AssetPrice;
    float StrikePrice;
    float GrowthRate;
    float Volatility;
    float YearsToMaturity;
    long NumberOfSimulations;

    double EuropeanCall;
    double EuropeanPut;

};

#endif