#include <iostream>
using namespace std;

template <typename T>
class AVL_tree
{
private:
    struct Node{
        T key;
        int height;
        Node * left;
        Node * right;
        Node(T key = T(), int height = 1, Node * left = nullptr, Node * right = nullptr) : key(key), height(height), left(left), right(right){}
    };
    Node * root;

    int height(Node * node){
        return node ? node->height : 0;
    }

    int getBalance(Node * node){
        return node ? height(node->left) - height(node->right) : 0;
    }

    int max(int a, int b){
        return (a > b) ? a : b;
    }

    Node * rightRotate(Node * node){
        Node * left = node->left;
        Node * Tree2 = left->right;

        left->right = node;
        node->left = Tree2;

        node->height = 1 + max(height(node->left), height(node->right));
        left->height = 1 + max(height(left->left), height(left->right));

        return left;
    }

    Node * leftRotate(Node * node){
        Node * right = node->right;
        Node * Tree2 = right->left;

        right->left = node;
        node->right = Tree2;

        node->height = 1 + max(height(node->left), height(node->right));
        right->height = 1 + max(height(right->left), height(right->right));

        return right;
    }

    Node * insertHelper(Node * node, T key){
        if(!node){
            Node * newNode = new Node(key);
            return newNode;
        }
        if(key < node->key){
            node->left = insertHelper(node->left, key);
        }else if(key > node->key){
            node->right = insertHelper(node->right, key);
        }else{
            return node; // No duplicates
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if(balance > 1 && key < node->left->key){
            return rightRotate(node);
        }

        if(balance < -1 && key > node->right->key){
            return leftRotate(node);
        }

        if(balance > 1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if(balance < -1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inOrderHelper(Node * node){
        if(!node) return;
        inOrderHelper(node->left);
        cout << node->key << " ";
        inOrderHelper(node->right);
    }
public:
    AVL_tree()
    {
        root = nullptr;
    }

    void insert(T key){
        root = insertHelper(root, key);
    }


    void inOrder(){
        inOrderHelper(root);
        cout << endl;
    }

};

int main() {
    AVL_tree<int> tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(10); // LL

    tree.insert(25); // LR
    tree.insert(40);
    tree.insert(50); // RR
    tree.insert(45); // RL

    tree.inOrder(); // Output: 10 20 25 30 40 50

    return 0;
}
