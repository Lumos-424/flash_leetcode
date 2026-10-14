#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

ListNode* reverselist(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr){
        ListNode* next = curr->next;
        curr-> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    int n,x;
    while(cin >> n){
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        // 构建链表
        for(int i = 0;  i < n; i++){
            // 将输入的每个数字构建为新的结点
            cin >> x;
            ListNode* node = new ListNode(x);
            if(!head){
                head = tail = node;//1st
            }else{
                tail->next = node;
                tail = node;// 更新tail
            }
        }
        ListNode* res = reverselist(head);
        cout << "[";
        for(ListNode* p = res; p; p->next){
            if(p != res) cout << ',';
            cout << p->val;
        }
        cout << "]";
    }
    return 0;
}
