///*
//�׽��ֵ�ַ����������getaddrinfo()	���ݴ����Ĳ���������������������־λ��Ϣ��ָ���׽��ֵ�ַָ���ָ�룬����׽��ֵ�ַ
//�׽��ֵ�ַ�������������������������������getnameinfo	
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
//	addrinfo hint, *res;	//����getaddrinfo()����������Ϣ�Ĵ洢�������׽��ֵ�ַ��Ϣ������������һ��getaddrinfo������Ҫ�ı�־λ��һ�������׽��ֵ�ַ��ָ��
//	memset(&hint, 0, sizeof(hint));	//��ʼ��
//
//
//	//addrinfo�ṹ����ǰ�ĸ���־λ���趨 ���Է��ز�ͬ������ ���õ����׽��ֵ�ַ�ܵ�Ӱ�죩
//	hint.ai_flags = AI_CANONNAME;		//��ù淶����������������
//	hint.ai_family = AF_INET;			//��õ�ַ�壬��ѯBվhttp�Ƿ���ipv6��ַ
//	hint.ai_socktype = SOCK_STREAM;
//	hint.ai_protocol = IPPROTO_TCP;
//
//
//	//getaddrinfo()����׽��ֵ�ַ�������Ĳ���������������������־λ��Ϣ��ָ���׽��ֵ�ַָ���ָ��
//	getaddrinfo("bilibili.com", "http", &hint, &res);	
//
//	map<string, int> ip2port;
//	for (addrinfo *p = res; p != NULL; p = p->ai_next) {	//������������׽��֣����Ǳ�������addrinfo�ṹ���еĳ�Աai_next��
//		sockaddr_in *addr = (sockaddr_in*)p->ai_addr;	//��addrinfo�д洢�׽��ֵ�ַ��������sockaddr��Ϊ�˷����������ת��sockaddr_in����
//		int port = ntohs(addr->sin_port);	//��ö˿ںţ�����õ����������ֽ�˳����Ҫת����������ʹ��ntohs()����
//		string ipaddr = inet_ntoa(addr->sin_addr);	//��ö˿ںţ�����õ����������ֽ�˳����Ҫת������������ʹ��inet_ntoa()����
//		ip2port[ipaddr] = port;		//���ʹ��map�洢
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
//	//ͨ���׽��ֵ�ַ���������������
//	getnameinfo((sockaddr*)&localaddr,sizeof(localaddr),hostname,1023,servername,1023,0);
//
//	WSACleanup();
//
//	return 0;
//}


