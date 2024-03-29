#include <stdio.h>

void itoa(int n, char s[])
{
	static int i = 0;

	if (n < 0) 
	{
		s[i++] = '-';
		n = - n;
	}

	if (n / 10)
		itoa(n / 10, s); 
	
	s[i++] = n % 10 + '0';

	s[i] = '\0';
}

int main(int argc, char const *argv[])
{
	int n = 1;
	char s[100];
	itoa(n, s);
	printf("%s\n", s);

	return 0;
}