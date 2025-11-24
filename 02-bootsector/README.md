# 🖥️ Bootsector Lesson
## 🔎 Concepts to Know

Before starting, it helps to know: <br>
Memory addresses & offsets <br>
CPU registers basics <br>
How the BIOS loads code at boot

## 🎯 Goal
Learn where the boot sector lives in memory and how to access it.
By the end, you'll understand how to place and read data in your boot sector.

## 📝 Steps
Open the example file
`boot_sector_example.asm`

Define a data byte
```
my_char:
    db "A"
```

Try different ways to access it

```
mov al, my_char          ; attempt 1
mov al, [my_char]        ; attempt 2
mov al, my_char + 0x7C00 ; attempt 3
mov al, 0x2d + 0x7C00    ; attempt 4 (real offset in binary)
```


Compile & run
- Observe which method works and why some show random bytes.
- If you change instructions, recalc offsets carefully!

## 📌 Using a Global Offset
The org directive sets a base memory address, so you don’t need to add 0x7C00 everywhere:
`
[org 0x7C00]
`
Open `boot_sector_org.asm` to see how this simplifies memory access.
Compile & run, then compare the results with the previous file.

## 💡 Key Takeaways
Boot sector is loaded at 0x7C00 by the BIOS.
Knowing memory offsets is crucial for low-level OS programming.
Practice accessing data in multiple ways to understand how memory works at boot time.

## 📚 References
Inspired by classic boot sector tutorials `https://github.com/cfenollosa/os-tutorial/tree/master`.
See the root README for more background info.
