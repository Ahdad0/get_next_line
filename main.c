#include "get_next_line.h"

int main()
{
	int a = read("file.txt", O_RDONLY);
	char *s = get_next_line(a);
	printf("re=%s\n", s);
}
