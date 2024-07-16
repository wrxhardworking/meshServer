//
// Created by 28108 on 2024/7/16.
//

#include "FileExplore.h"
#include "MyException.h"
#include <SMESH_MESH.hxx>


TopoDS_Shape Step::Input() {
    TopoDS_Shape shape;
    STEPControl_Reader aReader_Step;

    auto status = aReader_Step.ReadFile(fileName.c_str());
    if (status != IFSelect_RetDone) {
        throw FileException("the step file open error");
    }

    aReader_Step.PrintCheckLoad(Standard_False, IFSelect_ItemsByEntity);
    for (Standard_Integer i = 1; i <= aReader_Step.NbRootsForTransfer(); i++) {
        std::cout << "this is " << i << std::endl;
        aReader_Step.TransferRoot(i);
        std::cout << aReader_Step.NbShapes();
    }
    for (Standard_Integer i = 1; i <= aReader_Step.NbShapes(); i++) {
        std::cout << "this is " << i << "shape" << std::endl;
        TopoDS_Shape shape_Step = aReader_Step.Shape(i);
        shape = shape_Step;
    }
    return shape;
}

void Unv::Output(SMESH_Mesh *mesh) {
    mesh->ExportUNV(fileName.c_str());
}
