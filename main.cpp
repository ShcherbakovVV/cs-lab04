#include <conio.h>
#include "byteprint.h"

using namespace std;

int main()
{
    uint16_t first, second;
    char oper;
    cin >> first >> oper >> second;
    byte_calc( first, second, oper );
    getch();
    return 0;
}
