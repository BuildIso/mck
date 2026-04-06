# mck – Minimal Kernel Kit

mck is a modular, self-contained OS development kit designed to be copied directly into new operating system projects.  
It provides a minimal kernel structure, a reusable C89 core, utilities, architecture-specific code, and a clean directory layout suitable for both small experiments and long-term OS projects.

The goal is to offer a stable, minimal, dependency-free foundation for kernel development on x86 and x86_64 systems.

## Features

- C89-compatible core (no libc required)
- Minimal C++ support (no exceptions, no RTTI, no STL)
- x86 and x86_64 assembly components
- Kernel entry points for 64-bit mode
- Driver and module registries
- Time system (ticks, ms, seconds)
- Memory utilities (arena allocator, mem ops)
- Static containers (lists, vectors)
- String utilities
- Logging system (C and C++)
- Debug utilities (assert, panic)
- Bitset, ring buffer, hash table
- Event queue
- Clean kernel structure (arch/, mm/, sched/, debug/)
- Linker script for kernel layout
- Fully copy-paste friendly

## Directory Structure

mck/
├─ include/
│   ├─ core.h
│   ├─ drivers.h
│   ├─ modules.h
│   ├─ utils/
│   ├─ math/
│   ├─ log/
│   ├─ config/
│   ├─ debug/
│   ├─ buffer/
│   ├─ bit/
│   ├─ table/
│   └─ time/
├─ src/
│   ├─ core/
│   ├─ drivers/
│   ├─ modules/
│   ├─ utils/
│   ├─ math/
│   ├─ log/
│   ├─ config/
│   ├─ debug/
│   ├─ buffer/
│   ├─ bit/
│   ├─ table/
│   └─ time/
├─ asm/
│   ├─ x86/
│   │   ├─ boot/
│   │   ├─ cpu/
│   │   ├─ mem/
│   │   └─ util/
│   └─ x64/
│       ├─ boot/
│       ├─ cpu/
│       ├─ mem/
│       └─ util/
├─ cpp/
│   ├─ core/
│   └─ utils/
├─ kernel/
│   ├─ arch/
│   │   └─ x86_64/
│   ├─ mm/
│   ├─ sched/
│   ├─ debug/
│   ├─ init.c
│   └─ kernel.h
├─ ld/
│   └─ kernel.ld
├─ tools/
├─ build/
└─ docs/

## Core Concepts

### Core (C89)
The core provides:
- fixed-size integer types  
- result codes  
- logging callback  
- initialization state  

It contains no platform-specific code and no standard library dependencies.

### Drivers
Drivers are defined by a name and an initialization function.  
They are stored in a static registry and initialized in order.

### Modules
Modules follow the same structure as drivers and are initialized after them.

### Utilities
mck includes:
- memory utilities (set, copy, arena allocator)
- static lists
- string utilities
- math helpers
- bitsets
- ring buffers
- hash tables
- event queues

These components are designed for environments without dynamic allocation.

### Time System
A minimal time system provides:
- tick counter  
- millisecond uptime  
- second uptime  

It is hardware-agnostic and can be driven by any timer interrupt.

### Assembly (x86 / x86_64)
mck includes reusable assembly components:
- boot stubs
- GDT/IDT setup
- ISR stubs
- paging helpers
- port I/O
- CPU utilities (hlt, cli, sti)

### Kernel Structure
The kernel directory provides:
- architecture-specific startup code  
- kernel entry point  
- initialization sequence  
- panic handler  
- scheduler stub  
- memory map stub  

This forms a clean foundation for building a real OS.

### C++ Layer
Minimal C++ wrappers are provided:
- core wrapper  
- static vector  
- string view  

No exceptions, no RTTI, no STL.

## Integration

To use mck in your own OS project:

1. Copy the entire `mck/` directory into your project.
2. Use the provided linker script (`ld/kernel.ld`) or adapt it.
3. Implement or integrate a bootloader that enters 64-bit mode and jumps to `_start`.
4. Ensure the stack is set before calling the kernel entry.
5. Extend the kernel by adding drivers, modules, and architecture-specific code.

mck does not impose a build system or runtime.  
It is intended to be adapted freely.

## License

MIT License

Copyright (c) 2026 BuildIso/htmluser-hub

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.