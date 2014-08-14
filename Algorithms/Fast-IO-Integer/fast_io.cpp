#include <stdint.h>
#include <unistd.h>
#include <stdio.h>

#define pc(x) putchar_unlocked(x);
typedef unsigned int uint;

/*
    Unsigned int is interesting in certain cases,
    because it uses less processing (involving fewer logic gates).

    We are using registers to increase the performance of storage
    integer or long values.

    Usually it is not recommended to use these methods for I/O in
    professional environment because scanf, printf, cin and cout
    are prepared in case of errors.

    It is recommended to be used in situations that you have large
    input values and you really know that you only have integer
    or long values to be processed.
*/

uint next_int() {
	register uint res = 0;
	register char ch;

    	/*  While you don't pass any value, the program will wait.
    	*/
	while((ch = getc_unlocked(stdin)) < '0') {}

	/*  getc_unlocked will return the next character from the input.
            The character '0' is when you press enter.
    	*/
	do {
        /*  Converting each character in decimal values.
            If your input character is less than '0', is because
            you probably pressed enter or other invalid character.
        */
		res *= 10;
		res += (ch - '0');
	} while((ch = getc_unlocked(stdin)) >= '0');
	return res;
}

/*
    Here we use putchar_unlocked to return values (similar to printf).
    The value n is converted in binary and putchar_unlocked will print the value.
*/
inline void writeInt(uint n) {
    uint N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;}
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}

int main() {
    // Input
    int x = next_int();
    // Output
    writeInt(x);
    return 0;
}
