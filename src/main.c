#include <stdio.h>

#include "../include/template.h"

int main(){
   	puts("Would you like to use a template or generate a custom Makefile?");
	puts("1) Template\n2) Custom");

	unsigned short choice;
	scanf("%hu", &choice);

	if (choice == 1) {
		// pick template
	} else if (choice == 2) {
		// create template
	}

    return 0;
}
