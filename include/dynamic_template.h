#ifndef DYNAMIC_TEMPLATE_H
#define DYNAMIC_TEMPLATE_H

#include "makefiles.h"

extern const char* supported_languages;

void prompt_language(makefile_t* makefile);
void prompt_dir_structure(makefile_t* makefile);
void prompt_output_format(makefile_t* makefile);
void prompt_flags(makefile_t* makefile);
void prompt_all_targets(makefile_t* makefile);
void prompt_install(makefile_t* makefile);
void prompt_clean_targets(makefile_t* makefile);
void prompt_misc(makefile_t* makefile);

void set_language(makefile_t* makefile);
void set_dir_structure(makefile_t* makefile);
void set_output_format(makefile_t* makefile);
void set_flags(makefile_t* makefile);
void set_all_targets(makefile_t* makefile);
void set_install(makefile_t* makefile);
void set_clean_targets(makefile_t* makefile);
void set_misc(makefile_t* makefile);

void dealloc_makefile(makefile_t* makefile);

void generate_template();

#endif /* DYNAMIC_TEMPLATE_H */
