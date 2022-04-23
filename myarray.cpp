#include "myarray.h"

myarray::myarray(/* args */)
{
}

myarray::~myarray()
{
}

/* test_03 */
/* 修改了输入数组 */
int myarray::findRepeatNumber1(vector<int>& nums) {
    int res = -1;
    int nums_size = nums.size();
    if(nums_size == 0) return res;
    
    for(int i=0; i<nums_size; ++i){
        if(nums[i]<0 || nums[i]>=nums_size){
            cout << "输入格式有误!";
            return res;
        }
    }

    for(int i=0; i<nums_size; ++i){
        int k=nums[i];
        if(k<0) k+=nums_size;
        if(nums[k]>=0) nums[k]-=nums_size;
        else {
            res=k;
            break;
        }
    }

    return res;
}

int findRepeatNumber2_core(int left, int right, vector<int>& nums){
    int num = 0, mid = (right+left)/2, res=-1; /* 运算符 / 向下取整 */
    for(int i=0; i<nums.size(); ++i){
        if(nums[i]>=left && nums[i]<=mid){
            num++;
        }
    }
    if(num > (mid-left+1)){
        if(left == mid) return left;
        else res = findRepeatNumber2_core(left, mid, nums);
    }else{
        res = findRepeatNumber2_core(mid+1, right, nums);
    }
}

/* 不修改输入数组 */
int myarray::findRepeatNumber2(vector<int>& nums) {
    int res = -1;
    int nums_size = nums.size();
    if(nums_size == 0) return res;
    
    for(int i=0; i<nums_size; ++i){
        if(nums[i]<1 || nums[i]>=nums_size){
            cout << "输入格式有误!";
            return res;
        }
    }

    res = findRepeatNumber2_core(1, nums_size-1, nums);

    return res;
}

/* test_04 */
bool myarray::findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0) return false;
    int col = matrix[0].size();
    int row = matrix.size();
    for(int i=0; i<row; ++i){
        for(int j=col-1; j>=0; --j){
            int temp = matrix[i][j];
            if(temp == target) return true;
            else if(temp > target) continue;
            else break;
        }
    }
    return false;
}