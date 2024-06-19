#include <stdio.h>
#include <string.h> // INIT. DEPENDENCIES
#include <stdlib.h>


struct node // CREATE NODE STRUCTURE
{
    int data;
    struct node *next; // THIS IS A POINTER VARIABLE
};

struct node *head = NULL; // INIT. THE NODES
struct node *currentNode = NULL;

void output()
{
    struct node *output = head;

    printf("[");
    while (output != NULL)
    {
        printf("%d, ", output->data);
        output = output->next;
    };

    printf("]\n");
}

void initNode(int data)
{                                                                        // CREATE NODE AT START
    struct node *listStart = (struct node *)malloc(sizeof(struct node)); // IMPLEMENT NODE
    listStart->data = data;                                              // INSERT VALUE
    listStart->next = NULL;                                              // MAKE IT THE CURRENT NODE

    head = listStart; // MAKE IT THE START
}

void newNode(int data)
{ // INSERT NODE AT END
    struct node *inputNode = (struct node *)malloc(sizeof(struct node));
    inputNode->next = NULL;
    inputNode->data = data;

    struct node *linkedList = head; // MAKE IT HEAD NODE

    while (linkedList->next != NULL) // CONTINUE UNTIL YOU HAVE NO NEW NODES
    {
        linkedList = linkedList->next; // PROCEED DOWN LINE
    }

    linkedList->next = inputNode; // MAKE INPUT THE NEW NODE
}

void deleteNode(int value)
{
    struct node *temp = head, *prev; // SET A NEW NODE STRUCTURE, MAKE IT HEAD NODE WITH A POINTER TO THE PREVIOUS NODE

    if (temp != NULL && temp->data == value)
    {
        head = temp->next;
        return;
    } // END OF IF STATEMENT

    while (temp != NULL && temp->data != value) // FIND NODE TO DELETE
    {
        prev = temp;
        temp = temp->next;
    } // END OF WHILE LOOP

    if (temp == NULL)
    {
        return;
    }

    prev->next = temp->next;
}

int listSize()
{
    // struct node *inputNode = (struct node *)malloc(sizeof(struct node));
    // inputNode -> next = NULL;

    struct node *linkedList = head;
    int totalSize = 0;

    while (linkedList != NULL)
    {
        linkedList = linkedList->next;
        totalSize++;
    }

    return totalSize;
}

void main()
{
    int userSelect;
    while (userSelect != 5)
    {
        printf("Welcome to the Linked List program. Please choose an operation.\n\n");
        printf("[1]: Add Node\n");
        printf("[2]: Delete Node\n");
        printf("[3]: Output List\n");
        printf("[4]: Get List Size\n");
        printf("[5]: Exit program\n\n");

        printf("Please enter your operation: ");
        scanf("%d", &userSelect);
        printf("\n");

        switch (userSelect)
        {
        case 1:
            int newValue; // OBSCENELY WEIRD VALUE FOR INIT.

            printf("Please enter your new value: ");
            scanf("%d", &newValue);
            printf("\n");

            if (head == NULL)
            {
                initNode(newValue);
            }
            else
            {
                newNode(newValue);
            }

            break;
        case 2:
            int deletedValue;
            if (head == NULL)
            {
                printf("There is nothing to delete.\n");
            }
            else
            {
                printf("Please enter the value you wish to delete: ");
                scanf("%d", &deletedValue);
                printf("\n");

                deleteNode(deletedValue);
            }

            break;
        case 3:
            if (head == NULL)
            {
                printf("There is nothing to output.\n");
            }
            else
            {
                output();
            }

            break;

        case 4:
            if (head == NULL)
            {
                printf("There is no list to get the size of.\n");
            }
            else
            {
                int completeList;

                completeList = listSize();

                printf("The list has %d integers within it.\n", completeList);
            }
            break;
        default:
            printf("There is no operation with that number. Try again.\n");
            break;
        } // END OF SWITCH
    }
};