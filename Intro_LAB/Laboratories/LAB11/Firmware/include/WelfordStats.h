#pragma once

#include <Arduino.h>
#include <math.h>

class WelfordStats
{
public:
    void reset()
    {
        n_ = 0;
        mean_ = 0.0;
        m2_ = 0.0;
    }

    void push(double x)
    {
        if (isnan(x) || isinf(x)) return;

        n_++;

        const double delta = x - mean_;
        mean_ += delta / static_cast<double>(n_);
        const double delta2 = x - mean_;
        m2_ += delta * delta2;
    }

    uint32_t count() const
    {
        return n_;
    }

    double mean() const
    {
        return mean_;
    }

    double variance() const
    {
        if (n_ < 2) return NAN;
        return m2_ / static_cast<double>(n_ - 1);
    }

    double stddev() const
    {
        const double v = variance();
        if (isnan(v)) return NAN;
        return sqrt(v);
    }

private:
    uint32_t n_ = 0;
    double mean_ = 0.0;
    double m2_ = 0.0;
};
