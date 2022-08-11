# Bitwise Operators

A program using the XOR operator that creates an encrypted version of a given file using a key. If the output file is passed in with the same key, the output will be the original text.

## Usage

`./main [key] [input file] [output file]`

I've included a text file containing lorem ipsum for easy testing.

## General Repo Notes

### Build System

With most languages and most projects it's wise to use some form of build system, this is for a couple of reasons.

Firstly to indicate the language level as that can affect how tools interact with the code, particularly how editors view the code.

For example, the default language level of my installed `g++` (and `clang++` for that matter) was C++98 which meant lines like:

```c++
std::ifstream input_file{ argv[2], std::ios::binary | std::ios::in };
```

, would show errors in my editor and on compilation as brace-initialization didn't exist (at least not in this context) at that time.

Secondly to provide some straightforward way of building the code. I've added a simple Makefile to the project (simple in it's operation, the syntax is a bit terse I'll admit), this means that to build the project and spit out a binary I just need to run `make`.

A secondary benefit of this is to generate a [`compile_commands.json`](https://clang.llvm.org/docs/JSONCompilationDatabase.html#build-system-integration) file - C++ doesn't have a single canonical build system or set of supporting dev tools, however one idea that has become standard is the `compile_commands` file which can be used to tell the intellisense of editors how to interpret the files.

By using a tool like [Bear](https://github.com/rizsotto/Bear) in conjunction with our Makefile, we can automatically generate this file.

### Including a Binary in Your Repo

Binaries are ***very*** architecture specific, a compiled binary that runs on your system is unlikely to run on most other systems.

This links in with the above section, not including the binary in the repo and instead providing a quick and easy way for your users to build their own binary is essential.

<!-- markdownlint-disable-file MD013 -->
