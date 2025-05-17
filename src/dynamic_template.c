#include "../include/templates.h"
#include "../include/makefiles.h"
#include "../include/dynamic_template.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* supported_languages = "C/C++";

char* prompt_language() {
	char* language = NULL;
	size_t line_len = 32;
	ssize_t buf;

	printf("What language is this makefile for? (%s)\n", supported_languages);

	for (;;) {
		buf = getline(&language, &line_len, stdin);
		if (buf == -1) {
			fprintf(stderr, "Error reading input\n");
			return 0;
		}

		if (buf > 0 && language[buf-1] == '\n') {
			language[buf-1] = '\0';
		}

		if (strstr(supported_languages, language)) {
			break;
		}

		puts("Please enter a language from the supported language list.");
	}
	return language;
}

char* prompt_file_structure() {
	return "placeholder";	
}

void set_language(makefile_t* makefile) {
	
	if (strcmp("C", makefile->language)) {	
		strncpy(makefile->contents, "CC = GCC\n", 10);
	}	
	if (strcmp("C++", makefile->language)) {
		strncpy(makefile->contents, "CC = GPP\n", 10);
	}
}

void set_file_structure(makefile_t* makefile) {
		
} 

void dealloc() {
	
}

void generate_template() {
	makefile_t* makefile = malloc(sizeof(struct MAKEFILE_STRUCT) * 1);
	makefile->contents = malloc(sizeof(char) * 4096);

	makefile->language = prompt_language();

 	set_language(makefile);

	
	puts(makefile->contents);

	free(makefile);
}
