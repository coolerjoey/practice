#include "mynum.h"

mynum::mynum(/* args */)
{
}

mynum::~mynum()
{
}

/* https://leetcode-cn.com/problems/xoh6Oh/solution/jian-dan-yi-dong-javac-pythonjs-zheng-sh-e8r6/ */
int mynum::divide(int a, int b){
    if (a == INT_MIN && b == -1) return INT_MAX;

    int sign = (a > 0) ^ (b > 0) ? -1 : 1; /* 异或取符号 */

    uint32_t ua = abs(a);
    uint32_t ub = abs(b);
    
    unsigned int res = 0;

    for(int i=31;i>=0;--i){
        // if(ua-(ub<<i)<0) continue; /* 左移改右移防越界 */
        if((ua>>i) < ub) continue;
        res += (1<<i);
        ua -= (ub<<i);
    }

    return sign == 1 ? res : -res;
}

string mynum::addBinary(string a, string b) {
    string res, long_str, out_str;
    int size_a = a.size(), size_b = b.size();
    int short_len=0, long_len=0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    short_len = ((size_a>size_b)? (res=a, long_str=a, long_len=size_a, size_b) : (res=b, long_str=b, long_len=size_b, size_a));
    int c = 0;
    for(int i=0; i<short_len; ++i){
        int temp = a[i]-'0' + b[i]-'0' + c;
        switch(temp){
            case 0:
                res[i] = '0';
                break;
            case 1:
                res[i] = '1';
                c = 0;
                break;
            case 2:
                res[i] = '0';
                c = 1;
                break;
            case 3:
                res[i] = '1';
                c = 1;
                break;
        }
    }
    for(int i=short_len; i<long_len; ++i){
        int temp = long_str[i]-'0'+c;
        switch(temp){
            case 0:
                res[i] = '0';
                break;
            case 1:
                res[i] = '1';
                c = 0;
                break;
            case 2:
                res[i] = '0';
                c = 1;
                break;
        }
    }
    if(c==1){
        out_str = res+'1';
    }else{
        out_str = res;
    }
    reverse(out_str.begin(), out_str.end());
    cout << out_str;
    return out_str;
}

/* 求 Fibonacci数列第n项 */
/* 动态规划 */
int mynum::Fibonacci_1(int n){
    if(n<=1) return n;
    int res=0;
    int n_1=1, n_2=0;
    for(int i=2; i<=n; ++i){
        res = n_1+n_2;
        n_2 = n_1;
        n_1 = res;
    }
    return res;
}

/* 矩阵幂 */
vector<int> vector_plus(vector<int> a, vector<int> b){
    vector<int> res(a.size(), 0);
    res[0] = a[0]*b[0] + a[1]*b[2];
    res[1] = a[0]*b[1] + a[1]*b[3];
    res[2] = a[2]*b[0] + a[3]*b[2];
    res[3] = a[2]*b[1] + a[3]*b[3];
    return res;
}

vector<int> Fibonacci_2_core(int n){
    vector<int> res(4,0);
    vector<int> init = {1, 1, 1, 0};
    if(n==1) return init;
    if(n%2 == 0){
        res = vector_plus(Fibonacci_2_core(n/2), Fibonacci_2_core(n/2));
    }else{
        res = vector_plus(Fibonacci_2_core((n-1)/2), Fibonacci_2_core((n-1)/2));
        res = vector_plus(res, init);
    }
    return res;
}

int mynum::Fibonacci_2(int n){
    if(n<=1) return n;
    vector<int> res(4,0);
    vector<int> init = {1, 1, 1, 0};

    n -= 1;

    if(n%2 == 0){
        res = vector_plus(Fibonacci_2_core(n/2), Fibonacci_2_core(n/2));
    }else{
        res = vector_plus(Fibonacci_2_core((n-1)/2), Fibonacci_2_core((n-1)/2));
        res = vector_plus(res, init);
    }

    return res[0];
}

/* 矩阵快速幂 */
vector<vector<int>> mul(vector<vector<int>>& a, vector<vector<int>>& b){
    vector<vector<int>> res(2, vector<int>(2,0));
    res[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    res[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    res[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    res[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][15];

    return res;
}


int mynum::Fibonacci_3(int n){
    if(n<=2) return n;
    vector<vector<int>> res = {{1, 1}, {1, 0}};
    vector<vector<int>> temp = {{1, 1}, {1, 0}};
    n -= 1;
    while(n){
        if(n & 1){
            res = mul(res, temp);
        }
        temp = mul(temp, temp);
        n >>= 1;
    }

    return res[0][0];
}

int minArray_core(vector<int>& numbers, int left, int right){
    if(left == right) return numbers[left];
    if(numbers[left] < numbers[right]){
        return numbers[left];
    }
    int mid = (right+left)/2;
    return min(minArray_core(numbers, left, mid), minArray_core(numbers, mid+1, right));
}

int mynum::minArray(vector<int>& numbers) {
    return minArray_core(numbers, 0, numbers.size()-1);
}

int mynum::hammingWeight(uint32_t n) {
    int res = 0;
    while(n){
        ++res;
        n = n&(n-1);
    }
    return res;
}

double mynum::myPow(double x, int n) {
    if(n==0) return 1;
    uint32_t m = n<0?-(uint32_t)n:n;
    double res = 1, temp=(x<0)?-x:x;
    while(m){
        if(m&1){
            res *= temp;
        }
        temp *= temp;
        m >>= 1;
    }
    if(x<0 && n&1) res = -res;
    if(n<0) res = 1/res;
    return res;
}

void printNumbers_cal_carry(char& ch, int add, int& carry){
    if(ch == '9' && (carry==1 || add==1)){
        ch = '0';
        carry = 1;
    }else{
        ch = ch+carry+add;
        carry = 0;
    }
}

string printNumbers_get_string_clz(string str){
    int i=0;
    while(str[i]=='0') i++;
    string temp(str, i);
    return temp;
}

vector<string> mynum::printNumbers(int n) {
    string temp(n+1, '0');
    vector<string> res;
    int carry = 0;
    while(true){
        carry = 0;
        printNumbers_cal_carry(temp[n], 1, carry);
        for(int i=n-1; i>=0; --i){
            printNumbers_cal_carry(temp[i], 0, carry);
        }
        if(temp[0]=='1') break;
        res.push_back(printNumbers_get_string_clz(temp));
    }
    cout << res.size();
    return res;
}