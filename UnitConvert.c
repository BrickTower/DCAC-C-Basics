#include <stdio.h>
#include <string.h>
#include <math.h>

void mileConversion()
{
    char miles[40];
    char exitCommand[] = "exit";

    printf("Welcome to Mile Conversion. Please enter any miles, and it will be converted to kilometers.\n");
    printf("Type \"exit\" at any time to leave.\n");

    while (strcmp(exitCommand, miles) != 0) // WHILE LOOP FOR PROGRAM
    {
        float milesFloat;
        float kilometers;

        printf("Please enter your number in miles: ");
        scanf("%s", miles);
        printf("\n");

        if (strcmp(miles, "exit") == 0)
        {
            break;
        } // END OF IF STATEMENT

        sscanf(miles, "%f", &milesFloat);

        kilometers = milesFloat * 1.609;

        printf("%s miles is equal to %.3f kilometer(s). \n\n", miles, kilometers);

    } // END OF WHILE LOOP

    return;
}

void inchConversion()
{
    char inches[40];
    char exitCommand[] = "exit";

    printf("Welcome to Inches Conversion. Please enter any inches, and it will be converted to centimeters.\n");
    printf("Type \"exit\" at any time to leave.\n");

    while (strcmp(exitCommand, inches) != 0) // WHILE LOOP FOR PROGRAM
    {
        float inchesFloat;
        float centimeters;

        printf("Please enter your number in inches: ");
        scanf("%s", inches);
        printf("\n");

        if (strcmp(inches, "exit") == 0)
        {
            break;
        } // END OF IF STATEMENT

        sscanf(inches, "%f", &inchesFloat);

        centimeters = inchesFloat * 2.54;

        printf("%s inches is equal to %.2f centimeter(s). \n\n", inches, centimeters);

    } // END OF WHILE LOOP

    return;
}

void degreeConversion()
{
    char degrees[40];
    char exitCommand[] = "exit";

    printf("Welcome to Degree Conversion. Please enter an angle in degrees, and it will be converted to radians.\n");
    printf("Type \"exit\" at any time to leave.\n");

    while (strcmp(exitCommand, degrees) != 0) // WHILE LOOP FOR PROGRAM
    {
        float degreeFloat;
        float radians;

        printf("Please enter your value: ");
        scanf("%s", degrees);
        printf("\n");

        if (strcmp(degrees, "exit") == 0)
        {
            break;
        } // END OF IF STATEMENT

        sscanf(degrees, "%f", &degreeFloat);

        radians = degreeFloat * (M_PI / 180);

        printf("%s degrees is equal to %.6f radians(s). \n\n", degrees, radians);

    } // END OF WHILE LOOP

    return;
}
void tempConversion()
{
    char fahrenheit[40];
    char exitCommand[] = "exit";

    printf("Welcome to Temperature Conversion. Please enter a temperature in Fahrenheit, and it will be converted to Celsius.\n");
    printf("Type \"exit\" at any time to leave.\n");

    while (strcmp(exitCommand, fahrenheit) != 0) // WHILE LOOP FOR PROGRAM
    {
        float fahrenFloat;
        float celsius;

        printf("Please enter the temperature in Fahrenheit: ");
        scanf("%s", fahrenheit);
        printf("\n");

        if (strcmp(fahrenheit, "exit") == 0)
        {
            break;
        } // END OF IF STATEMENT

        sscanf(fahrenheit, "%f", &fahrenFloat);

        celsius = (fahrenFloat - 32) * (5.0/9);

        printf("%s degrees Fahrenheit is %.2f degrees Celsius. \n\n", fahrenheit, celsius);

    } // END OF WHILE LOOP

    return;
}

int main()
{
    int numberSelect;

    printf("Welcome to Unit Conversion! Please enter what you'd like to convert.\n\n");
    printf("[1] Miles --> KM\n");
    printf("[2] Inches --> CM\n");
    printf("[3] Fahrenheit --> Celsius\n");
    printf("[4] Degrees --> Radians\n");

    printf("Please enter your conversion.\n");
    scanf("%d", &numberSelect);

    while (numberSelect > 4 || numberSelect < 1) // GUARD
    {
        printf("ERROR: CONVERSION IS NOT FOUND\n");
        printf("Please enter your conversion.\n");
        scanf("%d", &numberSelect);
    } // END OF WHILE LOOP

    switch (numberSelect)
    {
    case 1:
        mileConversion();
        break;
    case 2:
        inchConversion();
        break;
    case 3:
        tempConversion();
        break;
    case 4:
        degreeConversion();
        break;
    default:
        scanf("That number cannot be found.");
        break;
    } // END OF SWITCH

    return 0;
}
