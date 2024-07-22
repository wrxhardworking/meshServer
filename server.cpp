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
#include "mycontext.h"

Server::Server(int port, int threadNum) {
    server.setThreadNum(threadNum);
    server.port = port;

    //用于客户端测试服务端的连通性
    httpService.GET("/ping", [](const HttpContextPtr &ctx) {
        std::cout << "服务端正常" << std::endl;
        return ctx->send("pong");
    });
    //http服务
    httpService.POST("/smesh", [](const HttpContextPtr &ctx) {
        return ctx->send("smesh");
    });

    //webSocket服务
    webSocketService.onopen = [](const WebSocketChannelPtr &channel, const HttpRequestPtr &req) {
        printf("onopen: GET %s\n", req->Path().c_str());
        //channel创建一个上下文事件
        channel->newContextPtr<MyContext>();
    };
    webSocketService.onmessage = [](const WebSocketChannelPtr &channel, const std::string &msg) {
        //调用回调 处理
        std::string returnUrl = channel->getContextPtr<MyContext>()->handleStep(msg);
        channel->send(returnUrl);
    };
    webSocketService.onclose = [](const WebSocketChannelPtr &channel) {
        std::cout << "say good bye\n" << std::endl;
    };

    server.registerHttpService(&httpService);
    server.registerWebSocketService(&webSocketService);
}

void Server::start() {
    server.start();
}
