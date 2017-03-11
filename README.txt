Usage: python3 main.py [input_file] [path_to_fib.so]
Fib.so is a c library that is currently compiled for Ubunutu, Linux. The library may need to be recompiled from fib.c to run on a specific machine. 
If using Windows, main.py source code has to be modified. Ctypes currently uses cdll, which is meant for linux-based machines.

