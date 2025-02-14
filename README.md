ac_std
======

`ac_std` is a suite of C++ functions, classes and libraries I find myself 
writing over multiple projects.

## Available Modules

- [`core`](#core-module) - The most used modules (and which other modules use).
- [`profiling`](#profiling-module) - Utilities used for profiling.

## Core Module

The core module contains the most used classes and functions,
many of the other modules depending on them.

The core module exposes the following headers:

- [x] [`platform.h`](./include/ac_std/core/platform.h) - Defines different flags based on the current platform.
- [x] [`Result.h`](./include/ac_std/core/Result.h) - A class that can be used when the result is not always guaranteed.

