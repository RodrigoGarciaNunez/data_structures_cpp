#include "linked_list.h"

linked_list::linked_list(): data_structure(){
    root = nullptr;
}

void linked_list::append(int i){
    node_list * new_node =  new node_list(i);
    if(root == nullptr){
        root= new_node;
        return;
    }

    node_list * aux = root;
    while(aux != nullptr){
        if (aux->next_right == nullptr){
            aux->next_right = new_node;
            return;
        } 
            
        aux = aux->next_right;
    }
}

void linked_list::delete_node(int i){
    node_list * aux = root;
    node_list * aux1 = aux->next_right;
    while(aux1 != nullptr){
        if(aux1->id == i) break;
        aux = aux->next_right;
        aux1 = aux1->next_right;
    }

    aux->next_right = aux1->next_right;
    aux1 = nullptr;

}

node_list * linked_list::find(int i){
    if(root->id == i) return root;
    
    node_list * aux =  root->next_right;
    while(aux!= nullptr){
        if(aux->id == i) return aux;

        aux = aux->next_right;
    }
    return nullptr;
}

void linked_list::reverse(){
    if(root == nullptr) return;
    
    node_list * aux0 = root;
    node_list * aux1 = aux0->next_right;
    node_list * temp = nullptr;
    aux0->next_right = nullptr;

    while(aux0 != nullptr){
        temp = aux1->next_right;
        aux1->next_right = aux0;

        aux0 = aux1;
        aux1 = temp;
        if(aux1 == nullptr){
            root = aux0;
            break;
        } 
        
    }
}


void linked_list::print(){
    node_list *  aux = root;
    while(aux != nullptr){
        cerr << aux->id <<endl;
        aux = aux->next_right;
    }
}