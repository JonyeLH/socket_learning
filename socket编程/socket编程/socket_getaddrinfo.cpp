///*
//套接字地址解析函数：getaddrinfo()	根据传进的参数：域名，服务名，标志位信息，指向套接字地址指针的指针，获得套接字地址
//套接字地址获得主机名（域名），服务名函数：getnameinfo	
//*/
//
//#include <iostream>
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#include <string>
//#include <map>
//#include <winsock2.h>
//#include <ws2tcpip.h>
//using namespace std;
//
//#pragma comment(lib, "ws2_32.lib")
//
//int main() {
//	WSADATA wsaData;
//	WSAStartup(MAKEWORD(2, 2), &wsaData);
//
//	addrinfo hint, *res;	//用于getaddrinfo()函数返回信息的存储，包括套接字地址信息；在这声明了一个getaddrinfo函数需要的标志位，一个保存套接字地址的指针
//	memset(&hint, 0, sizeof(hint));	//初始化
//
//
//	//addrinfo结构体中前四个标志位的设定 可以返回不同输出结果 （得到的套接字地址受到影响）
//	hint.ai_flags = AI_CANONNAME;		//获得规范的主机名（域名）
//	hint.ai_family = AF_INET;			//获得地址族，查询B站http是否含有ipv6地址
//	hint.ai_socktype = SOCK_STREAM;
//	hint.ai_protocol = IPPROTO_TCP;
//
//
//	//getaddrinfo()获得套接字地址，传进的参数：域名，服务名，标志位信息，指向套接字地址指针的指针
//	getaddrinfo("bilibili.com", "http", &hint, &res);	
//
//	map<string, int> ip2port;
//	for (addrinfo *p = res; p != NULL; p = p->ai_next) {	//遍历所有输出套接字，就是遍历链表（addrinfo结构体中的成员ai_next）
//		sockaddr_in *addr = (sockaddr_in*)p->ai_addr;	//在addrinfo中存储套接字地址的类型是sockaddr，为了方便操作在这转成sockaddr_in类型
//		int port = ntohs(addr->sin_port);	//获得端口号，这里得到的是网络字节顺序，需要转成主机类型使用ntohs()函数
//		string ipaddr = inet_ntoa(addr->sin_addr);	//获得端口号，这里得到的是网络字节顺序，需要转换成主机类型使用inet_ntoa()函数
//		ip2port[ipaddr] = port;		//结果使用map存储
//	}
//
//
//
//	sockaddr_in localaddr;
//	localaddr.sin_family = AF_INET;
//	localaddr.sin_port = htons(80);
//	localaddr.sin_addr.s_addr = inet_addr("192.168.1.132");
//
//	char hostname[1024] = { 0 }, servername[1024] = { 0 };
//
//	//通过套接字地址获得域名，服务名
//	getnameinfo((sockaddr*)&localaddr,sizeof(localaddr),hostname,1023,servername,1023,0);
//
//	WSACleanup();
//
//	return 0;
//}


