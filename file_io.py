import os.path

def read_in(input):
    if not os.path.isfile(input):
        print ("ERROR in read_in(): input file " + str(input) + " not found.")
        return 1
    lines = [line.strip() for line in (open(input, 'r')).readlines()]

    t = int(lines[0])
    if len(lines) != t+1:
        print("ERROR in read_in(): first line should specify the number of subsequent lines.")
        return 1

    n = [line for line in lines[1:]]

    return n


def write_out(output_file, soln):
    with open(output_file, 'w') as output:
        for ans in soln:
            output.write(str(ans) + "\n")

