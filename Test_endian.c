#include <endian.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    union {
        uint32_t u32;
        uint8_t arr[4];
    } x;



    x.arr[0] = 0x11;     /* Lowest-address byte */
    x.arr[1] = 0x22;
    x.arr[2] = 0x33;
    x.arr[3] = 0x44;     /* Highest-address byte */

    printf("arr[0]= 0x%x  arr[1]= 0x%x  arr[2]= 0x%x  x.arr[3]= 0x%x  \n", x.arr[0],x.arr[1],x.arr[2],x.arr[3]);
    printf("x.u32 = 0x%x\n", x.u32);
    printf("htole32(x.u32) = 0x%x\n", htole32(x.u32));
    printf("htobe32(x.u32) = 0x%x\n", htobe32(x.u32));

    if(htole32(x.u32)==x.u32)
        printf("=>This Machine is LITTLE Endian\n");
    if(htobe32(x.u32)==x.u32)
        printf("=>This Machine is BIG Endian\n");


    uint32_t test32=0x11223344;
    uint8_t *p =(uint8_t*) &test32;
    if(*p==0x11)
        printf("=>This Machine is BIG Endian\n");
        else
      printf("=>This Machine is LITTLE Endian\n");

    exit(EXIT_SUCCESS);
}
