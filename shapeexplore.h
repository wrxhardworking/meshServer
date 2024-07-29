/**
  ******************************************************************************
  * @file           : ShapeExplore.h
  * @author         : ethan
  * @brief          : mange shape to mesh
  * @attention      : None
  * @date           : 2024/7/16
  ******************************************************************************
  */
#pragma once

#include <TopExp.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopTools_IndexedMapOfShape.hxx>

#include <iostream>

class ShapeExplore {
public:
    ShapeExplore() = default;

    explicit ShapeExplore(const TopoDS_Shape &shape);

    TopoDS_Shape &GetTopoDSShape() { return shape; }

    TopoDS_Shape GetFace(int index) { return TopoDS::Face(mapOfFaces(index)); }

    TopoDS_Shape GetSolid(int index) { return TopoDS::Solid(mapOfSolid(index)); }

    TopoDS_Shape GetCompound(int index) { return TopoDS::Compound(mapOfCompound(index)); }

    TopoDS_Shape GetCompoundSolid(int index) { return TopoDS::CompSolid(mapOfCompoundSolid(index)); }


private:
    //输出几何体详细信息
    void ShowShapeInfo(Standard_OStream &os);

    //打印shape类型
    void LogShapeType();

    TopoDS_Shape shape;

    //面、体、等的index映射
    TopTools_IndexedMapOfShape mapOfFaces;
    TopTools_IndexedMapOfShape mapOfSolid;
    TopTools_IndexedMapOfShape mapOfCompound;
    TopTools_IndexedMapOfShape mapOfCompoundSolid;

};
