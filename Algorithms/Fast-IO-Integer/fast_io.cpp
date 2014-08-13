#include <stdint.h>
#include <unistd.h>
#include <stdio.h>

#define pc(x) putchar_unlocked(x);
typedef unsigned int uint;

uint next_int() {
	register uint res = 0;
	register char ch;

	while((ch = getc_unlocked(stdin)) < '0') {}
	do {
		res *= 10;
		res += (ch - '0');
	} while((ch = getc_unlocked(stdin)) >= '0');
	return res;
}


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

class FastOutput {
	public:
		FastOutput() {
			m_dataOffset = 0;
		}
		~FastOutput() {
		}

		void Flush() {
			if (m_dataOffset) {
				if (write(1, m_data, m_dataOffset));
				m_dataOffset = 0;
			}
		}

		void PrintUint(uint32_t v, char d) {
			if (m_dataOffset + 11 > sizeof(m_data)) Flush();
			if (v < 100000) {
				if (v < 1000) {
					if (v < 10) {
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 1;
					} else if (v < 100) {
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 2;
					} else {
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 3;
					}
				} else {
					if (v < 10000) {
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 4;
					} else {
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 5;
					}
				}
			} else {
				if (v < 100000000) {
					if (v < 1000000) {
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 6;
					} else if (v < 10000000) {
						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 7;
					} else {
						m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 8;
					}
				} else {
					if (v < 1000000000) {
						m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 9;
					} else {
						m_data[m_dataOffset + 9] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 8] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 7] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 6] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 5] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 4] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 3] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 2] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 1] = v - v / 10 * 10 + 48; v /= 10;
						m_data[m_dataOffset + 0] = v + 48;
						m_dataOffset += 10;
					}
				}
			}
			m_data[m_dataOffset++] = d;
		}

		void PrintChar(char d) {
			if (m_dataOffset + 1 > sizeof(m_data)) Flush();
			m_data[m_dataOffset++] = d;
		}

		void ReplaceChar(int offset, char d) {
			m_data[m_dataOffset + offset] = d;
		}

	public:
		uint8_t m_data[32768];
		size_t m_dataOffset;
};

int main() {
    FastOutput out;

    // Input
	int x = next_int();

    // Output
    writeInt(x);

    // Another way to implement output
	out.PrintUint(x, '\n');
	out.Flush();

	return 0;
}
