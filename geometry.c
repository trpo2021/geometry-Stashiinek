#include <ctype.h>
#include <stdio.h>
#include <string.h>

void Check(char ch[], int n)
{
    int i = 0;

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

        if (isdigit(ch[i]))
            i++;
        else {
            printf("be3");
            return;
        }

        if (ch[i] == ' ')
            i++;
        else {
            printf("be4");
            return;
        }

        if (isdigit(ch[i]))
            i++;
        else {
            printf("be5");
            return;
        }

        while (ch[i] == ' ')
            i++;
        if (ch[i] == ',')
            i++;
        else {
            printf("be6");
            return;
        }

        while (ch[i] == ' ')
            i++;

        // float radius = 0;
        if (isdigit(ch[i])) {
            // radius = atof (ch[i]);
            i++;
            if (ch[i] == '.') {
                i++;
                if (isdigit(ch[i]))
                    i++;
            } else {
                printf("be7");
                return;
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

        while (i != 256) {
            if (isascii(ch[i])) {
                printf("be10");
                return;
            } else
                i++;
        }
        // a тут else count(radius);
    }
}

int main()
{
    int n = 0;

    char line[256];
    fgets(line, 256, stdin);

    n = strlen(line);

    char data[n];
    data[n] = line[256];
    Check(data, n);

    return 0;
}
