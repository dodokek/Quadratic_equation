# Quadratic_equation
## Overview
Meet the true approach for solving quadratic equation. With this tiny program you can easily solve:
- Quadratic equations
- Linear equations
- Round equations

It also includes a libraries, which allow you to:
- Read command line arguments
- Run unit tests on my poor program
- Write logs of executing functions 

The program is separated on files, that's why make file is included.

## Installation

First and foremost you need to clone the repo and build the project with makefile.

~~~
git clone https://github.com/dodokek/Quadratic_equation.git                               
cd Quadratic_equation/src                                                                     
make                                                           
~~~

Execute the programm:
~~~
square_equation.exe
~~~

## Comand line arguments

There are now three available command line flags:
- Start unit tests (-t, /t, --test)
- Start to write logs (-l, /l, --log)
- Call for help (-h, /h, --help)

### Unit tests
Unit tests get the data from the specified file, named tests.txt. You can have the tests execute from your own file by writing the filename right after the call of this argument.
~~~
square_equation.exe -t filename.txt
~~~

### Logging
This useful library can be copypasted in many different projects. It writes a tree of functions that are being called in real time!
The data is being writed into file log.txt, different file name coul be set by user.
~~~
square_equation.exe -l logfile.txt
~~~

### Help
~~~
square_equation.exe -h
~~~
By writing this you are being redirected to documentation, which is stored in **html/index.html** 

## Conclusion
This project gave me an insane amount of knowledge about C/C++, i hope you will respect my code :3