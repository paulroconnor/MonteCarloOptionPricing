// Option.cpp

#include "Option.h"
#include <cmath>
#include <random>
#include <vector>
#include <iostream>
#include <iomanip>

Option::Option(
            float S,  // Asset Price
            float K,  // Strike Price
            float r,  // Growth Rate
            float v,  // Volatility
            float Y,  // Years To Maturity
            long N    // Number of Simulations
            ) {
    AssetPrice = S;
    StrikePrice = K;
    GrowthRate = r;
    Volatility = v;
    YearsToMaturity = Y;
    NumberOfSimulations = N;
}

// European Options ------------------------------------------------------

void Option::priceEuropeanOptions() {

    // initial value for payoff sumation
    double callPayoff = 0.0;
    double putPayoff = 0.0;

    for (int i = 1; i <= getNumberOfSimulations(); i++) {

        std::vector<float>* pricePath = generateAssetPath();
        float finalPrice = (*pricePath).back();  // get last price - price at exercise date
        delete pricePath;  // delete price path from memory

        if (finalPrice > getStrikePrice()) {  // max(S - K, 0)
            callPayoff += finalPrice - getStrikePrice();
        } else if (finalPrice < getStrikePrice()) {  // max(K - S, 0)
            putPayoff += getStrikePrice() - finalPrice;
        }

    }

    // Set values as average payoff discounted to present value
    EuropeanCall = (callPayoff / getNumberOfSimulations()) * exp(-getGrowthRate() * getYearsToMaturity());
    EuropeanPut = (putPayoff / getNumberOfSimulations()) * exp(-getGrowthRate() * getYearsToMaturity());

    // Print Output
    std::cout << std::fixed << std::setprecision(4);
    std::cout << std::setw(30) << std::left << "European Call Option Price" << ": $" << getEuropeanCall() << std::endl;
    std::cout << std::setw(30) << std::left << "European Put Option Price" << ": $" << getEuropeanPut() << std::endl;

}

// European Options ------------------------------------------------------

void Option::priceAsianOptions() {

    // initial value for payoff sumation
    double callPayoff = 0.0;
    double putPayoff = 0.0;

    for (int i = 1; i <= getNumberOfSimulations(); i++) {

        std::vector<float>* pricePath = generateAssetPath();
        double meanPrice = std::accumulate((*pricePath).begin(), (*pricePath).end(), 0.0) / (*pricePath).size();  // get mean of prices in path
        delete pricePath;  // delete price path from memory

        if (meanPrice > getStrikePrice()) {  // max(avg(S) - K, 0)
            callPayoff += meanPrice - getStrikePrice();
        } else if (meanPrice < getStrikePrice()) {  // max(K - avg(S), 0)
            putPayoff += getStrikePrice() - meanPrice;
        }

    }

    // Set values as average payoff discounted to present value
    AsianCall = (callPayoff / getNumberOfSimulations()) * exp(-getGrowthRate() * getYearsToMaturity());
    AsianPut = (putPayoff / getNumberOfSimulations()) * exp(-getGrowthRate() * getYearsToMaturity());

    // Print Output
    std::cout << std::fixed << std::setprecision(4);
    std::cout << std::setw(30) << std::left << "Asian Call Option Price" << ": $" << getAsianCall() << std::endl;
    std::cout << std::setw(30) << std::left << "Asian Put Option Price" << ": $" << getAsianPut() << std::endl;

}


// Generate Asset Price Path ---------------------------------------------

std::vector<float>* Option::generateAssetPath() {
    float timeStep = 1 / TRADING_DAYS_PER_YEAR;
    float sqrtTimeStep = sqrt(timeStep);
    int timeToMaturity = static_cast<int>(std::round(getYearsToMaturity() * TRADING_DAYS_PER_YEAR));  // round float to int

    // Set up random normally distributed number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<float> d(0, 1);  // standard normal with zero mean and variance 1
    double z;

    // Create empty vector to store prices
    std::vector<float>* pricePath = new std::vector<float>(timeToMaturity);
    (*pricePath)[0] = static_cast<float>(getAssetPrice());

    for (int t = 1; t <= timeToMaturity - 1; t++) {
        z = d(gen);
        (*pricePath)[t] = (*pricePath)[t - 1] * exp(getGrowthRate() * timeStep + getVolatility() * sqrtTimeStep * z);
    };
    
    return pricePath;
}

// Output Functions ------------------------------------------------------

void Option::printInputs() {

    for (int i = 0; i < 50; ++i) {
        std::cout << "=";
    }
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::setw(30) << std::left << "Asset Price" << ": $" << getAssetPrice() << std::endl
              << std::setw(30) << std::left << "Strike Price" << ": $" << getStrikePrice() << std::endl 
              << std::setw(30) << std::left << "Growth Rate" << ": "  << getGrowthRate() * 100 << "%" << std::endl
              << std::setw(30) << std::left << "Volatility" << ": "  << getVolatility() * 100 << "%" << std::endl         
              << std::setw(30) << std::left << "Years To Maturity" << ": "  << getYearsToMaturity() << std::endl;

    std::cout << std::fixed << std::setprecision(0);
    std::cout << std::setw(30) << std::left << "Number of Simulations" << ": "  << getNumberOfSimulations() << std::endl;


    for (int i = 0; i < 50; ++i) {
        std::cout << "=";
    }
    std::cout << std::endl;
}


// Getting Variables -----------------------------------------------------

float Option::getAssetPrice() {
    return AssetPrice;
}

float Option::getStrikePrice() {
    return StrikePrice;
}

float Option::getGrowthRate() {
    return GrowthRate;
}

float Option::getVolatility() {
    return Volatility;
}

float Option::getYearsToMaturity() {
    return YearsToMaturity;
}

long Option::getNumberOfSimulations() {
    return NumberOfSimulations;
}

double Option::getEuropeanCall() {
    return EuropeanCall;
}

double Option::getEuropeanPut() {
    return EuropeanPut;
}

double Option::getAsianCall() {
    return AsianCall;
}

double Option::getAsianPut() {
    return AsianPut;
}