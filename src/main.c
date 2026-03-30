#include <stdio.h>

#include "../include/templates.h"
#include "../include/static_template.h"
#include "../include/dynamic_template.h"

/*
FLAGS
-s [X]  X being some int 0-9 to select a static template 
-d 		dynamic generation based on user inputs or other flags

*/

int main(){
   	puts("Would you like to use a template or generate a custom Makefile?");
	puts("1) Template\n2) Custom");

	unsigned short choice;
	scanf("%hu", &choice);

	while (choice > 2) {
		puts("Please select a valid option.  (1 or 2)");
		scanf("%hu", &choice);
	}

	while (getchar() != '\n');
	init_templates(&templates);
	if (choice == 1) {
		select_template();
	} else if (choice == 2) {
		generate_template();
	}
	destroy_templates(&templates);
    return 0;
}
