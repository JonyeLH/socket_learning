//#include <iostream>
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#include <string>
//#include <winsock2.h>
//using namespace std;
//
//#pragma comment(lib, "ws2_32.lib")
//
//int main() {
//	//�����׽��֣���ʼ��
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
//	////socket() �������������׽���
//	//SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	//��linux�У�ʹ��int server= socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//
//	////bind() �󶨲��������׽���ip���˿����������
//	//sockaddr_in serveraddr;	//�����׽��ֵ�ַ���͵Ľṹ�����������Ϊ��������˵�ַ�塢�˿ںš�ip��ַ 
//	//serveraddr.sin_family = AF_INET;
//	//serveraddr.sin_port = htons(12345);	//htons()�Ѳ���ת����tcp/ip�������ֽ�˳�򣬽��������޷��Ŷ�������ת���������ֽ�˳��https://blog.csdn.net/zhuguorong11/article/details/523006808
//	//serveraddr.sin_addr.s_addr = inet_addr("192.168.1.132");	//���ַ���ת����ULONG
//	//bind(server, (sockaddr*)&serveraddr, sizeof(serveraddr));	//���׽��ֺ��׽��ֵ�ַ��Ϣ
//
//
//	////listen() ����
//	//listen(server, 5);//��һ��������Ҫ�����ķ��������ڶ��������ļ�����Ŀ
//
//
//	////accept()	��ʵʮһ�������Ĺ��̣�����û����ʱ���ͻ�һֱ������������ִ���������
//	//sockaddr_in clientaddr;
//	//int len = sizeof(clientaddr);					//��linux�У�ʹ��socklen_t len = sizeof(clientaddr);	
//	//SOCKET client = accept(server, (sockaddr*)&clientaddr, &len);//��һ�������Ƿ��������׽��֣��ڶ��������ǿͻ����ĵ�ַ�������������ǿͻ����ĳ���
//
//
//	////recv()
//	//char recvdata[1024] = { 0 };
//	//recv(client, recvdata, 1023, 0);//��һ�������ǽ��յĿͻ��ˣ��ڶ��������ǽ������ݵĻ��壬�������ǽ������ݵĳ��ȣ����ı�־λһ������Ϊ0
//
//
//



//	/////////////////////////////////////////	client	//////////////////////////////////////
//	//socket() ����һ���ͻ����׽���
//	SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//
//	//connect()
//	sockaddr_in serveraddr;
//	serveraddr.sin_family = AF_INET;
//	serveraddr.sin_addr.s_addr = inet_addr("192.168.79.129");
//	serveraddr.sin_port = htons(12345);
//	connect(client, (sockaddr*)&serveraddr,sizeof(serveraddr));//���ͻ��������������,��һ�������ǿͻ��ˣ��ڶ��������������˵�ַ��Ϣ�������������Ƿ������˵�ַ����
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