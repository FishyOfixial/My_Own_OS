# MiniOS: A Simple 32-bit Protected Mode Kernel

**Author:** Ivan Ramos de la Torre

**University:** Universidad Autónoma de Guadalajara  

**Date:** November 2025  

---

## Overview

This project demonstrates the creation of a minimal operating system from scratch. The OS currently runs in 32-bit protected mode and prints a single character 'X' at the top-left corner of the screen. The main goals of this project were to:

- Understand bootloading in 16-bit real mode.
- Switch to 32-bit protected mode using a custom GDT.
- Write a simple kernel in C.
- Compile and link the kernel with assembly entry code.
- Build a bootable image that can be executed in QEMU.

This OS is **educational**, minimal, and only prints a character; it is not yet a full operating system.

---

## Project Structure

```
project/
│
├── 32bit-main.asm # Bootloader that switches from real mode to protected mode
├── 32bit-gdt.asm # Global Descriptor Table definitions
├── 32bit-switch.asm # Code to switch to 32-bit protected mode
├── 32bit-print.asm # Functions to print text in protected mode
├── boot_sect_print.asm # Functions to print text in real mode
├── kernel.c # Minimal C kernel (prints 'X')
├── kernel_entry.asm # Assembly entry code for the kernel
├── bootsect.asm # Boot sector code
├── Makefile # Automates compilation and image creation
└── os-image.bin # Concatenated boot sector + kernel (floppy image)
``` 

---

## Prerequisites

You need a **cross-compiler** targeting `i386-elf` to compile the C kernel:

- binutils (GNU assembler, linker, etc.)
- GCC (cross-compiled for `i386-elf`)

Example paths: `/usr/local/i386elfgcc/bin/i386-elf-gcc`

---

## Building the Project

1. Compile the kernel in C:

```bash
i386-elf-gcc -ffreestanding -c kernel.c -o kernel.o
```

2. Compile the kernel entry assembly:
nasm kernel_entry.asm -f elf -o kernel_entry.o

3. Link the kernel and entry into a single binary;
i386-elf-ld -o kernel.bin -Ttext 0x1000 kernel_entry.o kernel.o --oformat binary

4. Compile the bootloader:
nasm bootsect.asm -f bin -o bootsect.bin

5. Combine the bootloader and kernel:
cat bootsect.bin kernel.bin > os-image.bin

6. Run in QEMU:
qemu-system-i386 -fda os-image.bin


### Learning Outcomes
By completing this project, you have learned:
* Writing bootloaders in assembly.
* Setting up a Global Descriptor Table (GDT) and entering protected mode.
* Writing a minimal C kernel for a freestanding environment.
* Compiling and linking C and assembly code into a bootable binary.
* Using QEMU to test your OS.

---

### Future Work
* Expand the kernel to support basic input/output and memory management.
* Implement a simple filesystem.
* Add multitasking support.
* Create drivers for basic hardware like keyboard and timer.

---
