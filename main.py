import sys
import file_io, os
import ctypes


def byteland(argv):
    if len(argv) < 2: print("\nERROR: Input file must be specified as the first parameter.")
    if len(argv) < 3: print("\nERROR: C library path must be specified as the second parameter")

    elif not os.path.isfile(argv[2]):
        print ("ERROR in read_in(): c library " + str(argv[2]) + " not found.")
        return 1

    else:
        input = argv[1]
        clib_path = argv[2]

        # WINDOWS requires a different implementation for dynamic library
        ctypes.cdll.LoadLibrary(clib_path)
        clib = ctypes.CDLL(clib_path)

        n = file_io.read_in(input)
        size = len(n)
        soln = (ctypes.c_longlong*size)()

        print("\nFiles loaded, scanning the landscape.")

        #finding the number of n-length byte strings without 00s is akin to finding the nth fibonacci number
        #this is handled in C
        for i in range(len(n)):
            ctype_n = (ctypes.c_longlong)(int(n[i]))
            clib.fib_string((ctypes.c_int)(i), ctype_n, soln) #pass to c function

        file_io.write_out("output.txt", soln)
        print("\nFinished exploring byteland.")


if __name__ == "__main__":
    byteland(sys.argv)
