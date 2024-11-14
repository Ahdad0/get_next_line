#include "get_next_line.h"

int main()
{
	char *s;
	int a = open("file.txt", O_RDONLY);
	
	while ((s = get_next_line(a)) != 0)
	{
		printf("re=%s", s);
	}
}
