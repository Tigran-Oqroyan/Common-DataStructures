#include <iostream>
using namespace std;

template <typename T>
class CircularDoublyLinkedList{
    private:
        struct Node{
            T data;
            Node * next;
            Node * prev;
            Node(T data = T(), Node * next = nullptr, Node * prev = nullptr) : data(data), next(next), prev(prev) {}
        };
        int length;
        Node * head;
        Node * tail;

        Node * getNode(const int index){
            if(index < 0 || index >=length){
                throw out_of_range("Index out of range");
            }
            Node * temp;
            if(index < length/2){
                temp = head;
                for(int i = 0; i < index; i++){
                    temp = temp->next;
                }
            }else{
                temp = tail;
                for(int i = length-1; i > index; i--){
                    temp = temp->prev;
                }
            }
            return temp;
        }

    public:
        CircularDoublyLinkedList(){
            length = 0;
            head = nullptr;
            tail = nullptr;
        }
        ~CircularDoublyLinkedList(){
            clear();
        }
        bool empty() const{
            return length == 0;
        }
        int size() const {
            return length;
        }
        void clear(){
            while(!empty()){
                pop_front();
            }
        }
        void push_back(T data){
            Node * newNode = new Node(data);
            if(!tail){
                head = tail = newNode;
                newNode->next = head;
                newNode->prev = tail;
            }else{
                newNode->prev = tail;
                newNode->prev = head;
                head->prev = newNode;
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        void push_front(T data){
            Node * newNode = new Node(data);
            if(!head){
                head = tail = newNode;
                newNode->next = head;
                newNode->prev = tail;
            }else{
                newNode->next = head;
                newNode->prev = tail;
                tail->next = newNode;
                head->prev = newNode;
                head = newNode;   
            }
            length++;
        }

        void insert(int index, T data){
            if(index < 0 || index > length){
                throw out_of_range("Index out of bounds");
            }
            if(index == 0){
                push_front(data);
            }else if(index == length){
                push_back(data);
            }else{
                Node * currentNode = getNode(index);
                Node * newNode = new Node(data);

                newNode->next = currentNode->next;
                newNode->prev = currentNode;
                currentNode->next->prev = newNode;
                currentNode->next = newNode;
                length++;
            }
        }
        
        void pop_front(){
            if(empty()){
                throw runtime_error("List is empty");
            }
            if(length == 1){
                delete head;
                head = nullptr;
                tail = nullptr;
            }else{
                Node * temp = head;
                head = head->next;
                head->prev = tail;
                delete temp;
            }
            length--;
        }

        void pop_back(){
            if(empty()){
                throw runtime_error("List is empty");
            }
            if(length == 1){
                delete tail;
                head = nullptr;
                tail = nullptr;
            }else{
                Node * temp = tail;
                tail = tail->prev;
                tail->next = head;
                delete temp;
            }
            length--;
        }

        void remove_at(int index){
            if(index < 0 || index >= length){
                throw out_of_range("Index out of range");
            }
            if(index == 0){
                pop_front();
            }else if(index == length - 1){
                pop_back();
            }else{
                Node * nodeToDelete = getNode(index);
                nodeToDelete->prev->next = nodeToDelete->next;
                nodeToDelete->next->prev = nodeToDelete->prev;
                delete nodeToDelete;
                length--;
            }
        }

        void print_forward() const{
            Node * current = head;
            for(int i = 0; i < length; i++){
                cout << current->data << " ";
                current= current->next;
            }
            cout << endl;
        }

        void print_backward() const{
            Node * current = tail;
            for(int i = length-1; i >= 0; i--){
                cout << current->data << " ";
                current = current->prev;
            }
            cout << endl;
        }

        T & at(int index) const{
            Node * node = getNode(index);
            return node->data;
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
    CircularDoublyLinkedList<int> list;
    list.insert(0, 56);
    list.insert(1, 11);
    list.print_backward();
}