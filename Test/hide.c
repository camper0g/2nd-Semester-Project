#include <stdio.h>
#include <windows.h>

int main() {
    const char* filename = "file.txt";

    if (SetFileAttributes(filename, FILE_ATTRIBUTE_HIDDEN)) {
        printf("File '%s' hidden successfully.\n", filename);
    } else {
        printf("Error hiding file '%s'.\n", filename);
    }

    return 0;
}
