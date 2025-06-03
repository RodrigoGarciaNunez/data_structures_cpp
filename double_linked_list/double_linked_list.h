#include <iostream>
#include "node_list.h"
#include "../data_structure.h"

using namespace std;
class d_linked_list:public data_structure<node_list>{
public:
    d_linked_list();

    void append(int i) override;

    void delete_node(int to_delete) override;
    
    node_list *  find(int looking) override;

    void reverse();

    void print() override;

private:

    //node_list *raiz;
    node_list * bottom;
    //int size;
};
