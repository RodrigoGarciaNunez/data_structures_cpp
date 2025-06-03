#include <iostream>
#include <random>
#include "double_linked_list/double_linked_list.h"
#include "linked_list/linked_list.h"
#include "search_binary_tree/search_binary_tree.h"

int main(int argc, char *argv[]){
    
    search_binary_tree * tree = new search_binary_tree();
    linked_list * linked = new linked_list();
    d_linked_list * d_linked = new d_linked_list();
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100); 
    int random_number;

    for(int i =0; i < 15; i++){
            random_number = dis(gen);
            linked->append(random_number);
            d_linked->append(random_number);
            tree->add_node_recursive(tree->root,nullptr,random_number);
    }

    tree->print();
    linked->print();
    d_linked->print();



    
}