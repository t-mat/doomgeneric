#!/usr/bin/env python3
import fnmatch
import os

def read_file(filename):
    with open(filename, 'r', encoding='utf8') as f:
        return f.readlines()


def main():
    output_filename = "doomgeneric_amalgamed.c"
    include_patterns = [ "*.c" ]
    exclude_patterns = [ "doomgeneric_*.c", "i_sdl*.c" ]
    path = "."

    filenames = []
    for f in os.listdir(path):
        filename = os.path.join(path, f)
        if not os.path.isfile(filename):
            continue

        include = False
        for pattern in include_patterns:
            if fnmatch.fnmatch(filename, os.path.join(path, pattern)):
                include = True
        for pattern in exclude_patterns:
            if fnmatch.fnmatch(filename, os.path.join(path, pattern)):
                include = False
        if include:
            filenames.append(filename)

    with open(output_filename, "w") as output_file:
        for filename in filenames:
            print(f"filename={filename}")
            output_file.write("//\n")
            output_file.write(f"// filename={filename}\n")
            output_file.write("//\n")
            file_lines = read_file(filename)
            for line in file_lines:
                output_file.write(line)

if __name__ == '__main__':
    main()
