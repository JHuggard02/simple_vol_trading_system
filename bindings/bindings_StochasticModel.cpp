#include <pybind11/pybind11.h>
#include <memory>
#include "../cpp/pricing/stochasticModels/StochasticModel.hpp"

namespace py = pybind11;

void bind_stochastic_model(py::module_ &m) {
    py::class_<StochasticModel, std::shared_ptr<StochasticModel>>(m, "StochasticModel");
}