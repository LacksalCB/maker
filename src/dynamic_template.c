#include "../include/templates.h"
#include "../include/makefiles.h"
#include "../include/dynamic_template.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN 32

const char* supported_languages = "C/C++";

char* prompt_language() {
	char* language_prompt = NULL;
	size_t line_len = LINE_LEN;
	ssize_t buf;

	printf("\nWhat language is this makefile for? (%s)\n", supported_languages);

	for (;;) {
		buf = getline(&language_prompt, &line_len, stdin);
		if (buf == -1) {
			fprintf(stderr, "Error reading input\n");
			return 0;
		}

		if (buf > 0 && language_prompt[buf-1] == '\n') {
			language_prompt[buf-1] = '\0';
		}

		if (strstr(supported_languages, language_prompt)) {
			break;
		}

		puts("Please enter a language from the supported language list.");
	}
	return language_prompt;
}

char** prompt_file_structure() {
	puts("\nWhat is your intended file structure? (simple single dir project, or multiple dirs like src, include etc)\n1) Simple\n2) Custom\n");

	int fs_option = 0;
	char** fs_prompt = NULL;
	int file_count = 0;

	
	char* file;
	for (;;) {
		int buf = scanf("%d", &fs_option);

		if (buf == EOF) {
			fprintf(stderr, "Error reading input\n");
			return 0;
		}

		if (fs_option == 1) {	
			break;
		}

		if (fs_option == 2) {
			puts("\nEnter the desired number of files:");
			scanf("%d", &file_count);

			puts("\nEnter desired file names:");			
			for (int i = 0; i < file_count+1; i++) {
				size_t line_len = LINE_LEN;
				ssize_t buf = getline(&file, &line_len, stdin);
				if (buf == -1) {
					fprintf(stderr, "Error reading input\n");
					return 0;
				}

				if (buf > 0 && file[buf-1] == '\n') {
					file[buf-1] = '\0';
				}

				fs_prompt = realloc(fs_prompt, sizeof(char*) * (i + 1));
				fs_prompt[i] = malloc(sizeof(char) * (strlen(file) + 1));
				strcpy(fs_prompt[i], file);
			}
			break;
		}
	}

	free(file);
	return fs_prompt;	
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

void dealloc_makefile(makefile_t* makefile) {
	free(makefile->contents);
	free(makefile->language);	
	for (int i = 0; i <= 2; i++) { // do this better
		free(makefile->dir_structure[i]);	
	}
	free(makefile->dir_structure);
/*
	free(makefile->output_format);
	free(makefile->flags);
	free(makefile->all_targets);
	free(makefile->install);
	free(makefile->clean_targets);
	free(makefile->misc);
*/
	free(makefile);
}

void generate_template() {
	makefile_t* makefile = malloc(sizeof(struct MAKEFILE_STRUCT) * 1);
	makefile->contents = malloc(sizeof(char) * 4096);

	makefile->language = prompt_language();
 	set_language(makefile);

	makefile->dir_structure = prompt_file_structure();
	set_file_structure(makefile);

	
	puts(makefile->contents);
	
	dealloc_makefile(makefile);
}
