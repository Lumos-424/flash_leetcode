#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};
//快慢指针，若有环快指针始终会追上慢指针
bool hasCycle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

int main(){
    //构造环形链表
    int n, pos;//pos为尾部连到的下标
    vector<ListNode*> nodes;

    //或者硬性写死一个环形链表用例
    while(cin >> n >> pos){
        for(int i = 0; i + 1 < n; i++){
            int x;
            cin >> x;
            nodes.push_back(new ListNode(x));
        }
        for(int i = 0; i + 1 < n; i++){
            nodes[i]->next = nodes[i +1];
        }
        if(pos >= 0 && pos < n){
            nodes[n - 1]->next = nodes[pos];
        }
        ListNode* head = nodes.empty()? nullptr:nodes[0];
        cout << (hasCycle(head)?"true":"false") << endl;
    }
    return 0;

}