#include "AVLTree.hpp"

int main(int argc, char const *argv[])
{
    AVLTree *tree = new AVLTree(2);

    tree->insert_new_nod(1);
    tree->insert_new_nod(3);
    tree->insert_new_nod(4);
    tree->tree_printer(tree->get_root(),"root   ");
    return 0;
}
