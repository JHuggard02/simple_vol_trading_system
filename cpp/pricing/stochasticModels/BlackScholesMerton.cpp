#include "BlackScholesMerton.hpp"
#include <vector>
#include <cmath>
#include <random>

BlackScholesMerton::BlackScholesMerton(double S0, double mu, double sigma)
    : S0(S0), mu(mu), sigma(sigma) {};

std::vector<double> BlackScholesMerton::generate_path(double T, int steps) const {
    double dt = T / steps;
    std::vector<double> path(steps + 1);
    path[0] = S0;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::normal_distribution<double> distribution(0.0, 1.0);
    for (int i = 1; i <= steps; ++i) {
        double Z = distribution(generator);
        path[i] = path[i - 1] * std::exp((mu - 0.5 * sigma * sigma) * dt + sigma * std::sqrt(dt) * Z);
    }
    return path;
}