rmdir /s d:\efi
mkdir d:\efi
mkdir d:\efi\boot
copy "gnu-efi\x86_64\bootloader\main.efi" "d:\efi\boot"
rename "d:\efi\boot\main.efi" "bootx64.efi"
copy "kernel\bin\kernel.elf" "d:"
copy "kernel\bin\zap-light16.psf" "d:"