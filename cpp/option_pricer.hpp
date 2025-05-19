#pragma once

class OptionPricer {
public:
    static double black_scholes_price(double S, double K, double T, double r, double sigma, bool isCall);
};
