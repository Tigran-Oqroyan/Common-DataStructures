#include <iostream>
using namespace std;

template <typename T>
class CircularSinglyLinkedList{
    private:
        struct Node{
            T data;
            Node * next;
            Node(T data = T(), Node * next = nullptr) : data(data), next(next)  {}
        };
        int length;
        Node * head;

    public:
        CircularSinglyLinkedList(){
            length = 0;
            head = nullptr;
        }
        ~CircularSinglyLinkedList(){
            clear();
        }

        void clear(){
            while(!empty()){
                pop_front();
            }
        }

        bool empty(){
            return length == 0;
        }

        int get_size(){
            return length;
        }

        void push_back(T data){
            Node * newNode = new Node(data);
            if(!head){
                head = newNode;
                newNode->next = head;
            }else{
                Node * current = head;
                while(current->next != head){
                    current = current->next;
                }
                current->next = newNode;
                newNode->next = head;
            }
            length++;
        }

        void push_front(T data){
            Node * newNode = new Node(data);
            if(!head){
                head = newNode;
                newNode->next = head;
            }else{
                Node * current = head;
                while(current->next != head){
                    current = current->next;
                }

                newNode->next = head;
                current->next = newNode;
                head = newNode;
            }
            length++;
        }

        void pop_front(){
            if(!head){
                throw runtime_error("List is empty");
            }else if(length == 1){
                delete head;
                head = nullptr;
            }else{
                Node * current = head;
                while(current->next != head){
                    current = current->next;
                }
                Node * temp = head;
                head = head->next;
                current->next = head;
                delete temp;
            }
            length--;
        }

        void pop_back(){
            if(!head){
                throw runtime_error("List is empty");
            }else if(length == 1){
                delete head;
                head = nullptr;
            }else{
                Node * current = head;
                while(current->next->next != head){
                    current = current->next;
                }
                delete current->next;
                current->next = head;
            }
            length--;
            
        }

        void insert(int index, T data){
            if(index < 0 || index > length){
                throw out_of_range("Index out of range");
            }
            if(index == 0){
                push_front(data);
            }else if(index == length){
                push_back(data);
            }else{
                Node * prev = head;
                for(int i = 0; i < index - 1; i++ ){
                    prev = prev->next;
                }
                Node * newNode = new Node(data);
                newNode->next = prev->next;
                prev->next = newNode;
                length++;
            }
        }

        void remove_at(int index){
            if(index < 0 || index >= length){
                throw out_of_range("Index out of range");
            }  
            if(index == 0){
                pop_front();
                return;
            }
            Node * current = head;
            for(int i = 0; i < index; i++){
                current = current->next;
            } 
            Node * deleting = current->next;
            current->next = current->next->next;
            delete deleting;
            length--;

        }

        T & at(int index){
            if(index < 0 || index > length){
                throw out_of_range("Index out of range");
            }
            Node * current = head;
            for(int i = 0; i < index; i++){
                current = current->next;
            }
            return current->data;
        }

        void print(){
            if(!head) return ;
            Node * current = head;
            for(int i = 0; i < length; i++){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        int find(T data){
            Node * current = head;
            for(int i = 0; i < length; i++){
                if(current->data == data){
                    return i;
                }
                current = current->next;
            }
            return -1;
        }
};

int main(){
    CircularSinglyLinkedList<int> list;
    list.push_back(11);
    list.push_back(45);
    list.push_back(56);
    list.print();
    list.pop_back();
    list.print();
    list.pop_front();
    list.print();
    list.push_front(77);
    list.push_front(90);
    list.push_front(41);
    list.print();
    cout << list.at(2) << endl; // 77
    cout << list.find(90) << endl; // 1 (index)
}