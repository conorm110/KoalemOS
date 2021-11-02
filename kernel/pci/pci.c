/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include <stdint.h>
#include "pci.h"
#include "k_stdio.h"
#include "ports.h"
#include "os_helpers.h"

/**
 * pci_read - read pci device
 * 
 * Using PCI device's data, read data from it
 * and return it as a uint32_t.
 */
uint32_t pci_read(uint32_t bus, uint32_t device, uint32_t function, uint32_t offset, uint32_t reg)
{
    reg |= (bus & 0xFF) << 16;
    reg |= (device & 0x1F) << 11;
    reg |= (function & 0x7) << 8;
    reg |= (offset & 0xFF) & 0xFC;

    port_long_out(PCI_CONFIG, reg);

    return port_long_in(PCI_DATA);
}

/**
 * pci_write - write pci device
 * 
 * Using PCI device's data, write data to it
 * in form of uint32_t.
 */
void pci_write(uint32_t bus, uint32_t device, uint32_t function, uint32_t offset, uint32_t reg, uint32_t data)
{
    reg |= (bus & 0xFF) << 16;
    reg |= (device & 0x1F) << 11;
    reg |= (function & 0x7) << 8;
    reg |= offset & 0xFC;

    port_byte_out(PCI_CONFIG, reg);
    port_byte_out(PCI_DATA, data);
}

/**
 * pci_find - find pci device
 * 
 * Find pci device based on class and subclass
 * and then update supplied pointers to point
 * to located devices info. Note: Updates pointer,
 * this function returns void.
 */
void pci_find(uint8_t _class, uint8_t subclass, uint32_t* bus, uint32_t* device, uint32_t* function, uint16_t* vendor)
{
    uint32_t tmp_bus, tmp_device, tmp_function, tmp_vendor, tmp_subclass;
    for(tmp_bus = 0; tmp_bus < 256; tmp_bus++)
    {
        for(tmp_device = 0; tmp_device < 32; tmp_device++)
        {
            for(tmp_function = 0; tmp_function < 8; tmp_function++)
            {
                tmp_vendor = pci_read(tmp_bus, tmp_device, tmp_function, PCI_VENDOR_DEVICE, PCI_VENDOR_DEVICE_REG);
                if(tmp_vendor != 0xFFFFFFFF)
                {
                    tmp_subclass = pci_read(tmp_bus, tmp_device, tmp_function, PCI_CLASS_SUBCLASS, PCI_CLASS_SUBCLASS_REG);
                    if(_class == (tmp_subclass & 0x000000FF) && subclass == (tmp_subclass & 0x0000FF00) >> 8)
                    {
                        *bus = tmp_bus;
                        *device = tmp_device;
                        *function = tmp_function;
                        *vendor = tmp_vendor;
                        return;
                    }
                }
            }
        }
    }
}

/**
 * pci_test - test pci bus
 * 
 * Prints our orginized table of all connected
 * pci devices. Has Bus, Dev#, Function#, VendorID,
 * DeviceID, Class, and Subclass
 */
void pci_test()
{
    uint32_t bus, device, function, vendor, subclass;
    puts("Devices over PCI:\r\n");
    puts("-------------------------------------------------------\r\n");
    puts("| BUS | DEV | FUN | VENDOR ID | DEVICE ID | CLAS:SUBC |\r\n");
    puts("-------------------------------------------------------\r\n");
    for(bus = 0; bus < 256; bus++)
    {
        for(device = 0; device < 32; device++)
        {
            for(function = 0; function < 8; function++)
            {
                vendor = pci_read(bus, device, function, PCI_VENDOR_DEVICE, PCI_VENDOR_DEVICE_REG);
                if(vendor != 0xFFFFFFFF)
                {
                    subclass = pci_read(bus, device, function, PCI_CLASS_SUBCLASS, PCI_CLASS_SUBCLASS_REG);
                    // printf("%x\t", vendor);
                    // printf("%x\t", (vendor & 0xFFFF0000) >> 16); /*device id*/
                    // printf("%x\t", (vendor & 0xFFFF)); /*vendor id*/
                    
                    // printf("%x\t", subclass);
                    // printf("%x\t", (subclass & 0xFF000000) >> 24); /*class*/
                    // printf("%x\t", (subclass & 0xFF0000) >> 16); /*subclass*/
                    // printf("%x\t", (subclass & 0xFF00) >> 8); /*progif*/
                    // printf("%x\t", (subclass & 0xFF)); /*revisionid*/

                    puts("|  ");
                    char buffer[128];
                    puts(itoa(bus, buffer, 10));
                    puts("  |  ");
                    puts(itoa(device, buffer, 10));
                    puts("  |  ");
                    puts(itoa(function, buffer, 10));
                    puts("  |    ");
                    puts(itoa((vendor & 0x0000FFFF), buffer, 16));
                    puts("   |   ");
                    puts(itoa((vendor & 0xFFFF0000 >> 16), buffer, 16));
                    puts("    | ");
                    puts(itoa((subclass & 0x000000FF), buffer, 16));
                    puts(":");
                    puts(itoa(((subclass & 0x0000FF00) >> 8), buffer, 16));
                    puts("\n");

                    
                    //uint32_t bar0 = pci_read(bus, device, function, PCI_BASE_ADDRESS_0_OFFSET, PCI_BASE_ADDRESS_0_REG);
                    //printf("Bar0: %x\r\n", bar0);
                }
            }
        }
    }
    puts("-------------------------------------------------------\r\n");
}