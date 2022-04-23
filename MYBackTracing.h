#pragma once

#include <vector>
#include <string>

using namespace std;

class MYBackTracing
{
private:
    /* data */
public:
    MYBackTracing(/* args */);
    ~MYBackTracing();

    static bool exist(vector<vector<char>>& board, string word);
    static int movingCount(int m, int n, int k);
};

