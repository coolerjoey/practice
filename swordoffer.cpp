//
// Created by cooler on 20-8-10.
//

/** 
 * 1. 乘除要想到移位，同时注意防止数据溢出
 * 2. 查找替换数组、字符串等带有方向性的操作时要想到改变方向
 * 3. 处理长度不同的字符串时考虑短的字符串剩余部分的处理(先别考虑分段操作)
 * 4. 数组处理时考虑对其下标进行处理
 * 5. 带有方向性的查找中要注意查找方向应该具有单一性
 * 6. 处理一段(数组、字符串、容器...)区间时，应考虑传入位置参数，而不是重新构建
 * 7. 在M*N的矩阵中进行进行长度为K(搜索K长度字符串、序列...)的DFS时间复杂度O(M*N*3^k),空间复杂度(K) https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/mian-shi-ti-12-ju-zhen-zhong-de-lu-jing-shen-du-yo/
 * 8. DFS一般用递归实现，BFS一般用循环加队列实现
 * 9. 找解-回溯法(找一个解-DFS,找所有解-BFS)，找最优解-动态规划
 */

#include "swordoffer.h"
#include "myarray.h"
#include "mystring.h"
#include "MyList.h"
#include "mytree.h"
#include "myqueue.h"
#include "mynum.h"
#include "MYBackTracing.h"
#include "MYDynamicProgramming.h"

/** @brief:  剑指 Offer 03.数组中重复的数字
 *  @task: 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
 *          数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
 */
void swordoffer::test_03(){
    vector<int> input_nums;
    // cout << "输入一个长度为 n 的数组， nums 里的所有数字都在 0～n-1 的范围内，数组中必须有重复的数字,数字间用空格分隔:" << endl;
    // input_nums = io_put::input_numbers();
    // int res = myarray::findRepeatNumber1(input_nums);

    cout << "输入一个长度为 n 的数组， nums 里的所有数字都在 1～n-1 的范围内，数组中必须有重复的数字,数字间用空格分隔:" << endl;
    input_nums = io_put::input_numbers();
    int res = myarray::findRepeatNumber2(input_nums);

    if(res == -1)
        cout << "没有找到重复数字!" << endl;
    else cout << "重复数字: " << res << endl;
}

/** @brief:  剑指 Offer 04.二维数组中的查找
 *  @task: 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 *          请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */
void swordoffer::test_04(){
    vector<vector<int>> matrix = io_put::input_num_matrix();
    cout << "输入要查找的数：" << endl;
    int target = 0;
    cin >> target;
    bool res = myarray::findNumberIn2DArray(matrix, target);
    if(res == false)  cout << "矩阵中没有想要查找的数!" << endl;
    else cout << "矩阵中有想要查找的数" << endl;
}

/** @brief:  剑指 Offer 05.替换空格
 *  @task: 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 */
void swordoffer::test_05(){
    cout << "输入一个字符串" << endl;
    string input_str;
    getline(cin, input_str);
    string output_str = mystring::replaceSpace(input_str);
    cout << "空格替换为%%20: " << output_str << endl;
}

/** @brief:  剑指 Offer 06.从尾到头打印链表
 *  @task: 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
 */
void swordoffer::test_06(){
    ListNode* head = MyList::ListNodeInit(ListTypeCommon);
    vector<int> res = MyList::reversePrint2(head);
    cout << "逆序输出链表值：";
    for(auto val : res){
        cout << val << " ";
    }
}

/** @brief:  剑指 Offer 07.重建二叉树
 *  @task: 输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
 *          假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 */
void swordoffer::test_07(){
    cout << "输入前序遍历序列：";
    vector<int> preorder = io_put::input_numbers();
    cout << "输入中序遍历序列：";
    vector<int> inorder = io_put::input_numbers();
    TreeNode* res = mytree::buildTree2(preorder, inorder);
    mytree::BinaryTreePreOrder(res);
}

/** @brief:  剑指 Offer 09.用两个栈实现队列
 *  @task: 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
 *      分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
 */
void swordoffer::test_09(){
    myqueue my_queue;
    my_queue.appendTail(3);
    my_queue.deleteHead();
    my_queue.deleteHead();
}

/** @brief:  剑指 Offer 10-1.斐波那契数列
 *  @task: 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)
 */
void swordoffer::test_10_1(){
    cout << "输入Fibonacci想求的第几项：" << endl;
    int n;
    cin >> n;
    cout << mynum::Fibonacci_2(n) << endl;
}

/** @brief:  剑指 Offer 10-2.青蛙跳台阶问题
 *  @task: 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
 */
void swordoffer::test_10_2(){
    cout << "输入台阶阶数：" << endl;
    int n;
    cin >> n;
    cout << mynum::Fibonacci_3(n) << endl;
}

/** @brief:  剑指 Offer 11.旋转数组的最小数字
 *  @task: 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 *      输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 *      例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
 */
void swordoffer::test_11(){
    cout << "输入旋转数组：" << endl;
    vector<int> array_input = io_put::input_numbers();
    int res = mynum::minArray(array_input);
    cout << "最小值是 " << res << endl;
}

/** @brief:  剑指 Offer 12.矩阵中的路径
 *  @task: 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
 *      如果 word 存在于网格中，返回 true ；否则，返回 false 。
 *      单词必须按照字母顺序，通过相邻的单元格内的字母构成，
 *      其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 *  @example: [[a,b,c,e],[s,f,c,s],[a,d,e,e]] abcced
 */
void swordoffer::test_12(){
    cout << "输入字母矩阵：" << endl;
    vector<vector<char>> char_matrix = io_put::input_char_matrix();
    cout<<"请输入字符串：";
    string word;
    getline(cin, word);
    bool res =  MYBackTracing::exist(char_matrix, word);
    if(res) cout << "找到目标字符串" <<endl;
    else cout << "没找到目标字符串!" << endl;
}

/** @brief:  剑指 Offer 13.机器人的运动范围
 *  @task: 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
 *      一个机器人从坐标 [0, 0] 的格子开始移动，
 *      它每次可以向左、右、上、下移动一格（不能移动到方格外），
 *      也不能进入行坐标和列坐标的数位之和大于k的格子。
 *      例如，当k为18时，机器人能够进入方格 [35, 37] ，
 *      因为3+5+3+7=18。但它不能进入方格 [35, 38]，
 *      因为3+5+3+8=19。请问该机器人能够到达多少个格子？
 */
void swordoffer::test_13(){
    cout << "输入矩阵行数，列数，K值：" << endl;
    int m, n, k;
    cin >> m >> n >> k;
    int res =  MYBackTracing::movingCount(m, n, k);
    cout << "机器人能到达 " << res <<" 个格子" << endl;
}

/** @brief:  剑指 Offer 14- I. 剪绳子
 *  @task: 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
 *      每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
 *      例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 */
void swordoffer::test_14_1(){
    cout << "输入绳子长度：" << endl;
    int n;
    cin >> n;
    int res =  MYDynamicProgramming::cuttingRope(n);
    cout << "最大乘积是 " << res << endl;
}

/** @brief:  剑指 Offer 15- 二进制中1的个数
 *  @task: 编写一个函数，输入是一个无符号整数（以二进制串的形式），
 *      返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）。
 */
void swordoffer::test_15(){
    cout << "输入一个无符号整数：" << endl;
    uint32_t n;
    cin >> n;
    int res =  mynum::hammingWeight(n);
    cout << "其二进制表达式中数字位数为 '1' 的个数为 " << res << endl;
}

/** @brief:  剑指 Offer 16- 数值的整数次方
 *  @task: 实现 pow(x, n) ，即计算 x 的 n 次幂函数。不得使用库函数，同时不需要考虑大数问题。
 */
void swordoffer::test_16(){
    cout << "输入一个数和幂次方：" << endl;
    double x;
    int n;
    string input;
    getline(cin, input);
    const char *p = input.c_str();
    sscanf(p, "%lf %d", &x, &n);
    double res =  mynum::myPow(x, n);
    cout << "结果为：" << res << endl;
}

/** @brief:  剑指 Offer 17- 打印从1到最大的n位数
 *  @task: 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
 */
void swordoffer::test_17(){
    cout << "输入n：" << endl;
    int n;
    cin >> n;
    vector<string> res =  mynum::printNumbers(n);
}

/** @brief:  剑指 Offer 18-1- 删除链表的节点
 *  @task: 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。
 */
void swordoffer::test_18_1(){
    ListNode* mylist = MyList::ListNodeInit(ListTypeCommon);
    cout << "输入要删除的节点值" << endl;
    int val;
    cin >> val;
    ListNode* res = MyList::deleteNode(mylist, val);
    MyList::printListNode(res);
}

/** @brief:  剑指 Offer 18-2- 删除链表中重复的节点
 *  @task: 在一个排序的链表中，删除重复的节点。
 */
void swordoffer::test_18_2(){
    ListNode* mylist = MyList::ListNodeInit(ListTypeCommon);
    ListNode* res = MyList::DeleteDuplication_2(mylist);
    MyList::printListNode(res);
}

/** @brief:  剑指 Offer 19- 正则表达式匹配
 *  @task: 请实现一个函数用来匹配包含'. '和'*'的正则表达式。
 *      模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
 *      在本题中，匹配是指字符串的所有字符匹配整个模式。
 *      例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
 */
void swordoffer::test_19(){
    string s,p;
    cout<<"输入要匹配的字符串：";
    getline(cin,s);
    cout<<"输入要匹配的正则表达式：";
    getline(cin,p);
    bool res = MYDynamicProgramming::isMatch(s, p);
    cout << "匹配结果：" << res <<endl;
}

// //剑指 Offer 19. 正则表达式匹配
// bool isMatch(string s, string p) {
//     if(s.size()==0 && p.size()==0) return true;
//     if(s.size()!=0 && p.size()==0) return false;
//     if(p[1]=='*'){
//         string p_temp2(p, 2);
//         if(p[0]==s[0] || (p[0]=='.'&&!s.empty())) { //注意：s不能为空
//             string s_temp1(s, 1);
//             return isMatch(s, p_temp2) || //*=0
//                    isMatch(s_temp1, p_temp2) || //*=1
//                    isMatch(s_temp1, p); //*>1
//         }
//         else {
//             return isMatch(s,p_temp2);
//         }
//     }
//     if(p[0]==s[0] || (p[0]=='.'&&!s.empty())){
//         string p_temp(p,1);
//         string s_temp(s,1);
//         return isMatch(s_temp,p_temp);
//     }
//     return false;

// }
// void swordoffer::offer_19_test() {
//     string s,p;
//     cout<<"输入要匹配的字符串：";
//     getline(cin,s);
//     cout<<"输入要匹配的正则表达式：";
//     getline(cin,p);
//     cout<<isMatch(s,p);
// }

// //剑指 Offer 20. 表示数值的字符串
// //是数值： (3.) (.1) (.e1) (1 ) (1  ) (46.e3)
// //不是数值： (.e1) (0e )
// bool isNumber(string s) {
//     bool is_null = false;
//     bool is_posneg = false;
//     bool is_float = false;
//     bool is_e = false;
//     bool is_digit = false;
//     bool is_edigit = false;
//     for(int i=0;i<s.size();i++){
//         if(s[i]=='+'||s[i]=='-'){
//             if((i==0 || (is_null && !is_digit)) && i!=s.size()-1) is_posneg = true;
//             else if(s[i-1]=='e'||s[i-1]=='E');
//             else return false;
//         }
//         else if(s[i]=='e'||s[i]=='E'){
//             if(is_digit && !is_e && i!=0 && i!=s.size()-1)
//                 is_e = true;
//             else return false;
//         }
//         else if(s[i]=='.'){
//             if(!is_float && !is_e)
//                 is_float = true;
//             else return false;
//         }
//         else if(isalpha(s[i]) && (s[i]!='e' || s[i]!='E')){
//             return false;
//         }
//         else if(isdigit(s[i])){
//             if(is_e) is_edigit = true;
//             else is_digit = true;
//         }
//         else if(s[i]==' '){
//             if(!is_posneg && !is_e && !is_float && !is_digit)
//                 is_null = true; //' '在最前面
//             else
//             {
//                 int j=i;
//                 while(j<s.size()){
//                     if(s[j]!=' ') return false;
//                     j++;
//                 }
//             }
//         }
//         else return false;
//     }
//     if(is_digit){
//         if(is_e && is_edigit) return true;
//         if(is_e && !is_edigit) return false;
//         return true;
//     }
//     return false;
// }

// void swordoffer::offer_20_test(){
//     cout<<"请输入要判断的数值字符串：";
//     string str;
//     cin>>str;
//     cout<<isNumber(str);
// }


// //剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
// vector<int> exchange(vector<int>& nums) {
//     int former = 0; //从头向后开始放奇数
//     int later = nums.size()-1; //从后向前放偶数
//     int i=0;
//     while(former<later){
//         if(nums[former]&0x01);  //奇数
//         else{   //偶数
//             while(later>=0 && !(nums[later]&0x01)) later--;
//             if((later == -1) || (later == former-1)) break;
//             int _temp= nums[former];
//             nums[former] = nums[later];
//             nums[later] = _temp;
//         }
//         former++;
//     }
//     for(int i=0;i<nums.size();i++)
//         cout<<nums[i]<<' ';
//     cout<<endl;
//     return nums;
// }

// void swordoffer::offer_21_test(){
//     vector<int> v = io_put::input_numbers();
//     exchange(v);
// }

// //剑指 Offer 22. 链表中倒数第k个节点
// ListNode* getKthFromEnd(ListNode* head, int k) {
//     if(!head) return head;
//     vector<ListNode*> v;
//     ListNode *temp = head;
//     while(temp){
//         v.push_back(temp);
//         temp = temp->next;
//     }
//     if(k>v.size()) return nullptr;
//     return v[v.size()-k];
// }
// void swordoffer::offer_22_test(){
//     ListNode *head = mylist1.ListNodeInit(ListTypeCommon);
//     int n;
//     cout<<"请输入输出倒数第几个节点：";
//     cin>>n;
//     ListNode *p = getKthFromEnd(head,n);
//     mylist1.printListNode(p);
// }


// void swordoffer::offer_23_test(){
//     ListNode *head = mylist1.ListNodeInit(ListTypeCommon);
//     ListNode *p = mylist1.EntryNodeOfLoop(head);
//     if(p) cout<<"链表中环的入口节点是"<<p->val;
//     else cout<<"无环链表";
// }

// //剑指 Offer 25. 合并两个排序的链表
// ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//     if(!l1) return l2;
//     if(!l2) return l1;
//     ListNode *l1_temp = l1;
//     ListNode *l2_temp = l2;
//     ListNode *_temp = new ListNode(0);
//     ListNode *res = _temp;
//     _temp->next = l1;
//     while(l1_temp && l2_temp){
//         if(l2_temp->val<l1_temp->val){
//             _temp->next = new ListNode(l2_temp->val);
//             _temp->next->next = l1_temp;
//             _temp = _temp->next;
//             l2_temp = l2_temp->next;
//         }
//         else {
//             l1_temp = l1_temp->next;
//             _temp = _temp->next;
//         }
//     }
//     if(!l1_temp) _temp->next = l2_temp;
//     return res->next;
// }
// void swordoffer::offer_25_test(){
//     cout<<"请输入两个链表"<<endl;
//     ListNode *l1 = mylist1.ListNodeInit(ListTypeCommon);
//     ListNode *l2 = mylist1.ListNodeInit(ListTypeCommon);
//     cout<<"合并链表是：";
//     mylist1.printListNode(mergeTwoLists(l1,l2));
// }

// //剑指 Offer 26. 树的子结构
// bool isSubStructureCore(TreeNode* A, TreeNode* B){
//     if((!A&&!B) || (A&&!B)) return true;
//     if(!A&&B) return false;
//     if(A->val != B->val) return false;
//     return isSubStructureCore(A->left,B->left) && isSubStructureCore(A->right,B->right);
// }
// //先序遍历找A中和B根节点相同的节点
// bool treePreOrder(TreeNode* root,TreeNode *treefind) {
//     if (!root) return false;
//     bool res = false;
//     if (root->val == treefind->val) {
//         res =  isSubStructureCore(root, treefind);
//     }
//     if(!res)  return treePreOrder(root->left, treefind) || treePreOrder(root->right, treefind);
//     else return res;
// }
// bool isSubStructure(TreeNode* A, TreeNode* B) {
//     if(!A || !B) return false;
//     return  treePreOrder(A,B);
// }

// void swordoffer::offer_26_test(void){
//     cout<<"请输入树A：";
//     TreeNode *A = mytree::TreeNodeInit();
//     cout<<"请输入树B：";
//     TreeNode *B = mytree::TreeNodeInit();
//     cout<<"A包含B的结果："<<isSubStructure(A,B);
// }

// //剑指 Offer 27. 二叉树的镜像
// TreeNode* mirrorTree(TreeNode* root) {
//     if(!root) return root;
//     TreeNode *p=root->left;
//     root->left = mirrorTree(root->right);
//     root->right = mirrorTree(p);
//     return root;
// }
// void swordoffer::offer_27_test(void){
//     cout<<"请输入树：";
//     TreeNode *A = mytree::TreeNodeInit();
//     cout<<"镜像结果：";
//     vector<int> a;vector<string> b;
//     mytree::BinaryTreeLevelOrder(mirrorTree(A),a,b);
// }

// //剑指 Offer 28. 对称的二叉树
// bool isSymmetricCore(TreeNode *A,TreeNode *B){
//     if(!A&&!B) return true;
//     if(!A || !B || A->val!=B->val) return false;
//     return isSymmetricCore(A->left,B->right)&&isSymmetricCore(A->right,B->left);
// }
// bool isSymmetric(TreeNode* root) {
//     if(!root) return true;
//     if(root->left&&!root->right || !root->left&&root->right)
//         return false;
//     return isSymmetricCore(root->left,root->right);
// }
// void swordoffer::offer_28_test(void){
//     cout<<"请输入树：";
//     TreeNode *A = mytree::TreeNodeInit();
//     cout<<"对称结果："<<isSymmetric(A);
// }

// //剑指 Offer 29. 顺时针打印矩阵
// enum dir{
//     left_dir = 0,
//     upper_dir,
//     right_dir,
//     down_dir
// };
// bool isAvaiable(int x,int y,vector<vector<int>>& matrix,dir d,vector<vector<bool>> &flag){
//     switch(d){
//         case left_dir:
//             if(y==0) return false;
//             if(!flag[x][y-1]) return true;
//             return false;
//             break;
//         case upper_dir:
//             if(x==0) return false;
//             if(!flag[x-1][y]) return true;
//             return false;
//             break;
//         case right_dir:
//             if(y==matrix[0].size()-1) return false;
//             if(!flag[x][y+1]) return true;
//             return false;
//             break;
//         case down_dir:
//             if(x==matrix.size()-1) return false;
//             if(!flag[x+1][y]) return true;
//             return false;
//             break;
//     }
// }
// bool pathisnotfinish(int x,int y,vector<vector<int>>& matrix,vector<vector<bool>> &flag){
//     return  isAvaiable(x,y,matrix,left_dir,flag) ||
//             isAvaiable(x,y,matrix,upper_dir,flag) ||
//             isAvaiable(x,y,matrix,right_dir,flag) ||
//             isAvaiable(x,y,matrix,down_dir,flag);
// }
// vector<int> spiralOrder(vector<vector<int>>& matrix) {
//     vector<int> res;
//     if(matrix.size()==0) return res;
//     int n = matrix.size(),m=matrix[0].size();
//     int i=0,j=0;
//     vector<vector<bool>> flag(n,vector<bool>(m,false));
//     while(pathisnotfinish(i,j,matrix,flag)){
//         res.push_back(matrix[i][j]);
//         flag[i][j] = true;
//         if(!isAvaiable(i,j,matrix,left_dir,flag)&&!isAvaiable(i,j,matrix,upper_dir,flag)){
//             if(isAvaiable(i,j,matrix,right_dir,flag)) j+=1;
//             else i+=1;
//         }
//         else if(!isAvaiable(i,j,matrix,upper_dir,flag)&&!isAvaiable(i,j,matrix,right_dir,flag)){
//             if(isAvaiable(i,j,matrix,down_dir,flag)) i+=1;
//             else j-=1;
//         }
//         else if(!isAvaiable(i,j,matrix,right_dir,flag)&&!isAvaiable(i,j,matrix,down_dir,flag)){
//             if(isAvaiable(i,j,matrix,left_dir,flag)) j-=1;
//             else i-=1;
//         }
//         else if(!isAvaiable(i,j,matrix,down_dir,flag)&&!isAvaiable(i,j,matrix,left_dir,flag)){
//             if(isAvaiable(i,j,matrix,upper_dir,flag)) i-=1;
//             else j+=1;
//         }
//     }
//     res.push_back(matrix[i][j]);
//     return  res;
// }
// void swordoffer::offer_29_test(void) {
//     vector<vector<int>> v = io_put::input_num_matrix();
//     cout<<"顺时针打印矩阵："<<endl;
//     vector<int> res =  spiralOrder(v);
//     for(int i=0;i<res.size();i++){
//         cout<<res[i]<<' ';
//     }
// }

// //剑指 Offer 30. 包含min函数的栈
// void swordoffer::offer_30_test(void){
//     MinStack *minStack = new MinStack();
//     minStack->push(-2);
//     minStack->push(0);
//     minStack->push(-3);
//     minStack->min();
//     minStack->pop();
//     minStack->top();
//     minStack->min();
// }

// //剑指 Offer 31. 栈的压入、弹出序列
// bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//     stack<int> stack_push;
//     int p_pop=0;
//     for(int i=0;i<pushed.size();i++){
//         if(stack_push.empty()&&pushed[i]!=popped[p_pop] || pushed[i]!=popped[p_pop]){
//             stack_push.push(pushed[i]);
//         } else if(pushed[i]==popped[p_pop]){
//             p_pop+=1;
//             while(!stack_push.empty() && stack_push.top()==popped[p_pop]){
//                 p_pop+=1;
//                 stack_push.pop();
//             }
//         }
//     }
//     if(stack_push.empty()) return true;
//     return false;

// }
// void swordoffer::offer_31_test(void){
//     cout<<"请输入压栈序列：";
//     vector<int> pushed = io_put::input_numbers();
//     cout<<"请输入出栈序列：";
//     vector<int> poped = io_put::input_numbers();
//     cout<<"入栈出栈匹配结果：";
//     if(pushed.size() != poped.size()){
//         cout<<"false";
//         return;
//     }
//     cout<<validateStackSequences(pushed,poped);
// }

// //剑指 Offer 32 - I. 从上到下打印二叉树
// void swordoffer::offer_32_1_test(void) {
//     cout<<"请输入树：";
//     TreeNode *A = mytree::TreeNodeInit();
//     vector<int> res;vector<string> b;
//     mytree::BinaryTreeLevelOrder(mirrorTree(A),res,b);
//     cout<<"中序遍历结果：";
//     for(auto val:res){
//         cout<<val<<' ';
//     }
// }
// //剑指 Offer 32 - II. 从上到下打印二叉树 II
// struct TreeLayer{
//     int layer;
//     TreeNode *node;
//     TreeLayer(int x,TreeNode *root):layer(x),node(root){}
// };
// vector<vector<int>> levelOrder_2(TreeNode* root) {
//     vector<vector<int>> res;
//     if(!root) return res;
//     queue<TreeLayer> q;
//     q.push(TreeLayer(1,root));
//     while(!q.empty()){
//         TreeLayer p = q.front();
//         q.pop();
//         if(p.layer>res.size()){
//             res.push_back(vector<int>(1,p.node->val));
//         } else{
//             res[p.layer-1].push_back(p.node->val);
//         }
//         if(p.node->left) q.push(TreeLayer(p.layer+1,p.node->left));
//         if(p.node->right) q.push(TreeLayer(p.layer+1,p.node->right));
//         cout<<q.size();
//     }
//     return res;

// }
// void swordoffer::offer_32_2_test(void) {
//     cout<<"请输入树：";
//     TreeNode *A = mytree::TreeNodeInit();
//     vector<vector<int>> res = levelOrder_2(A);
//     cout<<"从上到下打印二叉树 II："<<endl;
//     for(auto v:res){
//         for(auto val:v){
//             cout<<val<<' ';
//         }
//         cout<<endl;
//     }
// }

// //剑指 Offer 32 - III. 从上到下打印二叉树 III
// vector<vector<int>> levelOrder_3(TreeNode* root) {
//     vector<vector<int>> res;
//     if(!root) return res;
//     queue<TreeNode*> q;
//     q.push(root);
//     while(!q.empty()){
//         int len = q.size();
//         vector<int> v;
//         for(int i=0;i<len;i++){
//             TreeNode *p = q.front();
//             v.push_back(p->val);
//             q.pop();
//             if(p->left) q.push(p->left);
//             if(p->right) q.push(p->right);
//         }
//         res.push_back(v);
//     }
//     return res;
// }
// vector<vector<int>> vector_even_reverse(vector<vector<int>> &vec){
//     for(int i=0;i<vec.size();i++){
//         if(i&0x01) reverse(vec[i].begin(),vec[i].end());
//     }
//     return vec;
// }
// void swordoffer::offer_32_3_test(void) {
//     cout<<"请输入树：";
//     TreeNode *A = mytree::TreeNodeInit();
//     vector<vector<int>> res = levelOrder_3(A);
//     vector_even_reverse(res);
//     cout<<"从上到下打印二叉树 III："<<endl;
//     for(auto v:res){
//         for(auto val:v){
//             cout<<val<<' ';
//         }
//         cout<<endl;
//     }
// }

// //剑指 Offer 33. 二叉搜索树的后序遍历序列
// bool verifyPostorderCore(int left,int right,vector<int>& postorder){
//     if(left==right) return true;
//     int rootVal = postorder[right]; //根节点值
//     if(postorder[right-1]<rootVal){ //没有右子树
//         //判断左子树上的值是否都小于根节点
//         if(*max_element(postorder.begin()+left,postorder.begin()+right)<rootVal)
//             return verifyPostorderCore(left,right-1,postorder);
//         return false;
//     } else{
//         int i;
//         for(i=right;i>=left;i--){   //找到左子树和右子树的分界
//             if(postorder[i]<rootVal) break;
//         }
//         if(i<left) return verifyPostorderCore(left,right-1,postorder);  //没有左子树
//         //判断左子树的最大值小于根节点值
//         if(*max_element(postorder.begin()+left,postorder.begin()+i)<rootVal){   //小于
//             return verifyPostorderCore(left,i,postorder)&&verifyPostorderCore(i+1,right-1,postorder);
//         }
//         return false;
//     }
// }
// bool verifyPostorder(vector<int>& postorder) {
//     if(postorder.empty()) return true;
//     int left=0,right=postorder.size()-1;
//     return verifyPostorderCore(left,right,postorder);
// }
// void swordoffer::offer_33_test(void) {
//     cout<<"请输入后续遍历数列：";
//     vector<int> postOrder = io_put::input_numbers();
//     cout<<"该序列是二叉搜索树的结果："<<verifyPostorder(postOrder);
// }

// //剑指 Offer 34. 二叉树中和为某一值的路径
// vector<vector<int>> pathSumCore(TreeNode* root, int sum,vector<vector<int>> &res,vector<int> path,int *p_sum){
//     *p_sum += root->val;
//     path.push_back(root->val);
//     if(!root->left && !root->right){
//         if(*p_sum==sum)
//             res.push_back(path);
//     }
//     if(root->left) pathSumCore(root->left,sum,res,path,p_sum);
//     if(root->right) pathSumCore(root->right,sum,res,path,p_sum);
//     *p_sum -= root->val;
//     path.pop_back();
//     return res;
// }
// vector<vector<int>> pathSum(TreeNode* root, int sum) {
//     int sum_path = 0;
//     vector<int> path;
//     vector<vector<int>> res;
//     if(!root) return res;
//     return pathSumCore(root,sum,res,path,&sum_path);
// }
// void swordoffer::offer_34_test(void) {
//     cout<<"请输入二叉树：";
//     TreeNode *root = mytree::TreeNodeInit();
//     cout<<"请输入路径和sum：";
//     int sum;
//     cin>>sum;
//     vector<vector<int>> path = pathSum(root,sum);
//     cout<<"二叉树路径和等于sum的路径有："<<endl;
//     for(auto v:path) {
//         for (auto val:v)
//             cout << val << ' ';
//         cout<<endl;
//     }

// }

// //剑指 Offer 37. 序列化二叉树
// void swordoffer::offer_37_test(){
//     TreeNode *root = mytree::TreeNodeInit();    //生成二叉树
//     vector<int> resInt;
//     vector<string> resStr;
//     mytree::BinaryTreeLevelOrder(root,resInt,resStr); //序列化 TreeNode->vector<string>
//     cout<<"序列化结果:";
//     for(auto val:resStr)
//         cout<<val<<' ';
//     cout<<endl;
//     root = mytree::TreeNodeInit(resStr); //反序列化vector<string>->TreeNode
//     mytree::BinaryTreeLevelOrder(root,resInt,resStr);
//     cout<<"反序列化二叉树:";
//     for(auto val:resStr)
//         cout<<val<<' ';
//     cout<<endl;

// }

// //剑指 Offer 38. 字符串的排列
// //void permutationCore(vector<char> val,vector<string> &res,queue<string> q){
// //    set<char> s;
// //    for(int i=0;i<val.size();i++){
// //        if(s.count(val[i])==1) continue;
// //        s.insert(val[i]);
// //        if(q.empty()) q.push(to_string(val[i]));
// //        else{
// //            string str = q.front();
// //            q.pop();
// //            str = str+val[i];
// //            vector<char> temp(val.begin())
// //            if(){
// //
// //            }
// //        }
// //    }
// //}

// vector<string> permutation(string s) {
//     vector<char> str_val;
//     for(char val:s){
//         str_val.push_back(val);
//     }
//     vector<string> res;
//     queue<string> q;

// }