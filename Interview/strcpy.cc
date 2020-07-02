#include <stdio.h>
#include <string>
#include <memory>
using namespace std;

char* strcpy(const char *from, char *to) {
	int len = strlen(from);
	char *p = to;

	if (to >= from && to < from + len) {
		*(to + len) = 0;
		while (--len >= 0) *(to + len) = *(from + len);
	} else {
		while (*(from) != 0) *to++ = *from++;
		*to = 0;
	}
	return p;
}

int main() {
	const char *from = "ababbbbbbbbbbccdef";
	char *to = (char*)malloc(sizeof(char) * (strlen(from)+1));
	char *ret = nullptr;

	ret = strcpy(from, to);
	printf("test to out of from str\n");
	printf("from:\t%s\n", from);
	printf("to:\t%s\n", to);
	printf("ret:\t%s\n", ret);
}
