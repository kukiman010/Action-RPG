
#include <iostream>
#include <vector>
#include <string>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/core/noncopyable.hpp>
#include <boost/enable_shared_from_this.hpp>

using namespace std;
using namespace boost::asio;
io_service service;

typedef boost::shared_ptr<ip::tcp::socket> socket_ptr;
ip::tcp::endpoint ep(ip::tcp::v4(), 2001); // listen on 2001
ip::tcp::acceptor acc(service, ep);

void start_accept(socket_ptr sock);
void handle_accept(socket_ptr sock, const boost::system::error_code & err);
	
int main() 
{
	
	socket_ptr sock(new ip::tcp::socket(service));
	start_accept(sock);
	service.run();
}

void start_accept(socket_ptr sock)
{
	acc.async_accept(*sock, boost::bind(handle_accept, sock, _1));
}
void handle_accept(socket_ptr sock, const boost::system::error_code & err)
{
	if (err) return;
	// at this point, you can read/write to the socket
	socket_ptr sockk(new ip::tcp::socket(service));
	start_accept(sock);
}