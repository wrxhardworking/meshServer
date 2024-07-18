/**
  ******************************************************************************
  * @file           : server.cpp
  * @author         : 28108
  * @brief          : None
  * @attention      : None
  * @date           : 2024/7/18
  ******************************************************************************
  */

#include "hv/EventLoop.h"
#include "hv/htime.h"
#include "hv/hfile.h"
#include "server.h"

Server::Server(int port) {
    server.port = port;

    httpService.GET("/ping", [](const HttpContextPtr &ctx) {
        return ctx->send("pong");
    });

    //webSocket是基于一个长连接
    webSocketService.onopen = [](const WebSocketChannelPtr &channel, const HttpRequestPtr &req) {
        printf("onopen: GET %s\n", req->Path().c_str());
    };
    webSocketService.onmessage = [](const WebSocketChannelPtr &channel, const std::string &msg) {
    };
    webSocketService.onclose = [](const WebSocketChannelPtr &channel) {
    };

}

void Server::start() {
    server.start();
}
