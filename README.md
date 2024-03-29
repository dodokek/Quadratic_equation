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
main.exe
~~~

## Comand line arguments

There are now three available command line flags:
- Start unit tests (-t, /t, --test)
- Start to write logs (-l, /l, --log)
- Call for help (-h, /h, --help)
- Includes loading screen (-g, /g, --graphics)

### Unit tests
Unit tests get the data from the specified file, named tests.txt. You can have the tests execute from your own file by writing the filename right after the call of this argument.
The execution of the main programm is supressed while running unit tests.
~~~
main.exe -t filename.txt
~~~

### Logging
This useful library can be copypasted in many different projects. It writes a tree of functions that are being called in real time!
The data is being writed into file log.txt, different file name coul be set by user.
~~~
main.exe -l logfile.txt
~~~

### Help
~~~
main.exe -h
~~~
By writing this you are being redirected to documentation, that is store in **html/index.html** 

### Graphics
~~~
main.exe -g
~~~
With this command line argument a new window will will be opened. In this window you'll be able to look on satisfying loading screen.
![Loading screen](https://github.com/dodokek/Quadratic_equation/blob/main/src/img/loading_screen.png?raw=true)

## Documentation

Documentation is provided by doxygen. 
Configuration file **doxyfile** is not recommended to be changed
To generate documentation you need to run doxygen by writing the following command:
~~~
doxygen
~~~

## Conclusion
You can use different libraries from my project separately they work perfectly one without another.
Bye. 
**DodoKek all rights reversed**                           
