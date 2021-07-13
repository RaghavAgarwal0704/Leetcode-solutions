class Solution {
public:
  //recursive
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return NULL;
        TreeNode* left=invertTree(root->left);
        TreeNode* right=invertTree(root->right);
        root->left=right;
        root->right=left;
        return root;
    }
  //iterative-BFS
    TreeNode* invertTree(TreeNode* root){
        queue<TreeNode*>q;
        if(!root)return NULL;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* fr=q.front();
                q.pop();
                if(fr->right)q.push(fr->right);
                if(fr->left)q.push(fr->left);
                TreeNode * temp=fr->left;
                fr->left=fr->right;
                fr->right=temp;
            }
        }
        return root;
    }
};
