#include "../port/port.h"
#include "../graphics/render_text.h"
#include "pci.h"
#include "../lib/klm_string.h"

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
    print_str("VENDOR ID:DEVICE ID, BUS, FUN, DEV, CLASS:SUBCLASS");
    print_nl();
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
                    char buffer0[] = "\0\0\0\0\0\0\0\0";
                    char buffer1[] = "\0\0\0\0\0\0\0\0";
                    char buffer2[] = "\0\0\0\0\0\0\0\0";
                    char buffer3[] = "\0\0\0\0\0\0\0\0";
                    char buffer4[] = "\0\0\0\0\0\0\0\0";
                    char buffer5[] = "\0\0\0\0\0\0\0\0";
                    char buffer6[] = "\0\0\0\0\0\0\0\0";
                    char *vendor_id = itoa((vendor & 0xFFFF0000), buffer1, 16);
                    vendor_id[4] = '\0';
                    char *bus_str = itoa(device, buffer4, 10);
                    print_str(itoa((vendor & 0x0000FFFF), buffer0, 16));
                    print_str(":");
                    print_str(vendor_id);
                    print_str(", ");
                    print_str(itoa(bus, buffer2, 10));
                    print_str(", ");
                    print_str(itoa(function, buffer3, 10));
                    print_str(", ");
                    print_str(bus_str);
                    print_str(", ");
                    print_str(itoa((subclass & 0x000000FF), buffer5, 16));
                    print_str(":");
                    print_str(itoa(((subclass & 0x0000FF00) >> 8), buffer6, 16));
                    print_nl();
                }
            }
        }
    }
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