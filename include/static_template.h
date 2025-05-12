#ifndef STATIC_TEMPLATE_H
#define STATIC_TEMPLATE_H

enum {
	C_EXEC,
	C_STATIC_LIB,
	C_DYN_LIB
};

void load_template(int template_num);
void select_template();

#endif /* STATIC_TEMPLATE_H */
