//#pragma once
#include <iostream>
#include <string>
#include <winsock2.h>
using namespace std;

#pragma comment(lib, "ws2_32.lib")
class IOmode {
private:
	sockaddr_in serveraddr;
public:
	IOmode(int pirt, string ipaddr);
	~IOmode();

	void blockmode();
	void selectmode();
};
