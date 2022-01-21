/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "pci.h"
#include "../io/textio.h"
#include "../ports/ports.h"
#include "../lib/string.h"

/**
 * pci_read - read pci device
 * 
 * Using PCI device's data, read data from it
 * and return it as a uint32_t.
 */
unsigned long pci_read(unsigned long bus, unsigned long device, unsigned long function, unsigned long offset, unsigned long reg)
{
    reg |= (bus & 0xFF) << 16;
    reg |= (device & 0x1F) << 11;
    reg |= (function & 0x7) << 8;
    reg |= (offset & 0xFF) & 0xFC;

    port_long_out(PCI_CONFIG, reg);

    return port_long_in(PCI_DATA);
}

void test_pci(){
    unsigned long bus, device, function, vendor, subclass;
    CursorPosition.Y += 16;
    CursorPosition.X = 0;
    puts("Devices over PCI:");
    CursorPosition.Y += 16;
    CursorPosition.X = 0;
    puts("-------------------------------------------------------");
    CursorPosition.Y += 16;
    CursorPosition.X = 0;
    puts("| BUS | DEV | FUN | VENDOR ID | DEVICE ID | CLAS:SUBC |");
    CursorPosition.Y += 16;
    CursorPosition.X = 0;
    puts("-------------------------------------------------------");
    CursorPosition.Y += 16;
    CursorPosition.X = 0;
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
                    CursorPosition.X = 54 * 8;
                    puts("|");
                    CursorPosition.Y += 16;
                    CursorPosition.X = 0;
                }
            }
        }
    }
    puts("-------------------------------------------------------");
    CursorPosition.Y += 16;
    CursorPosition.X = 0;
    return;
}
/**
 * pci_write - write pci device
 * 
 * Using PCI device's data, write data to it
 * in form of uint32_t.
 */
void pci_write(unsigned long bus, unsigned long device, unsigned long function, unsigned long offset, unsigned long reg, unsigned long data)
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
void pci_find(unsigned char _class, unsigned char subclass, unsigned long* bus, unsigned long* device, unsigned long* function, unsigned short* vendor)
{
    unsigned long tmp_bus, tmp_device, tmp_function, tmp_vendor, tmp_subclass;
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
