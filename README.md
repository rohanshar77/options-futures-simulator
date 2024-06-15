# Options-Futures Simulation Project

This project simulates trading options and futures contracts, using the Black-Scholes model for option pricing and generating synthetic market data. The goal is to calculate the profit and loss (PnL) for a portfolio of options and futures over a series of trading periods.

## Features

- **Options and Futures Trading Simulation:** Handles buying and selling of options and futures, calculating the PnL.
- **Random Market Data Generation:** Uses a normal distribution to simulate market price changes.
- **Black-Scholes Model:** Implements the Black-Scholes formula for option pricing.
- **PnL Calculation:** Tracks and outputs the profit and loss for options and futures.
- **Training Data Loader:** Loads training data from a CSV file using PyTorch for potential future model integration.

## Prerequisites

- C++17 or later
- CMake 3.10 or later
- PyTorch C++ API (LibTorch)

## Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/rohanshar77/options-futures-simulator.git
    cd options-futures-simulator
    ```

2. **Install dependencies:**
    - Ensure you have CMake and a C++17 compatible compiler installed.
    - Download and install LibTorch from the [official PyTorch website](https://pytorch.org/).

3. **Build the project:**
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

## Code Overview

### `main.cpp`

- **Libraries and Constants:**
  - Includes necessary libraries.
  - Defines constants for the initial price, spread, and risk-free rate.

- **Structures:**
  - Defines `Option` and `Future` structures to hold trading data.

- **Random Number Generation:**
  - Uses a normal distribution to generate random market price changes.

- **Bid-Ask Price Calculation:**
  - Function to calculate bid and ask prices based on the spread.

- **Black-Scholes Model:**
  - Function to calculate the price of an option using the Black-Scholes formula.

- **Order Handling:**
  - Functions to handle buy and sell orders for both options and futures.

- **Data Loading:**
  - Function to load training data from a CSV file using PyTorch.

- **Simulation Loop:**
  - Main loop simulating market price changes and trading actions, calculating the resulting PnL.

### Example Data Format

`volatility_data.csv` should contain rows of historical data, where each row represents a time step, and each column represents a different feature.

```csv
0.2,0.3,0.25,0.27
0.21,0.31,0.26,0.28
...
