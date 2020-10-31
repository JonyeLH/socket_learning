/*
UDP：
socktype = SOCK_DGRAM
protocol = IPPROTO_UDP

TCP:
socktype =SOCK_STREAM
protocol = IPPROTO_TCP
*/

//#include <iostream>
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#include <string>
//#include <winsock2.h>
//using namespace std;
//
//#pragma comment(lib, "ws2_32.lib")
//
//int main() {
//	//启动套接字，初始化
//	WORD wVersionRequested;
//	WSADATA wsaData;
//	int err;
//
//	/* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
//	wVersionRequested = MAKEWORD(2, 2);
//
//	err = WSAStartup(wVersionRequested, &wsaData);
//	if (err != 0) {
//		/* Tell the user that we could not find a usable */
//		/* Winsock DLL.                                  */
//		printf("WSAStartup failed with error: %d\n", err);
//		return 1;
//	}
//
//
//	///////////////////////////////////////////		socket_基于UDP协议	服务器端			///////////////////////////////
//	///*
//	//不需要listen和connect两个状态，直接在服务端中添加recvfrom(),其中就包含套接字的地址和指针，来获取数据包的源地址
//	//*/
//
//
//	////socket() 创建套接字
//	//int server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);	//采用UDP协议，对应的参数设置
//
//
//	////bind() 绑定操作，将套接字ip、端口与服务器绑定		与tcp一致
//	//sockaddr_in serveraddr;	//创建套接字地址类型的结构体变量，并且为变量填充了地址族、端口号、ip地址 
//	//serveraddr.sin_family = AF_INET;
//	//serveraddr.sin_port = htons(12345);	//htons()把参数转换成tcp/ip的网络字节距，将主机的无符号短整形数转换成网络字节顺序。https://blog.csdn.net/zhuguorong11/article/details/523006808
//	//serveraddr.sin_addr.s_addr = inet_addr("192.168.79.129");
//	//bind(server, (sockaddr*)&serveraddr, sizeof(serveraddr));	//绑定套接字和套接字地址信息
//
//
//	////recvfrom()
//	////int len;
//	////sockaddr_in clientaddr;
//	////char recvdata[1024] = { 0 };
//	////recvfrom(server, recvdata, 1023, 0, (sockaddr*)&clientaddr, &len);	//UDP服务器对应的recvfrom函数，前四个参数与TCP一致，后面增加了客户端的地址信息和客户机的长度
//
//	////cout << recvdata << endl;
//
//
//	//// 使用死循环尝试将接收到的数据打印，因为udp是无阻塞的（没有accept）
//	//int len;
//	//sockaddr_in clientaddr;
//	//char recvdata[1024] = { 0 };
//	//while (1) {
//	//	if (recvfrom(server, recvdata, 1023, 0, (sockaddr*)&clientaddr, &len))
//	//		cout << recvdata << endl;
//	//}
//
//
//
//
//
//	////////////////////////////////////////////////	client		/////////////////////////////////////////////
//	//socket() 创建套接字
//	int client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);	//采用UDP协议，对应的参数设置
//
//
//	sockaddr_in serveraddr,clientaddr;	
//	serveraddr.sin_family = AF_INET;
//	serveraddr.sin_port = htons(12345);	
//	serveraddr.sin_addr.s_addr = inet_addr("192.168.79.129");
//
//
//	sendto(client, "hahahhahah!", sizeof("hahahhahah!"), 0, (sockaddr*)&serveraddr,sizeof(serveraddr));	//第5个参数是客户端要发送给服务器的地址信息，第6个参数是对应的服务器长度
//
//
//	WSACleanup();
//
//	system("pause");
//	return 0;
//}