#include "MYBackTracing.h"

vector<vector<int>> dir={{-1,0},{0,-1},{0,1},{1,0}}; /* 上左下右 */

bool exist_core(int row_index, int col_index, vector<vector<bool>>& flag, vector<vector<char>>& board, string word, int ch_index){
    if(ch_index == word.size()) return true;
    int row = board.size(), col = board[0].size();
    for(int i=0; i<4; ++i){
        int row_next=row_index+dir[i][0], col_next=col_index+dir[i][1];
        if(row_next>=0 && row_next<row && col_next>=0 && col_next<col){
            if(flag[row_next][col_next]==false && board[row_next][col_next]==word[ch_index]){
                if(ch_index == word.size()-1) return true;
                else{
                    flag[row_next][col_next] = true;
                    if(exist_core(row_next, col_next, flag, board, word, ch_index+1)){
                        return true;
                    }
                }
            }
        }
    }
    flag[row_index][col_index] = false;
    return false;
}

bool MYBackTracing::exist(vector<vector<char>>& board, string word){
    if(board.size()==0 || word.size()==0) return false;
    int row = board.size(), col = board[0].size();
    vector<vector<bool>> flag(row, vector<bool>(col, false));
    for(int i=0; i<row; ++i){
        for(int j=0; j<col; ++j){
            if(board[i][j] == word[0]){
                flag[i][j] = true;
                if(exist_core(i, j, flag, board, word, 1))
                    return true;
            }
        }
    }
    return false;
}

int getDigitSum(int num){
    int i=0;
    int res=0;
    while(num/10){
        res += num%10;
        num = num/10;
    }
    res += num;
    return res;
}

void movingCount_core(int m, int n, int row_index, int col_index, int k, int& num, vector<vector<bool>>& flag){
    if(row_index>=0 && row_index<m && col_index>=0 && col_index<n){
        if(getDigitSum(row_index)+getDigitSum(col_index)<=k && flag[row_index][col_index]==false){
            num++;
            flag[row_index][col_index] = true;
            /* 注意：搜索方向可以缩减为向右和向下 */
            for(int i=2; i<4; ++i){ 
                movingCount_core(m, n, row_index+dir[i][0], col_index+dir[i][1], k, num, flag);
            }
        }
    }
}

int MYBackTracing::movingCount(int m, int n, int k) {
    if(m<1 || n<1 || k<0) return 0;
    vector<vector<bool>> flag(m, vector<bool>(n, false));
    int res=0;
    movingCount_core(m, n, 0, 0, k, res, flag);
    return res;
}