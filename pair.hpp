#pragma once

#include <iostream>
using namespace std;

template<typename T1, typename T2>
struct Pair {
    T1 first;
    T2 second;

    Pair() = default;

    Pair(const T1& first_arg, const T2& second_arg) : first(first_arg), second(second_arg) {
    }
};
