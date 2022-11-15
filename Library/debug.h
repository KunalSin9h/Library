#pragma once

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <bitset>
#include <tuple>

using std::cerr;
using std::string;
using std::pair;
using std::vector;
using std::endl;

void __print(int x) { std::cerr << x; }

void __print(long x) { std::cerr << x; }

void __print(long long x) { std::cerr << x; }

void __print(unsigned x) { std::cerr << x; }

void __print(unsigned long x) { std::cerr << x; }

void __print(unsigned long long x) { std::cerr << x; }

void __print(float x) { std::cerr << x; }

void __print(double x) { std::cerr << x; }

void __print(long double x) { std::cerr << x; }

void __print(char x) { std::cerr << '\'' << x << '\''; }

void __print(const char *x) { std::cerr << '\"' << x << '\"'; }

void __print(const std::string &x) { std::cerr << '\"' << x << '\"'; }

void __print(bool x) { std::cerr << (x ? "true" : "false"); }

// for all those who have .begin() defined (bcoz the can be looped through "ranged based for loop")
template<typename T, typename V>
void __print(const std::pair <T, V> &x) {
    std::cerr << '{';
    __print(x.first);
    std::cerr << ", ";
    __print(x.second);
    std::cerr << '}';
}

template<typename T>
void __print(const T &x) {
    int f = 0;
    std::cerr << '{';
    for (auto &i: x) std::cerr << (f++ ? ", " : ""), __print(i);
    std::cerr << "}";
}

void _print() { std::cerr << "]\n"; }

template<typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) std::cerr << ", ";
    _print(v...);
}

// For bitset<size_t>
template<size_t bits>
void _print(const std::bitset <bits> &b) {
    cerr << "{" << b << "}]" << '\n';
}

// for 2D vector
template<typename T>
void _print(const std::vector <vector<T>> &x) {
    int n = x[0].size();
    n <<= 1;
    n--;
    int m = n;
    std::cerr << ";)";
    _print();
    while (n--)std::cerr << '-';
    std::cerr << '\n';
    for (const auto &vec: x) {
        for (const T &i: vec) {
            std::cerr << i << ' ';
        }
        std::cerr << '\n';
    }
    while (m--)std::cerr << '-';
    std::cerr << '\n';
}

// for queue
template<typename T>
void _print(const std::queue <T> &q) {
    cerr << "{";
    std::queue <T> qtemp = q;
    int n = q.size();
    while (!qtemp.empty()) {
        cerr << qtemp.front() << (n == 1 ? "" : ", ");
        qtemp.pop();
        n--;
    }
    cerr << "}]";
}

//for stack
template<typename T>
void _print(const std::stack <T> &s) {
    cerr << "{";
    std::stack <T> stemp = s;
    int n = s.size();
    while (!stemp.empty()) {
        cerr << stemp.top() << (n == 1 ? "" : ", ");
        stemp.pop();
        n--;
    }
    cerr << "}]";
}

// for priority_queue
template<typename T>
void _print(const std::priority_queue <T> &pq) {
    cerr << "{";
    auto pqt = pq;
    int n = pq.size();
    while (!pqt.empty()) {
        cerr << pqt.top() << (n == 1 ? "" : ", ");
        pqt.pop();
        n--;
    }
    cerr << "}]";
}

#ifdef LOCAL
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#endif
