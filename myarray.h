#pragma once

#include <iostream>
#include <vector>

using namespace std;
using std::vector;

class myarray
{
private:
    /* data */
public:
    myarray(/* args */);
    ~myarray();
     
    static int findRepeatNumber1(vector<int> &nums);
    static int findRepeatNumber2(vector<int> &nums);
    static bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);
};

