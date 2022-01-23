/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */



#define PCI_CONFIG  0xCF8
#define PCI_DATA    0xCFC

#define PCI_VENDOR_DEVICE_REG   0x80000000
#define PCI_CLASS_SUBCLASS_REG  0x80000002

#define PCI_BASE_ADDRESS_0_REG  0x80000004
#define PCI_BASE_ADDRESS_1_REG  0x80000005
#define PCI_BASE_ADDRESS_2_REG  0x80000006
#define PCI_BASE_ADDRESS_3_REG  0x80000007
#define PCI_BASE_ADDRESS_4_REG  0x80000008
#define PCI_BASE_ADDRESS_5_REG  0x80000009

#define PCI_VENDOR_DEVICE 0x00
#define PCI_CLASS_SUBCLASS 0x08

#define PCI_BASE_ADDRESS_0_OFFSET   0x10
#define PCI_BASE_ADDRESS_1_OFFSET   0x14
#define PCI_BASE_ADDRESS_2_OFFSET   0x18
#define PCI_BASE_ADDRESS_3_OFFSET   0x1C
#define PCI_BASE_ADDRESS_4_OFFSET   0x20
#define PCI_BASE_ADDRESS_5_OFFSET   0x24

void test_pci();
void pci_find(unsigned char _class, unsigned char subclass, unsigned long* bus, unsigned long* device, unsigned long* function, unsigned short* vendor);
unsigned long pci_read(unsigned long bus, unsigned long device, unsigned long function, unsigned long offset, unsigned long reg);
void pci_write(unsigned long bus, unsigned long device, unsigned long function, unsigned long offset, unsigned long reg, unsigned long data);