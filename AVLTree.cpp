#include "AVLTree.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    AVLTree *tree = new AVLTree(2);

    tree->insert_new_nod(1);
    tree->insert_new_nod(3);
    tree->insert_new_nod(6);
    tree->insert_new_nod(4);
    tree->insert_new_nod(5);

    tree->tree_printer(tree->get_root(), "root");
    std::cout << " ***************** " << std::endl;
    tree->delete_node(3);
    std::cout << " ***************** " << std::endl;
    tree->tree_printer(tree->get_root(), "root");
    std::cout << " ***************** " << std::endl;
    t_node *searchedOne = tree->search(4, tree->get_root());
    std::cout << searchedOne->content << std::endl;

    return 0;
}
