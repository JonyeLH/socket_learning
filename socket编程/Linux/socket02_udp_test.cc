#include<sys/socket.h>
#include<arpa/inet.h>	//for inet_addr head
#include<iostream>
using namespace std;

int main(){

	/////////////////////////////////////////		socket_基于UDP协议			///////////////////////////////
	/*
	不需要listen和connect两个状态，直接在服务端中添加recvfrom(),其中就包含套接字的地址和指针，来获取数据包的源地址
	*/


	//socket() 创建套接字
	int server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);	//采用UDP协议，对应的参数设置


	//bind() 绑定操作，将套接字ip、端口与服务器绑定		与tcp一致
	sockaddr_in serveraddr;	//创建套接字地址类型的结构体变量，并且为变量填充了地址族、端口号、ip地址 
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(12345);	//htons()把参数转换成tcp/ip的网络字节距，将主机的无符号短整形数转换成网络字节顺序。https://blog.csdn.net/zhuguorong11/article/details/523006808
	serveraddr.sin_addr.s_addr = inet_addr("192.168.79.129");
	bind(server, (sockaddr*)&serveraddr, sizeof(serveraddr));	//绑定套接字和套接字地址信息


	//recvfrom()
	socklen_t len;
	sockaddr_in clientaddr;
	char recvdata[1024] = { 0 };
	recvfrom(server, recvdata, 1023, 0, (sockaddr*)&clientaddr, &len);	//UDP服务器对应的recvfrom函数，前四个参数与TCP一致，后面增加了客户端的地址信息和客户机的长度

	cout << recvdata << endl;


	// 使用死循环尝试将接收到的数据打印，因为udp是无阻塞的（没有accept）
	//socklen_t len;
	//sockaddr_in clientaddr;
	//char recvdata[1024] = { 0 };
	//while (1) {
	//	if (recvfrom(server, recvdata, 1023, 0, (sockaddr*)&clientaddr, &len))
	//		cout << recvdata << endl;
	//}

	return 0;
}
