/**
  ******************************************************************************
  * @file           : meshmanger.h
  * @author         : ethan
  * @brief          : manage mesh process
  * @attention      : None
  * @date           : 2024/7/22
  ******************************************************************************
  */

#pragma once

#include "meshexplore.h"
#include "shapeexplore.h"
#include "fileexplore.h"

#include <string_view>

//std::string urlPrefix("");

class MeshManger {
public:
    //文件名应该是依靠一个宏定来定义
    explicit MeshManger(std::string_view fileName);

    MeshManger() = default;

    const char *startMesh();

    static std::string urlPrefix;

private:
    //fixme 存储来自json的数据
    Step step;
    ShapeExplore shapeExplore;
    MeshExplore meshExplore;
    std::string url;
    std::unordered_map<std::string, std::string> map{};
};


