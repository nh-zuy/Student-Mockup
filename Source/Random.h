#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <ctime>

class Random
{
    static bool _seeded;

public:
    Random() {
        srand(time(NULL));
        _seeded = true;
    }

    int nextInt() {
        if (!_seeded) {
            srand(time(NULL));
            _seeded = true;
        };

        return rand();
    }

    int nextInt(int ceiling) {
        if (!_seeded) {
            srand(time(NULL));
            _seeded = true;
        };

        return rand() % ceiling;
    }

    int nextInt(int left, int right) {
        if (!_seeded) {
            srand(time(NULL));
            _seeded = true;
        };

        return rand() % (right - left + 1) + left;
    }
};

bool Random::_seeded = false;

#endif // RANDOM_H
