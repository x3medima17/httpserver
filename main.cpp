#include <iostream>
#include "HttpRequest.h"
#include "HttpApplication.h"
#include "RequestHandler.h"
#include "HttpServer.h"
#include "HttpResponse.h"
#include <map>


class Main : public RequestHandler 
{
public:	
	void get()
	{
		render("index.html");
	}
};
int main()
{
	
	std::map<std::string, std::shared_ptr<RequestHandler>> H;
	
	H["/"] = std::shared_ptr<RequestHandler>(new Main);
	
	HttpApplication app(H);
	HttpServer server(app);
	server.bind(8081);
	server.listen(5);
	server.start();
	return 0;
}
