// isEmpty
// display
// push
// pop
// peek

#include <iostream>
using namespace std;

template <typename T>
class Stack{
    private:
        struct Node{
            T data;
            Node * next;

            Node(T data = T(), Node * next = nullptr): data(data), next(next){};
        };
        Node * top;

    public:
        Stack(){
            top = nullptr;
        }

        ~Stack(){
            while(!isEmpty()){
                pop();
            }
        }

        bool isEmpty(){
            return top == nullptr;
        }

        void push(int value){
            Node * newNode = new Node(value);
            newNode->next = top;
            top = newNode;
        }

        void pop(){
            if(isEmpty()){
                cout << "Stack is empty" << endl;
                return;
            }
            Node * temp = top;
            top = top->next;
            delete temp;
        }

        T peek(){
            if(isEmpty()){
                cout << "Stack is empty" << endl;
                return -1;
            }
            return top->data;
        }

        void display(){
            if(isEmpty()){
                cout << "Stack is empty" << endl;
                return;
            }

            Node * current = top;
            while(current != nullptr){
                cout << current->data << endl;
                current = current->next;
            }
            cout << endl;
        }
};

int main(){
    Stack<int> stack;
    stack.push(45);
    stack.push(22);
    stack.push(67);
    stack.display();
    cout << "Top element is " << stack.peek() << endl;
    stack.pop();
    cout << "Top element is " << stack.peek() << endl;
}