#include "ftp_client.hpp"
#include <iostream>
#include <format>

FtpClient::FtpClient(const std::string &host, int port, const std::string &username, const std::string &password)
    : _host(host), _port(port), _username(username), _password(password), _controlSocket{-1}
{
    std::clog << std::format("Client created for {}:{}!", host, port) << std::endl;
}

FtpClient::~FtpClient()
{
    if (_controlSocket != -1)
    {
        disconnect();
    }
    std::cout << "FtpClient destroyed" << std::endl;
}

bool FtpClient::connect()
{
    _controlSocket = 41; // placeholder

    std::clog << "FTP client connected!" << std::endl;

    return true;
}

void FtpClient::disconnect()
{
    _controlSocket = -1;
    std::cout << "FTP client disconnected!" << std::endl;
}
