#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printer.h"
#include "my_list.h"
void init_printer(Printer* p, const char* manufacturer, PaperFormat paper_format, int print_speed) {
    strncpy(p->manufacturer, manufacturer, sizeof(p->manufacturer) - 1);
    p->manufacturer[sizeof(p->manufacturer) - 1] = '\0';
    p->paper_format = paper_format;
    p->print_speed = print_speed;
}
void print_printer_info(const Printer* p) {
    printf("Manufacturer: %s\n", p->manufacturer);
    printf("Paper format: %s\n", p->paper_format == A3 ? "A3" : "A4");
    printf("Print speed: %d pages per minute\n", p->print_speed);
}
int are_printers_equal(const Printer* p1, const Printer* p2) {
    return strcmp(p1->manufacturer, p2->manufacturer) == 0 &&
        p1->paper_format == p2->paper_format &&
        p1->print_speed == p2->print_speed;
}
int compare_printers(const Printer* p1, const Printer* p2) {
    int cmp = strcmp(p1->manufacturer, p2->manufacturer);
    if (cmp != 0) {
        return cmp;
    }
    if (p1->paper_format != p2->paper_format) {
        return p1->paper_format - p2->paper_format;
    }
    return p1->print_speed - p2->print_speed;
}
int main() {
    Node* list = NULL;

    Printer p1, p2, p3;
    init_printer(&p1, "Epson", A4, 20);
    init_printer(&p2, "HP", A3, 25);
    init_printer(&p3, "Canon", A4, 15);

    add_node_to_start(&list, &p1);
    add_node_to_start(&list, &p2);
    add_node_to_start(&list, &p3);

    remove_node_from_start(&list);

    print_list(list);
    free_list(list);
    //
    Node* sorted_list = NULL;

    Printer p4;
    init_printer(&p4, "Brother", A4, 22);

    add_node_sorted(&sorted_list, &p1);
    add_node_sorted(&sorted_list, &p2);
    add_node_sorted(&sorted_list, &p3);
    add_node_sorted(&sorted_list, &p4);

    remove_node(&sorted_list, &p3);

    printf("\nSorted list:\n");
    print_list(sorted_list);
    free_list(sorted_list);

    return 0;
}