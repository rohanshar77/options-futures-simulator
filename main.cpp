#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

const double INITIAL_PRICE = 100.0;
const double SPREAD = 1.0;
const double RISK_FREE_RATE = 0.05;

double generateRandomNumber(double mean, double std_dev) {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    normal_distribution<double> distribution(mean, std_dev);
    return distribution(generator);
}

void calculateBidAsk(double mid_price, double& bid_price, double& ask_price) {
    double half_spread = SPREAD / 2.0;
    bid_price = mid_price - half_spread;
    ask_price = mid_price + half_spread;
}

struct Option {
    string symbol;
    double strike;
    double expiry;
    double price;
    int quantity;
};

double N(double x) {
    return 0.5 * (1 + erf(x / sqrt(2)));
}

double blackScholes(double S, double K, double T, double r, double sigma, bool isCall) {
    double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    if (isCall) {
        double call_price = S * exp(-r * T) * N(d1) - K * exp(-r * T) * N(d2);
        return call_price;
    } else {
        double put_price = K * exp(-r * T) * N(-d2) - S * exp(-r * T) * N(-d1);
        return put_price;
    }
}

void handleBuyOrder(const Option& option, double bid_price, double& optionsPnL) {
    double pnl = (option.price - bid_price) * option.quantity;
    optionsPnL += pnl;
}

void handleSellOrder(const Option& option, double ask_price, double& optionsPnL) {
    double pnl = (ask_price - option.price) * option.quantity;
    optionsPnL += pnl;
}

int main() {
    double current_price = INITIAL_PRICE;
    double bid_price, ask_price;

    // Simulate price changes and calculate bid/ask prices
    for (int i = 1; i <= 10; ++i) {
        double price_change = generateRandomNumber(0.0, 1.0); // Use a fixed standard deviation for now
        double mid_price = current_price + price_change;
        calculateBidAsk(mid_price, bid_price, ask_price);
        current_price = mid_price;
        cout << "Mid price: " << mid_price << ", Bid price: " << bid_price << ", Ask price: " << ask_price << endl;
    }

    vector<Option> options{
        {"TSLA", 650.0, 0.25, 0.0, 0},
        {"NFLX", 520.0, 0.5, 0.0, 0},
        {"NVDA", 700.0, 0.75, 0.0, 0},
        {"AMD", 95.0, 1.0, 0.0, 0}
    };

    double optionsPnL = 0.0;

    for (auto& option : options) {
        option.price = blackScholes(current_price, option.strike, option.expiry, RISK_FREE_RATE, 0.2, true); // Assume fixed volatility for now

        // Handle buy and sell orders for options
        if (option.quantity > 0) {
            handleSellOrder(option, ask_price, optionsPnL);
        } else if (option.quantity < 0) {
            handleBuyOrder(option, bid_price, optionsPnL);
        }
    }

    cout << "Options PnL: " << optionsPnL << endl;

    return 0;
}
