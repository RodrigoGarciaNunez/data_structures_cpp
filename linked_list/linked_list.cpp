#include "linked_list.h"

linked_list::linked_list(){
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
        if (aux->next == nullptr){
            aux->next = new_node;
            return;
        } 
            
        aux = aux->next;
    }
}

void linked_list::delete_node(int i){
    node_list * aux = root;
    node_list * aux1 = aux->next;
    while(aux1 != nullptr){
        if(aux1->val == i) break;
        aux = aux->next;
        aux1 = aux1->next;
    }

    aux->next = aux1->next;
    aux1 = nullptr;

}

node_list * linked_list::find_node(int i){
    if(root->val == i) return root;
    
    node_list * aux =  root->next;
    while(aux!= nullptr){
        if(aux->val == i) return aux;

        aux = aux->next;
    }
    return nullptr;
}

void linked_list::reverse(){
    if(root == nullptr) return;
    
    node_list * aux0 = root;
    node_list * aux1 = aux0->next;
    node_list * temp = nullptr;
    aux0->next = nullptr;

    while(aux0 != nullptr){
        temp = aux1->next;
        aux1->next = aux0;

        aux0 = aux1;
        aux1 = temp;
        if(aux1 == nullptr){
            root = aux0;
            break;
        } 
        
    }
}


void linked_list::print_list(){
    node_list *  aux = root;
    while(aux != nullptr){
        cerr << aux->val <<endl;
        aux = aux->next;
    }
}