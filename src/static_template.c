#include "../include/templates.h"
#include "../include/static_template.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void write_makefile(char* makefile, long fsize) {
	FILE* fptr;
	if (access("Makefile", F_OK) == 0 ) {
		puts("Overwite existing Makefile? (y/n)");
		char overwrite_query;
		scanf(" %c", &overwrite_query);

		if (overwrite_query == 'y') {
			fptr = fopen("thing.txt", "w");
			fwrite(makefile, sizeof(char), fsize, fptr);
			fclose(fptr);	
		} else {
			puts(makefile);	
		}
		return;
	} 

	puts("Creating Makefile...");
	fptr = fopen("thing.txt", "w");
	fwrite(makefile, sizeof(char), fsize, fptr);
	fclose(fptr);	
}

void load_template(int template_num) {
	FILE* fptr;
	char filename[256];	
	sprintf(
		filename, 
		"%s/.local/share/maker/templates/%s", 
		getenv("HOME"), 
		templates.template_names[template_num]
	);
	fptr = fopen(filename, "r");

	fseek(fptr, 0, SEEK_END);
	long fsize = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);
	char* buff = malloc(fsize + 1);
	fread(buff, fsize, 1, fptr);
	fclose(fptr);
	buff[fsize] = 0; // Null Char termination

	write_makefile(buff, fsize);

	free(buff);
}

void select_template() {
	puts("Please select a template:");

	for (int i = 0; i < templates.template_count; i++) {
		printf("%d) %s\n", i+1, templates.template_names[i]);	
	}

	unsigned short template_style;
	scanf(" %hu", &template_style);
	switch (template_style) {
		case 1: 
			load_template(0);
			break;
		case 2:
			load_template(1);
			break;
		case 3:
			load_template(2);
			break;
		default:
			puts("Invalid option.");
	}
}
