#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include "processes.h"

void list_processes(const char *log_file) {
    FILE *output = log_file ? fopen(log_file, "a") : stdout;

    if (!output) {
        fprintf(stderr, "Error: Cannot open log filen");
        return;
    }

    DIR *proc = opendir("/proc");
    struct dirent *entry;

    // Считывание процессов из каталога /proc
    while ((entry = readdir(proc)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            char path[256];
            snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
            FILE *stat_file = fopen(path, "r");
            if (stat_file) {
                int pid;
                fscanf(stat_file, "%d", &pid);
                fprintf(output, "PID: %dn", pid);
                fclose(stat_file);
            }
        }
    }

    closedir(proc);
    if (log_file) fclose(output);
}


