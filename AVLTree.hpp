#ifndef AVLTREE_H_PP
#define AVLTREE_H_PP

#include "iostream"

typedef struct              s_node {
    int                     content;
    struct s_node           *right_node;
    struct s_node           *left_node;
}                           t_node;

class AVLTree {
    public:
        AVLTree() {
            root = NULL;
        };

        AVLTree(int val) {
            root = new t_node;
            root->content = val;
            root->right_node = NULL;
            root->left_node = NULL;

        };

        int get_content() {
            return root->content;
        };

        void set_content(int val) {
            root->content = val;
        };

        t_node  *get_root() {
            return root;
        }

        void tree_printer(t_node *node, std::string str) {
            t_node *tmp = node;
            if (node == NULL)
                return ;
            std::cout <<str << tmp->content << std::endl;
            tree_printer(tmp->left_node,"left_node ");
            tree_printer(tmp->right_node, "right_node ");
        };

        t_node *insert_a_nod(int value, t_node *root) {
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

        void insert_new_nod(int value) {
            root = insert_a_nod(value, root);
        }

        ~AVLTree() {

        };
    
    private:
        t_node *root;
        
};

#endif