#include <stdio.h>
#include <stdlib.h>
// using namespace std;

 void *memory_copy(void *dst, const void *src, size_t n) {
 	if (dst == NULL || src == NULL) {
 		return NULL;
 	} 
 	int m = n / 4;
 	int remain = n % 4;

 	if (dst > src && dst < src + n) {
 		char* temp1 = (char*)(dst + n - 1);
 		char* temp2 = (char*)(src + n - 1);
 		while (remain--) {
 			*temp1-- = *temp2--;
 		}
 		temp1++, temp2++;
 		int* pdst = (int*)temp1;
 		int* psrc = (int*)temp2;
 		pdst--, psrc--;
 		while (m--) {
 			*pdst-- = *psrc--;
 		}
 	} else {
 		int* pdst = (int*)dst;
 		int* psrc = (int*)src;
 		while (m--) {
 			*pdst++ = *psrc++;
 		}
 		char* temp1 = (char*)pdst;
 		char* temp2 = (char*)psrc;
 		while (remain--) {
 			*temp1++ = *temp2++;
 		}
 	}

 	return dst;
 }


 int main(int argc, char const *argv[])
 {
 	
 	char* src = (char*)malloc(sizeof(char) * 12);

 	src[0] = 'a';
 	src[1] = 'b';
 	src[2] = 'c';
 	src[3] = 'd';
 	src[4] = 'e';
 	src[5] = 'f';
 	src[6] = 'g';
 	src[7] = '4';
 	src[8] = 'l';

 	src = memory_copy(src + 3, src, 9);


 	for (int i = 0; i < 12; i++) {
 		printf("%c\n", src[i]);
 	}

 	return 0;
 }

