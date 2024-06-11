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

    return 0;
}
