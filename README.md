# Command Line Parsing

The venerable command line tool has its origins from Unix programs. [Utility Conventions](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap12.html)
Early programs have command line options are marked by dash (-) and a single letter.

Later command line options use two dashes (--) and often have fully spelled words. [GNU Interface](https://www.gnu.org/prep/standards/html_node/Command_002dLine-Interfaces.html)

For DOS based command line programs, the options are marked by the forward slash (/).

A good command line program will have familiar conventions such as:
* -h and -? options that will list all available parameters and descriptions of each.
* ordering of parameters does not matter -a -b works the same way as -b -a
* -v for verbose

## C 

In the olden days, but not crazy old days of computing (80's to 90's), one of the biggest languages at the time was C. 
C did not, and still does not include a standard way to parse command lines. If you work with Unix, and Linux, there is 
[getopt()](https://en.wikipedia.org/wiki/Getopt) which is part of the [POSIX](https://en.wikipedia.org/wiki/POSIX) standard. If you work on the PC and offered DOS based products, you are on your own.

Many companies would use widely available open source code and use an implementation of getopt() or invent some way to handle command line parameters with varying degrees of success.

## C#

You'd think C# have a standard way to handle command line. No, there is not. 

There are several competing NuGet libraries that you can use. A NuGet solution is often OK, but if you want to ship a product you will also need to ship the DLL. Libaries love to change, and all the time. The programmer often need to waste time to keep up with usually unnecessary and breaking changes.

I find the [CommandLineParser](https://github.com/commandlineparser/commandline) package the most intutive.

## Python

python has **argparse**. It is not perfect, it is include in the Python Standard Library.