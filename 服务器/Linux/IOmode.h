#ifndef _IOMODE_H_
#define _IOMODE_H_


#include <sys/socket.h>
#include<arpa/inet.h>
#include <fcntl.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

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


#endif
