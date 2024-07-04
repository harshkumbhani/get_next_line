# Get Next Line

The Get Next Line project aims to code a function that behaves like the [``getline()``](https://man7.org/linux/man-pages/man3/getline.3.html#:~:text=getline()%20reads%20an%20entire,buffer%20for%20storing%20the%20line.) function in C standard library. 

## Description

The function must have the following prototype: `char *get_next_line(int fd);`

This function returns a line read from a file descriptor, without the newline. 

A "line" is defined as a succession of characters that end with `\n` (ascii code 0x0a) or with End Of File (EOF).

### Features

- The function get_next_line reads from a file and returns one line ending with a newline each time it's called.
- The reading must be done from the file descriptor only once.
- This project includes handling multiple file descriptors.
- It properly manages the reading of large files and the latency that it implies.

### Usage

- Include "get_next_line.h" in your C file.
- Use the function as such: `char *line = get_next_line(fd);`
- Compile with flags: gcc -Wall -Wextra -Werror
- Compile with get_next_line.c get_next_line_utils.c for mandatory part
- Compile with get_next_line_bonus.c get_next_line_utils_bonus.c for bonus part

### Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.
