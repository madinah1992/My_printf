# Welcome to My Printf
***

## Task
The very first thing we do when learning a programming language is to write "Hello World !" on the screen. Well guess what ? This custom comes from a notebook called ... Programming in C: A Tutorial !

Unfortunately for you, this project will bring you back in the 1970s, before the existence of this book, and you will have to write your own function to greet the world.

Fortunately for you, you will strengthen your programming skills and learn new programming concepts: variadic functions and variable argument lists. Recoding printf is also a good exercise to learn to have
a well structured code organisation. Modularity is the key here since printf has a lot of different options that you will have to recode yourself. Adding a new option feature should be easy and smooth if
the code is well designed !

## Description
The my_printf() function produce output according to a format as described below. The my_printf() functions write output to stdout, the standard output stream;

This function writes the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.

The format string is composed of zero or more directives: ordinary characters (not PERCENT), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.

Each conversion specification is introduced by the PERCENT character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the PERCENT, the following appear in sequence:

doux The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).
c The int argument is converted to an unsigned char, and the resulting character is written.
s The char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.
p The void * pointer argument is printed in hexadecimal.

## Installation
there is no need for any installation. it works on the terminal by giving the command.

## Usage
it will be use to do the following 
print output hello world,
simple output %c
simple output %s
simple output %d
simple output %o
simple output %p
simple output %x
```
./my_project argument1 argument2
MY PRINTF

### The Core Team
ABDULKARIM MADINAH OTNI

<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
