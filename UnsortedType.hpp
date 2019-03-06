#ifndef UnsortedType_hpp
#define UnsortedType_hpp

#include <stdio.h>
#include <iostream>
typedef int ItemType;

struct NodeType{
    ItemType info;
    NodeType* next;
};

class  UnsortedType{
    
public:
    // constructor
    UnsortedType();
    // assignment operator =
    UnsortedType operator = (const UnsortedType&);
    // destructor
    ~UnsortedType();
    // Copy Constructor
    UnsortedType(const UnsortedType&);   // WAS NEEDED FOR TESTING. NOT WRITTEN BY US. TAKEN FROM STACK E.
    void   MakeEmpty();
    bool   IsFull()  const;
    int    Length()  const;
    void   RetrieveItem(ItemType& item, bool& found);
    void   InsertItem(ItemType  item);
    void   DeleteItem(ItemType  item);
    void   ResetList();
    void   GetNextItem(ItemType&  item);
    
    
    // print list for testing
    void printList();
    
    
    // friend functions for exercise 2
    friend UnsortedType operator & (const UnsortedType&, const UnsortedType&);
    friend UnsortedType operator | (const UnsortedType&, const UnsortedType&);

    
private :
    NodeType*  listData;
    int length;
    NodeType*  currentPos;
    // deletes all elements in the list
    void deleteList();
    // Checks if an item exists in list, int stores the index
    bool   itemExists(const ItemType&, int&);

} ;


#endif /* UnsortedType_hpp */
