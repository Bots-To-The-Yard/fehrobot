# FEH Team M7 Code
This repository contains all the program code and the robot library for FEH Team M7 2020.

## Dependencies
The `arm-none-eabi-g++` compiler is required to build the code for the Proteus microcontroller.

This package can be obtained by installing the `gcc-arm-none-eabi` package with a package manager or by downloading it from the ARM website.

Make is also required, which is commonly installed on most systems, but can be obtained from the make website or a package manager.

## Installation
To clone the code from GitHub run `git clone https://github.com/Bots-To-The-Yard/fehrobot.git`.

To download the Proteus firmware and compile the code run `make`.

## Building for the Proteus
To build the code, first insert the Proteus SD Card and run `make` to build the code and then `make deploy` to copy the code to the SD card.

## Building the Documentation
Doxygen is required to build the documentation. Doxygen can be installed from the website or by using a package manager.

To build the documentation run `make docs`.

To open the documentation run `make help`.

## Folder Structure
The project is seperated into three primary folders `include`, `lib`, and `src`.

The `include` folder contains all header files for the robot library.

The `lib` folder contains implementations for all the robot library classes and functions.

The `src` folder contains the `main.cpp` file and any team programs in the `programs` folder.

The `docs` folder contains the auto-generated documentation and should not be modified.