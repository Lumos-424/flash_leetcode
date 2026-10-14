#include <iostream>
using namespace std;

// 快慢指针找中点，然后反转链表判对称
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

bool isPalindrome(ListNode* head){
    if( !head || !head->next) return true;

    // fast到头则slow恰好在中点
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    //反转以slow作为head的链表
    ListNode* prev = nullptr;
    ListNode* curr = slow;
    while(curr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    //比较前半和后半
    ListNode* p1 = head;
    ListNode* p2 = prev;//此时这个是反转后的头
    while(p2){
        if(p1->val != p2->val)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

int main(){
    int x,n;
    while(cin >> x){
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        for(int i = 0; i < n; i++){
            ListNode* node = new ListNode(x);
            if(!head) head = tail = node;
            else{
                tail->next = node;
                tail = node;
            }
        }
        cout << (isPalindrome(head) ? "true" : "false") << endl;
    }
}