#include "../include/templates.h"

#include <stdlib.h>
#include <string.h>

maker_template_t templates;

void init_templates(maker_template_t* templates) {
	templates->template_index = 0;
	templates->template_count = 0;	
	templates->template_names = NULL;
	add_template(templates, "c_exec.txt");
	add_template(templates, "c_static_lib.txt");
	add_template(templates, "c_dyn_lib.txt");
}

void get_template() {
	
}

void add_template(maker_template_t* templates, char* str) {
	templates->template_names = realloc(templates->template_names, sizeof(char*) * (templates->template_count+1));
	templates->template_names[templates->template_count] = strdup(str);
	templates->template_count += 1;
}

void remove_template(  ) {
	
}

void destroy_templates(maker_template_t* templates) {
	for (int i = 0; i < templates->template_count; i++) {
		free(templates->template_names[i]);
		templates->template_names[i] = NULL;
	}
	free(templates->template_names);
}
