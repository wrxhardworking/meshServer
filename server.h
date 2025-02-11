/**
  ******************************************************************************
  * @file           : server.h
  * @author         : ethan
  * @brief          : server base on libhv ,http,websocket
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
    explicit Server(int port, int threadNum = 4);

    //开始服务
    void start();

private:
    WebSocketService webSocketService{};
    HttpService httpService{};
    WebSocketServer server{};
};
