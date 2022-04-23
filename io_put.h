//
// Created by cooler on 20-8-18.
//

#ifndef LEETCODE_IO_PUT_H
#define LEETCODE_IO_PUT_H

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class io_put {
public:
    static void input_num_array(void) ;
    static vector<vector<int>> input_num_matrix(void);
//    static void input_num_space_array(void);
    static vector<int> input_numbers(void);
    static vector<vector<char>> input_char_matrix(void);
    static vector<vector<int>>  input_multi_n_array(void);
    static vector<string> input_strline_divede(void);
};


#endif //LEETCODE_IO_PUT_H
