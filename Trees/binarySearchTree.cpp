#include <iostream>
using namespace std;

template <typename T>
class BinarySearchTree
{
private:
    struct Node
    {
        T data;
        Node *left;
        Node *right;
        Node(T data = T(), Node *left = nullptr, Node *right = nullptr) : data(data), left(left), right(right) {}
    };
    Node *root;

    Node *insertHelper(Node *node, T data)
    {
        if (!node)
        {
            Node *newNode = new Node(data);
            return newNode;
        }
        if (data < node->data)
        {
            node->left = insertHelper(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insertHelper(node->right, data);
        }
        return node;
    }

    Node *removeHelper(Node *node, T data)
    {
        if (!node)
        {
            return nullptr;
        }
        if (data < node->data)
        {
            node->left = removeHelper(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = removeHelper(node->right, data);
        }
        else
        {
            // Found Node
            if (!node->left && !node->right)
            {
                delete node;
                return nullptr;
            }
            if (!node->left)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *successor = findMin(node->right);
            node->data = successor->data;
            node->right = removeHelper(node->right, successor->data);
        }
        return node;
    }

    Node *findMin(Node *node)
    {
        while (node && node->left)
        {
            node = node->left;
        }
        return node;
    }

    void inOrderHelper(Node *node)
    {
        if (!node)
            return;
        inOrderHelper(node->left);
        cout << node->data << " ";
        inOrderHelper(node->right);
    }

    bool searchHelper(Node *node, T data)
    {
        if (!node)
            return false;
        if (data == node->data)
        {
            return true;
        }
        if (data < node->data)
        {
            return searchHelper(node->left, data);
        }
        else
        {
            return searchHelper(node->right, data);
        }
    }

public:
    BinarySearchTree()
    {
        root = nullptr;
    }
    void insert(T data)
    {
        root = insertHelper(root, data);
    }

    void inOrder()
    {
        inOrderHelper(root);
        cout << endl;
    }

    bool search(T data)
    {
        return searchHelper(root, data);
    }

    void remove(T data)
    {
        root = removeHelper(root, data);
    }
};

int main()
{
    BinarySearchTree<int> binary_search_tree;
    binary_search_tree.insert(10);
    binary_search_tree.insert(5);
    binary_search_tree.insert(15);
    binary_search_tree.insert(3);
    binary_search_tree.insert(7);

    cout << "In-order traversal: ";
    binary_search_tree.inOrder(); // Should print 3 5 7 10 15

    cout << "Search 7: " << (binary_search_tree.search(7) ? "Found" : "Not found") << endl;
    cout << "Search 20: " << (binary_search_tree.search(20) ? "Found" : "Not found") << endl;

    binary_search_tree.remove(7);
    cout << "Search 7 after remove: " << (binary_search_tree.search(7) ? "Found" : "Not found") << endl;

    cout << "In-order traversal: ";
    binary_search_tree.inOrder(); // Should print 3 5 10 15
    return 0;
}