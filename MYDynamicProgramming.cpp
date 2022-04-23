#include "MYDynamicProgramming.h"

/* 减绳子，要求减出的长度乘积最大 */
int MYDynamicProgramming::cuttingRope(int n){
    if(n<1) return 0;
    if(n<4) return n-1;
    vector<int> dp(n+1,0);
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4; i<=n; ++i){
        for(int j=2; j<=i/2; ++j){
            int max = dp[j]*dp[i-j];
            if(max>dp[i]) dp[i]=max;
        }
    }
    return dp[n];
}

/* 匹配正则表达式 */
bool MYDynamicProgramming::isMatch(string str, string pattern) {

}