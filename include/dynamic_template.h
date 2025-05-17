#ifndef DYNAMIC_TEMPLATE_H
#define DYNAMIC_TEMPLATE_H

#include "makefiles.h"

extern const char* supported_languages;

char* prompt_language();
char* prompt_file_structure();
char* prompt_output_format();
char* prompt_flags();
char* prompt_all_targets();
char* prompt_install();
char* prompt_clean_targets();
char* prompt_misc();

void set_language(makefile_t* makefile);
void set_file_structure(makefile_t* makefile);
void set_output_format(makefile_t* makefile);
void set_flags(makefile_t* makefile);
void set_all_targets(makefile_t* makefile);
void set_install(makefile_t* makefile);
void set_clean_targets(makefile_t* makefile);
void set_misc(makefile_t* makefile);

void generate_template();

#endif /* DYNAMIC_TEMPLATE_H */
