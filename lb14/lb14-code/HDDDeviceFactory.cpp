//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : HDDDeviceFactory.cpp
//  @ Date : 21.06.2023
//  @ Author : 
//
//


#include "IPCDevice.h"
#include "HDDPCDevice.h"
#include "HDDLaptopDevice.h"
#include "ILaptopDevice.h"
#include "HDDDeviceFactory.h"

IPCDevice* HDDDeviceFactory::fPCDevice() {
    return new HDDPCDevice();
}

ILaptopDevice* HDDDeviceFactory::fLaptopDevice() {
    return new HDDLaptopDevice();
}

