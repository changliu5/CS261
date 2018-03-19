#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "dynamicArray.h"


/* param: s the string
 param: num a pointer to double
 returns: true (1) if s is a number else 0 or false.
 postcondition: if it is a number, num will hold
 the value of the number
 */
int isNumber(char *s, double *num)
{
    char *end;
    double returnNum;
    
    if(strcmp(s, "0") == 0)
    {
        *num = 0;
        return 1;
    }
    else
    {
        returnNum = strtod(s, &end);
        /* If there's anythin in end, it's bad */
        if((returnNum != 0.0) && (strcmp(end, "") == 0))
        {
            *num = returnNum;
            return 1;
        }
    }
    return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their sum is pushed back onto the stack.
 */
void add (struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
    int num1,num2;
    num1 = topDynArr(stack);
    popDynArr(stack);
    num2 = topDynArr(stack);
    popDynArr(stack);
    num1 = num1 + num2;
    pushDynArr(stack, num1);
    /* FIXME: You will write this function */
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their difference is pushed back onto the stack.
 */
void subtract(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
    int num1,num2;
    num1 = topDynArr(stack);
    popDynArr(stack);
    num2 = topDynArr(stack);
    popDynArr(stack);
    num1 = num2 - num1;
    pushDynArr(stack, num1);

    /* FIXME: You will write this function */
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their quotient is pushed back onto the stack.
 */
void multiply(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
    int num1,num2;
    num1 = topDynArr(stack);
    popDynArr(stack);
    num2 = topDynArr(stack);
    popDynArr(stack);
    num1 = num1 * num2;
    pushDynArr(stack, num1);

}
void divide(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
    int num1,num2;
    num1 = topDynArr(stack);
    popDynArr(stack);
    num2 = topDynArr(stack);
    popDynArr(stack);
    if(num1 == 0){
        printf("Error(divide by 0)\n");
        return;
    }
    num1 = num2 / num1;
    pushDynArr(stack, num1);

    /* FIXME: You will write this function */
}

void power(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
    int num1,num2;
    num1 = topDynArr(stack);
    popDynArr(stack);
    num2 = topDynArr(stack);
    popDynArr(stack);
    num1 = pow(num2, num1);
    pushDynArr(stack, num1);
    
}

void square(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
    int num1;
    num1 = topDynArr(stack);
    popDynArr(stack);
    num1 = pow(num1, 2.0);
    pushDynArr(stack, num1);

}

void cube(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
    int num1;
    num1 = topDynArr(stack);
    popDynArr(stack);
    num1 = pow(num1, 3.0);
    pushDynArr(stack, num1);

}

void absolute(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
    int num1;
    num1 = topDynArr(stack);
    popDynArr(stack);
    num1 = abs(num1);
    pushDynArr(stack, num1);

}

void sqroot(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
    int num1;
    num1 = topDynArr(stack);
    popDynArr(stack);
    if(num1 < 0){
        printf("Error(squart root of a negative number");
        return;
    }
    num1 = sqrt(num1);
    pushDynArr(stack, num1);

}

void exponent(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
    int num1;
    num1 = topDynArr(stack);
    popDynArr(stack);
    num1 = exp(num1);
    pushDynArr(stack, num1);

}

void naturalLog(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
    int num1;
    num1 = topDynArr(stack);
    popDynArr(stack);
    if(num1 < 0){
        printf("Error(natural log with a negative number");
        return;
    }
    num1 = log(num1);
    pushDynArr(stack, num1);

}

void commonLog(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
    int num1;
    num1 = topDynArr(stack);
    popDynArr(stack);
    if(num1 < 0){
        printf("Error(log with a negative number");
        return;
    }
    num1 = log10(num1);
    pushDynArr(stack, num1);

}

double calculate(int numInputTokens, char **inputString)
{
    int i;
    double result = 0.0;
    char *s;
    struct DynArr *stack;
    
    //set up the stack
    stack = createDynArr(20);
    
    // start at 1 to skip the name of the calculator calc
    for(i=1;i < numInputTokens;i++)
    {
        s = inputString[i];
        
        // Hint: General algorithm:
        // (1) Check if the string s is in the list of operators.
        //   (1a) If it is, perform corresponding operations.
        //   (1b) Otherwise, check if s is a number.
        //     (1b - I) If s is not a number, produce an error.
        //     (1b - II) If s is a number, push it onto the stack
        
        if(strcmp(s, "+") == 0)
            add(stack);
        else if(strcmp(s,"-") == 0)
            subtract(stack);
        else if(strcmp(s, "/") == 0)
            divide(stack);
        else if(strcmp(s, "x") == 0)
        /* FIXME: replace printf with your own function */
            multiply(stack);
        else if(strcmp(s, "^") == 0)
        /* FIXME: replace printf with your own function */
            power(stack);
        else if(strcmp(s, "^2") == 0)
        /* FIXME: replace printf with your own function */
            square(stack);
        else if(strcmp(s, "^3") == 0)
        /* FIXME: replace printf with your own function */
            cube(stack);
        else if(strcmp(s, "abs") == 0)
        /* FIXME: replace printf with your own function */
            absolute(stack);
        else if(strcmp(s, "sqrt") == 0)
        /* FIXME: replace printf with your own function */
            sqroot(stack);
        else if(strcmp(s, "exp") == 0)
        /* FIXME: replace printf with your own function */
            exponent(stack);
        else if(strcmp(s, "ln") == 0)
        /* FIXME: replace printf with your own function */
            naturalLog(stack);
        else if(strcmp(s, "log") == 0)
        /* FIXME: replace printf with your own function */
            commonLog(stack);
        else
        {
            TYPE num;
            if(isNumber(s, &num) == 0){
                if(strcmp(s,"pi") == 0)
                    pushDynArr(stack, 3.14159265);
                else if(strcmp(s, "e") == 0)
                    pushDynArr(stack, 2.7182818);
                else
                    printf("Oops, something wrong");
            }
            else
                pushDynArr(stack, num);
            // FIXME: You need to develop the code here (when s is not an operator)
            // Remember to deal with special values ("pi" and "e")
            
        }
    }	//end for
    if(sizeDynArr(stack) != 1){
        printf("Oops, something wrong");
        return 0;
    }
    result = topDynArr(stack);
    printf("The result is %f\n", result);
    /* FIXME: You will write this part of the function (2 steps below) 
     * (1) Check if everything looks OK and produce an error if needed.
     * (2) Store the final value in result and print it out.
     */
    
    return result;
}

int main(int argc , char** argv)
{
    // assume each argument is contained in the argv array
    // argc-1 determines the number of operands + operators
    if (argc == 1)
        return 0;
    
    calculate(argc,argv);
    return 0;
}