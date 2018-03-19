/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
    struct student* students = malloc(10*sizeof(struct student));/*Allocate memory for ten students*/
     
    return students;/*return the pointer*/
}

void generate(struct student* students){
    for(int i=0;i<10;i++){
        students[i].id = rand() % 10 + 1;
        students[i].score = rand() % 101;
    }/*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
     
}

void output(struct student* students){
    for(int i=0;i<10;i++){
        printf("Student#%d %d %d\n", i+1, students[i].id, students[i].score);
    }/*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
}

void summary(struct student* students){
    int min = 100, max = 0, sum = 0;
    float average = 0;
    for(int i=0;i<10;i++){
        if(students[i].score > max){
            max = students[i].score;
        }
        else if(students[i].score < min){
            min = students[i].score;
        }
        sum = sum + students[i].score;
    }
    average = sum / 10;
    printf("minimum = %d, maximum = %d, average = %f\n", min, max, average);
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     
}

void deallocate(struct student* stud){
     if(stud != NULL)
         free(stud);/*Deallocate memory from stud*/
}

int main(){
    struct student* stud = NULL;
    
    stud = allocate();/*call allocate*/
    
    generate(stud);/*call generate*/
    
    output(stud);/*call output*/
    
    summary(stud);/*call summary*/
    
    deallocate(stud);/*call deallocate*/

    return 0;
}
