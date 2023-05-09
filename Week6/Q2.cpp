#include <iostream>
#include <time.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int x) {
        //insert data into the top of the stack
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        //remove/delete data from the top of the stack
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
        }
        Node* temp = top;
        top = top->next;
        delete temp; 
    }

    int StackTop() {
        //find what is at the top of the stack
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        //check whether a stack is empty or not
        return (top == NULL);
    }

    void Display() {
        //print elements in the stack
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* curr = top;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    cout<<"Stack implemation using linked-list"<<endl;
    clock_t start = clock();
    Stack newstack;
    newstack.push(8);
    newstack.push(10);
    newstack.push(15);
    newstack.push(11);
    newstack.push(15);
    newstack.push(23);
    newstack.push(6);
    newstack.push(18);
    newstack.push(20);
    newstack.push(17);
    newstack.Display();
    newstack.pop();
    newstack.pop();
    newstack.pop();
    newstack.pop();
    newstack.pop();
    newstack.Display();
    newstack.push(4);
    newstack.push(30);
    newstack.push(3);
    newstack.push(1);
    newstack.Display();
    clock_t end=clock();
    double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
    std::cout << std::endl;
    cout<<" Time taken is "<<time_spent<<endl;
    cout<<"\n";
    return 0;
}
