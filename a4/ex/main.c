#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "animalbst.h"
#include "struct.h"

int main(){
    struct BSTree *database = uploaddatabase();
    struct Node *curr = database->root;
    char  ans[4];
    while (curr != NULL) {
        print_type(curr->val);
        printf("\n");
        scanf("%3s", ans);
        if(strcmp(ans, "yes") == 0){
            if(curr->left == NULL){
                printf("Yeah, the animal you were thinking is ");
                print_type(curr->val);
                printf("\n");
            }
            curr = curr->left;
        }
        else if(strcmp(ans, "no") == 0){
            if(curr->right == NULL)
                printf("alright I can't figure out what you were thinking, I'm quit\n");
            curr = curr->right;
        }
        else
            printf("please enter 'yes' or 'no'");
        }
    
    return 0;
}
