#pragma once

#include <cstddef>

namespace Xenn {
    class Statistic {
    public:
        Statistic();
        ~Statistic();

        void add(float value);
        void reset();

        float min();
        float max();
        float avg();
        size_t count();

    private:
        float _min;
        float _max;
        float _sum;
        size_t _count;
    };
}