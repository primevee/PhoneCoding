// C program to read multiple characters
// using getchar():
#include <stdio.h>
 
// Driver code
int main()
{
    int s = 13;
    int x;
    while (s--) {
        x = getchar();
        putchar(x);
    }
    return 0;
}
