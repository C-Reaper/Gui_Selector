# Project README

## Overview
This project is a simple GUI application written in C using a custom windowing library. The application features a selector that can be used to choose between different colors, and display the selected color.

## Features
- A graphical user interface with a selectable color picker.
- Color selection via mouse input.
- Increment/Decrement color selection using keyboard (TAB key).
- Display of the selected color in the window.

## Project Structure
- `build/`: Contains the compiled `.exe` file for Windows and Linux, and other build artifacts.
- `libs/`: Not present in this project.
- `lib/`: Custom libraries used by the project, not present here.
- `code/`: Scripts from custom languages like .rex or .omml, not relevant to this project.
- `data/`: No data files are included in this project.
- `assets/`: No assets like images or sounds are included in this project.
- `src/`: Source code directory containing the main source file:
  - `Main.c`: Entry point of the application and implementation for the selector functionality.
  - `*.h`: Standalone header files that might be included by other source files, though none are present here.
- `Makefile.linux`: Linux build configuration using GCC.
- `Makefile.windows`: Windows build configuration using MinGW-w64.
- `Makefile.wine`: Build configuration for Linux cross-compilation targeting Windows using Wine.
- `Makefile.web`: Build configuration for WebAssembly using Emscripten.
- `README.md`: This file.
- `LICENSE`: Contains the project license.

## Prerequisites
- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools
- Libraries needed in specific projects:
  - Linux: X11 for windowing, png/jpeg for image handling.
  - Windows: WINAPI for windowing.
  - Wine: No additional libraries required for cross-compilation to Windows on Linux.

## Build & Run

### Building the Project
To build the project on Linux:

```sh
cd <Project>
make -f Makefile.linux all
```

To build the project on Windows (assuming a MinGW-w64 environment):

```sh
cd <Project>
make -f Makefile.windows all
```

To clean and rebuild:

```sh
make -f Makefile.linux clean
make -f Makefile.linux all
```

### Running the Project
After building, you can run the project using:

```sh
make -f Makefile.linux exe
```

or on Windows:

```sh
./build/Main.exe
```

If you are cross-compiling to Windows on Linux:

```sh
make -f Makefile.wine all
WINEPREFIX=~/wine64 WINEARCH=win64 wine ./build/Main.exe
```