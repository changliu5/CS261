#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
    char cmd = ' ';
    DynArr* mainList = createDynArr(10);
    
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
               );
        /* get input command (from the keyboard) */
        cmd = getchar();
        /* clear the trailing newline character */
        while (getchar() != '\n');
        switch (cmd) {
            case 'l':{
                char filename[100],*new;
                FILE* file;
                printf("Please enter the filename: ");
                if (fgets(filename, sizeof(filename), stdin) != NULL)
                {
                    new = strchr(filename, '\n');
                    if (new)
                        *new = '\0';
                }
                //scanf("%100s",filename);
                file = fopen(filename, "r");
                if(file == 0){
                    printf("Can't open it.");
                    break;
                }
                //while (getchar() != '\n');
                loadList(mainList, file);
                printf("The list has been loaded successfully.\n");
                break;
            }
            
            case 's':{
                if(sizeDynArr(mainList) == 0){
                    printf("your to-do list is empty.\n");
                    break;
                }
                char filename[100],*new;
                FILE* file;
                printf("Please enter the filename: ");
                if (fgets(filename, sizeof(filename), stdin) != NULL)
                {
                    new = strchr(filename, '\n');
                    if (new)
                        *new = '\0';
                }
                //scanf("%100s",filename);
                file = fopen(filename, "w");
                //while (getchar() != '\n');
                saveList(mainList, file);
                printf("The list has been saved successfully.\n");
                break;
            }
                
            case 'a':{
                char desc[TASK_DESC_SIZE],*new;
                int pri;
                printf("Please enter the task description: ");
                if (fgets(desc, sizeof(desc), stdin) != NULL)
                {
                    new = strchr(desc, '\n');
                    if (new)
                        *new = '\0';
                }
                //scanf("%100s", desc);
                do {
                    printf("Please enter the task priority (0-999): ");
                    scanf("%d", &pri);
                } while(pri < 0 || pri > 999);
                while (getchar() != '\n');
                TaskP newTask = createTask(pri, desc);
                addHeap(mainList, newTask,compare);
                printf("The task '%s' has been added to your to-do list.\n\n", desc);
                break;
            }
            
            case 'g':{
                if (sizeDynArr(mainList) > 0)
                {
                    TaskP firstTask = getMinHeap(mainList);
                    printf("Your first task is: %s\n\n", firstTask->description);
                }
                else
                    printf("Your to-do list is empty!\n\n");
                
                break;
            }
                
            case 'r':{
                if (sizeDynArr(mainList) > 0)
                {
                    TaskP firstTask = getMinHeap(mainList);
                    removeMinHeap(mainList,compare);
                    printf("Your first task '%s' has been removed from the list.\n\n", firstTask->description);
                    free(firstTask);
                }
                else
                    printf("Your to-do list is empty!\n\n");
                break;
            }
                
            case 'p':{
                if (sizeDynArr(mainList) > 0)
                {
                    printList(mainList);
                }
                else
                    printf("Your to-do list is empty!\n\n");
                
                break;
            }
            
            case 'e':{
                printf("Bye!\n\n");
                break;
            }
    
            default:{
                printf("Enter it again.\n\n" );
                break;
            }
        }
        /* Fixme:  Your logic goes here! */
        
        /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
    while(cmd != 'e');
    /* delete the list */
    deleteDynArr(mainList);
    
    return 0;
}