cmake_minimum_required(VERSION 3.12)
project(pricer)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(pybind11)
pybind11_add_module(pricer 
    bindings/bindings.cpp 
    bindings/bindings_StochasticModel.cpp
    bindings/bindings_BlackScholes.cpp
    cpp/pricing/option_pricer.cpp
    cpp/pricing/stochasticModels/BlackScholesMerton.cpp)
