// isEmpty
// displya
// enqueue - add element at the rear (end)
// dequeue - remove elemnt from the front
// peek - return front element

#include <iostream>
using namespace std;

template <typename T>
class Queue{
    private:
        struct Node{
            T data;
            Node * next;

            Node(T data = T(), Node * next = nullptr): data(data), next(next) {};
        };
        Node * front;
        Node * rear;
    public:
        Queue(){
            front = rear = nullptr;
        }
        ~Queue(){
            while(!isEmpty()){
                dequeue();
            }
        }

        bool isEmpty(){
            return front == nullptr;
        }

        void enqueue(T data){
            Node * newNode = new Node(data);
            if(rear == nullptr){
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        void dequeue(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return;
            }
            Node * temp = front;
            front = front->next;
            if(front == nullptr){
                rear = nullptr;
            }
            delete temp;
        }

        T peek(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return -1;
            }
            return front->data;
        }

        void display(){
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return;
            }
            Node * current = front;
            while(current){
                cout << current->data << endl;
                current = current->next;
            }
            cout << endl;
        }
};

int main(){
    Queue<int> queue;
    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.display();       // Output: 5 10 15

    cout << "Front element is: " << queue.peek() << endl; // 5
    queue.dequeue();       // Remove 5
    queue.display();       // Output: 10 15
}