/*
UDP��
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
//	///////////////////////////////////////////		socket_����UDPЭ��	��������			///////////////////////////////
//	///*
//	//����Ҫlisten��connect����״̬��ֱ���ڷ���������recvfrom(),���оͰ����׽��ֵĵ�ַ��ָ�룬����ȡ���ݰ���Դ��ַ
//	//*/
//
//
//	////socket() �����׽���
//	//int server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);	//����UDPЭ�飬��Ӧ�Ĳ�������
//
//
//	////bind() �󶨲��������׽���ip���˿����������		��tcpһ��
//	//sockaddr_in serveraddr;	//�����׽��ֵ�ַ���͵Ľṹ�����������Ϊ��������˵�ַ�塢�˿ںš�ip��ַ 
//	//serveraddr.sin_family = AF_INET;
//	//serveraddr.sin_port = htons(12345);	//htons()�Ѳ���ת����tcp/ip�������ֽھ࣬���������޷��Ŷ�������ת���������ֽ�˳��https://blog.csdn.net/zhuguorong11/article/details/523006808
//	//serveraddr.sin_addr.s_addr = inet_addr("192.168.79.129");
//	//bind(server, (sockaddr*)&serveraddr, sizeof(serveraddr));	//���׽��ֺ��׽��ֵ�ַ��Ϣ
//
//
//	////recvfrom()
//	////int len;
//	////sockaddr_in clientaddr;
//	////char recvdata[1024] = { 0 };
//	////recvfrom(server, recvdata, 1023, 0, (sockaddr*)&clientaddr, &len);	//UDP��������Ӧ��recvfrom������ǰ�ĸ�������TCPһ�£����������˿ͻ��˵ĵ�ַ��Ϣ�Ϳͻ����ĳ���
//
//	////cout << recvdata << endl;
//
//
//	//// ʹ����ѭ�����Խ����յ������ݴ�ӡ����Ϊudp���������ģ�û��accept��
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
//	//socket() �����׽���
//	int client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);	//����UDPЭ�飬��Ӧ�Ĳ�������
//
//
//	sockaddr_in serveraddr,clientaddr;	
//	serveraddr.sin_family = AF_INET;
//	serveraddr.sin_port = htons(12345);	
//	serveraddr.sin_addr.s_addr = inet_addr("192.168.79.129");
//
//
//	sendto(client, "hahahhahah!", sizeof("hahahhahah!"), 0, (sockaddr*)&serveraddr,sizeof(serveraddr));	//��5�������ǿͻ���Ҫ���͸��������ĵ�ַ��Ϣ����6�������Ƕ�Ӧ�ķ���������
//
//
//	WSACleanup();
//
//	system("pause");
//	return 0;
//}