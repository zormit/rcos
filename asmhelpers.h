typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

#define DONT_EMIT extern inline __attribute__ ((gnu_inline, always_inline))

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