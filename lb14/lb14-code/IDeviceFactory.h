//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : IDeviceFactory.h
//  @ Date : 21.06.2023
//  @ Author : 
//
//


#if !defined(_IDEVICEFACTORY_H)
#define _IDEVICEFACTORY_H

#include "IPCDevice.h"
#include "ILaptopDevice.h"
#include <iostream>

class IDeviceFactory {
public:
	virtual IPCDevice* fPCDevice() = 0;
    virtual ILaptopDevice* fLaptopDevice() = 0;
};

#endif  //_IDEVICEFACTORY_H
