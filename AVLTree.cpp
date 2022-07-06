#include "AVLTree.hpp"
#include "BetaAVL.hpp"
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    {
        ft::AVLTree<int> *tree = new ft::AVLTree<int>();

        tree->insert_new_nod(1);
        tree->insert_new_nod(3);
        tree->insert_new_nod(6);
        tree->insert_new_nod(4);
        tree->insert_new_nod(5);

        tree->tree_printer(tree->get_root(), "root");
        std::cout << " ***************** " << std::endl;
        tree->delete_node(3);
        tree->tree_printer(tree->get_root(), "root");
        std::cout << " ***************** " << std::endl;
    }
    return 0;
}
