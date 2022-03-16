#include <stdlib.h>
#include <string.h>

int main(void)
{
	static char *heap;

	heap = malloc(sizeof(char) * 6);
	heap[0] = 'h';
	heap[1] = 'e';
	heap[2] = 'l';
	heap[3] = 'l';
	heap[4] = 'o';
	heap[5] = '\0';
	heap[0] = 0;
	//free(heap);
	//system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
}