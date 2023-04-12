# My Git Project

## Description

MyGit is a project to make a git-like program in C.
This project is made along with the course LU2IN006, at Sorbonne University.

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

## Authors

- AUDUGÉ Baptiste
- BENABOUD Taha
