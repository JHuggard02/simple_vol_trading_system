#pragma once
#include <vector>

class StochasticModel {
    public:
        virtual std::vector<double> generate_path(double T, int steps) const = 0;
        virtual ~StochasticModel() = default;
};