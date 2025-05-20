#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../cpp/pricing/stochasticModels/BlackScholesMerton.hpp"
#include "../cpp/pricing/stochasticModels/StochasticModel.hpp"
#include <memory>

namespace py = pybind11;

void bind_black_scholes(py::module_ &m) {
    py::class_<BlackScholesMerton, StochasticModel, std::shared_ptr<BlackScholesMerton>>(m, "BlackScholesMerton")
        .def(py::init<double, double, double>())
        .def("generate_path", &BlackScholesMerton::generate_path);
}