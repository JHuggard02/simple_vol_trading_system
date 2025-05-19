#include "MonteCarloPricer.hpp";
#include <cmath>
#include <numeric>

MonteCarloPricer::MonteCarloPricer(const StochasticModel& model, int steps, int num_paths) :
    model_(model), steps_(steps), num_paths_(num_paths) {};

double MonteCarloPricer::price_option(double S0, double K, double T, double r, bool isCall) const {
    double payoff_sum = 0.0;

    for (int i = 0; i < num_paths_; ++i){
        std::vector<double> path = model_.generate_path(S0, T, steps_);
        double ST = path.back();

        double payoff = isCall ? std::max(ST - K, 0.0) : std::max(K - ST, 0.0);
        payoff_sum += payoff;
    }

    return std::exp(-r * T) * (payoff_sum / num_paths_);
};