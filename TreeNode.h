#include <iostram>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode():val(0), left(nullptr),right(nullptr) {};
    TreeNode(int x):val(x), left(nullptr),right(nullptr) {};
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {};
};

TreeNode* buildTree(const vector<int> &vals){
    if(vals.empty()) return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while(i < (int)vals.size()){
        TreeNode* node = q.front();
        q.pop();
        if(vals[i] != INT_MIN){
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        i++;
        if(i < (int)vals.size() && vals[i] != INT_MIN){
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}