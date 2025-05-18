#include "../include/templates.h"
#include "../include/makefiles.h"
#include "../include/dynamic_template.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_LEN 32

const char* supported_languages = "C/C++";

void prompt_language(makefile_t* makefile) {
	char* language_prompt = NULL;
	size_t line_len = LINE_LEN;
	ssize_t buf;

	printf("\nWhat language is this makefile for? (%s)\n", supported_languages);

	for (;;) {
		buf = getline(&language_prompt, &line_len, stdin);
		if (buf == -1) {
			fprintf(stderr, "Error reading input\n");
			return;
		}

		if (buf > 0 && language_prompt[buf-1] == '\n') {
			language_prompt[buf-1] = '\0';
		}

		if (strstr(supported_languages, language_prompt)) {
			break;
		}

		puts("Please enter a language from the supported language list.");
	}
	makefile->language = language_prompt;
}

void prompt_file_structure(makefile_t* makefile) {
	puts("\nWhat is your intended file structure? (simple single dir project, or multiple dirs like src, include etc)\n1) Simple\n2) Custom\n");

	int fs_option = 0;
	char** fs_prompt = NULL;
	int file_count = 0;

	
	char* file;
	for (;;) {
		int buf = scanf("%d", &fs_option);

		if (buf == EOF) {
			fprintf(stderr, "Error reading input\n");
			return;
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
					return;
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
	makefile->file_structure = fs_prompt;	
	makefile->file_count = file_count;
}

void set_language(makefile_t* makefile) {	
	if (strcmp("C", makefile->language)) {	
		strncpy(makefile->contents, "CC = GCC\n\n", 11);
	}	
	if (strcmp("C++", makefile->language)) {
		strncpy(makefile->contents, "CC = GPP\n\n", 11);
	}
}

char* str_toupper(char* str) {
	char* s = malloc(sizeof(char) * (strlen(str) + 1));

	for (int i = 0; i < (int)strlen(str); i++) {
		s[i] = toupper(str[i]);	
	}

	s[strlen(str)] = 0;
	puts(s);
	return s;
}

void set_file_structure(makefile_t* makefile) {
	const char* file_decl_skeleton = "_DIR = ";	

	// Explore why 0 index prints nothing to contents.  
	for (int i = 1; i <= makefile->file_count; i++) {
		char* makefile_file_name = str_toupper(makefile->file_structure[i]);
		char file_decl[128];
		sprintf(file_decl, "%s%s%s\n", makefile_file_name, file_decl_skeleton, makefile->file_structure[i]);
		strcat(makefile->contents, file_decl);
		free(makefile_file_name);
	}
} 

void dealloc_makefile(makefile_t* makefile) {
	free(makefile->contents);
	free(makefile->language);	
	for (int i = 0; i <= makefile->file_count; i++) {
		free(makefile->file_structure[i]);	
	}
	free(makefile->file_structure);
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

	prompt_language(makefile);
 	set_language(makefile);

	prompt_file_structure(makefile);
	set_file_structure(makefile);

	
	puts(makefile->contents);
	
	dealloc_makefile(makefile);
}
