#include "geometry.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define UNUSED(x) (void)(x)

// typedef struct circle circle;

void Check(char ch[], int n, circle* ring)
{
    UNUSED(n);
    int i = 0;

    char x[20], y[20], radius[20];
    int count = 0;

    while (ch[i] == ' ')
        i++;
    if (ch[i] == 'c') {
        i++;
        char example[6] = {"circle"};
        for (int k = 1; k < 6; k++) {
            if (ch[i] != example[k]) {
                printf("be1");
                return;
            } else
                i++;
        }

        while (ch[i] == ' ')
            i++;

        if (ch[i] != '(') {
            printf("be2");
            return;
        } else
            i++;

        while (ch[i] == ' ')
            i++;

        if (isdigit(ch[i])) {
            x[count] = ch[i];
            count++;
            i++;
        } else {
            printf("be3");
            return;
        }

        if (ch[i] == ' ')
            i++;
        else {
            printf("be4");
            return;
        }

        count = 0;
        if (isdigit(ch[i])) {
            y[count] = ch[i];
            count++;
            i++;
        } else {
            printf("be5");
            return;
        }

        while (ch[i] == ' ')
            i++;
        if (ch[i] == ',') {
            y[count] = ch[i];
            count++;
            i++;
        } else {
            printf("be6");
            return;
        }

        while (ch[i] == ' ')
            i++;

        count = 0;
        // float radius = 0;
        if (isdigit(ch[i])) {
            radius[count] = ch[i];
            count++;
            // radius = atof (ch[i]);
            i++;
            if (ch[i] == '.') {
                radius[count] = ch[i];
                count++;
                i++;
                if (isdigit(ch[i])) {
                    radius[count] = ch[i];
                    count++;
                    i++;
                } else {
                    printf("be7");
                    return;
                }
            }

        } else {
            printf("be8");
            return;
        }

        while (ch[i] == ' ')
            i++;

        while (ch[i] == ' ')
            i++;
        if (ch[i] != ')') {
            printf("be9");
            return;
        } else
            i++;

        while (i != n - 1) {
            if (isascii(ch[i])) {
                printf("be10");
                return;
            } else
                i++;
        }

        // a тут else count(radius)
    }
    ring->x = strtod(x, NULL);
    ring->y = strtod(y, NULL);
    ring->radius = strtod(radius, NULL);
}

void Perimeter(circle* ring)
{
    ring->per = ring->radius * 2 * 3.14;
}

void Square(circle* ring)
{
    ring->sq = ring->radius * ring->radius * 3.14;
}

int Executes(circle* ring1, circle* ring2)
{
    if ((ring1->x + ring1->radius) == (ring2->x + ring2->radius)) {
        return 1;
    } else if ((ring2->x + ring2->radius) == (ring1->x + ring2->radius)) {
        return 1;
    }

    if ((((ring1->x + ring1->radius) > (ring2->x + ring2->x))
         && ((ring1->x - ring1->radius) < (ring2->x - ring2->radius)))) {
        return 0;
    }
    if ((ring1->x + ring1->radius) > ring2->x) {
        return 2;
    } else if ((ring2->x + ring2->radius) > ring1->x) {
        return 2;
    }

    if ((ring1->y + ring1->radius) > ring2->y) {
        return 2;
    } else if ((ring2->y + ring2->radius) > ring1->y) {
        return 2;
    }

    return 0;
}
