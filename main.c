#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
    printf("6. --exit to exit the app\n");
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
        printf("%s", line);
    }
    printf("\n");
    printf("=======================\n");
    printf("\n");

    fclose(fp);
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
    }
    

}