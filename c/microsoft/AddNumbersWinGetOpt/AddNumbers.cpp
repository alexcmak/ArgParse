#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getopt.h"
//
// Alex Mak 2025
//
// Microsoft Visual Studio - Windows program that use wingetopt - NetBSD's implementation of getopt() and getopt_long()
// unlike IBM's implementation, Windows style /x will not work
// 
// Examples:
//
// AddNumbers -x 4 -y 5
// AddNumbers -y 5 -x 6 -v
// AddNumbers -x 3 -y 10 -f c:\answer.txt

// getopt_long() is case sensitive
// AddNumbers --VarX 4 --VarY 5
// AddNumbers --VarX 4 -y 5
// AddNumbers --VarX 4 -y 5 --file output.txt

void printUsage()
{
    printf("AddNumbers -x x -y y [-v][-f output.txt]\n");
    printf("or\n");
    printf("AddNumbers --VarX x --VarY y [--verbose][--file output.txt]\n");

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


    int verbose_flag = 0; // Flag to indicate if verbose option is present

    // Define long options
    static struct option long_options[] = {
        {"verbose", no_argument, &verbose_flag, 1}, // Sets verbose_flag to 1 if --verbose is used; only C++ allow this
        {"VarX", required_argument, 0, 'x'},        
        {"VarY", required_argument, 0, 'y'},
        {"file", required_argument, 0, 'f'},

        {0, 0, 0, 0}                               // Sentinel to mark the end of the array
    };

    while (1) {
        int option_index = 0;
        c = getopt_long(argc, argv, "x:y:vf:", long_options, &option_index);

        // Detect the end of the options
        if (c == -1)
            break;

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

    if (verbose_flag)
        printf("\nVerbose flag was set\n");


    return 0;
}