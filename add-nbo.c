#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

FILE *f1, *f2;
uint32_t num1, num2;

int main(int argc, char *argv[]) {

    f1 = fopen(argv[1], "rb");
    f2 = fopen(argv[2], "rb");

    fread(&num1, sizeof(num1), 1, f1);
    fread(&num2, sizeof(num2), 1, f2);

    num1 = ntohl(num1); 
    num2 = ntohl(num2);  

    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);
    
    fclose(f1);
    fclose(f2);
    return 0;
}

