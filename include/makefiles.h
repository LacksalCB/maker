#ifndef MAKEFILES_H
#define MAKEFILES_H

typedef struct MAKEFILE_STRUCT {
	char* contents;
	char* language;
	char* file_structure;
	char* output_format;
	char* flags;
	char* all_targets;
	char* install;
	char* clean_targets;
	char* misc;
} makefile_t;

#endif /* MAKEFILES_H */
