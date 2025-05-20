#pragma once
#include "StochasticModel.hpp"
#include <vector>

class BlackScholesMerton : public StochasticModel {
    private:
        double S0;
        double mu;
        double sigma;
    public:
        BlackScholesMerton(double S0, double mu, double sigma);
        std::vector<double> generate_path(double T, int steps) const override;
};