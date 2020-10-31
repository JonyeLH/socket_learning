#include"IOmode.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS

typedef int SOCKET;

#pragma warning(disable:4996)	//强制关闭出错的代码严重性	
//错误	C4996	'inet_addr': Use inet_pton() or InetPton() instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings	socket编程	c : \users\12185\desktop\网络编程\socket编程\socket编程\input and output.cpp	13

#pragma comment(lib, "ws2_32.lib")


IOmode::IOmode(int port, string ipaddr) {
	//WSADATA wsaData;				//LINUX DON'T NEED THIS CODE
	//WSAStartup(MAKEWORD(2, 2), &wsaData);		//LINUX DON'T NEED THIS CODE
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	serveraddr.sin_addr.s_addr = inet_addr(ipaddr.c_str());
	//WSACleanup();
}

IOmode::~IOmode() {
	//WSACleanup();					//LINUX DON'T NEED THIS CODE
}

void IOmode::blockmode() {
	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	sockaddr_in clientaddr;

	//unsigned long ul = 0;//0:阻塞，否则为非阻塞		//FOR WINDOWS 
	//控制:socket I/0阻塞模式
	//int nret = ioctlsocket(server, FIONBIO, (unsigned long*)&ul);

	//1inux中对应设置为非阻塞				//FOR LINUX
	int flags = fcntl(server, F_GETFL, 0);//获取文件的f1ags值
	fcntl(server, F_SETFL, flags | O_NONBLOCK); //设置 成非阻塞模式;

	bind(server, (sockaddr*)&serveraddr, sizeof(serveraddr));

	char buffer[1024];

	recvfrom(server, buffer, 1023, 0, (sockaddr*)&clientaddr, 0);

	listen(server, 5);
	socklen_t len = sizeof(sockaddr);
	SOCKET client = accept(server, (sockaddr*)&clientaddr, &len);


}

void IOmode::selectmode() {

	vector<SOCKET> clientset;//客 户机套接字集合
	map<SOCKET, sockaddr_in> s2addr;//套接字， 地址
	fd_set readfd; //用于检查可读取数据的套接字集合
	int ret = 0;

	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//unsigned long ul = 1;
	//ioctlsocket(server, FIONBIO, (unsigned long*)&ul);//设置server套接字为非阻塞，用于accept

	int flags = fcntl(server, F_GETFL, 0);//获取文件的f1ags值
	fcntl(server, F_SETFL, flags | O_NONBLOCK); //设置 成非阻塞模式;	

	bind(server, (sockaddr*)&serveraddr, sizeof(serveraddr));
	listen(server, 5);

	// 不断接收连接与使用select检查各个客户机套接字是否有数据到来
	while (1) {
		sockaddr_in addr;

		socklen_t len = sizeof(addr);

		int client = accept(server, (sockaddr*)&addr, &len);//接收连接
		if (client > 0) {		//JUST MODIFT CLIENT>0
			clientset.push_back(client);
			s2addr[client] = addr;
			cout << inet_ntoa(addr.sin_addr) << "已加入连接.." << "当前连接数：" << clientset.size() << endl;
		}

		FD_ZERO(&readfd);

		for (int i = 0; i < clientset.size(); i++)
			FD_SET((int)(clientset[i]), &readfd);

		// 査看各个客戸机是否友送数据辻来。
		ret = 0;
		if (!clientset.empty()) {
			timeval tv = { 0,0 };
			ret = select(clientset[clientset.size() - 1] + 1, &readfd, NULL, NULL, &tv);
		}

		if (ret > 0) {
			vector<SOCKET> deleteclient; //要退出的套接字，待刪除的套接字vector
			for (int i = 0; i < clientset.size(); i++) {
				if (FD_ISSET((int)(clientset[i]), &readfd))
				{
					char data[1024] = { 0 };
					recv(clientset[i], data, 1023, 0);
					string recvdata = data;
					if (recvdata == "quit") //呟里規定-下，如果対方发送quit, 我仂就iカ他要断幵注接.我仞就把相座的套接字关闭掉
						deleteclient.push_back(clientset[i]);

					else
						cout << "来自" << inet_ntoa(s2addr[clientset[i]].sin_addr) << ":" << data << endl;
				}
			}

			//关闭要退出的套接字，在套接字集合中刪除它
			if (!deleteclient.empty()) {
				for (int i = 0; i < deleteclient.size(); i++) {
					cout << "客户机" << inet_ntoa(s2addr[deleteclient[i]].sin_addr) << "已退出连接，剩余连接数目：" << clientset.size() - 1 << endl;
					//closesocket(deleteclient[i]);		//LINUX DON'T NEED THIS CODE
					vector<SOCKET>::iterator it = find(clientset.begin(), clientset.end(), deleteclient[i]);
					clientset.erase(it);
				}
			}
		}
	}
}

