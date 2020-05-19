
#ifndef SIMPLE_INTERPRETER_HEAP_H
#define SIMPLE_INTERPRETER_HEAP_H
template <class k, class v>
struct Node{
    k key;
    v value;
    Node *left;
    Node *right;
};

template <class k, class v>
class Heap {
private:
    int count;
public:
 void put(k key,v value);
 Node<k, v> extractMin();
 void sort();
};


#endif //SIMPLE_INTERPRETER_HEAP_H
