#ifndef MAKEFILES_H
#define MAKEFILES_H


// add enums and stuff for presets
typedef struct MAKEFILE_STRUCT {
	char* contents;
	char* language;
	char** file_structure;
	int file_count;
	char* output_format;
	char* flags;
	char* all_targets;
	char* install;
	char* clean_targets;
	char* misc;
} makefile_t;

#endif /* MAKEFILES_H */
