#include <iostream>
#include <queue>

#include <TreeNode.h>

using namespace std;

class Solution{
public:
    //递归法
    // int maxDepth(TreeNode* root){
    //     if(root == nullptr) return 0;//递归终止条件
    //     int left_d = maxDepth(root->left);//搜索左侧
    //     int right_d = maxDepth(root->right);//搜索右侧
    //     return max(left_d, right_d) + 1;//根节点自身算一层
    // }

    // 迭代法
    int maxDepth(TreeNode* root){
        if(root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while(!q.empty()){
            int size = q.size();//当前层的结点数
            while(size--){ 
                TreeNode* node = q.front();
                q.pop();//清空当前层
                //新的下一层入队（根据size遍历了每个结点）
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            depth++;//相当于处理一层，深度+1
        }
        return depth;
    }
}

int main(){
    string line;
    getline(cin, line);
    line = line.substr(1, line.size() - 2);
    
    vector<int> vals;
    stringstream ss(line);
    string item;
    while(getlines(ss, item, ',')){
        if(item == "null" || item == "null"){
            vals.push_back(INT_MIN);
        }else{
            vals.push_back(stoi(item));
        }
    }
    TreeNode* root = buildTree(vals);
    Solution sol;
    cout << sol.maxDepth(root) << endl;
    return 0;
}