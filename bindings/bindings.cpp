#include <pybind11/pybind11.h>
#include "../cpp/option_pricer.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pricer, m) {
    m.def("black_scholes_price", &OptionPricer::black_scholes_price, 
          "Compute Black-Scholes option price",
          py::arg("S"), py::arg("K"), py::arg("T"),
          py::arg("r"), py::arg("sigma"), py::arg("isCall"));
}
