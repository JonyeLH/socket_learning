#include "IOmode.h"

int main(int argc, char **argv) {
	IOmode iom(12345, "192.168.79.129");
	iom.selectmode();
	return 0;
}
