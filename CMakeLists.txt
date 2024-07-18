cmake_minimum_required(VERSION 3.10)
# 项目名称
project(MyProject)
# 指定C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置MyLibrary的路径
set(MYLIBRARY_DIR "D:\\conda\\pkgs\\smesh-9.9.0.0-h27babe3_8\\Library")

option(ENABLE_NETGEN "Enable Netgen" ON)
option(ENABLE_TEST "enable test" ON)

add_definitions(-D_USE_MATH_DEFINES)

#different compiler set different flag
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # GCC-specific compiler flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # MSVC-specific compiler flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W1 /bigobj /MP /wd4068")
endif ()

#设置SALOME_USE_64BIT_IDS宏定义
if (CMAKE_SIZEOF_VOID_P STREQUAL 8)
    add_definitions(-DSALOME_USE_64BIT_IDS)
endif (CMAKE_SIZEOF_VOID_P STREQUAL 8)


set(CMAKE_PREFIX_PATH "E:\\boost\\boost_1_85_0\\stage\\lib\\cmake")
find_package(Boost 1.85.0 REQUIRED)
if (Boost_FOUND)
    MESSAGE(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    MESSAGE(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
    MESSAGE(STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")
endif ()

if (MSVC)
    # find the shared boost libs
    add_definitions(-DBOOST_ALL_DYN_LINK)
    # set postfix for debug libs
    if (NOT CMAKE_DEBUG_POSTFIX)
        set(CMAKE_DEBUG_POSTFIX d)
    endif ()
endif ()

#vtk
find_package(VTK REQUIRED)
if (VTK_FOUND)
    message("find successful")
endif ()

#opencscade
set(CMAKE_PREFIX_PATH "D:\\conda\\pkgs\\occt-7.7.2-all_h165458f_201\\Library\\lib\\cmake\\opencascade")
find_package(OpenCASCADE REQUIRED)
if (OpenCASCADE_FOUND)
    include_directories(${OpenCASCADE_INCLUDE_DIR})
    message("find successful")
endif ()

#libhv
find_package(libhv CONFIG)
if (libhv_FOUND)
    message("find successful")
endif ()

#freeimage
find_library(freeimage NAMES FreeImage PATHS D:\\conda\\pkgs\\freeimage-3.18.0-h30d40d2_12\\Library\\lib)
if (NOT freeimage)
    message(${freeimage})
endif ()

# 包含头文件目录
include_directories(${MYLIBRARY_DIR}/include/smesh/Controls)
include_directories(${MYLIBRARY_DIR}/include/smesh/Driver)
include_directories(${MYLIBRARY_DIR}/include/smesh/DriverDAT)
include_directories(${MYLIBRARY_DIR}/include/smesh/DriverGMF)
include_directories(${MYLIBRARY_DIR}/include/smesh/DriverSTL)
include_directories(${MYLIBRARY_DIR}/include/smesh/DriverUNV)
include_directories(${MYLIBRARY_DIR}/include/smesh/Geom)
include_directories(${MYLIBRARY_DIR}/include/smesh/Kernel)
include_directories(${MYLIBRARY_DIR}/include/smesh/MEFISTO2)
include_directories(${MYLIBRARY_DIR}/include/smesh/MeshVSLink)
include_directories(${MYLIBRARY_DIR}/include/smesh/Netgen)
include_directories(${MYLIBRARY_DIR}/include/smesh/NETGENPlugin)
include_directories(${MYLIBRARY_DIR}/include/smesh/SMDS)
include_directories(${MYLIBRARY_DIR}/include/smesh/SMESHDS)
include_directories(${MYLIBRARY_DIR}/include/smesh/SMESHUtils)
include_directories(${MYLIBRARY_DIR}/include/smesh/StdMeshers)
include_directories(${MYLIBRARY_DIR}/include/smesh/SMESH)
#include_directories(${MYLIBRARY_DIR}/include/smesh/Gmsh)
#
# 链接库目录
link_directories(D:\\conda\\Library\\lib\\)#链接pthread
# 链接dll
link_directories(${MYLIBRARY_DIR}/lib)

#gmsh
#find_library(GMSHEngine_LIB GMSHEngine PATHS D:\\conda\\pkgs\\smesh-9.9.0.0-h27babe3_8\\Library\\lib)
#find_library(GMSHPluginGUI_LIB GMSHPluginGUI PATHS D:\\conda\\pkgs\\smesh-9.9.0.0-h27babe3_8\\Library\\lib)
#find_library(SalomeIDLGMSHPLUGIN_LIB SalomeIDLGMSHPLUGIN PATHS D:\\conda\\pkgs\\smesh-9.9.0.0-h27babe3_8\\Library\\lib)
# 添加可执行文件
add_executable(${PROJECT_NAME} main.cpp ${SRC_LIST}
        FileExplore.cpp
        MyException.h
        ShapeExplore.cpp
        ShapeExplore.h
        MyLog.h
        MeshExplore.h
        MeshExplore.cpp
        test/client_test.cpp
        mycontext.cpp
        mycontext.h
        server.cpp
        server.h
)
# 链接动态库
target_link_libraries(${PROJECT_NAME}
        #        ${GMSHEngine_LIB}
        #        ${GMSHPluginGUI_LIB}
        #        ${SalomeIDLGMSHPLUGIN_LIB}
        Geom.dll
        Kernel.dll
        Controls.dll
        MEFISTO2.dll
        Driver.dll
        MeshVSLink.dll
        DriverDAT.dll
        DriverGMF.dll
        NETGENPlugin.dll
        DriverSTL.dll
        SMDS.dll
        nglib4smesh.dll
        SMESHDS.dll
        DriverUNV.dll
        SMESHUtils.dll
        StdMeshers.dll
        SMESH.dll
        ${VTK_LIBRARIES}
        ${Boost_LIBRARIES}
        ${OpenCASCADE_LIBRARIES}
        hv
)

# 将DLL文件复制到输出目录
#add_custom_command(TARGET MyExecutable POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_if_different
#        ${MYLIBRARY_DIR}/lib/MyLibrary.dll
#        $<TARGET_FILE_DIR:MyExecutable>)
#if (ENABLE_TEST)
#    add_subdirectory(${PROJECT_SOURCE_DIR}/test)
#endif ()