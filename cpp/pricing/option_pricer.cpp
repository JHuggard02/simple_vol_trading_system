#include "option_pricer.hpp"
#include <cmath>
#include <random>
#include <algorithm>

double OptionPricer::norm_cdf(double x){
    return 0.5 * std::erfc(-x * M_SQRT1_2);
}

double OptionPricer::norm_pdf(double x){
    return (1.0 / std::sqrt(2.0 * M_PI)) * std::exp(-0.5 * x * x);
}

double OptionPricer::d1(double S, double K, double T, double r, double sigma){
    return (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
}

double OptionPricer::black_scholes_price(double S, double K, double T, double r, double sigma, bool isCall) {
    double d1 = OptionPricer::d1(S, K, T, r, sigma);
    double d2 = d1 - sigma * sqrt(T);
    if (isCall)
        return S * OptionPricer::norm_cdf(d1) - K * exp(-r * T) * OptionPricer::norm_cdf(d2);
    else
        return K * exp(-r * T) * OptionPricer::norm_cdf(-d2) - S * OptionPricer::norm_cdf(-d1);
}

double OptionPricer::delta(double S, double K, double T, double r, double sigma, bool isCall){
    double d1 = OptionPricer::d1(S, K, T, r, sigma);
    if (isCall) return OptionPricer::norm_cdf(d1);
    return OptionPricer::norm_cdf(d1) - 1.0;
}

double OptionPricer::vega(double S, double K, double T, double r, double sigma){
    double d1 = OptionPricer::d1(S, K, T, r, sigma);
    return S * OptionPricer::norm_pdf(d1) * std::sqrt(T);
}

double OptionPricer::gamma(double S, double K, double T, double r, double sigma){
    double d1 = OptionPricer::d1(S, K, T, r, sigma);
    return (OptionPricer::norm_pdf(d1)/ (S * sigma * std::sqrt(T)));
}

double OptionPricer::rho(double S, double K, double T, double r, double sigma, bool isCall){
    double d1 = OptionPricer::d1(S,K,T,r,sigma);
    double d2 = d1 - sigma * std::sqrt(T);
    if (isCall)
        return K * T * std::exp(-r * T) * OptionPricer::norm_cdf(d2);
    else
        return -K * T * std::exp(-r * T) * OptionPricer::norm_cdf(-d2);
}

double OptionPricer::IV(double S, double K, double T, double r, double initial_sigma, bool isCall, double marketPrice) {
    const double tol = 1e-6;
    const int max_iter = 100;
    double sigma = initial_sigma;
    
    for (int i = 0; i < max_iter; ++i) {
        double price = OptionPricer::black_scholes_price(S, K, T, r, sigma, isCall);
        double vega = OptionPricer::vega(S, K, T, r, sigma);

        if (vega < 1e-8) 
            break;

        double diff = price - marketPrice;
        if (std::abs(diff) < tol)
            return sigma;

        sigma -= diff / vega;

        if (sigma <= 0.0) sigma = 1e-4;
        if (sigma > 5.0) sigma = 5.0;
    }

    return sigma;  
}