/* 
 * 1. 乘除要想到移位，同时注意防止数据溢出
 * 2. 循环时要想到改变方向
 * 3. 处理长度不同的字符串时考虑短的字符串剩余部分的处理(先别考虑分段操作)
 */

#include "leetcode_offer.h"
#include "mynum.h"

using namespace std;

leetcode_offer::leetcode_offer(/* args */)
{
}

leetcode_offer::~leetcode_offer()
{
}

/* @task 整数除法 
 * @req 给定两个整数 a 和 b ，求它们的除法的商 a/b ，要求不得使用乘号 '*'、除号 '/' 以及求余符号 '%' 
 */
void leetcode_offer::test_1(){
    int a, b;
    cout << "输入除数和被除数，用空格分隔: " << endl;
    cin >> a >> b;
    mynum::divide(a, b);

}

/* @task 二进制加法
 * @req  给定两个 01 字符串 a 和 b ，请计算它们的和，并以二进制字符串的形式输出。输入为 非空 字符串且只包含数字 1 和 0。
 */
void leetcode_offer::test_2(){
    string a, b;
    cout << "输入两个只含01的字符串，用换行分隔: " << endl;
    getline(cin, a);
    getline(cin, b);
    mynum::addBinary(a, b);
}