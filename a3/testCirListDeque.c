#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
        

	/* Test your linked list in here! */
    struct cirListDeque *list;
    list = createCirListDeque();
    printf("Testing...\n\nSet your list for [2,1]");
    addFrontCirListDeque(list, 1);
    addFrontCirListDeque(list, 2);
    printCirListDeque(list);
    printf("\nAdding 4 on the back...");
    addBackCirListDeque(list, 4);
    printCirListDeque(list);
    printf("\nAdding 3.14 on the front");
    addFrontCirListDeque(list, 3.14);
    printCirListDeque(list);
    printf("\nRemoving the first element...");
    removeFrontCirListDeque(list);
    printCirListDeque(list);
    printf("\nRemoving the last element...");
    removeBackCirListDeque(list);
    printCirListDeque(list);
    printf("\nAdd 3 and 4 in front, your list become[4,3,2,1]");
    addFrontCirListDeque(list, 3);
    addFrontCirListDeque(list, 4);
    printCirListDeque(list);
    printf("\nDo some megic to your list to make it reversed");
    reverseCirListDeque(list);
    printCirListDeque(list);
    printf("\n");

	//printf("Hello from test code!\n");
	return 0;
}


