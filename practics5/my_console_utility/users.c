#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <dirent.h>
#include "users.h"

void list_users(const char *log_file) {
    struct passwd *pw;
    FILE *output = log_file ? fopen(log_file, "a") : stdout;

    if (!output) {
        fprintf(stderr, "Error: Cannot open log filen");
        return;
    }

    // Считывание пользователей и их домашних директорий
    while ((pw = getpwent()) != NULL) {
        fprintf(output, "%s: %sn", pw->pw_name, pw->pw_dir);
    }
    
    endpwent();
    if (log_file) fclose(output);
}

