// NOTE: FORKING ONLY WORKS ON LINUX
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#ifndef CHILD_EXIT_CODE
#define CHILD_EXIT_CODE 42
#endif

#define EXPECTED_CODE 42

void childRoutine(pid_t pid, int valueArray[], int arraySize)
{
   
    printf("Child: [");
    for (size_t i = 0; i < arraySize; i++)
    {
        valueArray[i] = valueArray[i] + 1;
        printf("%d, ", valueArray[i]);
    }
    printf("]\n");

    exit(CHILD_EXIT_CODE);
}

void parentRoutine(pid_t pid, int valueArray[], int arraySize)
{
    int status;
    printf("Parent: PID is %d.\n", pid);
    printf("Parent: Waiting for Child with PID[%d]\n", pid);
    waitpid(pid, &status, 0); // WAIT FOR CHILD

    if (WIFEXITED(status))
    {
        printf("Parent: [");
        for (size_t i = 0; i < arraySize; i++)
        {
            printf("%d, ", valueArray[i]);
        }
        printf("]\n");
    }
}

int main()
{
    int valueArray[] = {0, 1, 2, 3, 4, 5};
    int arraySize = (sizeof(valueArray) / sizeof(int));

    pid_t pid;

    printf("Fork here.\n");
    pid = fork();
    if (pid == -1)
    {
        return EXIT_FAILURE;
    }
    printf("Fork successful!\n");

    if (pid == 0)
    {
        childRoutine(pid, valueArray, arraySize);
    }
    else if (pid > 0)
    {
        parentRoutine(pid, valueArray, arraySize);
    }
}