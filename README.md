# Volatility Trading System (Hybrid C++ + Python)

This is a simple  hybrid volatility trading system using C++ (for performance-critical option pricing) and Python (for flexibility and strategy logic). 

## 📁 Project Structure

```
vol_trading_system/
├── CMakeLists.txt               # Build configuration
├── cpp/
│   └── option_pricer.cpp       # C++ Black-Scholes pricing engine
│   └── option_pricer.hpp
├── bindings/
│   └── bindings.cpp            # pybind11 glue code
├── python/
│   └── main.py                 # Python driver script
├── pybind11/                   # Clone pybind11 here
└── README.md
```

---

## 🧰 Requirements

### General
- `cmake`
- `make` or Visual Studio
- C++17 compiler (e.g. `g++`, `clang++`)
- `python3` (with headers: `python3-dev` on Linux)

### OS-specific

#### macOS
```bash
brew install cmake python
```

#### Ubuntu / Debian
```bash
sudo apt update
sudo apt install cmake build-essential python3-dev
```

#### Windows
- Install [CMake](https://cmake.org/download/)
- Install [Visual Studio Community](https://visualstudio.microsoft.com/vs/)
  - Select "Desktop development with C++"
- Ensure Python is installed and added to PATH

---

## 🧩 Step 1: Clone pybind11

From the root of this project, run:

```bash
git clone https://github.com/pybind/pybind11.git
```

---

## 🏗️ Step 2: Build the Extension

```bash
mkdir build
cd build
cmake ..
make
```

This creates the `pricer` Python module.

---

## 🚀 Step 3: Run the Python Strategy

```bash
cd ../python
python main.py
```

You should see the computed Black-Scholes call and put option prices.

---

## What's Next?

- Add more option pricing models (Heston, SABR, etc.)
- Add Greeks calculation (Delta, Gamma, Vega...)
- Use market data feeds and backtesting frameworks
- Deploy as part of a live trading stack

---

## 📬 Questions?

Feel free to reach out!
