#pragma once
#include "./stochasticModels/StochasticModel.hpp"

class MonteCarloPricer{
    private:
        const StochasticModel& model_;
        int steps_;
        int num_paths_;

    public:
        MonteCarloPricer(const StochasticModel& model, int steps, int num_paths);

        double price_option(double S0, double K, double T, double r, bool isCall) const;
};