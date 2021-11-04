## Function Overview
<hr>

**void pci_test()** - test pci bus
 
Prints our orginized table of all connected
pci devices. Has Bus, Dev#, Function#, VendorID,
DeviceID, Class, and Subclass
<hr> 

**void pci_find(uint8_t _class, uint8_t subclass, uint32_t\* bus, uint32_t\* device, uint32_t\* function, uint16_t\* vendor)** - find pci device

Find pci device based on class and subclass
and then update supplied pointers to point
to located devices info. Note: Updates pointer,
this function returns void.
<hr>

**uint32_t pci_read(uint32_t bus, uint32_t device, uint32_t function, uint32_t offset, uint32_t reg)** - read pci device

Using PCI device's data, read data from it and return it as a uint32_t.
<hr>

**void pci_write(uint32_t bus, uint32_t device, uint32_t function, uint32_t offset, uint32_t reg, uint32_t data)** - write pci device

Using PCI device's data, write data to it in form of uint32_t.
<hr>

## OS Commands and Access
`pcilist` - runs pci_test()

## PCI Lookup Table
While there are many great resources online for looking up PCI device data, here is a list of some QEMU specific and/or commonly used PCI devices

<table>
    <tr>
    <th>NAME</th>
    <th>BUS</th>
    <th>DEV</th>
    <th>FUN</th>
    <th>VENDOR ID</th>
    <th>DEVICE ID</th>
    <th>CLAS:SUBC</th>
    </tr>
    <td>Unclassified Device</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>8086*</td>
    <td>8086*</td>
    <td>0:6</td>
    </tr>
    <tr>
    <td>AHCI 1.0 SATA Controller</td>
    <td>0</td>
    <td>1</td>
    <td>0</td>
    <td>8086*</td>
    <td>8086*</td>
    <td>1:6</td>
    </tr><tr>
    <td>Unspecified IDE Interface</td>
    <td>0</td>
    <td>1</td>
    <td>1</td>
    <td>8086*</td>
    <td>8086*</td>
    <td>1:1</td>
    </tr><tr>
    <td>Unknown</td>
    <td>0</td>
    <td>1</td>
    <td>3</td>
    <td>8086*</td>
    <td>8086*</td>
    <td>80:6</td>
    </tr><tr>
    <td>Unclassified Device</td>
    <td>0</td>
    <td>2</td>
    <td>0</td>
    <td>1234</td>
    <td>1234</td>
    <td>0:3</td>
    </tr><tr>
    <td>Unclassified Device</td>
    <td>0</td>
    <td>3</td>
    <td>0</td>
    <td>8086*</td>
    <td>8086*</td>
    <td>0:2</td>
    </tr><tr>
    <td>ISA Bridge**</td>
    <td>0</td>
    <td>4</td>
    <td>0</td>
    <td>8086*</td>
    <td>8086*</td>
    <td>6:1</td>
    </tr>
    <tr>
    <td>Unspecified IDE Controller</td>
    <td>0</td>
    <td>4</td>
    <td>0</td>
    <td>8086*</td>
    <td>8086*</td>
    <td>1:1</td>
    </tr>
</table>
*The number 8086 seems to be related to the C200 chipset from intel

**According to a PCI Lookup website this is an PCI->ISA Bridge controller but it appears when a SATA drive is connected

NOTE: Intel does have a Vendor ID 8086 but no pci device with a device ID of 8086. Jank.
