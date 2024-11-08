// Copyright (c) 2024 Alexandru Constantin

#ifndef INCLUDE_CORE_PLATFORM_H_
#define INCLUDE_CORE_PLATFORM_H_

//=== COMPILER ===\\

#if defined(__clang__)
#define COMPILER_CLANG 1
#elif defined(__GNUC__)
#define COMPILER_GCC 1
#elif defined(_MSC_VER)
#define COMPILER_MSVC 1
#else
#error missing Compiler definition
#endif  // Compiler

//=== OPERATING SYSTEM ===\\

#if defined(_WIN32)
#define OS_WINDOWS 1
#elif defined(__linux__)
#define OS_LINUX 1
#elif defined(__APPLE__) && defined(__MACH__)
#define OS_MAC 1
#else
#error missing OS definition
#endif  // OS

//=== ARCHITECTURE ===\\

#if defined(__amd64__) || defined(_M_AMD64)
#define ARCH_X64 1
#elif defined(__i386__) || defined(_M_I86)
#define ARCH_X86 1
#elif defined(__arm__) || defined(_M_ARM)
#define ARCH_ARM 1
#else
#error missing Architecture definition
#endif

//=== DEFAULT VALUES ===\\

#if !defined(COMPILER_CLANG)
#define COMPILER_CLANG 0
#endif

#if !defined(COMPILER_GCC)
#define COMPILER_GCC 0
#endif

#if !defined(COMPILER_MSVC)
#define COMPILER_MSVC 0
#endif

#if !defined(OS_WINDOWS)
#define OS_WINDOWS 0
#endif

#if !defined(OS_LINUX)
#define OS_LINUX 0
#endif

#if !defined(OS_MAC)
#define OS_MAC 0
#endif

#if !defined(ARCH_X64)
#define ARCH_X64 0
#endif

#if !defined(ARCH_X86)
#define ARCH_X86 0
#endif

#if !defined(ARCH_ARM)
#define ARCH_ARM 0
#endif

#endif  // INCLUDE_CORE_PLATFORM_H_
