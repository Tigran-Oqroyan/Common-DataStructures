#include <iostream>
using namespace std;

template <typename T>
class SinglyLinkedList{
    private:
        struct Node{
            Node * next;
            T data;
            Node(T data = T(), Node * next = nullptr): data(data), next(next){}
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
        int get_size() const {
            return _size;
        }

        bool is_empty() const {
            return _size == 0;
        }

        void push_back(T data){
            if(!head){
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
            head = new Node(data, head);
            _size++;
        }

        void insert(int index, T data){
            if(index < 0 || index > _size){
                throw out_of_range("Insert: Inex out of bounds");
            }
            if(index == 0){
                push_front(data);
            }else{
                Node * newNode = new Node(data);
                Node * previous = head;
                for(int i = 0;i < index-1; i++){
                    previous = previous->next;
                }
                newNode->next = previous->next;
                previous->next = newNode;
                _size++;
            }
        }

        void pop_front(){
            if(!head){
                throw runtime_error("List is empy");
            }
            Node * temp = head;
            head = head->next;
            delete temp;
            _size--;
        }

        void pop_back(){
            if(_size == 0){
                throw runtime_error("List is empty");
            }
            remove_at(_size-1);
        }

        void remove_at(int index){
            if(index < 0 || index >= _size){
                throw out_of_range("Remove: Index out of bounds");
            }
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
                _size--;
            }
        }

        T & at(int index){
            if(index < 0 || index >= _size){
                throw out_of_range("Access at: Index out of bounds");
            }
            Node * current = head;
            for(int i = 0; i < index; i++){
                current = current->next;
            }
            return current->data;
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
            return at(index);
        }

        bool contains(T data){
            Node * current = head;
            while(current){
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
    list.insert(1, 99);  // Insert at index 1
    list.print_list();   // Output: 56 99 11 45
    cout << endl;

    cout << "At index 0: " << list.at(0) << endl;     // 56
    cout << "Front: " << list.front() << endl;        // 56
    cout << "Back: " << list.back() << endl;          // 45

    list.remove_at(0);
    list.print_list();   // Output: 99 11 45
    cout << endl;

    list.clear();
    cout << "Size after clear: " << list.get_size() << endl;  // 0
}