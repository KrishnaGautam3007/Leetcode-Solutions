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
class Solution {
public:
    void solve(TreeNode* root, int targetSum,int&sum,vector<int>&temp,vector<vector<int>>&result){
        if(root==NULL){
            return;
        }
        sum=sum+root->val;
        temp.push_back(root->val);
        if((root->left==NULL && root->right==NULL) && sum==targetSum){
            result.push_back(temp);
        }
        solve(root->left,targetSum,sum,temp,result);
        solve(root->right,targetSum,sum,temp,result);
        temp.pop_back();
        sum=sum-root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> result;
       vector<int>temp;
       int sum=0;
       solve(root,targetSum,sum,temp,result);
       return result; 
    }
};