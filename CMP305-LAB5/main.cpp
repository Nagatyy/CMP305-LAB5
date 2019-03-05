#include <iostream>
#include "UnsortedType.hpp"

int main() {
    
    UnsortedType list;
    ItemType item;

    for(int i = 0; i < 10; i++)
        list.InsertItem(i);

    list.GetNextItem(item);
    std::cout << item << "\n";
    list.GetNextItem(item);
    std::cout << item << "\n";
    list.GetNextItem(item);
    std::cout << item << "\n";
    list.GetNextItem(item);
    std::cout << item << "\n";
    list.GetNextItem(item);
    std::cout << item << "\n";
    list.GetNextItem(item);
    std::cout << item << "\n";
    list.GetNextItem(item);
    std::cout << item << "\n";
    list.GetNextItem(item);
    std::cout << item << "\n";
    list.GetNextItem(item);
    std::cout << item << "\n";
    list.GetNextItem(item);
    std::cout << item << "\n";
    list.GetNextItem(item);
    std::cout << item << "\n";

    return 0;
}
