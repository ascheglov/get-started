# Sample C++ application

This tutorial shows how to make a C++ application.
It doesn't explain _how to write_ C++ code, only how to build and test it.

## Software to install

- [CMake](http://www.cmake.org/download/)
- C++ compiler, one of:
  - MS Visual Studio Community 2013
  - MinGW - take latest from [MinGW-builds](http://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/4.9.2/threads-posix/dwarf/)
  - Clang or GCC on *nix
- (optional) [Ninja](http://martine.github.io/ninja/)

## Setting things up

Create a directory for binary files, and run `cmake ..` from it.
You can do it with the `.\configure-*.bat`  files.

## Build and test

If you use MSVS, build the `./out-vc/crc32.sln` file.
For Ninja, run `ninja -C ./out/debug`.
Also, you can run a build tool from CMake, e.g. `cmake --build ./out-vc`.

Tests will be executed in a post-build step.

# Porting to Emscripten

This section shows how to build C++ code with Emscripten.

There is no need to change the code.
In the build files, Emscripten-specific things are wrapped with `if (EMSCRIPTEN)` blocks.

Required software list - [CMake](http://www.cmake.org/download/),
[Ninja](http://martine.github.io/ninja/) and [Emscripten](http://emscripten.org/).

You have to set Emscripten environment, e.g. run `emsdk_env.bat`.
Then run `.\configure-emscripten.bat` to create output directories and generate build files.

`ninja -C ./out-js/debug` builds the code and run tests on Node.js.

`./out-js/debug/web_calc/web_calc.html` is a demo HTML page which uses bindings to the `Crc32` class.
