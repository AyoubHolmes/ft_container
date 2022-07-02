#include "BSTree.hpp"

int main(int argc, char const *argv[])
{
    BSTree *tree = new BSTree(2);

    tree->insert_new_nod(1);
    tree->insert_new_nod(3);
    tree->insert_new_nod(4);
    tree->tree_printer(tree->get_root(),"root");
    // tree->tree_printer(tree->get_root(), "Hola");
    return 0;
}
