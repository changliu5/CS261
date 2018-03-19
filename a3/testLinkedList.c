#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void assertTrue(int predicate, char *message)
{
    printf("%s: ", message);
    if (predicate)
        printf("PASSED\n");
    else
        printf("FAILED\n");
}

int main(int argc, char* argv[]) {
    struct linkedList *list;
    list = createLinkedList();
    printf("\n\nTesting function _initList and isEmptyList\n");
    assertTrue(isEmptyList(list) == 1, "fuction should return 1: ");
    printf("\nTesting addFrontList\n");
    printf("Your list is [1,2,3,4]\n");
    addFrontList(list, 4);
    addFrontList(list, 3);
    addFrontList(list, 2);
    addFrontList(list, 1);
    assertTrue(EQ(frontList(list), 1), "1st element is 1");
    assertTrue(EQ(backList(list), 4), "last element is 4");
    printf("Testing addBackList\nYour list is [1,2,3,4,5]\n");
    addBackList(list, 5);
    assertTrue(EQ(backList(list), 5), "last element is 5");
    printf("Removing last element on the back\nYour list is [1,2,3,4]\n");
    removeBackList(list);
    assertTrue(EQ(backList(list), 4), "last element is 4");
    assertTrue(EQ(frontList(list), 1), "1st element is 1");
    printf("Removing first element on the front.\nYour list is [2,3,4]\n");
    removeFrontList(list);
    assertTrue(EQ(frontList(list), 2), "1st element is 2");
    assertTrue(EQ(backList(list), 4), "last element is 4");
    printf("\nTesting bag function\n");
    printf("Adding 5 to the bag, list should be [2,3,4,5]\n");
    addList(list, 5);
    assertTrue(EQ(frontList(list), 2), "1st element is 2");
    assertTrue(EQ(backList(list), 5), "last element is 5");
    printf("Testing contain function.\n");
    assertTrue(containsList(list, 1) == 0, "Should not contain 1");
    assertTrue(containsList(list, 2) == 1, "it should contain 2");
    assertTrue(containsList(list, 3) == 1, "it should contain 3");
    assertTrue(containsList(list, 4) == 1, "it should contain 4");
    assertTrue(containsList(list, 5) == 1, "it should contain 5");
    assertTrue(EQ(frontList(list), 2), "1st element is 2");
    assertTrue(EQ(backList(list), 5), "last element is 5");
    printf("Removing 3 from bag.\n");
    removeList(list, 3);
    assertTrue(containsList(list, 2) == 1, "it should contain 2");
    assertTrue(containsList(list, 5) == 1, "it should contain 5");
    assertTrue(containsList(list, 4) == 1, "it should contain 4");
    assertTrue(containsList(list, 3) == 0, "Should not contain 3");
    assertTrue(EQ(frontList(list), 2), "1st element is 2");
    assertTrue(EQ(backList(list), 5), "last element is 5");
    
	/* Test your linked list in here! */

	printf("Goodbye from test code!\n");
	return 0;
}


