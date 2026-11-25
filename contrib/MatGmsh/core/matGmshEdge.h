#pragma once

#include <algorithm>

struct matGmshEdge {
    int a;
    int b;

    matGmshEdge(int i, int j)
    {
        if(i > j) {
            std::swap(i, j);
        }
        a = i;
        b = j;
    }

    bool operator<(const matGmshEdge& other) const
    {
        if(a != other.a) {
            return a < other.a;
        }
        return b < other.b;
    }

    bool operator==(const matGmshEdge& other) const
    {
        return a == other.a && b == other.b;
    }
};
