#include <stdio.h>
#include <stdlib.h>

#define TEMPLATE_FILE "template.cpp"  // Define the template file name

void copy_template(const char *new_filename) {
    FILE *template_fp, *new_fp;
    char ch;
    char new_file[256];

    // Create the new filename with .cpp extension
    snprintf(new_file, sizeof(new_file), "%s.cpp", new_filename);

    // Open the template file for reading
    template_fp = fopen(TEMPLATE_FILE, "r");
    if (template_fp == NULL) {
        perror("Error opening template file");
        exit(EXIT_FAILURE);
    }

    // Open the new file for writing
    new_fp = fopen(new_file, "w");
    if (new_fp == NULL) {
        perror("Error creating new file");
        fclose(template_fp);
        exit(EXIT_FAILURE);
    }

    // Copy the contents from the template file to the new file
    while ((ch = fgetc(template_fp)) != EOF) {
        fputc(ch, new_fp);
    }

    printf("File '%s' has been created successfully.\n", new_file);

    // Close both files
    fclose(template_fp);
    fclose(new_fp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <new filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *new_filename = argv[1];

    copy_template(new_filename);

    return EXIT_SUCCESS;
}

