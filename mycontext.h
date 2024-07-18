/**
  ******************************************************************************
  * @file           : mycontext.h
  * @author         : 28108
  * @brief          : None
  * @attention      : None
  * @date           : 2024/7/18
  ******************************************************************************
  */
#pragma once

#include "hv/WebSocketServer.h"
#include "hv/EventLoop.h"
#include "hv/htime.h"
#include "hv/hfile.h"

using namespace hv;

class MyContext {
public:

private:
    TimerID timerID;
};