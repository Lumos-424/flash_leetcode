#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr){}//构造函数初始化为空
};

// 相当于 a + b = b + a去补相互的长度差
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    ListNode *pa = headA, *pb = headB;//最初始的
    while(pa != pb){
        // pa ? 是表示if(pa != nullptr)
        pa = pa ? pa->next : headB;
        pb = pb ? pb->next : headA;
    }
    return pa;
}

int main(){
    // A = 4 -> 1 -> 8 -> 4 -> 5
    // B = 5 -> 6 -> 1 -> 8 -> 4 -> 5
    // 构造相交链表
    ListNode *a1 = new ListNode(4), *a2 = new ListNode(1);
    ListNode *b1 = new ListNode(5), *b2 = new ListNode(6), *b3 =new ListNode(1);
    ListNode *c1 = new ListNode(8), *c2 = new ListNode(4), *c3 = new ListNode(5);

    a1->next = a2;
    a2->next = c1;
    b1->next = b2;
    b2->next = b3;
    b3->next = c1;
    c1->next = c2;
    c2->next = c3;

    ListNode *res = getIntersectionNode(a1,b1);
    if(res){
        cout << "Intersectied at" << res->val << endl;
    }else{
        cout <<"null" << endl;
    }
    return 0;
}