#include <iostream>
#include <cmath>

// Compute standard normal PDF
double normal_pdf(double x) {
    static const double inv_sqrt_2pi = 1.0 / std::sqrt(2.0 * std::acos(-1.0));
    return inv_sqrt_2pi * std::exp(-0.5 * x * x);
}

// Compute d1 for Black-Scholes formula
double d1(double S, double K, double r, double T, double sigma) {
    return (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
}

// Compute Vega
double vega(double S, double K, double r, double T, double sigma) {
    double d1_val = d1(S, K, r, T, sigma);
    return S * normal_pdf(d1_val) * std::sqrt(T);
}

// Example usage
int main() {
    double S = 100.0;     // Spot price
    double K = 100.0;     // Strike price
    double r = 0.05;      // Risk-free rate
    double T = 1.0;       // Time to maturity (years)
    double sigma = 0.2;   // Volatility

    double v = vega(S, K, r, T, sigma);
    std::cout << "Vega: " << v << std::endl;

    return 0;
}
