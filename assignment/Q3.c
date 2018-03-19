/* CS261- Assignment 1 - Q.3*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n){
    int i = 0,j = 0;
    for(j=0;j<n;j++){
        for(i=0;i<n-1;i++){
            if(number[i]>number[i+1]){
                int temp = number[i];
                number[i] = number[i+1];
                number[i+1] = temp;
            }
        }
    }/*Sort the given array number , of length n*/
}

int main(){
    int n = 20;/*Declare an integer n and assign it a value of 20.*/
    
    int* list = malloc(n*sizeof(int));/*Allocate memory for an array of n integers using malloc.*/
    
    int i = 0;
    for(i=0;i<n;i++)
        list[i] = rand() % (n+1);/*Fill this array with random numbers between 0 and n, using rand().*/
    
    for(i=0;i<n;i++)
        printf("The number#%d is %d\n", i+1, list[i]);/*Print the contents of the array.*/

    sort(list,n);/*Pass this array along with n to the sort() function.*/
    
    for(i=0;i<n;i++)
        printf("The sorted number#%d is %d\n", i+1, list[i]);/*Print the contents of the array.*/
    
    return 0;
}
