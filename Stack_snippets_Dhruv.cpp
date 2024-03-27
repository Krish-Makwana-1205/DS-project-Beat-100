#include <iostream>
using namespace std;

//Creating stack using array
class stack_array{

    public:
    int top;
    int top1;
    int size;
    int *arr;

    stack_array(int size){
        this -> size =size;
        top = -1;
        arr = new int[size];

    }

    void push(int element){
        if(top1 - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top >=0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    void peek(){
        if(top>=0){
            cout<< arr[top]<<endl;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }

    void empty(){
        if(top == -1){
            cout<< "Stack is empty"<<endl;
        }
        else{
            cout<<"Stack is not empty"<<endl;
        }
    }
};

//Creating stack using linked list
class Node {
public:
    int data;
    Node* link;
   
    Node(int n)
    {
        this->data = n;
        this->link = NULL;
    }
};
 
class Stack_Linked_List {
    Node* top;
 
public:
    Stack_Linked_List() { top = NULL; }
 
    void push(int data)
    {

        Node* temp = new Node(data);
        if (!temp) {
            cout << "Stack Overflow";
            exit(1);
        }
        temp->data = data;

        temp->link = top;

        top = temp;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    int peek()
    {
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }

    void pop()
    {
        Node* temp;

        if (top == NULL) {
            cout << "Stack Underflow" << endl;
            exit(1);
        }
        else {
            temp = top;
 
            top = top->link;

            free(temp);
        }
    }

    void display()
    {
        Node* temp;
 
        if (top == NULL) {
            cout << "Stack Underflow";
            exit(1);
        }
        else {
            temp = top;
            while (temp != NULL) {
 
                cout << temp->data;
 
                temp = temp->link;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};

int main(){
    return 0;
}