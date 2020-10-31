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
//
//	/////////////////////////////////////////	server	//////////////////////////////////////
//	////socket() 创建服务器端套接字
//	//SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	//在linux中，使用int server= socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//
//	////bind() 绑定操作，将套接字ip、端口与服务器绑定
//	//sockaddr_in serveraddr;	//创建套接字地址类型的结构体变量，并且为变量填充了地址族、端口号、ip地址 
//	//serveraddr.sin_family = AF_INET;
//	//serveraddr.sin_port = htons(12345);	//htons()把参数转换成tcp/ip的网络字节顺序，将主机的无符号短整形数转换成网络字节顺序。https://blog.csdn.net/zhuguorong11/article/details/523006808
//	//serveraddr.sin_addr.s_addr = inet_addr("192.168.1.132");	//把字符串转换成ULONG
//	//bind(server, (sockaddr*)&serveraddr, sizeof(serveraddr));	//绑定套接字和套接字地址信息
//
//
//	////listen() 监听
//	//listen(server, 5);//第一个参数是要监听的服务器，第二个是最大的监听数目
//
//
//	////accept()	其实十一个阻塞的过程，连接没到来时，就会一直被阻塞，不会执行下条语句
//	//sockaddr_in clientaddr;
//	//int len = sizeof(clientaddr);					//在linux中，使用socklen_t len = sizeof(clientaddr);	
//	//SOCKET client = accept(server, (sockaddr*)&clientaddr, &len);//第一个参数是服务器的套接字，第二个参数是客户机的地址，第三个参数是客户机的长度
//
//
//	////recv()
//	//char recvdata[1024] = { 0 };
//	//recv(client, recvdata, 1023, 0);//第一个参数是接收的客户端，第二个参数是接收数据的缓冲，参数三是接收数据的长度，第四标志位一般设置为0
//
//
//



//	/////////////////////////////////////////	client	//////////////////////////////////////
//	//socket() 创建一个客户端套接字
//	SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//
//	//connect()
//	sockaddr_in serveraddr;
//	serveraddr.sin_family = AF_INET;
//	serveraddr.sin_addr.s_addr = inet_addr("192.168.79.129");
//	serveraddr.sin_port = htons(12345);
//	connect(client, (sockaddr*)&serveraddr,sizeof(serveraddr));//将客户端与服务器连接,第一个参数是客户端，第二个参数服务器端地址信息，第三个参数是服务器端地址长度
//
//
//	//send()
//	send(client,"holle world!",sizeof("holle world!"),0);
//
//
//
//
//	WSACleanup();
//
//	system("pause");
//	return 0;
//}