#ifndef TELEMETRY_CORE_CALCULATOR_H_
#define TELEMETRY_CORE_CALCULATOR_H_

#pragma once

#include <vector>
#include <cmath>
#include <stdexcept>
#include <limits>

namespace telemetry {
namespace core {

/**
 * @class Calculator
 * @brief Provides mathematical operations for telemetry data processing.
 * 
 * The Calculator class implements essential statistical and mathematical operations
 * required for processing large-scale telemetry data in manufacturing environments.
 * It supports basic arithmetic, aggregation, and statistical analysis functions.
 */
class Calculator {
public:
    /**
     * @brief Default constructor
     */
    Calculator() = default;

    /**
     * @brief Default destructor
     */
    ~Calculator() = default;

    // Basic Arithmetic Operations
    
    /**
     * @brief Adds two numbers
     * @param a First operand
     * @param b Second operand
     * @return Sum of a and b
     */
    double Add(double a, double b) const;

    /**
     * @brief Subtracts two numbers
     * @param a First operand (minuend)
     * @param b Second operand (subtrahend)
     * @return Difference (a - b)
     */
    double Subtract(double a, double b) const;

    /**
     * @brief Multiplies two numbers
     * @param a First operand
     * @param b Second operand
     * @return Product of a and b
     */
    double Multiply(double a, double b) const;

    /**
     * @brief Divides two numbers
     * @param a First operand (dividend)
     * @param b Second operand (divisor)
     * @return Quotient (a / b)
     * @throws std::invalid_argument if divisor is zero
     */
    double Divide(double a, double b) const;

    /**
     * @brief Calculates the power of a number
     * @param base The base number
     * @param exponent The exponent
     * @return base raised to the power of exponent
     * @throws std::invalid_argument if operation results in domain error
     */
    double Power(double base, double exponent) const;

    /**
     * @brief Calculates the square root of a number
     * @param value The input value
     * @return Square root of the value
     * @throws std::invalid_argument if value is negative
     */
    double SquareRoot(double value) const;

    // Statistical Operations

    /**
     * @brief Calculates the sum of a vector of numbers
     * @param values Vector of numeric values
     * @return Sum of all values
     * @throws std::invalid_argument if vector is empty
     */
    double Sum(const std::vector<double>& values) const;

    /**
     * @brief Calculates the average (mean) of a vector of numbers
     * @param values Vector of numeric values
     * @return Average of all values
     * @throws std::invalid_argument if vector is empty
     */
    double Average(const std::vector<double>& values) const;

    /**
     * @brief Calculates the minimum value in a vector
     * @param values Vector of numeric values
     * @return Minimum value
     * @throws std::invalid_argument if vector is empty
     */
    double Minimum(const std::vector<double>& values) const;

    /**
     * @brief Calculates the maximum value in a vector
     * @param values Vector of numeric values
     * @return Maximum value
     * @throws std::invalid_argument if vector is empty
     */
    double Maximum(const std::vector<double>& values) const;

    /**
     * @brief Calculates the standard deviation of a vector of numbers
     * @param values Vector of numeric values
     * @param use_sample If true, calculates sample standard deviation (N-1), 
     *                   otherwise population standard deviation (N)
     * @return Standard deviation
     * @throws std::invalid_argument if vector is empty or has insufficient data
     */
    double StandardDeviation(const std::vector<double>& values, 
                            bool use_sample = true) const;

    /**
     * @brief Calculates the variance of a vector of numbers
     * @param values Vector of numeric values
     * @param use_sample If true, calculates sample variance (N-1), 
     *                   otherwise population variance (N)
     * @return Variance
     * @throws std::invalid_argument if vector is empty or has insufficient data
     */
    double Variance(const std::vector<double>& values, 
                   bool use_sample = true) const;

    // Utility Operations

    /**
     * @brief Calculates the absolute value
     * @param value The input value
     * @return Absolute value
     */
    double Absolute(double value) const;

    /**
     * @brief Rounds a number to the nearest integer
     * @param value The input value
     * @return Rounded value
     */
    double Round(double value) const;

    /**
     * @brief Rounds a number to a specified number of decimal places
     * @param value The input value
     * @param decimal_places Number of decimal places to round to
     * @return Rounded value
     */
    double RoundToDecimals(double value, int decimal_places) const;

    /**
     * @brief Checks if a value is within a specified range
     * @param value The value to check
     * @param min The minimum boundary (inclusive)
     * @param max The maximum boundary (inclusive)
     * @return True if value is within range, false otherwise
     */
    bool IsInRange(double value, double min, double max) const;

private:
    // Private helper constants
    static constexpr double EPSILON = std::numeric_limits<double>::epsilon();
};

} // namespace core
} // namespace telemetry

#endif // TELEMETRY_CORE_CALCULATOR_H_
