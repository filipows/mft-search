#include <stdio.h>
#include <ctype.h>

#define BUF_SIZE 512

int show_sector(unsigned char *p)
{
	printf("       0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f\n");
	for (int i=0; i<32; i++)
	{
		printf("%04x: ", i*16);
		for (int j=0; j<16; j++)
		{
			printf("%02x ", p[16*i+j]);
		}
		for (int j=0; j<16; j++)
		{
			unsigned char b = p[16*i+j];
			char c = isprint((char)b)? (char) b : '.';
			printf("%c", c);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int n;
	unsigned char buffer[BUF_SIZE];
	
	FILE* fp = fopen("/dev/sda", "rb");
	printf("Otwarcie pliku: %s\n", (fp == NULL)? "Nic z tego..." : "Ok!");
	if (fp == NULL)
		return 1;

	n = fread(buffer, 1, BUF_SIZE, fp);
	printf("Odczytano: %d bajtów\n\n", n);
	if (n < BUF_SIZE)
	{
		printf("Coś nie tak...\n");
		return 2;
	}
	
	show_sector(buffer);
	return 0;
}

