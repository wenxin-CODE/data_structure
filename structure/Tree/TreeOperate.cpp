#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    // TreeNode(int x, TreeNode *left,nullptr) : val(x), left(left), right(nullptr) {}
    // TreeNode(int x, nullptr,TreeNode *right) : val(x), left(nullptr), right(right) {}
};

// 中序、后序构造二叉树
class inPostTree {
    int post_idx;
    unordered_map<int,int> idx_map;
public:
    TreeNode* helper(int in_left,int in_right,vector<int>& inorder,vector<int>& postorder){
        if(in_left>in_right)
            return nullptr;
        int root_val=postorder[post_idx];
        TreeNode* root=new TreeNode(root_val);

        int index=idx_map[root_val];
        post_idx--;
        root->right=helper(index+1,in_right,inorder,postorder);
        root->left=helper(in_left,index-1,inorder,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post_idx = (int)postorder.size()-1;
        int idx=0;
        for(auto& val:inorder)
            idx_map[val]=idx++;
        return helper(0,(int)inorder.size()-1,inorder,postorder);
    }
};

// 前序、中序构造二叉树
class preInTree {
private:
    unordered_map<int, int> index;

public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        
        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];
        
        // 先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // 得到左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

// 二叉树最大深度
class maxDeep {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

// 相同的树
class sameTree {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        } else if (p->val != q->val) {
            return false;
        } else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};

// 反转二叉树
class fanzhuan {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left=right;
        root->right=left;
        return root;
    }
};

// 对称二叉树
class duichen {
public:
    bool check(TreeNode *p,TreeNode *q){
        if(!p&&!q) return true;
        if(!p||!q) return false;

        return p->val==q->val&&check(p->left,q->right)&&check(p->right,q->left);
    }

    bool isSymmetric(TreeNode* root){
        return check(root,root);
    }
};

// 完全二叉树节点个数
class wanquan {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int level = 0;
        TreeNode* node = root;
        // 统计总共有几层
        while(node->left!=nullptr){
            level++;
            node=node->left;
        }
        // 确定节点数量的范围
        int low=1<<level,high=(1<<(level+1))-1;
        while(low<high){
            // 二分查找
            int mid = (high-low+1)/2+low;
            if(exits(root,level,mid)){
                low=mid;
            }else{
                high=mid-1;
            }
        }
        return low;
    }

    bool exits(TreeNode* root,int level,int k){
        // 从level-1层的第一个结点开始
        int bits=1<<(level-1);
        TreeNode* node = root;
        while(node!=nullptr&&bits>0){
            if(!(bits&k)){
                node = node->left;
            }else{
                node = node->right;
            }
            // 将二进制表示右移一位，去掉最低位
            bits >>= 1;
        }
        return node != nullptr;
    }
};

// 寻找二叉树里面的最大路径
class Solution {
private:
    int maxSum=INT_MIN;
public:
    int maxGain(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        // 
        int leftGain = max(maxGain(node->left),0);
        int rightGain = max(maxGain(node->right),0);
        // 拐弯路径
        int priceNewpath = node->val+leftGain+rightGain;
        maxSum = max(maxSum,priceNewpath);
        // 直上路径
        return node->val+max(leftGain,rightGain);
    }
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};

int main(){
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode();
    TreeNode* node7 = new TreeNode();
    TreeNode* node1 = new TreeNode(2,node4,node6);
    TreeNode* node2 = new TreeNode(3,node7,node5);
    TreeNode* node3 = new TreeNode(1,node1,node2);
    cout<<node3->right->right->val<<endl;
}