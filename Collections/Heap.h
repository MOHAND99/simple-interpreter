
#ifndef SIMPLE_INTERPRETER_HEAP_H
#define SIMPLE_INTERPRETER_HEAP_H
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
#include <vector>


using namespace std;




template <class k, class v>
class Node{
private:
    k key;
    v value;
public:
    Node(k key, v value) {
        this->key = key;
        this->value = value;
    }

    k getKey() const {
        return key;
    }

    v getValue() const {
        return value;
    }
};

template <class k, class v>
class Heap {
private:
    //Node<k, v> *arr;
    Node<k, v> *arr;
    //vector<Node<k, v>> vector;
    int n; // number of added nodes
public:
    Heap(int size) {
       // arr = (Node<k, v>*) malloc(sizeof(Node<k, v>) * size);
       arr = new Node<k, v>[size];
        n = 0;
    }
    void put(k key,v value) {
        int i;
        for(i=n; arr[(i-1)/2]. > value && i>0; i=(i-1)/2 ) {
            arr[i] = arr[(i - 1) / 2];
            //((Node<k, v>)arr[i]).value = ((Node<k, v>)arr[(i-1)/2]).value;
            cout << "value "<< ((Node<k, v>) arr[i]).v << "key " << ((Node<k, v>)arr[i]).key << endl;//debug
        }
        arr[i].value = value;
        arr[i].key = key;
        n++;
    }
    void insertMap(map<k, v> map);
    Node<k, v> extractMin();
    void sort();
    ~Heap();
};




template<class k, class v>
Node<k, v> Heap<k, v>::extractMin() {
    return Node<k, v>();
}

template<class k, class v>
void Heap<k, v>::sort() {

}

template<class k, class v>
Heap<k, v>::~Heap() {
   // delete[] arr;
}

template<class k, class v>
void Heap<k, v>::insertMap(map<k, v> map) {
    arr = realloc(arr, map.size() * sizeof(Node<k, v>));
    for(pair<k, v> element : map)
        put(element.first, element.second);
}

/*template<class k, class v>
Heap<k, v>::Heap(int size) {
   // arr = (Node<k, v>*) malloc(sizeof(Node<k, v>) * size);
    arr =(Node<k, v>*) malloc(sizeof(Node<k, v>) * size);
    n = 0;
    cout <<7;//debug
}*/


#endif //SIMPLE_INTERPRETER_HEAP_H
