project(CodeCraftSDK)
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

if (!WIN32)
    link_libraries(pthread rt m)
endif (!WIN32)

AUX_SOURCE_DIRECTORY(. src)
ADD_EXECUTABLE(main ${src}
        stastic/pojo/berth.h
        stastic/pojo/robot.h
        stastic/pojo/boat.h
        stastic/global_const_variation.h
        service/_service_header.h
        service/service_header.h
        stastic/pojo/pojo_header.h
        stastic/stastic_header.h
        service/init/init.h
        service/input/input.h
        service/input/input_header.h
        service/init/init_header.h
        service/init/_init_header.h
        service/input/_input_header.h
        stastic/pojo/_pojo_header.h
        stastic/_stastic_header.h)