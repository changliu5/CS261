/* CS261- Assignment 1 - Q.2*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    *a = 2 * *a;/*Set a to double its original value*/
    
    *b = *b / 2;/*Set b to half its original value*/
    
    c = *a + *b;/*Assign a+b to c*/
    
    return c;/*Return c*/
}

int main(){
    int x = 7, y = 8 , z = 9;/*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    
    printf("x = %d, y = %d, z = %d (Before passing into foo)\n", x, y, z);/*Print the values of x, y and z*/
    
    int returnvalue = foo(&x,&y,z);/*Call foo() appropriately, passing x,y,z as parameters*/
    
    printf("The value returned by foo is %d\n", returnvalue);/*Print the value returned by foo*/
    
    printf("x = %d, y = %d, z = %d (After passing into foo)\n", x, y, z);/*Print the values of x, y and z again*/
 
    printf("\nThe return value is different than the value of z, because we passed the value of z into the function foo rather than the address of variable z, so all the activity inside the function foo doesn't affect the value of z\n");/*Is the return value different than the value of z?  Why?*/
    return 0;
}
    
    
