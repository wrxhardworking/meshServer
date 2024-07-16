/**
  ******************************************************************************
  * @file           : ShapeExplore.h
  * @author         : 28108
  * @brief          : None
  * @attention      : None
  * @date           : 2024/7/16
  ******************************************************************************
  */
#pragma once

#include <TopoDS_Shape.hxx>

#include <iostream>

class ShapeExplore {
public:
    explicit ShapeExplore(TopoDS_Shape &shape);

private:
    //输出几何体详细信息
    void ShowShapeInfo(std::ostream &os);

    //打印shape类型
    void LogShapeType();

    TopoDS_Shape shape;
};
