# Get Next Line (GNL)

This project implements the **`get_next_line`** function, which reads a line from a file descriptor. The function is designed to handle different file descriptors simultaneously and efficiently, with support for bonus features.

## Files and Structure

### Mandatory Files:
1. [**`get_next_line.c`**](https://github.com/Ahdad0/get_next_line/blob/master/get_next_line.c)
   - Core implementation of the `get_next_line` function.
2. [**`get_next_line.h`**](https://github.com/Ahdad0/get_next_line/blob/master/get_next_line.h)  
   - Header file containing declarations for the `get_next_line` function and necessary macros.
3. [**`get_next_line_utils.c`**](https://github.com/Ahdad0/get_next_line/blob/master/get_next_line_utils.c)
   - Utility functions to support `get_next_line` (e.g., string manipulation, memory management).

### Bonus Files:
1. [**`get_next_line_bonus.c`**](https://github.com/Ahdad0/get_next_line/blob/master/get_next_line_bonus.c)
   - Extended functionality for `get_next_line` to handle multiple file descriptors simultaneously.
2. [**`get_next_line_bonus.h`**](https://github.com/Ahdad0/get_next_line/blob/master/get_next_line_bonus.h)
   - Header file containing declarations for the bonus version.
3. [**`get_next_line_utils_bonus.c`**](https://github.com/Ahdad0/get_next_line/blob/master/get_next_line_utils_bonus.c)
   - Utility functions for the bonus version of `get_next_line`.

### Compilation:
- **`CC`**: Compiler used for building the project (e.g., `gcc`).

## Usage

### Compilation
Compile the project using the provided source files. For example:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

For the bonus version:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```
