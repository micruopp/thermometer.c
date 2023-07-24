# temp

A simple program to convert Fahrenheit to Celsius or vice versa.

This is currently just a command line toy, and isn't built for use by programs.

## Installation

Download this code and navigate into its directory.

Then compile it with your favorite C compiler like
`gcc temp.c -o temp`
or
`clang temp.c -o temp`

## Usage
Unless you write your own script or add the project directory to your `PATH`, you'll need to navigate to the project directory to run the program.

Once there, enter the temperature you want to convert as a number followed by the character 'c' / 'C' or 'f' / 'F', no spaces, like

`./temp 69.0F`

or

`./temp -12.3c`

The decimal is not needed:

`./temp 21f`
