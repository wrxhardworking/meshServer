#include "fileexplore.h"
#include "myexception.h"
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

void Unv::Output(std::shared_ptr<SMESH_Mesh> meshPtr) {
    meshPtr->ExportUNV(fileName.c_str());
}


void StlAscii::Output(std::shared_ptr<SMESH_Mesh> meshPtr) {
    meshPtr->ExportSTL(fileName.c_str(), true);
}

TopoDS_Shape StlAscii::Input() {
    return TopoDS_Shape();
}

TopoDS_Shape StlBin::Input() {
    return TopoDS_Shape();
}

void StlBin::Output(std::shared_ptr<SMESH_Mesh> meshPtr) {
    meshPtr->ExportSTL(fileName.c_str(), false);
}
