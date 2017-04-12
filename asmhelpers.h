#ifndef ASMHELPERS_H
#define ASMHELPERS_H

#include "ourtypes.h"

#define PACKED __attribute__((packed))

#define DONT_EMIT extern inline __attribute__ ((gnu_inline, always_inline))

#define HTONL(n) (((((unsigned long)(n) & 0xFF)) << 24) | \
                  ((((unsigned long)(n) & 0xFF00)) << 8) | \
                  ((((unsigned long)(n) & 0xFF0000)) >> 8) | \
                  ((((unsigned long)(n) & 0xFF000000)) >> 24))

#define NTOHL(n) (((((unsigned long)(n) & 0xFF)) << 24) | \
                  ((((unsigned long)(n) & 0xFF00)) << 8) | \
                  ((((unsigned long)(n) & 0xFF0000)) >> 8) | \
                  ((((unsigned long)(n) & 0xFF000000)) >> 24))

// in a exception handler
struct exc_registers {
    u32 unused_eax, ecx, edx, ebx, esp, ebp, esi, edi;
    u32 eax, eflags, eip, cs;
};

DONT_EMIT void yield()
{
    asm volatile ("hlt");
}

DONT_EMIT void out8(unsigned short port, u8 val)
{
    asm volatile( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

DONT_EMIT u8
in8(unsigned int port)
{
   u8 ret;
   asm volatile ("inb %%dx,%%al":"=a" (ret):"d" (port));
   return ret;
}

DONT_EMIT void
out16(unsigned short port, u16 val)
{
    asm volatile( "outw %0, %1" : : "a"(val), "Nd"(port) );
}

DONT_EMIT u16
in16(unsigned int port)
{
   u16 ret;
   asm volatile ("inw %%dx,%%ax":"=a" (ret):"d" (port));
   return ret;
}

DONT_EMIT void
out32(unsigned short port, u32 val)
{
    asm volatile( "outl %0, %1" : : "a"(val), "Nd"(port) );
}

DONT_EMIT u32
in32(unsigned int port)
{
   u32 ret;
   asm volatile ("inl %%dx,%%eax":"=a" (ret):"d" (port));
   return ret;
}

#endif
