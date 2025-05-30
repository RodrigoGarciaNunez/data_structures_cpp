#include <iostream>
#include <random>
#include "search_binary_tree.h"


int main(int argc, char * argv[]){

    search_binary_tree * tree = new search_binary_tree();
    search_binary_tree * tree1 = new search_binary_tree();

    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); 

    int random_number;
    for(int i =0; i < 15; i++){
        random_number = dis(gen);
        tree->add_node(random_number);
        tree1->add_node_recursive(tree1->root,nullptr,random_number);
    }

    tree->print_preorden(tree->root);
    cerr << endl;
    tree1->print_preorden(tree1->root);

    int to_search;
    cin >> to_search;
    tree_node *& search = tree1->search_node(to_search, tree1->root);
    cerr << search->val << endl;

    //search =nullptr;

    //tree1->print_preorden(tree1->root);

    cin >> to_search;
    tree1->delete_node(to_search);

    tree1->print_preorden(tree1->root);
}