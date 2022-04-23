//
// Created by cooler on 20-8-16.
//

#include "mytree.h"
#include "io_put.h"
#include "MyList.h"

static vector<int> order;

//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树�?
/* assign构建 */
TreeNode *mytree::buildTree1(vector<int> &preorder, vector<int> &inorder) {
    if(preorder.size() == 0){
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[0]);
    
    vector<int> left_preorder, left_inorder, right_preorder, right_inorder;
    vector<int>::iterator index = find(inorder.begin(), inorder.end(), root->val);

    int root_pos = index-inorder.begin();
    left_preorder.assign(preorder.begin()+1, preorder.begin()+root_pos+1);
    left_inorder.assign(inorder.begin(), index);
    right_preorder.assign(preorder.begin()+root_pos+1, preorder.end());
    right_inorder.assign(index+1, inorder.end());
    root->left = buildTree1(left_preorder, left_inorder);
    root->right = buildTree1(right_preorder, right_inorder);
    
    return root;
}

/* 不构建而是传入位置索引，同时使用哈希表存储根节点位�? */
TreeNode* buildTree2_core(vector<int> &preorder, vector<int> &inorder, int left_preorder, int right_preorder, int left_inorder, int right_inorder, unordered_map<int, int>& map){
    if(left_inorder>right_inorder) return nullptr;

    int root_val = preorder[left_preorder];
    TreeNode* root = new TreeNode(root_val);
    int root_pos = map[root_val];

    /* 左子节点个数 */
    int left_node_num = root_pos-left_inorder;

    root->left = buildTree2_core(preorder, inorder, left_preorder+1, left_preorder+left_node_num, left_inorder, root_pos-1, map);
    root->right = buildTree2_core(preorder, inorder, left_preorder+left_node_num+1, right_preorder, root_pos+1, right_inorder, map);

    return root;
}

TreeNode *mytree::buildTree2(vector<int> &preorder, vector<int> &inorder) {
    int num = preorder.size();
    unordered_map<int, int> map;

    for(int i=0; i<inorder.size(); ++i){
        map[inorder[i]] = i;
    }
    
    return buildTree2_core(preorder, inorder, 0, num-1, 0, num-1, map);
}

//先序遍历
void mytree::BinaryTreePreOrderCore(TreeNode *root){
    if(!root) return;
    order.push_back(root->val);
    BinaryTreePreOrderCore(root->left);
    BinaryTreePreOrderCore(root->right);
}
vector<int> mytree::BinaryTreePreOrder(TreeNode *root){
    order.clear();
    BinaryTreePreOrderCore(root);
    cout << "先序遍历�?";
    for(auto val : order){
        cout << val << " ";
    }
    cout << endl;
    return order;
}

//中序遍历
void BinaryTreeInOrderCore(TreeNode *root){
    if(!root) return;
    BinaryTreeInOrderCore(root->left);
    order.push_back(root->val);
    BinaryTreeInOrderCore(root->right);
}
vector<int> mytree::BinaryTreeInOrder(TreeNode *root){
    order.clear();
    BinaryTreeInOrderCore(root);
    return order;
}

//后序遍历
vector<int> mytree::BinaryTreePostOrder(TreeNode *root){

}

//层次遍历
deque<TreeNode*> tree_queue;
//层次遍历返回vector<int>,跳过nullptr
vector<int> BinaryTreeLevelOrderCore(vector<int> &vec){
    TreeNode *p = tree_queue.front();
    tree_queue.pop_front();
    //对p做一些操�?
//    cout<<p->val<<"->";
    vec.push_back(p->val);
    if(p->left) tree_queue.push_back(p->left);
    if(p->right) tree_queue.push_back(p->right);
    if(!tree_queue.empty()) BinaryTreeLevelOrderCore(vec);
    return vec;
}
//层次遍历返回vector<string>,nullptr使用NULL表示
void BinaryTreeLevelOrderCore(vector<string> &vec){
    TreeNode *p = tree_queue.front();
    tree_queue.pop_front();
    //对p做一些操�?
    if(!p) {
        vec.push_back("NULL");
        return;
    }
    else vec.push_back(to_string(p->val));
    tree_queue.push_back(p->left);
    tree_queue.push_back(p->right);

    while(!tree_queue.empty()) { //当双端队列不为空且队列不全为NULL�?
        bool flag = false;
        for(auto val:tree_queue){
            if(val) {
                flag = true;
                break;
            }
        }
        if(flag) BinaryTreeLevelOrderCore(vec);
        else break;
    }
}
void mytree::BinaryTreeLevelOrder(TreeNode *root,vector<int> &LevelOrderInt,vector<string> &LevelOrderStr){
    vector<int> resint;
    vector<string> resstr;
    LevelOrderInt.clear();
    LevelOrderStr.clear();
    if(!root) {
        LevelOrderInt = resint;
        LevelOrderStr = resstr;
        return;
    }
    deque<TreeNode*> q;
    tree_queue = q;
    tree_queue.push_back(root);
    BinaryTreeLevelOrderCore(LevelOrderInt);
    tree_queue.push_back(root); //重新在队列里加入根节�?
    BinaryTreeLevelOrderCore(LevelOrderStr);
}

//输入数组初始化完全二叉树
//n+1表示已加入的结点�?
TreeNode* TreeNodeInitCore(TreeNode *root,int n,vector<int>& nums){
    if(n>nums.size()-1) return nullptr;
    if(2*n+1>nums.size()-1) {
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    else {
        TreeNode *root_left = new TreeNode(nums[2*n+1]);
        root->left = TreeNodeInitCore(root_left,2*n+1,nums);
    }
    if(2*n+2>nums.size()-1) root->right = nullptr;
    else{
        TreeNode *root_right = new TreeNode(nums[2*n+2]);
        root->right = TreeNodeInitCore(root_right,2*n+2,nums);
    }
    return root;
}

//判断是否是NULL字符
bool is_null(string str){
    return (str=="NULL"||str=="null"||str=="N"||str=="n");
}
//输入字符串初始化任意二叉�?->TODO 把flag标记改为队列
void TreeNodeInitCore(TreeNode *root,vector<string>& nodes,int pos,vector<bool> &flag){
    if(nodes.empty()) return;
    root->val = stoi(nodes[pos]);
    vector<TreeNode*> nodeTree(nodes.size(), nullptr);
    nodeTree[pos] = root;
    flag[pos] = true;
    while (pos<nodes.size() && !flag.back()){
        if(is_null(nodes[pos])){
            pos++;
            continue;
        }
        flag[pos] = true;
        int i=pos;
        for(;i<nodes.size();i++){
            if(!flag[i]) break;
        }
        if(is_null(nodes[i])) nodeTree[pos]->left = nullptr;
        else nodeTree[pos]->left = new TreeNode(stoi(nodes[i]));
        nodeTree[i] = nodeTree[pos]->left;
        flag[i] = true;
        if(i+1 == nodes.size()) return;
        if(is_null(nodes[i+1])) nodeTree[pos]->right = nullptr;
        else nodeTree[pos]->right = new TreeNode(stoi(nodes[i+1]));
        nodeTree[i+1] = nodeTree[pos]->right;
        flag[i+1] = true;
        pos++;
    }

}
//TreeNode* mytree::TreeNodeInit(){
//    cout<<"请输入完全二叉树序列，形�? 1 2 3 4 5 6 ，表示如下二叉树�?"<<endl;
//    printf("    1 \n");
//    printf("   / \\ \n");
//    printf("  2   3 \n");
//    printf(" /\\  / \\ \n");
//    printf("4  5 6  NULL\n");
//    vector<int> tree = io_put::input_numbers();
//    if(tree.size()==0) {
//        cout<<"输入是空�?"<<endl;
//        return nullptr;
//    }
//    TreeNode *root = new TreeNode(tree[0]);
//    TreeNodeInitCore(root,0,tree);
////    cout<<"输入二叉树的层次遍历为：";
//    BinaryTreeLevelOrder(root);
//    return root;
//}

bool isNum(string str)
{
    stringstream sin(str);
    double d;
    char c;
    if(!(sin >> d))
    {
        return false;
    }
    if (sin >> c)
    {
        return false;
    }
    return true;
}

TreeNode* mytree::TreeNodeInit(){
    cout<<"请输入二叉树序列，形�? 1 2 3 NULL NULL 4，表示如下二叉树�?"<<endl;
    printf("    1 \n");
    printf("   / \\ \n");
    printf("  2   3 \n");
    printf(" /\\  / \\ \n");
    printf("N  N 4  N\n");
    printf("\"N表示NULL\" \n");
    vector<string> tree = io_put::input_strline_divede();
    TreeNode *root(0);
    if(tree.size()==0 || tree[0]=="NULL"||tree[0]=="null"||tree[0]=="N"||tree[0]=="n") {
        cout<<"输入是空�?"<<endl;
        return nullptr;
    }
    for(auto node:tree){
        if(!isNum(node) && (node!="NULL"&&node!="null"&&node!="N"&&node!="n")){
            cout<<"输入有非法字�?,请输入整数或者NULL/null/N/n表示空字�?"<<endl;
            return root;
        }
    }
    root = new TreeNode(stoi(tree[0]));
    int pos = 0;
    vector<bool> flag(tree.size(), false);
    TreeNodeInitCore(root,tree,pos,flag);
//    cout<<"输入二叉树的层次遍历为：";
    return root;
}

TreeNode* mytree::TreeNodeInit(vector<string> tree){
    TreeNode *root(0);
    if(tree.size()==0 || tree[0]=="NULL"||tree[0]=="null"||tree[0]=="N"||tree[0]=="n") {
        cout<<"输入是空�?"<<endl;
        return nullptr;
    }
    for(auto node:tree){
        if(!isNum(node) && (node!="NULL"&&node!="null"&&node!="N"&&node!="n")){
            cout<<"输入有非法字�?,请输入整数或者NULL/null/N/n表示空字�?"<<endl;
            return root;
        }
    }
    root = new TreeNode(stoi(tree[0]));
    int pos = 0;
    vector<bool> flag(tree.size(), false);
    TreeNodeInitCore(root,tree,pos,flag);
    return root;
}