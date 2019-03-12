. = ALIGN(4);
__init_table_start = .;
*(.initializers*)
__init_table_end = .;

*(.dependencies*);