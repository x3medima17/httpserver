#include "gtest/gtest.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "HttpClient.h"
#include <string>


TEST(cli, basic)
{
    HttpClient cli("http://facebook.com/");

    EXPECT_EQ(cli.get_method(), HttpRequest::http_methods::GET);
    EXPECT_EQ(cli.get_uri(),"/");
    EXPECT_EQ(cli.get_host(),"facebook.com");
    EXPECT_EQ(cli.get_port(), 80);
    EXPECT_EQ(cli.get_status(), 0);

}


TEST(cli, basic_port)
{
    HttpClient cli("http://facebook.com:8080/");

    EXPECT_EQ(cli.get_method(), HttpRequest::http_methods::GET);
    EXPECT_EQ(cli.get_uri(),"/");
    EXPECT_EQ(cli.get_host(),"facebook.com");
    EXPECT_EQ(cli.get_port(), 8080);
    EXPECT_EQ(cli.get_status(), 0);
}


TEST(cli, basic_uri)
{
    HttpClient cli("http://facebook.com/index.html");

    EXPECT_EQ(cli.get_method(), HttpRequest::http_methods::GET);
    EXPECT_EQ(cli.get_uri(),"/index.html");
    EXPECT_EQ(cli.get_host(),"facebook.com");
    EXPECT_EQ(cli.get_port(), 80);
    EXPECT_EQ(cli.get_status(), 0);
}


TEST(cli, basic_wrong_protocol)
{
    HttpClient cli("https://facebook.com/");

    EXPECT_NE(cli.get_status(), 0);

}


TEST(cli, basic_wrong_structure)
{
    HttpClient cli("some random things");

    EXPECT_NE(cli.get_status(), 0);
}


TEST(cli, fetch_200)
{
    HttpClient cli("http://httpbin.org/status/200");

    cli.fetch();
    auto resp = cli.response;
    EXPECT_EQ(resp.get_status(), 0);
    EXPECT_EQ(resp.get_http_status(), 200);


}

TEST(cli, fetch_404)
{
    HttpClient cli("http://httpbin.org/status/404");

    cli.fetch();
    auto resp = cli.response;
    EXPECT_EQ(resp.get_status(), 0);
    EXPECT_EQ(resp.get_http_status(), 404);

}

TEST(cli, fetch_500)
{
    HttpClient cli("http://httpbin.org/status/500");

    cli.fetch();
    auto resp = cli.response;
    EXPECT_EQ(resp.get_status(), 0);
    EXPECT_EQ(resp.get_http_status(), 500);

}

TEST(cli, fetch_ip)
{
    HttpClient cli("http://httpbin.org/status/500");
    std::string str = "{\n  \"origin\": \"192.249.28.106\"\n}";
    cli.fetch();
    auto resp = cli.response;
    EXPECT_EQ(resp.get_status(), 0);
    EXPECT_EQ(resp.get_http_status(), 200);
    EXPECT_EQ(resp.get_content(), str);
    EXPECT_EQ(resp.get_content_length(), 33);

}

TEST(cli, headers)
{
    HttpClient cli("http://httpbin.org/status/200");

    HttpResponse::VecHeaders V = {
        { "Server",  "nginx" },
        { "Date", "Sun, 23 Oct 2016 06:54:32 GMT"},
        { "Content-Type", "text/html; charset=utf-8"},
        { "Content-Length", "0" },
        { "Connection", "keep-alive" },
        { "Access-Control-Allow-Origin", "*"},
        { "Access-Control-Allow-Credentials", "true"}
    };
    cli.fetch();
    auto resp = cli.response;
    EXPECT_EQ(resp.get_status(), 0);
    EXPECT_EQ(resp.get_http_status(), 200);
    EXPECT_EQ(resp.get_headers(), V);


}

