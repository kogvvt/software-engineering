//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : SSDDeviceFactory.cpp
//  @ Date : 21.06.2023
//  @ Author : 
//
//


#include "IPCDevice.h"
#include "SSDPCDevice.h"
#include "SSDLaptopDevice.h"
#include "ILaptopDevice.h"
#include "SSDDeviceFactory.h"


IPCDevice* SSDDeviceFactory::fPCDevice() {
    return new SSDPCDevice();
}

ILaptopDevice* SSDDeviceFactory::fLaptopDevice() {
    return new SSDLaptopDevice();
}

