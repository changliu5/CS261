/* CS261- Assignment 1 - Q.5*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void studly(char* word){
    int i = 0;
    while(1 == 1){
        if(word[i] == '\0')
            break;
        else if(i % 2 == 0){
            if(((int) word[i] >=97) & (((int)word[i])  <= 122))
                word[i] = toUpperCase(word[i]);
            
        }
        else{
            if(!((int) word[i] >=97) || !(((int)word[i])  <= 122))
                word[i] = toLowerCase(word[i]);
        }
        i++;
    }
    /*Convert to studly caps*/
}

int main(){
    char *word;
    word = malloc(100 * sizeof(char*));
    printf("Please enter your word: ");
    scanf("%s", word);
    /*Read word from the keyboard using scanf*/
    
    studly(word);/*Call studly*/
    
    printf("%s\n", word);/*Print the new word*/
    
    return 0;
}
