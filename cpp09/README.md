# cpp module 09
In this module there are three simple programs. First is using map, second stack and third is using vector   
[Back to Repo README](../README.md)

## ex00
Program which outputs the value of a certain amount of bitcoin on a certain date.
### input file
Program take file as argument that
- Each line in file must use the format: "date | value"
- A valid date will always be in the following format: Year-Month-Day
- A valid value must be either a float or a positive integer, between 0 and 1000

### usage
1. run command `make` inside ex00 directory -> this will create executable called `btc`
2. run executable like: `./btc <input_file>`

## ex01
Program that implements [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation#:~:text=In%20reverse%20Polish%20notation%2C%20the,5%20is%20added%20to%20it.)
### usage
1. run command `make` inside ex01 directory -> this will create executable called `RPN`
2. run executable like: `./RPN "<numbers> <operators>` for example `./RPN "7 8 +"`

## ex02
Program that implements merge insert-insertion sort/Ford-Johnson alorithm explained in volume 3 of  __The Art of Computer Programming__ written by Donald Knuth
### usage
1. run command `make` inside ex02 directory -> this will create executable called `PmergeMe`
2. run executable like: `./PmergeMe <number> <number> ..` like `./PmergeMe 6 7 2`


[← cpp module08](../cpp08/README.md) | [Repo Readme →](../README.md) 

