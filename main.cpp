#include <iostream>
#include <conio.h>
#include <cassert>

using namespace std;

char nibble_to_hex(uint8_t i)
{
    assert( 0x0 <= i && i <= 0xf );
    char digits[] = "0123456789abcdef";
    return digits[i];
}

void print_in_hex(uint8_t byte)
{
    cout << nibble_to_hex(byte >> 4)
         << nibble_to_hex(byte & 0xf);
}

int main()
{
    print_in_hex(0x0);
    print_in_hex(0xab);
    print_in_hex(0xff);
    getch();
    return 0;
}
