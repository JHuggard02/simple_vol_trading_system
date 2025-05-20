#include <pybind11/pybind11.h>
#include "../cpp/pricing/option_pricer.hpp"

void bind_stochastic_model(pybind11::module_ &);
void bind_black_scholes(pybind11::module_ &);
namespace py = pybind11;

PYBIND11_MODULE(pricer, m) {
    m.def("cdf", &OptionPricer::norm_cdf, "Compute Cumulative Normal Distribution",
        py::arg("x"));
    
    m.def("pdf", &OptionPricer::norm_pdf, "Compute the Probability Density Function of the Standard Normal Distribution",
        py::arg("x"));

    m.def("d1", &OptionPricer::d1, "Compute d1 (intermediate variable in option pricing)",
        py::arg("S"), py::arg("K"), py::arg("T"),
        py::arg("r"), py::arg("sigma"));

    m.def("black_scholes_price", &OptionPricer::black_scholes_price, 
          "Compute Black-Scholes option price",
        py::arg("S"), py::arg("K"), py::arg("T"),
        py::arg("r"), py::arg("sigma"), py::arg("isCall"));
    
    m.def("delta", &OptionPricer::delta, "Compute delta of an option,",
        py::arg("S"), py::arg("K"), py::arg("T"),
        py::arg("r"), py::arg("sigma"), py::arg("isCall"));

    m.def("vega", &OptionPricer::vega, "Compute vega of an option,",
        py::arg("S"), py::arg("K"), py::arg("T"),
        py::arg("r"), py::arg("sigma"));

    m.def("gamma", &OptionPricer::gamma, "Compute gamma of an option",
        py::arg("S"), py::arg("K"), py::arg("T"),
        py::arg("r"), py::arg("sigma"));

    m.def("rho", &OptionPricer::rho, "Compute rho of an option",
        py::arg("S"), py::arg("K"), py::arg("T"),
        py::arg("r"), py::arg("sigma"), py::arg("isCall"));

    m.def("iv", &OptionPricer::IV, "Compute Implied Volatility of an option",
        py::arg("S"), py::arg("K"), py::arg("T"),
        py::arg("r"), py::arg("initial_sigma"), py::arg("isCall"), py::arg("marketPrice"));

    bind_stochastic_model(m);
    bind_black_scholes(m);
}
