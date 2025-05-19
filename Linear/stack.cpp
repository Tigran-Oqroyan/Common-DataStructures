#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T value = T()) : data(value), next(nullptr) {}
    };
    Node *head;

public:
    Stack() : head(nullptr) {}

    bool is_empty()
    {
        return head == nullptr;
    }

    void push(T value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void pop()
    {
        if (head == nullptr)
        {
            throw runtime_error("Stack is empty");
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    T top()
    {
        if (head == nullptr)
        {
            throw runtime_error("Stack is empty");
        }
        return head->data;
    }

    void print_stack()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Stack()
    {
        while (!is_empty())
        {
            pop();
        }
    }
};

int main()
{
    Stack<int> stack;
    stack.push(11);
    stack.push(34);
    stack.push(56);
    stack.print_stack();

    stack.push(67);
    stack.print_stack();
}