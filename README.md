# Grep simulation
Implemented the grep command found in linux using C language.



## To run on your machine

Clone the repository,
move into the project directory

Type these commands
```
make final
./grep [OPTION...] [FILE...]

```



## Options supported

```
    --help: Output this page

    -r: Searches recursively in the current working directory (./grep -r PATTERN ./ )

    -c: Suppress normal output; instead print a count  of  matching
        lines  for  each  input  file.

    -h: Suppress  the  prefixing  of file names on output. This is
        the default

    -i: Ignore  case  distinctions,  so that characters that differ
        only in case match each other.

    -l: print the name of each input file from  which  output  
        would normally  have  been printed.

    -n: prefix the lines with their line number

    -w: match whole word

    -v: invert match

    -L: list of files that do not contain the given pattern 

    -o: print only the matched parts of a matching line 

    -H: Suppress  the  prefixing  of file names on output. This
        is the default when there is only one filename
```        