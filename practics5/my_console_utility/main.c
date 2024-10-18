#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"
#include "processes.h"
#include "utils.h"



void print_help() {
    printf("Usage:n");
    printf("  -u, --users          List users and their home directoriesn");
    printf("  -p, --processes      List running processes sorted by PIDn");
    printf("  -h, --help           Show this help messagen");
    printf("  -l PATH, --log PATH  Log output to specified filen");
    printf("  -e PATH, --errors PATH Log errors to specified filen");
}

int main(int argc, char *argv[]) {
    char *log_file = NULL;
    char *error_file = NULL;

    // Проверка наличия аргументов
    if (argc < 2) {
        handle_error("No arguments provided. Use -h for help.");
        return 1;
    }

    // Обработка аргументов командной строки
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--users") == 0) {
            list_users(log_file);
        } else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--processes") == 0) {
            list_processes(log_file);
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--log") == 0) {
            if (i + 1 < argc) {
                log_file = argv[++i];
            } else {
                handle_error("Missing path for log option");
                return 1;
            }
        } else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--errors") == 0) {
            if (i + 1 < argc) {
                error_file = argv[++i];
                freopen(error_file, "a", stderr); // Перенаправление stderr в файл
            } else {
                handle_error("Missing path for errors option");
                return 1;
            }
        }
    }

    return 0;
}

