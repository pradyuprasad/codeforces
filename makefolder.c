#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define MAKEFILE_TO_COPY "makefile.c"   // Define the first file to copy
#define TEMPLATE_TO_COPY "template.cpp" // Define the second file to copy

// Function to copy a file to the new folder
void copy_file_to_folder(const char *folder_name, const char *file_to_copy) {
    FILE *source_fp, *dest_fp;
    char ch;
    char dest_file[256];

    // Construct the destination file path
    snprintf(dest_file, sizeof(dest_file), "%s/%s", folder_name, file_to_copy);

    // Open the source file for reading
    source_fp = fopen(file_to_copy, "r");
    if (source_fp == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // Open the destination file for writing
    dest_fp = fopen(dest_file, "w");
    if (dest_fp == NULL) {
        perror("Error creating destination file");
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    // Copy contents from source file to destination file
    while ((ch = fgetc(source_fp)) != EOF) {
        fputc(ch, dest_fp);
    }

    printf("File '%s' has been copied to '%s'.\n", file_to_copy, dest_file);

    // Close both files
    fclose(source_fp);
    fclose(dest_fp);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <folder name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *folder_name = argv[1];

    // Create the new folder
    if (mkdir(folder_name, 0777) == -1) {
        if (errno == EEXIST) {
            printf("Folder '%s' already exists.\n", folder_name);
        } else {
            perror("Error creating folder");
            return EXIT_FAILURE;
        }
    } else {
        printf("Folder '%s' created successfully.\n", folder_name);
    }

    // Copy the files into the new folder
    copy_file_to_folder(folder_name, MAKEFILE_TO_COPY);
    copy_file_to_folder(folder_name, TEMPLATE_TO_COPY);

    return EXIT_SUCCESS;
}

