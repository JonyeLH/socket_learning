#include"input and output.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <ws2tcpip.h>
#include <winsock2.h>
#include <vector>
#include <map>
#include <string>

#pragma warning(disable:4996)	//ǿ�ƹرճ���Ĵ���������	
//����	C4996	'inet_addr': Use inet_pton() or InetPton() instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings	socket���	c : \users\12185\desktop\������\socket���\socket���\input and output.cpp	13

#pragma comment(lib, "ws2_32.lib")


IOmode::IOmode(int port, string ipaddr) {
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	serveraddr.sin_addr.s_addr = inet_addr(ipaddr.c_str());
	//WSACleanup();
}

IOmode::~IOmode() {
	WSACleanup();
}

void IOmode::blockmode() {
	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	sockaddr_in clientaddr;

	unsigned long ul = 0;//0:����������Ϊ������
						 //����:socket I/0����ģʽ
	int nret = ioctlsocket(server, FIONBIO, (unsigned long*)&ul);
	//1inux�ж�Ӧ����Ϊ������
	//int flags = fcnt1 (server, F GETFL, 0);//��ȡ�ļ���f1agsֵ
	//fcnt1(server, F_ SETFL, flags | 0_ NONBLOCK); //���� �ɷ�����ģʽ;

	bind(server, (sockaddr*)&serveraddr, sizeof(serveraddr));

	char buffer[1024];

	recvfrom(server, buffer, 1023, 0, (sockaddr*)&clientaddr, 0);

	listen(server, 5);
	int len = sizeof(sockaddr);
	SOCKET client = accept(server, (sockaddr*)&clientaddr, &len);


}

void IOmode::selectmode() {

	vector<SOCKET> clientset;//�� �����׽��ּ���
	map<SOCKET, sockaddr_in> s2addr;//�׽��֣� ��ַ
	fd_set readfd; //���ڼ��ɶ�ȡ���ݵ��׽��ּ���
	int ret = 0;

	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	unsigned long ul = 1;

	ioctlsocket(server, FIONBIO, (unsigned long*)&ul);//����server�׽���Ϊ������������accept

	bind(server, (sockaddr*)&serveraddr, sizeof(serveraddr));
	listen(server, 5);

	// ���Ͻ���������ʹ��select�������ͻ����׽����Ƿ������ݵ���
	while (1) {
		sockaddr_in addr;

		int len = sizeof(addr);

		int client = accept(server, (sockaddr*)&addr, &len);//��������
		if (client != INVALID_SOCKET) {
			clientset.push_back(client);
			s2addr[client] = addr;
			cout << inet_ntoa(addr.sin_addr) << "�Ѽ�������.." << "��ǰ��������" << clientset.size() << endl;
		}

		FD_ZERO(&readfd);

		for (int i = 0; i < clientset.size(); i++)
			FD_SET((int)(clientset[i]), &readfd);

		// �˿������͑����Ƿ����������y����
		ret = 0;
		if (!clientset.empty()) {
			timeval tv = { 0,0 };
			ret = select(clientset[clientset.size() - 1] + 1, &readfd, NULL, NULL, &tv);
		}

		if (ret > 0) {
			vector<SOCKET> deleteclient; //Ҫ�˳����׽��֣����h�����׽���vector
			for (int i = 0; i < clientset.size(); i++) {
				if (FD_ISSET((int)(clientset[i]), &readfd))
				{
					char data[1024] = { 0 };
					recv(clientset[i], data, 1023, 0);
					string recvdata = data;
					if (recvdata == "quit") //����Ҏ��-�£������������quit, �����i����Ҫ�ώ�ע��.����Ͱ��������׽��ֹرյ�
						deleteclient.push_back(clientset[i]);

					else
						cout << "����" << inet_ntoa(s2addr[clientset[i]].sin_addr) << ":" << data << endl;
				}
			}

			//�ر�Ҫ�˳����׽��֣����׽��ּ����Єh����
			if (!deleteclient.empty()) {
				for (int i = 0; i < deleteclient.size(); i++) {
					cout << "�ͻ���" << inet_ntoa(s2addr[deleteclient[i]].sin_addr) << "���˳����ӣ�ʣ��������Ŀ��" << clientset.size() - 1 << endl;
					closesocket(deleteclient[i]);
					vector<SOCKET>::iterator it = find(clientset.begin(), clientset.end(), deleteclient[i]);
					clientset.erase(it);
				}
			}
		}
	}
}

int main(int argc, char **argv) {

	IOmode iom(12345, "192.168.1.132");
	//iom.blockmode();
	iom.selectmode();
	return 0;
}

