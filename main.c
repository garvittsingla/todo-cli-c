#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct todo{
    int id;
    char content[100];
    bool completed;
};

int helperfunction(){
    printf("The Correct usage of this tool is :\n");
    printf("1. --help to display help\n");
    printf("2. --list to display all todos\n");
    printf("3. --add  'Your todo here' to add a new todo\n");
    printf("4. --completed 'todoid'  to mark as completed a todo\n");
    printf("5. --delete 'todoid'  to delete a todo\n");
}

int displaytodos(){
    FILE *fp;
    fp = fopen("todo.txt", "r");
     if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    char line[100];

    printf("Your current Todos are:\n");
    printf("=======================\n");
    while (fgets(line, sizeof(line), fp)) {
            static int lines = 1;
            printf("%s", line);
            // lines++;
            // printf("%d",lines);
            // printf("New line\n");
        
    }
    printf("\n");
    printf("=======================\n");
    printf("\n");

    fclose(fp);
}

void addTodo(char todo[100]){
    FILE *fptr;
    static int todoid = 1;
    fptr = fopen("todo.txt", "r");
     if (fptr == NULL) {
        printf("Error opening file for reading.\n");
        return ;
    }

    char line[100];
    while (fgets(line, sizeof(line), fptr)) {
            todoid++;
    }
    

    fptr = fopen("todo.txt", "a");
    fprintf(fptr,"\n");
    fprintf(fptr,"%d", todoid);
    fprintf(fptr,"%s", " ");
    fprintf(fptr,"%s", todo);
    fprintf(fptr,"%s", " false");
    fclose(fptr);
}

void completetodo(int todoid){
    FILE *fptr;
    static int lines = 1;
    // fptr = fopen("todo.txt", "r");
    //  if (fptr == NULL) {
    //     printf("Error opening file for reading.\n");
    //     return ;
    // }

    // char line[100];
    // while (fgets(line, sizeof(line), fptr)) {
    //     if (lines == todoid){
            
    //     }
    //         lines++;
    // }

    printf("Function under maintenance\n");
}
void deletetodo(int todoid){
    printf("Function under maintenance");
}
int main (int argc,char *argv[]){

    printf("Welcome to Todo List -- Made by @garvittsingla\n");

    

    if (argc < 2){
        printf("No arguments provided\n");
        helperfunction();
    }
    if (strcmp(argv[1],"--help")==0){
        helperfunction();
    }else if (strcmp(argv[1],"--list")==0){
        displaytodos();
    }else if (strcmp(argv[1] , "--add")==0){
        if (argc < 3){
            printf("Invalid usage\n");
            helperfunction();
        }else{
            char combined_todo[1000] = "";
            for(int i = 2; i < argc; i++) {
                strcat(combined_todo, argv[i]);
                if (i < argc - 1) {
                    strcat(combined_todo, " ");
                }
            }
            addTodo(combined_todo);
        }
    }else if (strcmp(argv[1],"--completed")==0){
         completetodo(atoi(argv[2]));
    }else if (strcmp(argv[1],"--delete")==0){
       deletetodo(atoi(argv[2]));
    }else{
        printf("Invalid Usage\n");
        helperfunction();
    }
    

}