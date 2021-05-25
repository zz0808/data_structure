#include <iostream>
#include <stdarg.h>

using namespace std;

std::string excute(const char* format, va_list al) {
	char* buf;
	string ans = "";
	int len = vasprintf(&buf, format, al);
	cout << len << endl;
	if (len != -1) {
		ans = std::string(buf, len);
		free(buf);
	}
	return ans;
}

void myprintf(const char* format, ...) {
	va_list al;
	va_start(al, format);
	cout << excute(format, al) << endl;
	va_end(al);

}

int main(int argc, char const *argv[]) {
	myprintf("hello %s, this is %s world", "mando", "dillon");

	return 0;
}

