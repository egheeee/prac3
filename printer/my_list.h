#ifndef MY_LIST_H
#define MY_LIST_H
#include "printer.h"

typedef struct Node {
    Printer data;
    struct Node* next;
} Node;

void add_node_to_start(Node** head, const Printer* p);
void remove_node_from_start(Node** head);
void print_list(const Node* head);
void free_list(Node* head);
void add_node_sorted(Node** head, const Printer* p);
void remove_node(Node** head, const Printer* p);

#endif // MY_LIST_H