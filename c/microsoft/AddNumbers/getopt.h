#ifndef _GETOPT_H
#define _GETOPT_H

int getopt(int argc, char* argv[], char* opstring);
extern char* optarg;
extern int opterr;

#endif