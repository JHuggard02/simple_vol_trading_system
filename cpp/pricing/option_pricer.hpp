#pragma once

class OptionPricer {
public:
    static double norm_cdf(double x);
    static double norm_pdf(double x);
    static double d1(double S, double K, double T, double r, double sigma);
    static double black_scholes_price(double S, double K, double T, double r, double sigma, bool isCall);
    static double delta(double S, double K, double T, double r, double sigma, bool isCall);
    static double vega(double S, double K, double T, double r, double sigma);
    static double gamma(double S, double K, double T, double r, double sigma);
    static double rho(double S, double K, double T, double r, double sigma, bool isCall);
};
