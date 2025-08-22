

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* outputList = new ListNode();
    ListNode* returnNode = outputList;
    int carry = 0;


    // NOTE: would have been a little nicer to do a do while
    while (l1 != nullptr || l2 != nullptr || carry != 0){
        // will always need a next because loop conditions verify that
        if (l1 == nullptr && l2 != nullptr){
            outputList->val = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
        } else if (l1 != nullptr && l2 == nullptr){
            outputList->val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
        } else if (l1 != nullptr && l2 != nullptr){
            outputList->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
        } else {
            outputList->val = carry;
            carry = 0;
        }
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
        if (carry != 0 || (l1 != nullptr || l2 != nullptr)){
            outputList->next = new ListNode();
            outputList = outputList->next;
        }
    }

    return returnNode;
}

int main(){
    int l1Arr[] = {2,4,3};
    int l2Arr[] = {5,6,4};
    ListNode* l1 = new ListNode(l1Arr[0]);
    l1->next = new ListNode(l1Arr[1]);
    l1->next->next = new ListNode(l1Arr[2]);
    ListNode* l2 = new ListNode(l2Arr[0]);
    l2->next = new ListNode(l2Arr[1]);
    l2->next->next = new ListNode(l2Arr[2]);
    addTwoNumbers(l1,l2);
    return 0;
}