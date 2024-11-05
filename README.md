# CPP modules 
In this 9 modules I was writing simple solutions to learn about object oriented programming in **C++ 98 Standard**. Each exercise have its own Makefile that will compile it source code which will result in executable. 
## Usage
1. Navigate to the directory of exercise. For example `cd cpp00/ex01`
2. In exercise directory run `make` to make executable
3. Run executable like `./phone`

*Note: each exercise will create executable with their own name and some of them require argument(s). In every Makefile there are at least this 4 rules
- `make` -> create all object files and executable
- `make clean` -> deletes all object files, but **keep executable**
- `make fclean` -> deletes all object files **and executable** 
- `make re` -> deletes all object files and executable and then make them again

## Modules
* [cpp00 - simple stuff about c++](./cppmodules/cpp00/README.md)