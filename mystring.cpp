#include "mystring.h"

mystring::mystring(/* args */)
{
}

mystring::~mystring()
{
}

/* test_05 */
/* 将字符串中的空格替换为%20  */
string mystring::replaceSpace(string s) {
    int space_num = 0;
    for(int i=0; i<s.size(); ++i){
        if(s[i] == ' ') space_num++;
    }
    int p1=s.size()-1, p2=s.size()-1+2*space_num;
    s += string(2*space_num, ' ');
    while(p1>=0){
        if(s[p1]!=' ') {
            s[p2] = s[p1];
            p2--;
            p1--;
        }else{
            s[p2--] = '0';
            s[p2--] = '2';
            s[p2--] = '%';
            p1--;
        }
    }
    return s;
}