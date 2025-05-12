#include <stdio.h>

#include "../include/template.h"

int main(){
   	puts("Would you like to use a template or generate a custom Makefile?");
	puts("1) Template\n2) Custom");

	unsigned short choice;
	scanf("%hu", &choice);

	while (choice > 2) {
		puts("Please select a valid option.  (1 or 2)");
		scanf("%hu", &choice);
	}

	if (choice == 1) {
		select_template();
	} else if (choice == 2) {
		generate_template();
	}

    return 0;
}
