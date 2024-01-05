/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Node{
    public:
    bool isBST;
    int mn,mx;
    int sum;
    Node(){
        isBST=true;
        mn=INT_MAX;
        mx=INT_MIN;
        sum=0;
    }
};
class Solution {
public:
    int ans=0;
    Node help(TreeNode* root){
        if(!root){
            return Node();
        }
        Node l=help(root->left);
        Node r=help(root->right);
        Node cur;
        if(l.isBST && r.isBST && root->val>l.mx && root->val<r.mn){
            cur.isBST=true;
            cur.sum=l.sum+r.sum+root->val;
            cur.mn=min(root->val,l.mn);
            cur.mx=max(root->val,r.mx);
        }
        else{
            cur.isBST=false;
            cur.sum=max(l.sum,r.sum);
        }
        ans=max(ans,cur.sum);
        return cur;
    }
    int maxSumBST(TreeNode* root) {
        help(root);
        return ans;
    }
};
