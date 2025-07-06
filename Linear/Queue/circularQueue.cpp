// isEmpty
// display
// enqueue
// dequeue
// peek

#include <iostream>
using namespace std;

template <typename T>
class CircularQueue{
    private:
        struct Node{
            T data;
            Node * next;
            Node(T data = T(), Node * next = nullptr): data(data), next(next){}        
        };

        Node * front;
        Node * rear;

    public:
        CircularQueue(){
            front = rear = nullptr;
        }
        ~CircularQueue(){
            while(!isEmpty()){
                dequeue();
            }
        }

        bool isEmpty() {
            return front == nullptr;
        }

        void enqueue(T value){
            Node * newNode = new Node(value);
            if(isEmpty()){
                front = rear = newNode;
                rear->next = front;
            }else{
                rear->next = newNode;
                rear = newNode;
                newNode->next = front;
            }
        }

        void dequeue(){
            if(isEmpty()){
                cout << "Circular Queue is empty" << endl;
                return;
            }
            if(front == rear){
                delete front;
                front = rear = nullptr;
            }else{
                Node * temp = front;
                front = front->next;
                rear->next = front;
                delete temp;
            }
        }

        T peek(){
            if(isEmpty()){
                cout << "Circular Queue is empty" << endl;
                return -1;
            }
            return front->data;
        }

        void display(){
            if(isEmpty()){
                cout << "Circular Queue is empty" << endl;
                return;
            }
            Node * current = front;
            do{
                cout << current->data << " ";
                current = current->next;
            }while(current != front);
            cout << endl;
        }
};

int main() {
    CircularQueue<int> circular_queue;

    circular_queue.enqueue(10);
    circular_queue.enqueue(20);
    circular_queue.enqueue(30);
    circular_queue.display();     // 10 20 30

    circular_queue.dequeue();     // Removes 10
    circular_queue.display();     // 20 30

    circular_queue.enqueue(40);
    circular_queue.enqueue(50);
    circular_queue.display();     // 20 30 40 50

    cout << "Front: " << circular_queue.peek() << endl;

    return 0;
}