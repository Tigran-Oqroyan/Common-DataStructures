#include <iostream>
using namespace std;

template <typename T>
class SinglyLinkedList{
    private:
        struct Node{
            Node * next;
            T data;
            Node(T data = T(), Node * next = nullptr){
                this->data = data;
                this->next = next;
            }
        };
        int _size;
        Node * head;

    public:
        SinglyLinkedList(){
            _size = 0;
            head = nullptr;
        }

        ~SinglyLinkedList(){
            clear();
        }
        int get_size(){
            return _size;
        }

        bool is_empty(){
            return _size == 0;
        }

        void push_back(T data){
            if(head == nullptr){
                head = new Node(data);
            }else{
                Node * current = head;
                while(current->next != nullptr){
                    current = current->next;
                }
                current->next = new Node(data);
            }
            _size++;
        }

        void push_front(T data){
            if(head == nullptr){
                head = new Node(data);
            }else{
                Node * newNode = new Node(data);
                newNode->next = head;
                head = newNode;
            }
            _size++;
        }

        void insert(int index, T data){
            if(index == 0){
                push_front(data);
            }else{
                Node * newNode = new Node(data);
                Node * previous = head;
                for(int i = 0;i < index-1; i++){
                    previous = previous->next;
                }
                previous->next = newNode;
            }
        }

        void pop_front(){
            Node * temp = head;
            head = head->next;
            delete temp;
            _size--;
        }

        void pop_back(){
            remove_at(_size-1);
        }

        void remove_at(int index){
            if(index == 0){
                pop_front();
            }else{
                Node * previous = head;
                for(int i = 0; i < index -1; i++){
                    previous = previous->next;
                }
                Node * removeNode = previous->next;
                previous->next = removeNode->next;
                delete removeNode;
            }
            _size--;
        }

        T & at(int index){
            int counter = 0;
            Node * current = head;
            while(current != nullptr){
                if(counter == index){
                    return current->data;
                }
                current = current->next;
                counter++;
            }
            throw out_of_range("Index out of bounds");
        }

        int front(){
            return at(0);
        }

        int back(){
            return at(_size - 1);
        }

        void clear(){
            while(_size){
                pop_front();
            }
        }

        T & operator[](const int index){
            int counter = 0;
            Node * current = head;
            while(current != nullptr){
                if(counter == index){
                    return current->data;
                }
                current = current->next;
                counter++;
            }
            throw out_of_range("Index out of bounds");
        }

        bool contains(T data){
            Node * current = head;
            while(current != nullptr){
                if(current->data == data){
                    return true;
                }
                current = current->next;
            }
            return false;
        }

        void print_list(){
            Node * current = head;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
        }
};

int main(){
    SinglyLinkedList<int> list;
    list.push_back(11);
    list.push_back(45);
    list.push_front(56);
    list.print_list();
    cout << endl;

    cout << list.at(0) << endl;
    cout << endl;
    list.remove_at(0);
    
    list.print_list();
}