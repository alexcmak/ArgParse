#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getopt.h"
//
// Alex Mak 2024
//
// Microsoft Visual Studio - Windows program that use IBM's implementation of getopt()
// programs must keep track of required options, and cannot really mix with options without parameters
// 
// Examples:
//
// AddNumbers -x 4 -y 5
// AddNumbers -y 5 -x 6 -v
// AddNumbers -x 3 -y 10 -f c:\answer.txt
// AddNumbers /x 4 /y 7

void printUsage()
{
    printf("AddNumbers -x x -y y [-v][-f output.txt]\n");
}

int main(int argc, char* argv[])
{

    int c; // a char in C is really an integer

    int x = 0;
    int y = 0;

    int x_specified = 0;
    int y_specified = 0;
    int v_specified = 0;
    int f_specified = 0;
    char output_file[256];

    while ((c = getopt(argc, argv, "x:y:vf:")) != -1)
    {
        switch (c)
        {
        case 'x':
            x = atoi(optarg);
            x_specified = 1;
            break;
        case 'y':
            y = atoi(optarg);
            y_specified = 1;
            break;
        case 'v':
            v_specified = 1;
            break;
        case 'f':
            f_specified = 1;
            strcpy(output_file, optarg);
            break;
        case '?':
            printf("Unknown option specified\n");
            break;
        }

    }

    if (x_specified && y_specified)
    {
        int answer = x + y;

        char response[100];

        sprintf(response, "%d", answer);

        if (v_specified)
        {
            sprintf(response, "%d + %d equals %d.\n", x, y, answer);
        }

        if (f_specified)
        {
            FILE* fp = fopen(output_file, "w");
            if (fp != NULL)
            {
                fprintf(fp, "%s", response);
                printf("answer written in %s", output_file);
                fclose(fp);
            }
        }
        else
        {
            printf("%s", response);
        }
    }
    else
    {
        printUsage();
        return 1;
    }

    return 0;
}