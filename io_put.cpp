//
// Created by cooler on 20-8-18.
//

#include "io_put.h"

//（1）输入一个数字再加上空格间隔的数组：
void io_put::input_num_array() {
    int num;
    cin >> num;
    int *arr = new int[num + 1];
    for (int i = 0; i <= num; i++) {
        cin >> arr[i];
    }
}

/*
 * 输入形如矩阵n维数，然后按行输入矩阵元素
 * 2
 * 1 2
 * 3 4
 * */
vector<vector<int>> io_put::input_num_matrix() {
    cout<<"请输入方阵维数：";
    int n;
    cin>>n;
    cout<<"按行输入矩阵："<<endl;
    vector<vector<int>> v(n,vector<int>(n,0));
    int i=0,j=0;
    while(i<n){
        for(;j<n;j++){
            cin>>v[i][j];
        }
        i++;
        j=0;
    }
    return v;
}

//输入任意个数的数字
//https://www.cnblogs.com/maples7/archive/2015/05/21/4519431.html
vector<int> io_put::input_numbers(){
    cout<<"请输入整数数组：";
    string str;
    getline(cin,str);
    int str_size = str.size();
    const char *p = str.c_str();
    vector<int> v;
    int num;
    while (*p != 0) //当p指向空字符(null)退出
    {
        // 过滤空格与缩进
        while (*p == ' ' || *p == '\t' || *p == ',') p++;
        // 读整数
        if (sscanf(p, "%d", &num) != 0){
            v.push_back(num);
            //计算p需要位移的长度
            int i=1;
            int _temp = abs(num);
            while(_temp/10){
                i++;
                _temp /= 10;
            }
            if(num<0) i++;
            p += i;
        }
        else {
            cout<<"输入含非法数字"<<endl;
            break;
        }
    }

//    char buffer[1024]={NULL};
//    char* p = buffer;
//    vector<int> v;
//    int num;
//    cin.get(buffer,sizeof(buffer));
//    while (*p != 0) //当p指向空字符(null)退出
//    {
//        // 过滤空格与缩进
//        while (*p == ' ' || *p == '\t') p++;
//        // 读整数
//        if (sscanf(p++, "%d", &num) != 0){
//            v.push_back(num);
//        }
//        else {
//            cout<<"输入含非法数字"<<endl;
//            break;
//        }
//    }
    cout<<"输入的数字序列为：";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
    return v;
}

/*
 * isalpha()用来判断一个字符是否为字母，如果是字符则返回非零，否则返回零。
 * isalnum()用来判断一个字符是否为数字或者字母，也就是说判断一个字符是否属于a~z||A~Z||0~9
 * islower()用来判断一个字符是否为小写字母，也就是是否属于a~z。
 * isupper()和islower相反，用来判断一个字符是否为大写字母。
 * tolower()函数是把字符串都转化为小写字母
 * toupper()函数是把字符串都转化为小写字母
 * */
//读入[['A','B'],['C','D']]这样的字符矩阵
vector<vector<char>> io_put::input_char_matrix(){
    stack<char> s;
    vector<vector<char>> vec;
    vector<char> v;
    char c;
    cout<<"请输入字符矩阵，格式如[[\"a\",\"b\"],[\"c\",\"d\"]]"<<endl;
    while(cin.get(c) && c!='\n'){
        if(c=='[') s.push(c);
        else if(c==']') {
            if (s.size() > 1) {   //去除最后一个]
                vec.push_back(v);
                v.clear();
                s.pop();
            }
        }
//        else if(('a'<=c && c<='z') || ('A'<=c && c<='Z')){ //不能用'a'<=c<='z'
        else if(isalpha(c)){
            v.push_back(c);
        }
    }
    cout<<"输入的字符矩阵为："<<endl;
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[0].size();j++){
            cout<<vec[i][j]<<' ';
        }
        cout<<endl;
    }
    return vec;
}

//输入数字n,然后输入n个数字。可进行多组输入，以单行换行结束
/* 输入：
 * 1
 * 2
 * 10
 * 15
 * 20
 * 32
 * 40
 * 67
 * 89
 * 300
 * 400
 *
 * 输出：[[2],[15,20,32,40,67,89,300,400]]
 * */
vector<vector<int>> io_put::input_multi_n_array(){
    int n;
    vector<vector<int>> vec;
    string str;
    while(getline(cin,str)){
        if(str=="") break;
        vector<int> v;
        n = stoi(str);
        int a;
        for(int i=0;i<n;i++){
            cin>>a;
            v.push_back(a);
        }
        vec.push_back(v);
        cin.ignore(1);  //忽略最后cin的换行，为什么会在cin缓冲区内？
    }
};

//输入一行字符串，以 空格符/tab 分割每个子字符串
vector<string> io_put::input_strline_divede(){
    string str;
    cout<<"请输入一行字符串：";
    vector<string> res;
    getline(cin,str);
    const char *p = str.c_str();
    char s[100];
    while(*p) {
        while (*p == ' ' || *p == '\t') p++;
        if(sscanf(p, "%s", s)) {    //Note:此处不能用char *去读取!  原因:TODO
            string _temp = s;
            res.push_back(_temp);
            p += _temp.size();
        }
    }
    return res;
}
