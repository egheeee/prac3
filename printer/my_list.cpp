#include "my_list.h"
#include <stdlib.h>
#include <stdio.h>
void add_node_to_start(Node** head, const Printer* p) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return;
    }
    new_node->data = *p;
    new_node->next = *head;
    *head = new_node;
}
void remove_node_from_start(Node** head) {
    if (*head == NULL) {
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}
void print_list(const Node* head) {
    while (head != NULL) {
        print_printer_info(&head->data);
        printf("\n");
        head = head->next;
    }
}
void free_list(struct Node* head) {
    for (struct Node* node = head; node != NULL; node = head) {
        head = head->next;
        free(node);
    }
}

void add_node_sorted(Node** head, const Printer* p) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        return;
    }
    new_node->data = *p;

    if (*head == NULL || compare_printers(&(*head)->data, p) >= 0) {
        new_node->next = *head;
        *head = new_node;
    }
    else {
        Node* current = *head;
        while (current->next != NULL && compare_printers(&current->next->data, p) < 0) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}
void remove_node(Node** head, const Printer* p) {
    if (*head == NULL) {
        return;
    }

    if (are_printers_equal(&(*head)->data, p)) {
        remove_node_from_start(head);
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        if (are_printers_equal(&current->next->data, p)) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

