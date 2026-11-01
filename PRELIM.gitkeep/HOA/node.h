#include "node.h"
#ifndef SEARCHINGALGO_H

/*
template <typename T>
void linearSearchArr(int maxSize, T dataFind, T data[]){

    int i = 0;
    while(i <= maxSize){
        if(dataFind == data[1]){
            std::cout << "Searching is successful";
            return;
        }
        i++;
    }
    std::cout << std::endl;
    std::cout << "The search is successful" << std::endl;
}
*/

template <typename T>
void linearSearchLL(Node<T>* node, T dataFind){
    // Create a loop that iterates until the node reaches the end (nullptr)
    while(node != nullptr){
        // Create a condition that will compare the search item to the current node data
        if(node -> data == dataFind){
            std::cout << "The search was successful" << std::endl;
            return;
        }
        // Iteration or Moving of node
        node = node -> next;
    } 
    // Displaying if unsuccessful
    std::cout << "The search was unsuccessful!" << std::endl;
}

template <typename T>
void binarySearchArr(T dataFind, T data[], int maxSize){
    int low = 0, up = maxSize -1, middle;
    while(low <= up){
        middle = (int)((low+up)/2);
        if the dataFind is == data[middle]{
            std::cout << "The data is found in the list!" << std::endl;
            return;
        }
        else if (dataFind > data[middle]){
            low = mid +1;
        } else {
            up = middle-1;
        }
    }
    std::cout << "The element your finding is not in the list." << std::endl;
}

// Create a helper functions to get the middle
template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    // use 2 pointers
    //slow moves one node at a time
    // fast moves two at a time

    Node<T>* slow = start;
    Node<T>* fast = start;

    // Create a loop until fast reaches the end 
    // Reaches the last node of the current search range
    while(fast != last && fast -> next != last){

        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* node, T dataFind){

    Node<T>* last = nullptr*;

    while(start != last){
        // middle element
        Node<T>* middle = getMiddle (start, last);

        if(midde -> data == dataFind){
            std::cout << "The data is found in the list" << std::endl;
            return;
        }
        else if ( middle -> data > dataFind){
            last = middle;
        }
        else{
            start = middle -> next;
        }
    }
    std::cout << "The element your finding is not in the list." << std::endl;
};

#endif