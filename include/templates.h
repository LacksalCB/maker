#ifndef TEMPLATE_H
#define TEMPLATE_H


typedef struct TEMPLATES_STRUCT {
	int template_index;
	int template_count;
	char** template_names;
}maker_template_t;

extern maker_template_t templates;

void init_templates(maker_template_t* template);
void get_template();
void add_template(maker_template_t* template, char* str);
void remove_template();
void destroy_templates(maker_template_t* template);

#endif /* TEMPLATE_H */
