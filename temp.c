#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// TODO: Make a ``temp'' struct that has value and unit props.
//
float fahr(float deg);
float cels(float deg);

int main(int argc, char **argv)
{
    char *errmess = "Please format the input correctly, like `69.0F` or `21.1c`.";

    if (argc == 2) {
        int i = 0;
        int j = 0;
        char *arg = argv[1];
        char ch = arg[i];
        int numdigs = strlen(arg) + 4;
        // TODO: Grab number of significant figures based on input
        // Relevant SO: https://stackoverflow.com/questions/16413609/printf-variable-number-of-decimals-in-float
        // int sigfigs;
        char temp[numdigs];
        char unit;
        // bool hasPeriod = false;
        // I thought I'd need to check for periods without numbers,
        //  or multiple periods, but it seems strtof doesn't have an
        //  issue with this
        float conv;

        while (ch != '\0') {
            if (isdigit(ch) || ch == '.' || (ch == '-' && j == 0)) {
                temp[j] = ch;
                j++;
            /*} else if (ch == '.') {
              if (hasPeriod) {
                  printf("%s\n", errmess);
                  break;
              } else {
                  temp[j] = ch;
                  j++;
                  hasPeriod = true;
              }*/
            } else if (ch == 'c' || ch == 'C') {
                unit = 'C';
            } else if (ch == 'f' || ch == 'F') {
                unit = 'F';
            }
            i++;
            ch = arg[i];
        }
        temp[j] = '\0';
        
        if (unit == 'C') {
            conv = fahr(strtof(temp, NULL));
        } else if (unit == 'F') {
            conv = cels(strtof(temp, NULL));
        } else {
            printf("%s\n", errmess);
        }
        // FIXME: Program still "executes" if the input was bad
        // Bad input prompting this ``44j''
        printf("%s%c = %.2f%c\n", temp, unit, conv, (unit == 'C' ? 'F' : 'C'));

    } else {
        printf("%s\n", errmess);
    }
    
    return 0;
}

float fahr(float deg)
{
    return ((9.0 * deg) + 160.0) / 5;
}

float cels(float deg)
{
    return (5.0 / 9.0) * (deg - 32.0);
}
