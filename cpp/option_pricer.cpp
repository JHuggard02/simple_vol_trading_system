#include "option_pricer.hpp"
#include <cmath>

double OptionPricer::black_scholes_price(double S, double K, double T, double r, double sigma, bool isCall) {
    double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    auto norm_cdf = [](double x) { return 0.5 * erfc(-x / std::sqrt(2)); };
    if (isCall)
        return S * norm_cdf(d1) - K * exp(-r * T) * norm_cdf(d2);
    else
        return K * exp(-r * T) * norm_cdf(-d2) - S * norm_cdf(-d1);
}
