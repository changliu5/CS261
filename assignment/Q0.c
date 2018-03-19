/* CS261- Assignment 1 - Q. 0*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
    printf("The value pointed to by iptr is %d\n", *iptr);/*Print the value pointed to by iptr*/
     
    printf("The address pointed to by iptr is %p\n", iptr);/*Print the address pointed to by iptr*/
     
    printf("The address of iptr itself is %p\n", &iptr);/*Print the address of iptr itself*/
}

int main(){
    
    int x = 0;/*declare an integer x*/
    
    printf("The address of x is %p\n", &x);/*print the address of x*/
    
    fooA(&x);/*Call fooA() with the address of x*/
    
    printf("The value of x is %d\n", x);/*print the value of x*/
    
    return 0;
}
