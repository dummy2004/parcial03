#include "Ejercicio01.h"
#include <queue>

Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* lists) {
    auto comparator = [](Node<int>* a, Node<int>* b) {
        return a->value < b->value;
        };

    std::priority_queue<Node<int>*, std::vector<Node<int>*>, decltype(comparator)> pq(comparator);

    while (lists != nullptr) {
        if (lists->value != nullptr) {
            pq.push(lists->value);
        }
        lists = lists->next;
    }

    Node<int>* dummy = new Node<int>{ 0, nullptr }; 
    Node<int>* current = dummy;

    while (!pq.empty()) {
        Node<int>* top = pq.top();
        pq.pop();

        current->next = top;
        current = current->next;

        if (top->next != nullptr) {
            pq.push(top->next);
        }
    }
    return dummy->next;
}

