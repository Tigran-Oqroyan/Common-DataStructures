// isEmpty
// displya
// enqueue - add element at the right place
// dequeue 
// peek 

#include <iostream>
using namespace std;

template <typename T>
class PriorityQueue{
    private:
        struct Node{
            T data;
            int priority;
            Node * next;

            Node(T data = T(), int priority = 1, Node * next = nullptr): data(data), next(next), priority(priority) {};
        };
        Node * front;

    public:
        PriorityQueue(){
            front = nullptr;
        }
        ~PriorityQueue(){
            while(!isEmpty()){
                dequeue();
            }
        }

        bool isEmpty(){
            return front == nullptr;
        }

        void enqueue(T data, int priority){
            Node * newNode = new Node(data, priority, nullptr);
            
            if(isEmpty() || priority > front->priority){
                newNode->next = front;
                front = newNode;
            } else {
                Node * current = front;
                while(current->next != nullptr && current->next->priority >= priority){
                    current = current->next;
                }

                newNode->next = current->next;
                current->next = newNode;
            }
        }

        void dequeue(){
            if(isEmpty()){
                cout << "Priority Queue is empty" << endl;
                return;
            }
            Node * temp = front;
            front = front->next;
            delete temp;
        }

        T peek(){
            if(isEmpty()){
                cout << "Priority Queue is empty" << endl;
                return -1;
            }
            return front->data;
        }

        void display(){
            if(isEmpty()){
                cout << "Priority Queue is empty" << endl;
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
    PriorityQueue<int> priority_queue;

    priority_queue.enqueue(10, 2); // lower priority
    priority_queue.enqueue(5, 5);  // highest priority
    priority_queue.enqueue(20, 1); // lowest priority
    priority_queue.enqueue(15, 3); // medium priority

    priority_queue.display(); // 5 15 10 20

    priority_queue.dequeue(); // removes 5 (priority 5)
    priority_queue.display(); // 15 10 20
}