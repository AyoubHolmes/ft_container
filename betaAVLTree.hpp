#ifndef AVLTree_H_PP
#define AVLTree_H_PP

#include <iostream>
#include <queue>
#include <fstream>
#include <iomanip>
#include <cmath>

namespace ft
{
    template <class T>
    struct Node
    {
        T data;
        int content;
        Node *rightNode;
        Node *leftNode;
        int balance_factor;
        Node *parent;
        int height;

        Node() : parent(nullptr), leftNode(nullptr), rightNode(nullptr), height(0), balance_factor(0) {}
        Node(T data) : content(data), parent(nullptr), leftNode(nullptr), rightNode(nullptr), height(0), balance_factor(0) {}
    };

    template <class T>
    class AVLTree
    {
    public:
        AVLTree() : root(nullptr), length(0), nodecount(0){};

        AVLTree(T val) : length(0), nodecount(0)
        {
            root = new Node<T>(val);
        };

        Node<T> *get_root()
        {
            return root;
        }

        void tree_printer(Node<T> *node, std::string str)
        {
            Node<T> *tmp = node;
            if (node == NULL)
                return;
            std::cout << str + "{ content: " << tmp->content << " height: " << tmp->height << " balance_factor: " << tmp->balance_factor << " }" << std::endl;
            tree_printer(tmp->leftNode, "leftNode");
            tree_printer(tmp->rightNode, "rightNode");
        };

        void tree_printer_in_order_traversal(Node<T> *node)
        {
            Node<T> *tmp = node;
            if (node == NULL)
                return;
            tree_printer_in_order_traversal(tmp->leftNode);
            std::cout << tmp->content << std::endl;
            tree_printer_in_order_traversal(tmp->rightNode);
        }

        /* HELPER FUNCTIONS */

        int max(int first, int second)
        {
            return first > second ? first : second;
        }

        /* *********** BALANCING FUNCTIONS **************** */

        void update(Node<T> *node)
        {
            int leftNodeHeight = (node->leftNode == NULL) ? -1 : node->leftNode->height;
            int rightNodeHeight = (node->rightNode == NULL) ? -1 : node->rightNode->height;

            node->height = 1 + max(leftNodeHeight, rightNodeHeight);
            node->balance_factor = rightNodeHeight - leftNodeHeight;
        }

        Node<T> *right_rotation(Node<T> *node)
        {
            Node<T> *parent = node->parent;
            Node<T> *_root = node->leftNode;
            node->leftNode = _root->rightNode;
            if (node->leftNode)
                node->leftNode->parent = node;
            node->parent = _root;
            _root->rightNode = node;
            _root->parent = parent;
            update(node);
            update(_root);
            return (_root);
        }

        Node<T> *left_rotation(Node<T> *y)
        {
            Node<T> *parent = y->parent;
            Node<T> *_root = y->rightNode;
            y->rightNode = _root->leftNode;
            if (y->rightNode)
                y->rightNode->parent = y;
            y->parent = _root;
            _root->leftNode = y;
            _root->parent = parent;
            update(y);
            update(_root);
            return (_root);
        }

        Node<T> *leftLeftCase(Node<T> *node)
        {
            return right_rotation(node);
        }

        Node<T> *leftRightCase(Node<T> *node)
        {
            node->leftNode = left_rotation(node->leftNode);
            return leftLeftCase(node);
        }

        Node<T> *rightRightCase(Node<T> *node)
        {
            return left_rotation(node);
        }

        Node<T> *rightLeftCase(Node<T> *node)
        {
            node->rightNode = right_rotation(node->rightNode);
            return rightRightCase(node);
        }

        Node<T> *balance(Node<T> *node)
        {
            if (node->balance_factor == -2)
            {
                if (node->leftNode->balance_factor <= 0)
                    return leftLeftCase(node);
                else
                    return leftRightCase(node);
            }
            else if (node->balance_factor == 2)
            {
                if (node->rightNode->balance_factor >= 0)
                    return rightRightCase(node);
                else
                    return rightLeftCase(node);
            }
            return node;
        }

        /* *************************************************** */

        /* INSERT FUNCTION */

        Node<T> *insert_a_nod(int value, Node<T> *node)
        {
            if (!node)
            {
                node = new Node<T>(value);
                // _alloc.construct(node, data, 0);
                // node->parent = parent;
                // _size++;
                return node;
            }
            if (value < node->content)
            {
                node->leftNode = insert_a_nod(value, node->leftNode);
                node->leftNode->parent = node;
            }
            else
            {
                node->rightNode = insert_a_nod(value, node->rightNode);
                node->rightNode->parent = node;
            }
            update(node);
            return balance(node);
            // if (root == NULL)
            //     root = new Node(value);
            // else if (root->content < value)
            // {
            //     root->leftNode = insert_a_nod(value, root->leftNode);
            //     root->leftNode->parent = root;
            // }
            // else
            // {
            //     root->rightNode = insert_a_nod(value, root->rightNode);
            //     root->rightNode->parent = root;
            // }
            // update(root);
            // return balance(root);
        }

        int getLenght(int data)
        {
            return (1);
        }

        void insert_new_nod(int value)
        {
            // std::cout << "HELLO \n";
            root = insert_a_nod(value, root);
            nodecount++;
            if (length < getLenght(value))
                length = getLenght(value);
        }

        Node<T> *findMin(Node<T> *root)
        {
            if (root == NULL)
                return NULL;
            if (root && root->leftNode == NULL)
                return (root);
            return (findMin(root->leftNode));
        }

        Node<T> *findMax(Node<T> *root)
        {
            if (root == NULL)
                return NULL;
            if (root && root->rightNode == NULL)
                return (root);
            return (findMax(root->rightNode));
        }

        Node<T> *delete_given_node(Node<T> *node, int elem)
        {
            if (node == NULL)
                return NULL;
            if (node->content > elem)
                node->leftNode = delete_given_node(node->leftNode, elem);
            else if (node->content < elem)
                node->rightNode = delete_given_node(node->rightNode, elem);
            else
            {
                if (node->leftNode == NULL)
                    return node->rightNode;
                else if (node->rightNode == NULL)
                    return node->leftNode;
                else
                {
                    if (node->leftNode->height > node->rightNode->height)
                    {
                        int successorValue = findMax(node->leftNode)->content;
                        node->content = successorValue;
                        node->leftNode = delete_given_node(node->leftNode, successorValue);
                    }
                    else
                    {
                        int successorValue = findMin(node->rightNode)->content;
                        node->content = successorValue;
                        node->rightNode = delete_given_node(node->rightNode, successorValue);
                    }
                }
            }
            update(node);
            return balance(node);
        }

        void delete_node(int val)
        {
            root = delete_given_node(root, val);
        }

        Node<T> *search(int val, Node<T> *rnode)
        {
            if (rnode->content > val)
                return search(val, rnode->leftNode);
            if (rnode->content < val)
                return search(val, rnode->rightNode);
            return rnode;
        }

        ~AVLTree(){

        };

    private:
        Node<T> *root;
        int nodecount;
        int length;
    };
}

#endif