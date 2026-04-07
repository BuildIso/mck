# mck Usage Guide

This document explains how to use every major component of mck, including the C core, utilities, C++ wrappers, assembly files, and the kernel structure.  
It is intended as a practical reference for developers integrating mck into their own OS projects.

---

# 1. Core (C89)

## Files
- include/core.h  
- src/core/*  

## Purpose
The core provides:
- fixed-size integer types  
- result codes  
- logging callback  
- initialization state  

## Usage
```c
core_init();
core_set_logger(my_logger);
core_log("message");
```

---

# 2. Drivers

## Files
- include/drivers.h  
- src/drivers/*  

## Purpose
Static driver registry.

## Usage
```c
mck_driver drv = { "driver", driver_init };
drivers_register(&drv);
drivers_init_all();
```

---

# 3. Modules

## Files
- include/modules.h  
- src/modules/*  

## Purpose
Static module registry.

## Usage
```c
mck_module mod = { "module", module_init };
modules_register(&mod);
modules_init_all();
```

---

# 4. Utilities

# 4.1 Memory Utilities

## Files
- include/utils/mem.h  
- src/utils/mem.c  

## Usage
```c
mck_arena arena;
mck_arena_init(&arena, buffer, size);
void* p = mck_arena_alloc(&arena, 128);
```

---

# 4.2 Static List

## Files
- include/utils/list.h  
- src/utils/list.c  

## Usage
```c
void* storage[16];
mck_list list;
mck_list_init(&list, storage, 16);
mck_list_push(&list, item);
```

---

# 4.3 String Utilities

## Files
- include/utils/string.h  
- src/utils/string.c  

## Usage
```c
mck_str_len("abc");
mck_str_cmp("a", "b");
```

---

# 5. Math

## Files
- include/math/math.h  
- src/math/math.c  

## Usage
```c
mck_min_u32(a, b);
mck_clamp_u32(v, min, max);
```

---

# 6. Logging

## Files
- include/log/log.h  
- src/log/log.c  

## Usage
```c
mck_log_set_callback(my_logger);
mck_log_msg(MCK_LOG_INFO, "message");
```

---

# 7. Config

## Files
- include/config/config.h  
- src/config/config.c  

## Usage
```c
mck_config cfg = { "project", 1, 0, 0 };
mck_config_set(&cfg);
```

---

# 8. Debug

# 8.1 Assert

## Files
- include/debug/assert.h  
- src/debug/assert.c  

## Usage
```c
mck_assert(x != 0, "x must not be zero");
```

---

# 8.2 Panic (kernel)

## Files
- kernel/debug/panic.c  
- include/debug/panic.h  

## Usage
```c
kernel_panic("fatal error");
```

---

# 9. Buffer Utilities

# 9.1 Ring Buffer

## Files
- include/buffer/ringbuffer.h  
- src/buffer/ringbuffer.c  

## Usage
```c
mck_ringbuffer rb;
mck_ringbuffer_init(&rb, buffer, capacity);
mck_ringbuffer_push(&rb, value);
mck_ringbuffer_pop(&rb, &out);
```

---

# 10. Bitset

## Files
- include/bit/bitset.h  
- src/bit/bitset.c  

## Usage
```c
mck_bitset bs;
mck_bitset_init(&bs, storage, 128);
mck_bitset_set(&bs, 5);
```

---

# 11. Hash Table

## Files
- include/table/table.h  
- src/table/table.c  

## Usage
```c
mck_table t;
mck_table_init(&t, entries, capacity);
mck_table_set(&t, "key", value);
void* v = mck_table_get(&t, "key");
```

---

# 12. Event Queue

## Files
- include/event/event.h  
- src/event/event.c  

## Usage
```c
mck_event_queue q;
mck_event_queue_init(&q, buffer, capacity);
mck_event_push(&q, handler, userdata);
mck_event_dispatch(&q);
```

---

# 13. Time System

## Files
- include/time/time.h  
- src/time/time.c  

## Usage
```c
mck_time_init(1);   // 1 tick = 1 ms
mck_time_tick();    // called by timer interrupt
mck_time_ms();
mck_time_seconds();
```

---

# 14. Assembly (x86)

## Directories
- asm/x86/boot/  
- asm/x86/cpu/  
- asm/x86/mem/  
- asm/x86/util/  

## Purpose
- boot sector  
- GDT  
- IDT  
- ISR stubs  
- paging  
- port I/O  
- CPU utilities  

These files must be integrated into a real boot pipeline.

---

# 15. Assembly (x86_64)

## Directories
- asm/x64/boot/  
- asm/x64/cpu/  
- asm/x64/mem/  
- asm/x64/util/  

## Purpose
- 64-bit kernel entry  
- GDT/IDT  
- paging helpers  
- port I/O  
- CPU utilities  

Requires a bootloader that already enabled long mode.

---

# 16. C++ Layer

# 16.1 C++ Core

## Files
- cpp/core/core.hpp  
- cpp/utils/vector.hpp  
- cpp/utils/string.hpp  

## Purpose
Minimal C++ core helpers (no exceptions, no RTTI, no STL).

---

# 17. Kernel

## Directories
- kernel/  
- kernel/arch/x86_64/  
- kernel/mm/  
- kernel/sched/  
- kernel/debug/  

## Key Files
- kernel/init.c  
- kernel/kernel.h  
- kernel/debug/panic.c  
- kernel/arch/x86_64/startup.asm  
- kernel/arch/x86_64/entry.c  

## Usage
```c
void kmain(void) {
    kernel_init();
    kernel_run();
}
```

---

# 18. Linker Script

## Files
- ld/kernel.ld

## Purpose
Defines memory layout, kernel entry, sections, and alignment rules.

---

# 19. Build System

mck does not impose a build system.  
You may use Make, CMake, custom scripts, or any other method.

# 19.1 Tools

## Files
- tools/*

## Purpose
Build scripts, helper utilities, and automation.

---

# 20. Extending mck

You can add:
- drivers  
- modules  
- architecture-specific code  
- memory management  
- filesystem  
- scheduler  
- multitasking  
- device drivers  

mck is designed to be extended freely.

---

# 21. Rust Integration

## Files
- rust/Cargo.toml
- rust/.cargo/config.toml
- rust/src/lib.rs

## Purpose
Provides optional Rust modules compiled as a static library (`libmck_rust.a`) usable from C.

## Usage (C side)
extern unsigned int mck_rust_add(unsigned int a, unsigned int b);

unsigned int v = mck_rust_add(2, 3);

# 22. Installer

---

## Files
- installer/*

## Purpose
Packaging, distribution, or installation helpers for mck.

# 23. Documentation System

---

## Files
- docs/*

## Purpose
Static documentation pages for mck (HTML, CSS, wiki-style layout).

---

# 24. Build Directory

## Files
- build/*

## Purpose
Intermediate build artifacts, object files, and generated binaries.

---

# 25. Root Source Directory

## Files
- src/*

## Purpose
Shared C sources not tied to kernel or utilities.

---

# 26. Repository Rules

## Files
- .gitattributes

## Purpose
Forces LF line endings across all platforms for OSDev compatibility.

---

# 27. Git Ignore Rules

## Files
- .gitignore

## Purpose
Excludes build artifacts, Rust target/, temporary files, and editor caches.

---

## 28. Device System

### Files
- `include/device/device.h`  
- `src/device/device.c`

### Purpose  
Minimal device registry for storing and retrieving devices by name.

### Usage
```c
mck_device devices[16];
mck_device_registry reg;

mck_device_registry_init(&reg, devices, 16);
mck_device_register(&reg, "uart0", uart_ptr);

mck_device *dev = mck_device_find(&reg, "uart0");
```

---

## 29. TTY Layer

### Files
- `include/tty/tty.h`  
- `src/tty/tty.c`

### Purpose  
Simple TTY abstraction on top of console or serial output.

### Usage
```c
mck_tty_set_write(my_write);
mck_tty_set_putc(my_putc);

mck_tty_write("Hello");
mck_tty_putc('A');
```

---

## 30. VFS Layer

### Files
- `include/vfs/vfs.h`  
- `src/vfs/vfs.c`

### Purpose  
Minimal virtual filesystem interface.  
Provides root node and lookup callback.

### Usage
```c
mck_vfs_node root = { "root", 0, 0 };
mck_vfs_set_root(&root);
mck_vfs_set_lookup(my_lookup);

mck_vfs_node *n = mck_vfs_lookup("/path");
```

---

## 31. Crypto (CRC32)

### Files
- `include/crypto/crc32.h`  
- `src/crypto/crc32.c`

### Purpose  
Minimal CRC32 implementation (polynomial 0xEDB88320).

### Usage
```c
unsigned long crc = mck_crc32(data, size);
```

---

## 32. Extra Math (Random)

### Files
- `include/math/extra/random.h`  
- `src/math/extra/random.c`

### Purpose  
Simple linear congruential generator (LCG).

### Usage
```c
mck_rand_seed(1234);
unsigned long v = mck_rand_next();
```

---

## 33. Dynamic Buffer

### Files
- `include/utils/buffer.h`  
- `src/utils/buffer.c`

### Purpose  
Minimal growable byte buffer.

### Usage
```c
unsigned char storage[64];
mck_buffer buf;

mck_buffer_init(&buf, storage, 64);
mck_buffer_push(&buf, 0x42);
```

---

## 34. Format Utilities

### Files
- `include/utils/format.h`  
- `src/utils/format.c`

### Purpose  
Minimal integer formatting (decimal and hex).

### Usage
```c
char tmp[32];
mck_format_u32(tmp, 12345);
mck_format_hex_u32(tmp, 0xABCD);
```

---

## 35. Architecture Common Helpers

### Files
- `kernel/arch/common/cpu.h`  
- `kernel/arch/common/cpu.c`

### Purpose  
Architecture‑independent CPU helpers.

### Usage
```c
mck_cpu_pause();
mck_cpu_halt();
```