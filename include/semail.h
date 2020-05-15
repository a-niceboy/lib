#ifndef __S_EMAIL_H__
#define __S_EMAIL_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <iostream>

using namespace std;
namespace email
{

class sendemail
{
public:
	sendemail(const string& user = "", const string& password = "", const string& smtp_url = "smtp.qq.com");
	~sendemail();

public:
	void user(const string& _user);
	void password(const string& _password);
	void url(const string& _url = "smtp.qq.com");
	
	void send_email(const string& to_user, const string& title, const string& text);
	
private:
	int m_send();
	int m_recv();

	void get_sockaddr();
	void start_socket();
	void login();
	void quit();

private:
	bool m_stop;
	
	string m_user;
	string m_password;
	string m_url;
	
	sockaddr_in m_servaddr;
	int m_sockfd;
	
	string m_send_buf;
    string m_recv_buf;
};
	
}

#endif
