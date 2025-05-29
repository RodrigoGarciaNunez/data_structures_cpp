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
        if(new_node->val <= aux->val){

            if(aux->left_child == nullptr){
                aux->left_child = new_node;
                //cerr << "agregado izquierda" << endl;
                break;
            }
            else{
                aux = (new_node->val <= aux->val) ? aux->left_child: aux->right_child;
                //cerr << "aun no agregado"<< endl;
            }    
        }
        else{
            if(aux->right_child == nullptr){
                aux->right_child = new_node; 
                //cerr << "agregado derecha" << endl;
                break;
            }
            else{
                aux = (new_node->val <= aux->val) ? aux->left_child: aux->right_child;
                //cerr << "aun no agregado"<< endl;
            }     
        }
    }
    
}

void search_binary_tree::add_node_recursive(int i){
    tree_node * aux  = new tree_node(i);
    if(root == nullptr){
        root = aux;
        return;
    }

    if(aux->val <= root->val) add_node_recursive(root->left_child, aux);
    else add_node_recursive(root->right_child, aux);
}

void search_binary_tree::add_node_recursive(tree_node *& child, tree_node *& aux){
    if(child == nullptr){
        child = aux;
        return;
    }

    if(aux->val <= child->val) add_node_recursive(child->left_child, aux);
    else add_node_recursive(child->right_child, aux);

}

void search_binary_tree::print_preorden(){
    if(root == nullptr) return;

    cerr << root->val;
    print_preorden(root->left_child);
    print_preorden(root->right_child);
}

void search_binary_tree::print_preorden(tree_node *& aux){
    if(aux == nullptr) return;

    cerr << " "<<aux->val;
    print_preorden(aux->left_child);
    print_preorden(aux->right_child);
    
}


void search_binary_tree::delete_node(int i){

}


bool search_binary_tree::search_node(int i, tree_node *& root){
    if(root != nullptr){
        if(root->val == i) return true;

        if( i <= root->val) search_node(i, root->left_child);
        else search_node(i, root->right_child);

    }
    else return false;   
}

    