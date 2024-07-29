#include "hv/EventLoop.h"
#include "hv/htime.h"
#include "hv/hfile.h"
#include "server.h"
#include "mycontext.h"
#include "myexception.h"

Server::Server(int port, int threadNum) {
    server.setThreadNum(threadNum);
    server.port = port;

    //用于客户端测试服务端的连通性
    httpService.GET("/ping", [](const HttpContextPtr &ctx) {
        return ctx->send("pong");
    });
    //http服务
    httpService.POST("/smesh", [](const HttpContextPtr &ctx) {
        return ctx->send("smesh");
    });
    //webSocket服务
    webSocketService.onopen = [](const WebSocketChannelPtr &channel, const HttpRequestPtr &req) {
        auto ctx = channel->newContextPtr<MyContext>();
    };
    webSocketService.onmessage = [](const WebSocketChannelPtr &channel, const std::string &msg) {
        //调用回调 处理
        try {
            std::string returnUrl = channel->getContextPtr<MyContext>()->handleStep(msg);
            channel->send(returnUrl);
        } catch (const std::exception &e) {
            channel->send(e.what());
            channel->close();
        }
    };
    webSocketService.onclose = [](const WebSocketChannelPtr &channel) {
        if (channel->isConnected())
            channel->close();
    };

    server.registerHttpService(&httpService);
    server.registerWebSocketService(&webSocketService);
}

void Server::start() {
    server.start();
}
