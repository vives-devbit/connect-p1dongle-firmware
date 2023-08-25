#include "Statistic.h"

#include <limits>
#include <algorithm>

namespace Xenn {
    Statistic::Statistic() {
        reset();
    }

    Statistic::~Statistic() {
    }

    void Statistic::add(float value) {
        _min = std::min(_min, value);
        _max = std::max(_max, value);
        _sum += value;
        _count++;
    }

    void Statistic::reset() {
        _sum = 0;
        _count = 0;
        _min = std::numeric_limits<float>::max();
        _max = -std::numeric_limits<float>::max();
    }

    float Statistic::min() {
        return _min;
    }

    float Statistic::max() {
        return _max;
    }

    float Statistic::avg() {
        if(_count == 0) return 0.0;
        return _sum / _count;
    }

    size_t Statistic::count() {
        return _count;
    }

}