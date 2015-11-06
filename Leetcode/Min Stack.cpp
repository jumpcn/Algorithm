struct node {
    int val, min;
    node* next;
    node(int a, int b) : val(a), min(b), next(NULL) {}
};

class MinStack {
public:

    node* head;
    MinStack() {
        head = NULL;
    }
    void push(int x) {
        if(head == NULL) {
            head = new node(x, x);
        } else {
            node* temp = new node(x, min(head->min, x));
            temp -> next = head;
            head = temp;
        }
    }

    void pop() {
        if(head == NULL) return;
        node* temp = head;
        head = head->next;
        delete temp;
        
    }

    int top() {
        return head == NULL ? 0 : head -> val;
    }

    int getMin() {
        return head == NULL ? 0 : head -> min;
    }
};
