#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList{
    private:
        struct Node{
            Node * next;
            Node * prev;
            T data;
            Node(T value = T()) : next(nullptr), prev(nullptr), data(value){}
        };

        Node * head;
        Node * tail;
        int length;

        Node * getNode(const int index){
            if(index < 0 || index >= length){
                throw out_of_range("Index out of range");
            }   
            Node * temp;
            if(index < length / 2){
                temp = head;
                for(int i = 0;  i < index; i++){
                    temp = temp->next;
                }
            }else{
                temp = tail;
                for(int i = length - 1 ; i > index; i--){
                    temp = temp->prev;
                }
            }
            return temp;
        }
    public:
        DoublyLinkedList(){
            length = 0;
            head = nullptr;
            tail = nullptr;
        }

        ~DoublyLinkedList(){
            clear();
        }

        void clear(){
            if(length){
                pop_front();
            }
        }

        int get_size(){
            return length;
        }

        bool empty(){
            return length == 0;
        }

        void print_forward(){
            Node * current = head;
            while(current !=nullptr){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        void print_backward(){
            Node * current = tail;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->prev;
            }
            cout << endl;
        }

        void push_front(T data){
            Node * newNode = new Node(data);
            if(head == nullptr){
                head = tail = new Node(data);
            }else{
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        void push_back(T data){
            Node * newNode = new Node(data);
            if( tail == nullptr){
                head = tail = newNode;
            }else{
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        void pop_front(){
            if(length == 0){
                cout << "Linked List is empty" << endl;
                return;
            }
            if(length == 1){
                delete head;
                head = nullptr;
                tail = nullptr;
            }else{
                Node * temp = head;
                head = head->next;
                head->prev = nullptr;
                delete temp;
            }
            length--;
        }

        void pop_back(){
            if(length == 0){
                cout << "Linked List is empty" << endl;
                return;
            }
            if(length == 1){
                delete tail;
                tail = nullptr;
                head = nullptr;
            }else{
                Node * temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
            length--;
        }

        void insert(const int index, T data){
            if(index < 0 || index > index){
                throw out_of_range("Index out of range");
            }
            if(index == 0){
                push_front(data);
            }else if(index == length){
                push_back(data);
            } else {
                Node * currentNode = getNode(index);
                Node * newNode = new Node(data);

                newNode->next = currentNode->next;
                newNode->prev = currentNode;

                currentNode->next->prev = newNode;
                currentNode->next = newNode;
            }
            length++;
        }

        void remove_at(const int index){
            if(index < 0 || index >= length){
                throw out_of_range("Index out of range");
            }
            if(index == 0){
                pop_front();
            }else if(index == length - 1){
                pop_back();
            }else{
                Node * nodeToDelete = getNode(index);
                Node * prev = nodeToDelete->prev;
                Node * next = nodeToDelete->next;
                prev->next = next;
                next->prev = prev;
                delete nodeToDelete;
            }
            length--;
        }

        T & operator[](const int index){
            if(index < 0 || index >= length){
                throw out_of_range("Index out of bounds");
            }else{
                Node * node = getNode(index);
                return node->data;
            }
        }

        T & at(const int index){
            if(index < 0 || index >= length){
                throw out_of_range("Index out of bounds");
            }else{
                Node * node = getNode(index);
                return node->data;
            }
        }
};

int main(){
    cout << "Hi from doubly linked list" << endl;
    DoublyLinkedList<int> list;
    list.push_back(12);
    list.push_back(34);
    list.insert(2, 123);
    list.print_forward();
    list.print_backward();
    cout << list.at(2) << endl;
    cout << list.at(2) << endl;
}