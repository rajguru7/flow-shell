#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LEN 512

typedef struct Node {
    char *name;
    char *command;
} Node;

Node node;

void parse_flow_file(FILE* flow_file) {
    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), flow_file)) {
        if (strncmp(line, "node=", 5) == 0) {
            node.name = strndup(line+5, strchr(line+5, '\n') - (line+5));
            printf("node name: %s\n", node.name);
            fgets(line, sizeof(line), flow_file);
            node.command = strndup(line+8, strchr(line+8, '\n') - (line+8));
            printf("node command: %s\n", node.command);
        }
    }
}

void execute_action(char* action_name) {
    if (strcmp(action_name, node.name) == 0) {
        char *args[] = { node.command, NULL };
        printf("output:\n");
        execvp(node.command, args);
    }
}

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Incorrect number of arguments");
        exit(1);
    }

    char *flow_file_name = argv[1];
    char *action_name = argv[2];
    
    FILE* flow_file = fopen(flow_file_name, "r"); 
    parse_flow_file(flow_file);
    execute_action(action_name);

    return 0;
}
