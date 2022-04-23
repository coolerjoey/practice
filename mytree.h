//
// Created by cooler on 20-8-16.
//

#ifndef LEETCODE_MYTREE_H
#define LEETCODE_MYTREE_H

#include <vector>
#include <deque>
#include <queue>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class mytree {
public:
    static void BinaryTreePreOrderCore(TreeNode *root);
    static vector<int> BinaryTreePreOrder(TreeNode *root);
    static vector<int> BinaryTreeInOrder(TreeNode *root);
    static vector<int> BinaryTreePostOrder(TreeNode *root);
    static void BinaryTreeLevelOrder(TreeNode *root,vector<int> &LevelOrderInt,vector<string> &LevelOrderStr);
    static TreeNode* TreeNodeInit(void);
    static TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder);
    static TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder);
    static TreeNode* TreeNodeInit(vector<string> tree);
        private:
//    queue<TreeNode*> tree_queue;
};


#endif //LEETCODE_MYTREE_H
