#include <iostream>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <string>
#include <winsock2.h>
using namespace std;

#pragma comment(lib, "ws2_32.lib")

int main() {
	WSADATA wsadata;
	SOCKET s;
	sockaddr_in serveraddr;

	WSAStartup(MAKEWORD(2, 2), &wsadata);
	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(12345);
	serveraddr.sin_addr.s_addr = inet_addr("192.168.79.129");

	int ret = connect(s, (sockaddr*)&serveraddr, sizeof(serveraddr));
	while (1) {
		char data[1024] = { 0 };
		cout << "请输入要发送的数据（quit提出）：";
		cin >> data;
		string senddata = data;
		if (senddata.size() > 0)
			send(s, senddata.c_str(), sizeof(senddata), 0);
		if (senddata == "quit")
			break;
	}
}