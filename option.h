// option.h

#ifndef _MONTECARLOOPTIONPRICING_OPTION_H
#define _MONTECARLOOPTIONPRICING_OPTION_H

#include <iostream>

class Option
{
public:

    const int TRADING_DAYS_PER_YEAR = 252;

    Option(
        float,  // Asset Price
        float,  // Strike Price
        float,  // Growth Rate
        float,  // Volatility
        float,  // Years To Maturity
        long // Number of Simulations
        );
    
    float getAssetPrice();
    float getStrikePrice();
    float getGrowthRate();
    float getVolatility();
    float getYearsToMaturity();
    long getNumberOfSimulations();

private:

    float AssetPrice;
    float StrikePrice;
    float GrowthRate;
    float Volatility;
    float YearsToMaturity;
    long NumberOfSimulations;

};

#endif