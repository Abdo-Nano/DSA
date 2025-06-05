#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <climits>


using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int val = 0) {
        this->left = nullptr;
        this->right = nullptr;
        this->val = val;
    }
};

void insert(TreeNode* &root , int val) {
    if(!root) 
    {
        root = new TreeNode(val);
        return; 
    }
    if(root->val > val)
        insert(root->left , val);
    else 
        insert(root->right , val);
}


bool search(TreeNode* &root , int value)
{
    stack<TreeNode*> nodes;
    nodes.push(root);
    while(!nodes.empty())
    {
        TreeNode* node = nodes.top();
        nodes.pop();
        
        if(node->val == value)
            return true;
        if(node->left) nodes.push(node->left);
        
        if(node->right) nodes.push(node->right); 
    }
    return false;

}





void inorder(TreeNode* root)
{
    if(!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}



bool result = true; 

void isBST(TreeNode* root) {
    if (root) {
        int left = (root->left) ? root->left->val : INT_MIN;
        int right = (root->right) ? root->right->val : INT_MAX;

        if (!(root->val < right && root->val > left)) {
            result = false;
            return; 
        }

        isBST(root->left);
        isBST(root->right);
    }


}


void getMiddles(vector<int>& arr , int start , int end , vector<int>& result)
{
    if(start >= end)
        return;

    int mid = start + (end - start) /2 ;
    result.push_back(arr[mid]);
    getMiddles(arr , start , mid , result);
    getMiddles(arr , mid +1 , end , result);
}


void convertArrayToBBST(TreeNode* root , vector<int>& arr)
{
   size_t size = arr.size();
   for(int i = 0 ;i < size ;i++)
   {
        insert(root , arr[i]);
   } 
}



void function(TreeNode* root , int& k , int & value)
{
    if(!root)
        return;
    function(root->left , k , value);
    if(--k == -1)
        {
            value = root->val;
            return;
        }
    function(root->right , k ,value);
}



int main() {

    
    return 0;
}
