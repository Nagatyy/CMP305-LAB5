#include <iostream>
#include "UnsortedType.hpp"



int main() {

    UnsortedType list1;  //[2 1]
    UnsortedType list2;  // [5 4 3 2 1]
    UnsortedType list3;

    for(int i = 1; i <= 2; i++)
        list1.InsertItem(i);
    for (int i = 1; i <= 5; i++) {
        list2.InsertItem(i);
    }
    std::cout << "List 1: ";
    list1.printList();
    std::cout << "List 2: ";
    list2.printList();


    list3 = list1 & list2;

    std::cout << "& between list 1 and 2: ";
    list3.printList();

    list3 = list1 | list2;

    std::cout << "| between list 1 and 2: ";
    list3.printList();

    list3.MakeEmpty();

    list3.printList();
    std::cout << list3.Length();



    return 0;
}


/*----
 Will lopp through both lists and insert every element in each
 since insertion checks for duplicates, we can insert all w/o issues
 ----*/
UnsortedType operator | (const UnsortedType& list1, const UnsortedType& list2){
    UnsortedType returnedList;
    NodeType* temp;
    ItemType current;
    
    temp = list1.listData;
    
    for(int i = 0; i < list1.length; i++){
        current = temp -> info;
        returnedList.InsertItem(current);
        temp = temp-> next;
    }
    
    temp = list2.listData;

    for(int i = 0; i < list2.length; i++){
        current = temp -> info;
        returnedList.InsertItem(current);
        temp = temp-> next;
    }

    return returnedList;
    
}
/* we will create a new list called returnedList, mean while we will loop through the shorter list
 and call itemExists on every element from that list to the other, if it exists, we insert it in the
 new list
 */

UnsortedType operator & (const UnsortedType& list1, const UnsortedType& list2){
    UnsortedType returnedList;
    UnsortedType shorterList;
    UnsortedType longerList;
    NodeType* temp;
    ItemType current;
    int holder;

//    first we determine which of the 2 lists is shorter and longer
    if(list1.length < list2.length){
        shorterList = list1;
        longerList = list2;
    }
    else{
        shorterList = list2;
        longerList = list1;
    }
    
    temp = shorterList.listData;
    
    for(int i = 0; i < shorterList.length; i++){
        current = temp -> info;
        if(longerList.itemExists(current, holder))// if the item from the shorter list exists in the longer list, add it to returned list
            returnedList.InsertItem(current);
        
        temp = temp-> next;
    }
    return returnedList;
}
