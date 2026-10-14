#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

// i的左孩是2i+1, 右孩是2i+2
// 中序遍历：先访问左子树，访问根节点(倒回上一层），再访问右子树

//构建二叉树
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

//迭代法
vector<int> inorderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;

    while(cur != nullptr || !st.empty()){
        //一路向左，把沿途节点全部压栈
        while(cur != nullptr){
            st.push(cur);
            cur = cur ->left;
        }
        cur = st.top(); //弹出栈顶，此时左子树已经处理完
        st.pop();
        res.push_back(cur->val);//访问根
        cur = cur->right;// 转向右子树
    }
    return res;
}

int main(){
    string line;
    getline(cin, line);
    //去掉首尾的[]
    line = line.substr(1, line.size() - 2);
    vector<int> vals;
    stringstream ss(line);
    string item;
    while(getline(ss, item, ',')){
        if(item == "null" || item == "null"){
            vals.push_back(INT_MIN);
        }else{
            vals.push_back(stoi(item));
        }
    }

    TreeNode* root  = buildTree(vals);
    vector<int> res = inorderTraversal(root);
    cout << "[";
    for(int i = 0; i < (int)res.size(); i++){
        if(i) cout << ',';
        cout << res[i];
    }
    cout << "]" << endl;
    return 0;
}