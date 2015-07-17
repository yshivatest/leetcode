#include<iostream>
#include<climits>
using namespace std;

struct Squeue_node {
    struct Squeue_node *next;
    int val;
    Squeue_node(int x):val{x}, next{NULL} {}
};

struct Squeue {
    // Enqueue at tail, dequeu from head
    struct Squeue_node *head, *tail;
    Squeue():head(NULL), tail(NULL) {}
    void enqueue(int x) {
        struct Squeue_node *temp = new Squeue_node(x);
        if (!head) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    int dequeue() {
        if (!head)
            return INT_MIN;
        if (head == tail) {
            int x = head->val;
            delete head;
            head = tail = NULL;
            return x;
        }
        auto temp = head;
        head = head->next;
        int x = temp->val;
        delete temp;
        return x;
    }
    void print() {
        while(head != tail) {
            cout<<head->val<<"->";
            head = head->next;
        }
        if (head)
            cout<<head->val;
        cout<<endl;

    }
};

int main()
{
    Squeue q;
    cout<<"Enter the num elements\n";
    int cnt;
    cin>>cnt;
    for (int i = 0; i < cnt; i++) {
        int y;
        cin>>y;
        q.enqueue(y);
    }
    q.dequeue();
    q.print();
}
