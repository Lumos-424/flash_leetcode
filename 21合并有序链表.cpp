#include <ListNode.h>

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while( l1 && l2){
        if(l1->val <= l2->val){
            tail->next = l1;//取小的那个
            l1 = l1->next;
        }else{
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* buildList(){
    int n,x;//n个元素，逐个读入是x
    cin >> n;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int i = 0; i < n; i++){
        cin >> x;
        ListNode* node = new ListNode(x);
        if(!head) head = tail = node;
        else{
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

int main(){
    ListNode* l1 = buildList();
    ListNode* l2 = buildList();

    ListNode* res = mergeTwoLists(l1, l2);
    cout << "[";
    for(ListNode* p = res; p; p = p->next){
        if(p != res)//第一个元素前不加 ,
            cout << ",";
        cout << p->val;
    }
    cout << "]";
    return 0;
}