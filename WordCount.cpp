#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: wordcount <filename>\n");
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Unable to open file %s\n", argv[1]);
        exit(1);
    }

    char word[MAX_WORD_LENGTH + 1];
    int word_count = 0;

    while (fscanf(file, "%s", word) == 1) {
    
        int i = strlen(word) - 1;
        while (i >= 0 && !isalpha(word[i])) {
            word[i] = '\0';
            i--;
        }
        if (strlen(word) > 0) {
            word_count++;
        }
    }

    printf("Word count: %d\n", word_count);

    fclose(file);
    return 0;
}

