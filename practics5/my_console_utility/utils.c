
#include <stdio.h>
#include <stdlib.h>

void handle_error(const char *message) {
    fprintf(stderr, "Error: %sn", message);
    fflush(stderr); // Убедитесь, что все данные выведены немедленно
}

