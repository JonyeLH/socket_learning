#include<sys/socket.h>
#include<arpa/inet.h>	//for inet_addr head
#include<iostream>
using namespace std;

int main(){

	//socket() 创建套接字
	int server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	


	//bind() 绑定操作，将套接字ip、端口与服务器绑定
	sockaddr_in serveraddr;	//创建套接字地址类型的结构体变量，并且为变量填充了地址族、端口号、ip地址 
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(12345);	//htons()把参数转换成tcp/ip的网络字节距，将主机的无符号短整形数转换成网络字节顺序。https://blog.csdn.net/zhuguorong11/article/details/523006808
	serveraddr.sin_addr.s_addr = inet_addr("192.168.79.129");

	bind(server, (sockaddr*)&serveraddr, sizeof(serveraddr));	//绑定套接字和套接字地址信息


	//listen() 监听
	listen(server, 5);//第一个参数是要监听的服务器，第二个是最大的监听数目
	cout<<"listen..."<<endl;	

	//accept()	其实十一个阻塞的过程，连接没到来时，就会一直被阻塞，不会执行下条语句
	sockaddr_in clientaddr;
	socklen_t len = sizeof(clientaddr);
	int client = accept(server, (sockaddr*)&clientaddr, &len);//第一个参数是服务器的套接字，第二个参数是客户机的地址，第三个参数是客户机的长度


	//recv()
	char recvdata[1024] = { 0 };
	recv(client, recvdata, 1023, 0);//第一个参数是接收的客户端，第二个参数是接收数据的缓冲，参数三是接收数据的长度，第四标志位一般设置为0

	cout<<recvdata<<endl;	

	return 0;
}
