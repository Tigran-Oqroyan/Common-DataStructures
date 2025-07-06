#include <iostream>
using namespace std;

template <typename T>
class Deque
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
        Node(T data = T(), Node *prev = nullptr, Node *next = nullptr) : data(data), prev(prev), next(next) {}
    };

    Node *front;
    Node *rear;

public:
    Deque()
    {
        front = rear = nullptr;
    }
    ~Deque()
    {
        while (isEmpty())
        {
            dequeueFront();
        }
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueueFront(T data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void enqueueRear(T data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeueFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty";
            return;
        }
        Node *temp = front;
        if (front == rear)
        {
            delete temp;
            front = rear = nullptr;
        }
        else
        {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
    }

    void dequeueRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty";
            return;
        }
        Node *temp = rear;
        if (rear == front)
        {
            delete rear;
            rear = front = nullptr;
        }
        else
        {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
    }

    T getFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty";
            return -1;
        }
        return front->data;
    }

    T getRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty";
            return -1;
        }
        return rear->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is empty";
            return;
        }
        Node *current = front;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Deque<int> deque;

    deque.enqueueRear(10);
    deque.enqueueRear(20);
    deque.enqueueFront(5);
    deque.enqueueFront(1);

    deque.display(); // 1 <-> 5 <-> 10 <-> 20 <-> NULL

    deque.dequeueFront(); // removes 1
    deque.dequeueRear();  // removes 20

    deque.display(); // 5 <-> 10 <-> NULL

    cout << "Front: " << deque.getFront() << endl; // 5
    cout << "Rear: " << deque.getRear() << endl;   // 10

    return 0;
}