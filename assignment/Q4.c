/* CS261- Assignment 1 - Q.4*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(students[j].score > students[j+1].score){
                int temp1 = students[j].id;
                int temp2 = students[j].score;
                students[j].score = students[j+1].score;
                students[j].id = students[j+1].id;
                students[j+1].score = temp2;
                students[j+1].id = temp1;
            }
        }
    }/*Sort the n students based on their score*/
     /* Remember, each student must be matched with their original score after sorting */
}

int main(){
    int n = 20,i;/*Declare an integer n and assign it a value.*/
    
    struct student* students = malloc(n*sizeof(struct student*));/*Allocate memory for n students using malloc.*/
    
    for(i=0;i<n;i++){
        students[i].id = i + 1;
        students[i].score = rand() % 101;
    }/*Generate random IDs and scores for the n students, using rand().*/
    
    for(i=0;i<n;i++)
        printf("Student ID: %d Score: %d\n", students[i].id,students[i].score);/*Print the contents of the array of n students.*/

    sort(students,n);/*Pass this array along with n to the sort() function*/
    printf("Sorting....\n");
    for(i=0;i<n;i++)
        printf("Student ID: %d Score: %d\n", students[i].id,students[i].score);/*Print the contents of the array of n students.*/
    
    return 0;
}
