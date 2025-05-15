#include "../include/templates.h"
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

void set_compiler(char** makefile, char* language) {
	if (strcmp("C", language)) {	
		strncpy(*makefile, "CC = GPP", 9);
	}	
	if (strcmp("C++", language)) {
		strncpy(*makefile, "CC = GPP", 9);
	}
}

void generate_template() {
	char* makefile = malloc(sizeof(char) * 4096);

	char* language = prompt_language();

 	set_compiler(&makefile, language);
	puts(makefile);

	free(language);
	free(makefile);
}
