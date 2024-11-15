## Python

python has standard support for parameters. 
All you need is *import argparse* and fill in the parser object.

You can have options with or without flags.


```

>python AddNumbers.py -?
usage: AddNumbers.py [-h] [-f OUTFILE] [-v] x y
AddNumbers.py: error: the following arguments are required: x, y
>python AddNumbers.py 1 2
3
python AddNumbers.py 1 2 -v
1 + 2 equals 3.

>python AddNumbers.py 1 2 -v -f output.txt
```