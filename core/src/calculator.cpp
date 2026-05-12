#include "calculator.h"
#include <algorithm>
#include <numeric>
#include <cmath>
#include <sstream>

namespace telemetry {
namespace core {

// Basic Arithmetic Operations

double Calculator::Add(double a, double b) const {
    return a + b;
}

double Calculator::Subtract(double a, double b) const {
    return a - b;
}

double Calculator::Multiply(double a, double b) const {
    return a * b;
}

double Calculator::Divide(double a, double b) const {
    if (std::abs(b) < EPSILON) {
        throw std::invalid_argument("Division by zero error");
    }
    return a / b;
}

double Calculator::Power(double base, double exponent) const {
    try {
        return std::pow(base, exponent);
    }
    catch (...) {
        throw std::invalid_argument("Power operation resulted in domain error");
    }
}

double Calculator::SquareRoot(double value) const {
    if (value < 0.0) {
        throw std::invalid_argument("Cannot calculate square root of negative number");
    }
    return std::sqrt(value);
}

// Statistical Operations

double Calculator::Sum(const std::vector<double>& values) const {
    if (values.empty()) {
        throw std::invalid_argument("Cannot calculate sum of empty vector");
    }
    return std::accumulate(values.begin(), values.end(), 0.0);
}

double Calculator::Average(const std::vector<double>& values) const {
    if (values.empty()) {
        throw std::invalid_argument("Cannot calculate average of empty vector");
    }
    return Sum(values) / static_cast<double>(values.size());
}

double Calculator::Minimum(const std::vector<double>& values) const {
    if (values.empty()) {
        throw std::invalid_argument("Cannot find minimum of empty vector");
    }
    return *std::min_element(values.begin(), values.end());
}

double Calculator::Maximum(const std::vector<double>& values) const {
    if (values.empty()) {
        throw std::invalid_argument("Cannot find maximum of empty vector");
    }
    return *std::max_element(values.begin(), values.end());
}

double Calculator::StandardDeviation(const std::vector<double>& values, 
                                     bool use_sample) const {
    return std::sqrt(Variance(values, use_sample));
}

double Calculator::Variance(const std::vector<double>& values, 
                           bool use_sample) const {
    if (values.empty()) {
        throw std::invalid_argument("Cannot calculate variance of empty vector");
    }

    if (use_sample && values.size() < 2) {
        throw std::invalid_argument(
            "Cannot calculate sample variance with less than 2 data points");
    }

    double mean = Average(values);
    double sum_squared_diff = 0.0;

    for (const auto& value : values) {
        double diff = value - mean;
        sum_squared_diff += diff * diff;
    }

    size_t divisor = use_sample ? (values.size() - 1) : values.size();
    return sum_squared_diff / static_cast<double>(divisor);
}

// Utility Operations

double Calculator::Absolute(double value) const {
    return std::abs(value);
}

double Calculator::Round(double value) const {
    return std::round(value);
}

double Calculator::RoundToDecimals(double value, int decimal_places) const {
    if (decimal_places < 0) {
        throw std::invalid_argument("Decimal places cannot be negative");
    }

    double multiplier = std::pow(10.0, static_cast<double>(decimal_places));
    return std::round(value * multiplier) / multiplier;
}

bool Calculator::IsInRange(double value, double min, double max) const {
    return (value >= min) && (value <= max);
}

} // namespace core
} // namespace telemetry
