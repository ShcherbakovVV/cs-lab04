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

char bit_digit(uint8_t byte, uint8_t bit)
{
    if( byte & ( 0x1 << bit ) )
        return '1';
    return '0';
}

void print_in_hex(uint8_t byte)
{
    cout << nibble_to_hex(byte >> 4)
         << nibble_to_hex(byte & 0xf);
}

void print_in_hex(const void* data, size_t datasize)
{
    const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);
    for( size_t i = 0; i < datasize; i++ )
    {
        print_in_hex( bytes[i] );
        if ( (i + 1) % 16 == 0)
            cout << '\n';
        else
            cout << ' ';
    }
}

void print_in_binary(uint8_t byte)
{
    for( int bit = 7; bit >= 0; bit-- )
        cout << bit_digit(byte, bit);
}

void print_in_binary(const void* data, size_t size)
{
    const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);
    for (size_t i = 0; i < size; i++)
    {
        print_in_binary(bytes[i]);
        if ( (i + 1) % 4 == 0 )
            cout << '\n';
        else
            cout << ' ';
    }
}

int main()
{
    uint8_t u8 = 42;
    cout << "u8 bytes: ";
    print_in_binary(&u8, sizeof(u8));
    cout << '\n';

    uint16_t u16 = 42;
    cout << "u16 bytes: ";
    print_in_binary(&u16, sizeof(u16));
    cout << '\n';

    uint32_t u32 = 42;
    cout << "u32 bytes: ";
    print_in_binary(&u32, sizeof(u32));
    cout << '\n';

    getch();
    return 0;
}
