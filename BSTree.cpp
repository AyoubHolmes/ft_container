#include "BSTree.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    BSTree *tree = new BSTree(2);

    tree->insert_new_nod(1);
    tree->insert_new_nod(3);
    tree->insert_new_nod(6);
    tree->insert_new_nod(4);
    tree->insert_new_nod(5);

    tree->tree_printer(tree->get_root(), "root");
    std::cout << "DELETE A NODE \n";
    std::cout << "DELETE A NODE \n";
    tree->delete_node(6);
    tree->tree_printer(tree->get_root(), "root");
    // tree->tree_printer(tree->get_root(), "Hola");
    t_node *searchedOne = tree->search(4, tree->get_root());
    std::cout << searchedOne->content << std::endl;

    return 0;
}
