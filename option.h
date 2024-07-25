// Option.h

#ifndef _MONTECARLOOPTIONPRICING_OPTION_H
#define _MONTECARLOOPTIONPRICING_OPTION_H

#include <iostream>
#include <vector>

class Option {
public:

    const float TRADING_DAYS_PER_YEAR = 252;
    const int PRINT_WIDTH = 50;

    Option(
        float,  // Asset Price
        float,  // Strike Price
        float,  // Growth Rate
        float,  // Volatility
        float,  // Years To Maturity
        long    // Number of Simulations
        );
    
    void priceEuropeanOptions();
    void priceAsianOptions();
    void priceLookbackOptions();

    std::vector<float>* generateAssetPath();

    void printInputs();

    float getAssetPrice();
    float getStrikePrice();
    float getGrowthRate();
    float getVolatility();
    float getYearsToMaturity();
    long getNumberOfSimulations();

    double getEuropeanCall();
    double getEuropeanPut();

    double getAsianCall();
    double getAsianPut();

    double getLookbackCallFloat();
    double getLookbackPutFloat();
    double getLookbackCallFixed();
    double getLookbackPutFixed();

private:

    float AssetPrice;
    float StrikePrice;
    float GrowthRate;
    float Volatility;
    float YearsToMaturity;
    long NumberOfSimulations;

    double EuropeanCall;
    double EuropeanPut;

    double AsianCall;
    double AsianPut;

    double LookbackCallFloat;
    double LookbackPutFloat;
    double LookbackCallFixed;
    double LookbackPutFixed;

};

#endif