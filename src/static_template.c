#include "../include/static_template.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* static_file_paths[] = {
	"c_exec.txt",
	"c_static_lib.txt",
	"c_dyn_lib.txt"
};

void load_template(int template_num) {
	FILE *fptr;
	char filename[128] = "templates/";
	strncat(filename, static_file_paths[template_num], strlen(static_file_paths[template_num]));
	fptr = fopen(filename, "r");

	fseek(fptr, 0, SEEK_END);
	long fsize = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);
	char* buff = malloc(fsize + 1);
	fread(buff, fsize, 1, fptr);
	fclose(fptr);
	buff[fsize] = 0; // Null Char termination

	puts(buff);

	free(buff);
}

void select_template() {
	puts("Please select a template:");
	
	puts("1) C Executable");
	puts("2) C Static Library");
	puts("2) C Dynamic Library");

	unsigned short template_style;
	scanf(" %hu", &template_style);
	switch (template_style) {
		case 1: 
			load_template(C_EXEC);
			break;
		case 2:
			load_template(C_STATIC_LIB);
			break;
		case 3:
			load_template(C_DYN_LIB);
			break;
		default:
			puts("Invalid option.");
	}

}
