#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class mynum
{
private:
    /* data */
    
public:
    mynum(/* args */);
    ~mynum();
    static int divide(int a, int b);
    static string addBinary(string a, string b);

    static int Fibonacci_1(int n);
    static int Fibonacci_2(int n);
    static int Fibonacci_3(int n);
    static int hammingWeight(uint32_t n);
    static double myPow(double x, int n);
    static vector<string> printNumbers(int n);

    static int minArray(vector<int>& numbers);
};
