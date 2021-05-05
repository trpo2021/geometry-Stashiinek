#include "geometry.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

int main()
{
    int n = 0;

    char line1[256] = {"\0"};
    char line2[256];
    circle *ln1 = malloc(sizeof(circle));
    circle *ln2 = malloc(sizeof(circle));
    fgets(line1, 20, stdin);
    //printf("\n");

    n = strlen(line1);
    Check(line1, n, ln1);

    fgets(line2, 20, stdin);
    n = strlen(line2);
    Check(line2, n, ln2);

    Perimeter(ln1);
    Square(ln1);
    printf("\nPerimeter of 1st figure: %.3f    Square of 1st figure: %.3f\n", ln1->per, ln1->sq);

    Perimeter(ln2);
    Square(ln2);
    printf("Perimeter of 2nd figure: %.3f    Square of 2nd figure: %.3f\n", ln2->per, ln2->sq);

    int e = Executes(ln1, ln2);
    printf("\nExecutes: %d\n", e);
    return 0;
}
