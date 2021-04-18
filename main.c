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
  //  char line2[256];
    circle *ln1 = malloc(sizeof(circle));
  //  circle *ln2;
    fgets(line1, 20, stdin);

    n = strlen(line1);

    Check(line1, n, ln1);

    Perimeter(ln1);

    Square(ln1);

    printf("\n%.3f    %.3f\n", ln1->per, ln1->sq);

    return 0;
}
