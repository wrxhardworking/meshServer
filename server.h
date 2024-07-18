/**
  ******************************************************************************
  * @file           : server.h
  * @author         : 28108
  * @brief          : None
  * @attention      : None
  * @date           : 2024/7/18
  ******************************************************************************
  */
#pragma once

#include <hv/WebSocketServer.h>
#include <hv/WebSocketServer.h>

using namespace hv;

class Server {
public:
    explicit Server(int port);

    //开始服务
    void start();

private:
    WebSocketService webSocketService{};
    HttpService httpService{};
    WebSocketServer server{};

};
