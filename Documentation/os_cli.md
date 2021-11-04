NOTE: All CLI actions for KoalemOS can be found in os/helpers/os_functions.[c][h][asm]

## Command List & Function List
**haltprogram** - hlt 

Extern to kernel.asm haltprogram which executes hlt command. Use for safe termination.

**termos** - terminate os

Disables cursor, clears screen, then halts all programs. Use at end of os_main or other shutdown routes

**clear** - clear

clears screen

**help** - output help

when called, outputs help menu with all terminal commands

**pcilist** - list pci connections

tests pci and lists out connections and their bus data

**echo** - echos user

echos string following user command, takes char *line as a param

\*   **_cmd_not_found** - output warning

outputs warning partaining to not found terminal command

<sub>*functions that start with a _ are not callable in terminal</sub>
