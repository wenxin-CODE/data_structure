#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 判断是否有环
class huan {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=nullptr){
            fast = fast->next;
            if(fast!=nullptr){
                fast = fast->next;
            }
            if(fast == slow){
                return true;
            }
            slow = slow->next;
        }
        return false;
    }
};

int main(){
    return 0;
}