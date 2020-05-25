#ifndef SIMPLE_INTERPRETER_SORT_H
#define SIMPLE_INTERPRETER_SORT_H

#include <string>
#include "Evaluation/Value.h"
#include <unordered_map>
#include "Collections/Heap.h"
#include "Collections/BST.h"

void sort(const unordered_map<string, Value> &map);

void sort(const unordered_map<string, Value>&map) {
    Heap<string, Value> heap(map.size());
    BST<string, Value> bst;

    for (const auto& variable : map) {
        heap.put(variable.first, variable.second);
        bst.put(variable.first, variable.second);
    }

    heap.sort();
    bst.inOrder();

    heap.print();
}

#endif //SIMPLE_INTERPRETER_SORT_H
