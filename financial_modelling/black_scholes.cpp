/* Black-Scholes model for pricing European call and put options */
#include <iostream>
#include <cmath>

using namespace std;

double cumulative_normal_distribution(double x) {
    return 0.5 * (1 + erf(x / sqrt(2)));
};

double CallOptionPrice(double S, double K, double r, double t, double sigma) {
    double d1 = log(S/K) + t*(r + (sigma*sigma / 2))/sigma* sqrt(t);
    double d2 = d1 - sigma * sqrt(t);
    double norm_d1 = cumulative_normal_distribution(d1);
    double norm_d2 = cumulative_normal_distribution(d2);
    double price = S * norm_d1 - K * ::exp(-r*t) * norm_d2;
    return price;
};

double PutOptionPrice(double S, double K, double r, double t, double sigma) {
    double d1 = log(S/K) + t*(r - (sigma*sigma / 2))/sigma* sqrt(t);
    double d2 = d1 - sigma * sqrt(t);
    double norm_d1 = cumulative_normal_distribution(-d1);
    double norm_d2 = cumulative_normal_distribution(-d2);
    double price = K * ::exp(-r*t) * norm_d2 - S * norm_d1;
    return price;
};

int main() {
    double S = 100;
    double K = 110;
    double r = 0.05;
    double t = 3;
    double sigma = 0.05;
    double call_price = CallOptionPrice(S, K, r, t, sigma);
    double put_price = PutOptionPrice(S, K, r, t, sigma);
    cout << "Call price: " << call_price << endl;
    cout << "Put price: " << put_price << endl;
    return 0;
}
