/**
  ******************************************************************************
  * @file           : ShapeExplore.cpp
  * @author         : 28108
  * @brief          : None
  * @attention      : None
  * @date           : 2024/7/16
  ******************************************************************************
  */

#include <BRepTools.hxx>
#include "shapeexplore.h"

#include <utility>

ShapeExplore::ShapeExplore(TopoDS_Shape &shape) : shape(std::move(shape)) {
    if (!shape.IsNull())
        LogShapeType();

}

void ShapeExplore::LogShapeType() {
    switch (shape.ShapeType()) {
        case TopAbs_COMPOUND:
            std::cout << "Shape type: COMPOUND" << std::endl;
            break;
        case TopAbs_COMPSOLID:
            std::cout << "Shape type: COMPSOLID" << std::endl;
            break;
        case TopAbs_SOLID:
            std::cout << "Shape type: SOLID" << std::endl;
            break;
        case TopAbs_SHELL:
            std::cout << "Shape type: SHELL" << std::endl;
            break;
        case TopAbs_FACE:
            std::cout << "Shape type: FACE" << std::endl;
            break;
        case TopAbs_WIRE:
            std::cout << "Shape type: WIRE" << std::endl;
            break;
        case TopAbs_EDGE:
            std::cout << "Shape type: EDGE" << std::endl;
            break;
        case TopAbs_VERTEX:
            std::cout << "Shape type: VERTEX" << std::endl;
            break;
        case TopAbs_SHAPE:
            std::cout << "Shape type: SHAPE" << std::endl;
            break;
    }
}


void ShapeExplore::ShowShapeInfo(Standard_OStream &os) {
    BRepTools::Dump(shape, os);
}
