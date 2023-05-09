#include <iostream>
#include <time.h>
using namespace std;

class Stack {
private:
    int* stack_arr; 
    int top;  
    int capacity; 

public:
    Stack(int size) {
        //creating a stack with the capacity equal to size
        stack_arr = new int[size];
        capacity = size;
        top = -1;
    }


    void push(int data) {
        //insert data into the top of the stack
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        stack_arr[top] = data;
    }

    void pop() {
        //remove/delete data from the top of the stack
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        top--;
    }

    int StackTop() {
        //find what is at the top of the stack
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return stack_arr[top];
    }

    bool isEmpty() {
        //check whether a stack is empty or not
        return (top == -1);
    }

    bool isFull() {
        //check whethet a stack is full or not
        return (top == capacity - 1);
    }

    void Display() {
        //print elements in the stack
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = 0; i <= top; i++)
            cout << stack_arr[i] << " ";
        cout << endl;
    }
};

int main() {
    cout<<"Stack implemation using array"<<endl;
    clock_t start = clock();
    Stack newstack(15);
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
