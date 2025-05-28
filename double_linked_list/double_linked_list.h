#include <iostream>
#include "node_list.h"

using namespace std;
class linked_list{
public:
    linked_list();

    void add_node(int i);

    void delete_node(int to_delete);

    node_list *  find_node(int looking);

    void reverse();

    void print_list();

private:

    node_list *raiz;
    node_list *bottom;
    int size;
};
