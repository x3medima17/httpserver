#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

#include <string>
TEST(req, basic_get)
{
    HttpRequest req("GET / HTTP/1.1\r\n\r\n");

    EXPECT_EQ(req.get_method(), HttpRequest::http_methods::GET);
    EXPECT_EQ(req.get_uri(),"/");
    EXPECT_EQ(req.get_version(),"HTTP/1.1");
    EXPECT_EQ(req.get_status(), 0);

}


TEST(req, basic_post)
{
    HttpRequest req("POST / HTTP/1.1\r\n\r\n");

    EXPECT_EQ(req.get_method(), HttpRequest::http_methods::POST);
    EXPECT_EQ(req.get_uri(),"/");
    EXPECT_EQ(req.get_version(),"HTTP/1.1");
    EXPECT_EQ(req.get_status(), 0);

}


TEST(req, basic_uri)
{
    HttpRequest req("GET /index.html HTTP/1.1\r\n\r\n");

    EXPECT_EQ(req.get_method(), HttpRequest::http_methods::GET);
    EXPECT_EQ(req.get_uri(),"/index.html");
    EXPECT_EQ(req.get_version(),"HTTP/1.1");
    EXPECT_EQ(req.get_status(), 0);

}


TEST(req, basic_error)
{
    HttpRequest req("GET / HTTP/1.1");
    EXPECT_NE(req.get_status(), 0);

}

TEST(req, basic_error_clrf)
{
    HttpRequest req("GET / HTTP/1.1\r\n");
    EXPECT_NE(req.get_status(), 0);

}

TEST(req, basic_header_one)
{
    HttpRequest req("GET / HTTP/1.1\r\nUser-Agent: Mozilla\r\n\r\n");

    HttpResponse::VecHeaders Headers;
    Headers = {
        {"User-Agent", "Mozilla"}
    };
    EXPECT_EQ(req.get_method(), HttpRequest::http_methods::GET);
    EXPECT_EQ(req.get_uri(),"/");
    EXPECT_EQ(req.get_version(),"HTTP/1.1");
    EXPECT_EQ(req.get_headers(), Headers);
    EXPECT_EQ(req.get_status(), 0);

}

TEST(req, basic_headers)
{
    HttpRequest req("GET / HTTP/1.1\r\nHost: facebook.com\r\nUser-Agent: Mozilla\r\n\r\n");

    HttpResponse::VecHeaders Headers;
    Headers = {
        {"Host", "facebook.com"},
        {"User-Agent", "Mozilla"}
    };
    EXPECT_EQ(req.get_method(), HttpRequest::http_methods::GET);
    EXPECT_EQ(req.get_uri(),"/");
    EXPECT_EQ(req.get_version(),"HTTP/1.1");
    EXPECT_EQ(req.get_headers(), Headers);
    EXPECT_EQ(req.get_status(), 0);

}

TEST(req, basic_content)
{
    HttpRequest req("GET / HTTP/1.1\r\n"
                    "Host: facebook.com\r\n"
                    "User-Agent: Mozilla\r\n"
                    "Content-Length: 11\r\n"
                    "\r\n"
                    "Hello World");

    HttpResponse::VecHeaders Headers;
    Headers = {
        {"Host", "facebook.com"},
        {"User-Agent", "Mozilla"},
        {"Content-Length", "11" }
    };
    EXPECT_EQ(req.get_method(), HttpRequest::http_methods::GET);
    EXPECT_EQ(req.get_uri(),"/");
    EXPECT_EQ(req.get_version(),"HTTP/1.1");
    EXPECT_EQ(req.get_headers(), Headers);
    EXPECT_EQ(req.get_status(), 0);
    EXPECT_EQ(req.get_content_length(), 11);
    EXPECT_EQ(req.get_content(), "Hello World");

}
