#include "AVLtree.hpp"

int main(int argc, char const *argv[])
{
    AVLtree *tree = new AVLtree(2);

    tree->insert_new_nod(1);
    tree->insert_new_nod(3);
    tree->insert_new_nod(4);
    tree->tree_printer_in_order_traversal(tree->get_root());
    return 0;
}
