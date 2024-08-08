class MyLinkedList {
public:
    int size = 0;
    ListNode* head = new ListNode(0);
    MyLinkedList() {

    }
    
    int get(int index) {
        if(index >= size) return -1;
        ListNode* temp = head->next;
        for(int i=0; i<index; i++) temp=temp->next;
        return temp->val;
    }
    
    void addAtHead(int val) {
        ListNode* temp = head->next;
        head->next = new ListNode(val);
        head->next->next = temp;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = new ListNode(val);
        size++;
    }

    void addAtIndex(int index, int val) {
        if(index > size) return;
        ListNode* temp = head;
        for(int i=0; i < index; i++) temp = temp->next;
        ListNode* temp1 = temp->next;
        temp->next = new ListNode(val);
        temp->next->next = temp1;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) return;
        ListNode* temp = head;
        for(int i=0; i < index; i++) temp = temp->next;
        ListNode* temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next = NULL;
        size--;
        delete temp1;
    }
};
