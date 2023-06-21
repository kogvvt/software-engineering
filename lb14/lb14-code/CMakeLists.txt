cmake_minimum_required(VERSION 3.25)
project(lb14_code)

set(CMAKE_CXX_STANDARD 11)

add_executable(lb14_code main.cpp HDDDeviceFactory.cpp HDDLaptopDevice.cpp SSDLaptopDevice.cpp SSDPCDevice.cpp SSDPCDevice.cpp SSDDeviceFactory.cpp HDDPCDevice.cpp)
