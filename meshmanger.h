/**
  ******************************************************************************
  * @file           : meshmanger.h
  * @author         : 28108
  * @brief          : None
  * @attention      : None
  * @date           : 2024/7/22
  ******************************************************************************
  */

#pragma once

#include "meshexplore.h"
#include "shapeexplore.h"
#include "fileexplore.h"

#include <string_view>

class MeshManger {
public:
    //文件名应该是依靠一个宏定来定义
    explicit MeshManger(std::string_view fileName);

    const char *StartMesh();

private:
    //fixme 存储来自json的数据
    std::unordered_map<std::string, std::string> map;
    MeshExplore meshExplore;
    ShapeExplore shapeExplore;
    Step step;
    std::string url;
};
