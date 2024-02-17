# My Git Project

This project is a simplified version of the Git version control system. It allows you to initialize a new repository, create and delete references, add files to the staging area, list and clear the staging area, and create new commits.
You can also merge references, list the commits of a reference, and display the content of a commit.

## Implementation

The project is implemented in C, no external library is used. The project is divided into several folders:

* `src`: contains the source code of the project (`.c` files)
* `include`: contains the header files of the project (`.h` files)
* `doc`: contains the documentation of the project (`.html` or `.tex` files, the documentation is created using Doxygen)
* `Makefile`: contains the instructions to compile the project
* `README.md`: contains the documentation of the project

The project is divided into several modules, each module is subdivided into several files for better organization:

* `add`: contains the functions to add files to the staging area
* `branch`: contains the functions to create and delete branches
* `checkout`: contains the functions to switch branches
* `commit`: contains the functions to create and display commits
* `init`: contains the functions to initialize a new repository
* `libs`: contains the functions to manipulate the files and the strings
    * `cell`: contains the functions to manipulate the cells of a linked list
    * `commit`: contains the functions to manipulate the commits
    * `file`: contains the functions to manipulate the files, create a blob, manage the permissions, and the file mode
    * `hash`: contains the functions to manipulate the hash of a file and a commit
    * `key_val`: contains the functions to manipulate the key-value pairs
    * `list`: contains the functions to manipulate the linked lists with the different types of data
    * `work_file`: contains the functions to manipulate the working files
    * `work_tree`: contains the functions to manipulate the working tree (based on the `work_file` module)
* `merge`: contains the functions to merge branches
* `mygit`: contains the functions to manage the project and the user interface
* `ref`: contains the functions to manipulate the references
* `utils`: contains some useful functions

## Usage

### Compilation

To compile the project, you need to run the following command:

```bash
make
make clean
```

### Execution

To execute the project, you need to run the following command:

```bash
./mygit.out <command> <args>
```

### Commands and arguments

* `init`: initialize a new repository
* `list-refs`: list all the references
* `create-ref`: create a new reference
  * `ref`: the name of the reference
  *  `hash`: the hash of the commit
* `delete-ref`: delete a reference
  * `ref`: the name of the reference
* `add`: add a file to the staging area
  * `file`: the name of the file
  * `[<file1>, <file2>, ...]`: the name of the files ***(optional)***
* `list-add`: list all the files in the staging area
* `clear-add`: clear the staging area
* `commit`: create a new commit
  * `branch`: the name of the branch
  * `-m <message>`: the message of the commit ***(optional)***

### Date

2022-2023

