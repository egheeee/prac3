#ifndef PRINTER_H
#define PRINTER_H

typedef enum {
    A3,
    A4
} PaperFormat;

typedef struct {
    char manufacturer[50];
    PaperFormat paper_format;
    int print_speed;
} Printer;

void init_printer(Printer* p, const char* manufacturer, PaperFormat paper_format, int print_speed);
void print_printer_info(const Printer* p);
int are_printers_equal(const Printer* p1, const Printer* p2);
int compare_printers(const Printer* p1, const Printer* p2);

#endif // PRINTER_H
