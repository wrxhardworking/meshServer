cmake_minimum_required(VERSION 3.10)

project(MeshServer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_NETGEN "Enable Netgen" ON)
option(ENABLE_TEST "enable test" ON)
option(ENABLE_DAEMON "enable test" ON)

# --------------------------------------------------------------------------- #
#different compiler set different flag
# --------------------------------------------------------------------------- #
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # GCC-specific compiler flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # MSVC-specific compiler flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W1 /bigobj /MP /wd4068")
    # ban the 'max' and 'min' of msvc
    add_compile_definitions(NOMINMAX)
endif ()


# --------------------------------------------------------------------------- #
#SALOME_USE_64BIT_IDS macro
# --------------------------------------------------------------------------- #
if (CMAKE_SIZEOF_VOID_P STREQUAL 8)
    add_definitions(-DSALOME_USE_64BIT_IDS)
endif (CMAKE_SIZEOF_VOID_P STREQUAL 8)


# --------------------------------------------------------------------------- #
#boost
# --------------------------------------------------------------------------- #
set(CMAKE_PREFIX_PATH "E:\\boost\\boost_1_85_0\\stage\\lib\\cmake")
#set(Boost_DIR "E:\\boost\\boost_1_85_0\\stage\\lib\\cmake\\Boost-1.85.0")
find_package(Boost 1.85.0 REQUIRED COMPONENTS filesystem thread serialization regex)
if (Boost_FOUND)
    message(STATUS "find boost successful")
endif ()

if (MSVC)
    # find the shared boost libs
    add_definitions(-DBOOST_ALL_DYN_LINK)
    # set postfix for debug libs
    if (NOT CMAKE_DEBUG_POSTFIX)
        set(CMAKE_DEBUG_POSTFIX d)
    endif ()
endif ()


# --------------------------------------------------------------------------- #
#VTK
# --------------------------------------------------------------------------- #
find_package(VTK REQUIRED)
if (VTK_FOUND)
    message(STATUS "find vtk successful")
endif ()

# --------------------------------------------------------------------------- #
#occ
# --------------------------------------------------------------------------- #
find_package(OpenCASCADE REQUIRED)
if (OpenCASCADE_FOUND)
    include_directories(${OpenCASCADE_INCLUDE_DIR})
    message(STATUS "find opencscade successful")
endif ()


# --------------------------------------------------------------------------- #
#SMESH
# --------------------------------------------------------------------------- #
find_package(SMESH REQUIRED)
if (SMESH_FOUND)
    message(STATUS "find semsh successful")
endif ()

# --------------------------------------------------------------------------- #
#libhv
# --------------------------------------------------------------------------- #
find_package(libhv REQUIRED CONFIG)
if (libhv_FOUND)
    message(STATUS "find libhv successful")
endif ()

#pthread
link_directories(D:\\conda\\Library\\lib)

add_executable(${PROJECT_NAME}
        main.cpp
        fileexplore.cpp
        myexception.h
        shapeexplore.cpp
        shapeexplore.h
        meshexplore.h
        meshexplore.cpp
        mycontext.cpp
        mycontext.h
        server.cpp
        server.h
        meshmanger.cpp
        meshmanger.h
        meshalogo.h
        meshlog.cpp
        meshlog.h
)


target_link_libraries(
        ${PROJECT_NAME}
        ${SMESH_LIBRARIES}
        #        ${VTK_LIBRARIES}
        #        ${Boost_LIBRARIES}
        #        ${OpenCASCADE_LIBRARIES}
        hv
)

if (ENABLE_DAEMON)
    add_subdirectory(daemon)
endif ()