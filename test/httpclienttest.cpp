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


TEST(cli, port_80)
{
    HttpClient cli("http://google.com/");

    EXPECT_EQ(cli.get_status(), 0);
    EXPECT_EQ(cli.get_port(), 80);
}

TEST(cli, port_8080)
{
    HttpClient cli("http://google.com:8080/");

    EXPECT_EQ(cli.get_status(), 0);
    EXPECT_EQ(cli.get_port(), 8080);
    EXPECT_EQ(cli.get_host(),"google.com");
    EXPECT_EQ(cli.get_uri(), "/");
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

TEST(cli, fetch_robots)
{
    HttpClient cli("http://httpbin.org/robots.txt");
    std::string str = "User-agent: *\nDisallow: /deny\n";
    cli.fetch();
    auto resp = cli.response;
    EXPECT_EQ(resp.get_status(), 0);
    EXPECT_EQ(resp.get_http_status(), 200);
    EXPECT_EQ(resp.get_content(), str);
    EXPECT_EQ(resp.get_content_length(), 30);

}

TEST(cli, fetch_headers)
{
    HttpClient cli("http://httpbin.org/status/200");

    HttpResponse::VecHeaders V = {
        { "Server",  "nginx" },
        { "Content-Type", "text/html; charset=utf-8"},
        { "Content-Length", "0" },
        { "Connection", "keep-alive" },
        { "Access-Control-Allow-Origin", "*"},
        { "Access-Control-Allow-Credentials", "true"}
    };
    cli.fetch();
    auto resp = cli.response;
    auto expV = resp.get_headers();
    expV.erase("Date");
    EXPECT_EQ(resp.get_status(), 0);
    EXPECT_EQ(resp.get_http_status(), 200);
    EXPECT_EQ(expV, V);


}

