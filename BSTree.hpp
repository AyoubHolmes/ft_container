#ifndef BSTree_H_PP
#define BSTree_H_PP

#include <iostream>

typedef struct s_node
{
    int content;
    struct s_node *right_node;
    struct s_node *left_node;
} t_node;

class BSTree
{
public:
    BSTree()
    {
        root = NULL;
    };

    BSTree(int val)
    {
        root = new t_node;
        root->content = val;
        root->right_node = NULL;
        root->left_node = NULL;
    };

    t_node *get_root()
    {
        return root;
    }

    void tree_printer(t_node *node, std::string str)
    {
        t_node *tmp = node;
        if (node == NULL)
            return;
        std::cout << str + " " << tmp->content << std::endl;
        tree_printer(tmp->left_node, "left_node");
        tree_printer(tmp->right_node, "right_node");
    };

    void tree_printer_in_order_traversal(t_node *node)
    {
        t_node *tmp = node;
        if (node == NULL)
            return;
        tree_printer_in_order_traversal(tmp->left_node);
        std::cout << tmp->content << std::endl;
        tree_printer_in_order_traversal(tmp->right_node);
    }

    t_node *insert_a_nod(int value, t_node *root)
    {
        t_node *tmp = root;
        if (root == NULL)
        {
            root = new t_node;
            root->content = value;
            root->right_node = NULL;
            root->left_node = NULL;
        }
        else if (root->content < value)
            root->right_node = insert_a_nod(value, root->right_node);
        else
            root->left_node = insert_a_nod(value, root->left_node);
        return (root);
    }

    void insert_new_nod(int value)
    {
        root = insert_a_nod(value, root);
    }

    t_node *minOfRightnode(t_node *root)
    {
        if (root->right_node == NULL)
            return (root);
        return (minOfRightnode(root->right_node));
    }

    t_node *delete_node_by_given_node(int val, t_node *root)
    {
        // t_node *tmp = NULL;

        if (root == NULL)
            return NULL;
        std::cout << "HEEEEEEEERE " << root->content << " " << val << std::endl;
        if (root->content > val)
            root->left_node = delete_node_by_given_node(val, root->left_node);
        else if (root->content < val)
            root->right_node = delete_node_by_given_node(val, root->right_node);
        else
        {

            if (root->right_node == NULL && root->left_node == NULL)
                return NULL;
            if (root->right_node == NULL)
            {
                t_node *tmp = root->left_node;
                free(root);
                return tmp;
            }
            if (root->left_node == NULL)
            {
                t_node *tmp = root->right_node;
                free(root);
                return tmp;
            }
            else
            {
                t_node *tmp = minOfRightnode(root);
                std::cout << tmp->content << std::endl;
                root->content = tmp->content;
                return delete_node_by_given_node(tmp->content, root->right_node);
            }
        }
        return root;
    }

    void delete_node(int val)
    {
        root = delete_node_by_given_node(val, root);
    }

    t_node *search(int val, t_node *rnode)
    {
        if (rnode->content > val)
            return search(val, rnode->left_node);
        if (rnode->content < val)
            return search(val, rnode->right_node);
        return rnode;
    }

    ~BSTree(){

    };

private:
    t_node *root;
};

#endif