#include <iostream>
#include "UnsortedType.hpp"

int main() {

    UnsortedType list1;  //[2 1]
    UnsortedType list2;  // [5 4 3 2 1]
    UnsortedType list3;
    ItemType holder;

    for(int i = 1; i <= 2; i++)
        list1.InsertItem(i);
    for (int i = 1; i <= 5; i++) {
        list2.InsertItem(i);
    }
    
    list2.DeleteItem(5);
    
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
    
    std::cout << "Testing GetNextElement() on List 2: ";
    for(int i = 0; i < list2.Length(); i++){
        list2.GetNextItem(holder);
        std::cout << holder << " ";
    }
    
    std::cout << "\nEmpying all Lists... \n";
    list1.MakeEmpty();
    list2 = list1;
    list3 = list2;
    
    std::cout << "List 1: ";
    list1.printList();
    std::cout << "List 2: ";
    list2.printList();
    std::cout << "List 3: ";
    list3.printList();

    
    return 0;
}

UnsortedType operator | (const UnsortedType& list1, const UnsortedType& list2){
    
    
    NodeType *l1, *l2;
    l1 = list1.listData;
    l2 = list2.listData;
    UnsortedType list;
    while (l1 != NULL)
    {
        list.InsertItem(l1->info);
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        list.InsertItem(l2->info);
        l2 = l2->next;
    }
    return list;
    
}

UnsortedType operator & (const UnsortedType& list1, const UnsortedType& list2){
    NodeType *l1, *l2;
    l1 = list1.listData;
    UnsortedType list;
    while (l1 != NULL)
    {
        l2 = list2.listData;
        while (l2 != NULL)
        {
            if (l1->info == l2->info)
                list.InsertItem(l1->info);
            l2 = l2->next;
        }
        l1 = l1->next;
        
    }
    return list;
}
