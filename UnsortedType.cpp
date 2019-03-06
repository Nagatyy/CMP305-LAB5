#include "UnsortedType.hpp"

// constructor
UnsortedType::UnsortedType(){
    length = 0;
    listData = NULL;
    currentPos = listData;;
    
}
// destructor
UnsortedType::~UnsortedType(){
    deleteList();
}
void  UnsortedType::MakeEmpty(){
    
    deleteList();
    length = 0;
    listData = NULL;
    currentPos = listData;
    
}
bool  UnsortedType::IsFull() const{
    // a linked list is only full if we run out of memory
    NodeType* temp = new NodeType;
    if(temp == NULL)
        return true;
    delete temp;
    return false;
}
int   UnsortedType::Length() const{
    return length;
}
void  UnsortedType::RetrieveItem(ItemType& item, bool& found){
    NodeType* temp;
    found = false;
    
    temp = listData;
    
    while(temp != NULL && !found){
        if(temp -> info == item){
            found = true;
            item = temp -> info;
        }
        else
            temp = temp -> next;
    }
}
void  UnsortedType::InsertItem(ItemType item){
    
    int holder;
    bool found = itemExists(item, holder);
    
    if(!found && !IsFull()){ // if the item is not found and the list isnt full, insert it
        NodeType* temp = new NodeType;
        temp -> next = listData;
        temp -> info = item;
        
        listData = temp;
        length++;
    }
    //else
        //std::cout << "Innsertion failed. Item already exists...\n";
    
}
void  UnsortedType::DeleteItem(ItemType item){
    // first check if the item exists
    int index;
    bool found = itemExists(item, index);
    
    // if the item is found, delete it
    if(found){
        NodeType* temp = listData;
        
        // Extreme Case 1: If there is only 1 item in the list (code below throws error if this is not checked)
        if(temp -> next == NULL){
            MakeEmpty();
        }
        
        else{
            while(temp -> next -> info != item) // keep looping and stop temp BEFORE the node with the item we will delete
                temp = temp -> next;
            
            // now that temp is pointing at the item BEFORE the one we will deleted:
            temp -> next = temp -> next -> next;
            delete temp;
            length--;
        }
        
    }
    else
        std::cout << "Deletion failed. Item does not exist...\n";

}
void  UnsortedType::ResetList(){
    currentPos = listData;
}
/*
 Works Cyclically ie when we reach the last item, we go back to the first
 */
void  UnsortedType::GetNextItem(ItemType&  item){
    
    if(currentPos == NULL)  // once you are on the last element (or getnext wasnt called yet), go to the first
        currentPos = listData;

    item = currentPos -> info;
    currentPos = currentPos -> next;
    
    
}
// checks if an item exits and returns its index, if it doesnt exist returns -1
bool UnsortedType::itemExists(const ItemType& item, int& index){
    int count = 0;
    NodeType* temp;
    bool found = false;
    
    temp = listData;
    
    while(temp != NULL && !found){
        count++;
        if(temp -> info == item)
            found = true;
        else
            temp = temp -> next;
    }
    found?index=count:index=-1; // was the item found? If yes, index becomes count, otherwise index = -1
    
    return found;
}

void  UnsortedType::printList(){
    NodeType* temp = listData;
    
    std::cout << "[ ";
    while(temp!=NULL){
        std::cout << temp -> info << " ";
        temp = temp -> next;
    }
    std::cout << "]\n";

}

UnsortedType::UnsortedType(const UnsortedType& other){
    
    if(other.listData == nullptr) return;
    NodeType* dummyHead = new NodeType;
    NodeType* curr = dummyHead;
    NodeType* othcurr = other.listData;
    for(; othcurr!=nullptr; othcurr = othcurr->next)
    {
        curr->next = new NodeType;
        curr = curr->next;
        curr->next = nullptr;
    }
    listData = dummyHead->next;
    delete dummyHead;

}

void UnsortedType::deleteList(){
    
    if(isEmpty()){
        // do nothing
    }
    else{
        NodeType* temp1 = listData;
        NodeType* temp2 = NULL;
        
        if(temp1 -> next != NULL) // if there is at least 1 element in the list, utilize temp2, otherwise there is no need
            temp2 = temp1 -> next;
        
        
        while(temp1 -> next!= NULL){
            delete temp1;
            temp1 = temp2;
            listData = temp2;
            if(temp2 != NULL) // if temp 2 isnt already pointing at the last element, move it up
                temp2 = temp2 -> next;
        }
    }
}


// assignment operator =
UnsortedType UnsortedType::operator =(const UnsortedType& other){
    // first we check for self assignment
    if(this == &other)
        return *this;
    
    if(other.length > 0){
        NodeType* temp = other.listData;
        
        listData = NULL;
        length = 0;
        currentPos = other.currentPos;
        
        for(int i = 0; i < other.length; i++){
            InsertItem(temp -> info);
            temp = temp -> next;
        }
    }
    return *this;
}

bool UnsortedType::isEmpty(){ // checks if list is already empty
    return listData == NULL;
}



