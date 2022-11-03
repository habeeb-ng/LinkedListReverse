//
//  main.cpp
//  linkedList2
//
//  Created by Habeeb Awolumate on 4/13/22.
//
//                            ECC CIS-223 Fall 2020                                                    //
//                                                                                                    //
//    Type of Assignment:        Lab                                                                         //
//    Section Number            223-100                                                                    //
//    Author:             Habeeb Awolumate                                                                                //
//    File Name:               main.cpp                                            //
//                                                                                                    //
//    Purpose of Program:                                                                                //
//        The purpose of this program is to work on manipulating linked list              //
//                                                  //
//                                                                                                    //
//  Algorithm:                                                                                        //
//    1. create a struct called Node that has two member variables                                 //
//    2. create a type def pointer definer that can be used to creat dynamic object of type Node                                                      //
//    3. Create a class called LinkedList with two member private variables                                      //
//    4.The add function adds a new node containing x to the front (head) of the list, while the isMember function tests to see if the list contains a node with the value x. Test your linked list class by adding various numbers to the list and then testing for membership. //
//    5. Add a print member function. Test the class by starting with an empty list, adding some elements, and then printing the resulting list out.

//     6. Add a function to remove an item from the list, and by adding a destructor:
//7.  Add a member function for reversing the list:
//8. 

#include <iostream>
#include <cstddef>
#include <string>
using namespace std;
struct Node{
    double num;
    Node* Next;
};
typedef Node*  NodePtr;

class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        void add(double x);
        bool isMember(double x);
        int searchPosition(double x);
        NodePtr search(double target);
        void print();
        void reversed(NodePtr rPtr);
        NodePtr reversedList();
        void remove(double x);

    private:
        double value;
        NodePtr head;
};

void printList(NodePtr n){
    while(n != NULL ){
        cout << n->num << endl;
        n = n-> Next;
    }
}

int main(int argc, const char * argv[]) {
    cout << "Lab #9 by Habeeb Awolumate - \n"
        << "Part 3\n\n";
    LinkedList listA;
    listA.add(99.99);
    listA.add(2.99);
    listA.add(29.99);
    listA.add(54.99); //all add function call works fine
    
    listA.remove(29.99);// works fine
    listA.print();
    
    
    //search position didn't work as expected
    if(listA.searchPosition(99.99) == NULL){
        cout <<"2.00 is not in the list" << endl;
    } else if(listA.searchPosition(99.99) != NULL){
        cout << "99.99 is at position "  << listA.searchPosition(99.99) <<endl;
    }
    
    if(listA.isMember(54.99)) // isMember function  works fine
        cout << 54.99 << " is a member of the list\n";
    else
        cout << 54.99 << " is not a member of the list\n";
    
    NodePtr rev = listA.reversedList();
    LinkedList listB;
    cout << "the reversed Linked lis is" << endl;
    printList(rev);
    
    listA.~LinkedList(); // free memory
    for (NodePtr iter = rev; iter != NULL; iter = iter -> Next){
        NodePtr temp = new Node;
        NodePtr discard = iter;
        temp = discard -> Next;
        discard = temp;
        delete discard; // free memory
    }
    
    
    
    return 0;
}
//default constructor creates an empty list by setting head pointer to null ptr (NULL)
LinkedList::LinkedList(){
    head = nullptr;

}
LinkedList::~LinkedList(){
    
    NodePtr temp = new Node;
    while(head != NULL){
        temp = head;
        head = temp -> Next;
        delete temp;
    }
}

void LinkedList:: add(double theNumber){
    NodePtr tempPtr;
    tempPtr = new Node;
    tempPtr ->num = theNumber;
    
    tempPtr->Next = head;
    head = tempPtr;
}

bool LinkedList:: isMember(double theNumber){
    NodePtr here = head; //Node*
    if (here == NULL){
        return 0;
    }
        while(here -> num != theNumber && here -> Next != NULL){
            here = here -> Next;
        }
    if(here-> num == theNumber){
        return 1;
    }else{
        return 0;
    }
}

void LinkedList::print(){
    NodePtr ptr;//travels through the list
    ptr = head;
    if (ptr == NULL){
        cout << "No items in the list," << endl;
    } else{
        while (ptr != NULL){
            cout << ptr->num << " ";
            ptr = ptr->Next;
        }
    }
    cout << endl;
}

void LinkedList::reversed(NodePtr rPtr){
    if(rPtr == nullptr){
        return;
    }else{
        cout << rPtr -> num << endl;
        reversed(rPtr->Next); //recursive
    }
}


int LinkedList::searchPosition(double x){
    int position = 0;
    NodePtr here = head;
    if (here == NULL){
        cout << "the node is empty" << endl;
        return NULL;
    }
    while (here->num !=x && here->Next != NULL){
        here = here -> Next;
        position++;
    }
    if (here ->num == x)
        return position;
    
    return NULL;
}
NodePtr LinkedList:: search(double target){
    NodePtr here = head;
    if(here == NULL){
        return NULL;
    }
    while (here -> num != target && here -> Next != NULL){ //while we have'nt find the data and the current node we in is  not linkind to NULL ->
        here = here -> Next; // we move to the nex NODE by pointing to its link property
    }
    if(here->num == target) // if the number we are looking for is in the here node, then we return the here node
        return here; // return here
     else
        return NULL; //other wise we return NULL;
}
void LinkedList::remove(double x){
    NodePtr discard = new Node;
    NodePtr before = new Node;
    if(search(x) == NULL){
        cout << "the item you want to delete is not in the Node" << endl;
        return;
    } else if(search(x) -> num == x){
        discard = search(x); // we obtain the one we want to delete
    }
    for (NodePtr iter = head; iter -> Next != NULL; iter = iter -> Next){
        if (iter -> Next == discard){
            before = iter; // here we get out before
        }
    }
    before -> Next = discard -> Next;
    delete discard;
}
NodePtr LinkedList:: reversedList(){
    NodePtr reversed = new Node;
    NodePtr current = new Node;
    NodePtr next = new Node;
    
    current = head;
    next = NULL; // this will stay at the end
    reversed = NULL;
    while (current != NULL){
        next = current -> Next;// next is now holding the location of what comes after current
        current -> Next = reversed; // now what comes after current is a NULL
        reversed = current; // now reverse it at current
        current = next; // and now current is not at next which is
    }
    return  reversed;
}
