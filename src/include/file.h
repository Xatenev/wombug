#ifndef WOMBUG_FILE_H
#define WOMBUG_FILE_H

/**
 * Check if given file name exists
 * @param name
 * @return if file exists true/false
 */
_Bool check_file_exists(const char *name);

/**
 * Check if file is a valid ELF file on linux, or a valid PE file on windows
 * @param name filename
 * @return if file is a valid executeable true/false
 */
_Bool check_file_pe_elf(const char *name);

#endif //WOMBUG_FILE_H
