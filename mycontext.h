/**
  ******************************************************************************
  * @file           : mycontext.h
  * @author         : ethan
  * @brief          : per client per context
  * @attention      : None
  * @date           : 2024/7/18
  ******************************************************************************
  */
#pragma once

#include "hv/WebSocketServer.h"
#include "hv/EventLoop.h"
#include "hv/htime.h"
#include "hv/hfile.h"
#include "hv/json.hpp"
#include "meshmanger.h"

#include <unordered_map>


using namespace hv;

class MyContext {
public:
    MyContext() = default;

    const char *handleStep(const std::string &msg);

    std::string handleElse(const std::string &msg);

private:
    TimerID timerID{};
    MeshManger meshManger;
    Json json;
};