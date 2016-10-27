#include "HttpMessage.h"
#include <vector>
#include <string>
#include <cassert>


HttpMessage::~HttpMessage(){}

HttpMessage::HttpMessage(){}

HttpMessage::HttpMessage(const std::string& raw, const std::string& ip, int port):
             remote_ip(ip),
             remote_port(port)
{

    auto tmp = split(raw,"\r\n\r\n");
    if(tmp.size() < 2)
    {
        status = 1;
        return;
    }
    auto header = split(tmp.front(),"\r\n");
    raw_header = tmp.front();

    //merge content
    std::string content("");
    for(size_t i=1;i <tmp.size();i++)
        content += tmp.at(i);
    raw_content = content;

    //request line
    this->first_line = header.front();

    //Headers
    for(size_t i=1; i<header.size();i++)
    {
        auto row = header.at(i);
        auto curr = split(row, ": ");
        if(curr.size() != 2)
        {
            status = 4;
            return;
        }
        Headers.insert({curr.front(), curr.back()});
    }
    if(Headers.find("Content-Length") != Headers.end())
        assert(Headers["Content-Length"] == std::to_string(content.length()));
    content_length = content.length();

    this->content = content;
}



std::vector<std::string> HttpMessage::split(const std::string& target, const std::string& splitter)
{
    std::vector<std::string> V;
    auto i = 0;
    auto delim_len = splitter.length();
    auto pos = target.find(splitter);
    while (pos != std::string::npos) {
      V.push_back(target.substr(i, pos-i));
      pos += delim_len;
      i = pos;
      pos = target.find(splitter, pos);

      if (pos == std::string::npos)
         V.push_back(target.substr(i, target.length()));
    }
    if(V.size() == 0)
        V.push_back(target);
    return V;
}



Utils::VecHeaders HttpMessage::get_headers() const { return Headers; }
std::string HttpMessage::get_version() const { return version; }
std::string HttpMessage::get_content() const { return content; }
int HttpMessage::get_status() const { return status; }
int HttpMessage::get_content_length() const { return content_length; }
std::string HttpMessage::get_remote_ip() const { return remote_ip; }
int HttpMessage::get_remote_port() const { return remote_port; }



