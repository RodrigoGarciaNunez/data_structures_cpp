#include "search_binary_tree.h"

search_binary_tree::search_binary_tree(){
    root = nullptr;
}


void search_binary_tree::add_node(int i){   //guacala
    tree_node * new_node = new tree_node(i);
    if(root == nullptr){ 
        root = new_node;
        return;
    }

    tree_node * aux = root;
    while(aux != nullptr){
        if(new_node->id <= aux->id){

            if(aux->next_left == nullptr){
                aux->next_left = new_node;
                //cerr << "agregado izquierda" << endl;
                break;
            }
            else{
                aux = (new_node->id <= aux->id) ? aux->next_left: aux->next_right;
                //cerr << "aun no agregado"<< endl;
            }    
        }
        else{
            if(aux->next_right == nullptr){
                aux->next_right = new_node; 
                //cerr << "agregado derecha" << endl;
                break;
            }
            else{
                aux = (new_node->id <= aux->id) ? aux->next_left: aux->next_right;
                //cerr << "aun no agregado"<< endl;
            }     
        }
    }
    
}


void search_binary_tree::add_node_recursive(tree_node *& root, tree_node * aux, int i){
    if(aux == nullptr) aux  = new tree_node(i);
    
    if(this->root == nullptr) {
        this->root = aux;
        return;
    }
    if(root == nullptr){
        root = aux;
        return;
    }

    if(aux->id <= root->id) add_node_recursive(root->next_left, aux);
    else add_node_recursive(root->next_right, aux);

}


void search_binary_tree::print(tree_node * aux){
    if(aux == nullptr) return; 

    cerr << " "<<aux->id;
    print(aux->next_left);
    print(aux->next_right);
    
}


void search_binary_tree::delete_node(int i){
    tree_node *& del = search_node(i, root);
    tree_node * next_left;
    tree_node * next_right;
    if(del != nullptr){
        next_left = del->next_left;
        next_right = del->next_right;
        del = nullptr;

        if(next_left != nullptr) add_node_recursive(root, next_left);
        if(next_right != nullptr) add_node_recursive(root, next_right);
        
    }   
}


tree_node *& search_binary_tree::search_node(int i, tree_node *& root){
    if(root != nullptr){
        if(root->id == i) return root;

        if( i <= root->id) search_node(i, root->next_left);
        else search_node(i, root->next_right);

    }
    else return root;   
}

    