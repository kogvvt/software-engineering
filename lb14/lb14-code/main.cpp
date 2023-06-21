#include <iostream>
#include "IDeviceFactory.h"
#include "HDDDeviceFactory.h"

int main() {
    IDeviceFactory *iDeviceFactory;
    ILaptopDevice *iLaptopDevice;
    iDeviceFactory = new HDDDeviceFactory;
    iLaptopDevice = iDeviceFactory->fLaptopDevice();
    iLaptopDevice->displayDevice();
    std::cin.get();

    return 0;
}
