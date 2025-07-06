#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTree
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

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void insert(T value)
    {
        Node *newNode = new Node(value);
        if (!root)
        {
            root = newNode;
            return;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (!temp->left)
            {
                temp->left = newNode;
                return;
            }
            else
            {
                q.push(temp->left);
            }

            if (!temp->right)
            {
                temp->right = newNode;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }

    void inOrder(Node *node)
    {
        if (!node)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void preOrder(Node *node)
    {
        if (!node)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node *node)
    {
        if (!node)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    void printInOrder()
    {
        cout << "In-order: ";
        inOrder(root);
        cout << endl;
    }

    void printPreOrder()
    {
        cout << "Pre-order: ";
        preOrder(root);
        cout << endl;
    }

    void printPostOrder()
    {
        cout << "Post-order: ";
        postOrder(root);
        cout << endl;
    }
};

int main()
{
    BinaryTree<int> binary_tree;

    binary_tree.insert(1);
    binary_tree.insert(2);
    binary_tree.insert(3);
    binary_tree.insert(4);
    binary_tree.insert(5);
    binary_tree.insert(6);
    binary_tree.insert(7);

    binary_tree.printInOrder();
    binary_tree.printPreOrder();
    binary_tree.printPostOrder();

    return 0;
}
