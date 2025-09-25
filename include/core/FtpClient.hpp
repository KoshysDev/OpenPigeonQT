#pragma once

#include <string>
#include <vector>

class FtpClient
{
private:
    std::string _host, _username, _password;
    int _port;
    int _controlSocket{-1};
    int _dataSocket{-1};

public:
    FtpClient(const std::string &host, int port, const std::string &username, const std::string &password);
    ~FtpClient();

    bool connect();
    void disconnect();

    std::vector<std::string> listDirectory();
    bool changeDirectory(const std::string& path);
    
    bool moveFile(const std::string& remoteStartingPath, const std::string& remoteEndPath);

    bool uploadFile(const std::string& localPath, const std::string& remotePath);
    bool downloadFile(const std::string& remotePath, const std::string& localPath);
};