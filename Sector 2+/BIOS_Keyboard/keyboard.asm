mapChar:
    inc dh
    
    ; letters
    cmp  bh,0x1E
    je   ascan
    cmp  bh,0x30
    je   bscan
    cmp  bh,0x2E
    je   cscan
    cmp  bh,0x20
    je   dscan
    cmp  bh,0x12
    je   escan
    cmp  bh,0x21
    je   fscan
    cmp  bh,0x22
    je   gscan
    cmp  bh,0x23
    je   hscan
    cmp  bh,0x17
    je   iscan
    cmp  bh,0x24
    je   jscan
    cmp  bh,0x25
    je   kscan
    cmp  bh,0x26
    je   lscan
    cmp  bh,0x32
    je   mscan
    cmp  bh,0x31
    je   nscan
    cmp  bh,0x18
    je   oscan
    cmp  bh,0x19
    je   pscan
    cmp  bh,0x10
    je   qscan
    cmp  bh,0x13
    je   rscan
    cmp  bh,0x1F
    je   sscan
    cmp  bh,0x14
    je   tscan
    cmp  bh,0x16
    je   uscan
    cmp  bh,0x2F
    je   vscan
    cmp  bh,0x11
    je   wscan
    cmp  bh,0x2D
    je   xscan
    cmp  bh,0x15
    je   yscan
    cmp  bh,0x2C
    je   zscan

    ; numbers
    cmp  bh,0x02
    je   onescan
    cmp  bh,0x03
    je   twoscan
    cmp  bh,0x04
    je   threescan
    cmp  bh,0x05
    je   fourscan
    cmp  bh,0x06
    je   fivescan
    cmp  bh,0x07
    je   sixscan
    cmp  bh,0x08
    je   sevenscan
    cmp  bh,0x09
    je   eightscan
    cmp  bh,0x0A
    je   ninescan
    cmp  bh,0x0B
    je   zeroscan

    
    ;special 
    cmp  bh,0x39
    je   spacescan

    sub  dh, 0x01 ; if no space occupying chars, dont inc dh

    cmp  bh,0x1C
    je   newline
    
    mov  bh,0x00  ; if no keyscan is reached clear char reg

    ret

spacescan:
    mov bh, ' '
    ret
onescan:
    mov bh, '1'
    ret
twoscan:
    mov bh, '2'
    ret
threescan:
    mov bh, '3'
    ret
fourscan:
    mov bh, '4'
    ret
fivescan:
    mov bh, '5'
    ret
sixscan:
    mov bh, '6'
    ret
sevenscan:
    mov bh, '7'
    ret
eightscan:
    mov bh, '8'
    ret
ninescan:
    mov bh, '9'
    ret
zeroscan:
    mov bh, '0'
    ret

ascan:
    mov bh, 'a'
    ret
bscan:
    mov bh, 'b'
    ret
cscan:
    mov bh, 'c'
    ret
dscan:
    mov bh, 'd'
    ret
escan:
    mov bh, 'e'
    ret
fscan:
    mov bh, 'f'
    ret
gscan:
    mov bh, 'g'
    ret
hscan:
    mov bh, 'h'
    ret
iscan:
    mov bh, 'i'
    ret
jscan:
    mov bh, 'j'
    ret
kscan:
    mov bh, 'k'
    ret
lscan:
    mov bh, 'l'
    ret
mscan:
    mov bh, 'm'
    ret
nscan:
    mov bh, 'n'
    ret
oscan:
    mov bh, 'o'
    ret
pscan:
    mov bh, 'p'
    ret
qscan:
    mov bh, 'q'
    ret
rscan:
    mov bh, 'r'
    ret
sscan:
    mov bh, 's'
    ret
tscan:
    mov bh, 't'
    ret
uscan:
    mov bh, 'u'
    ret
vscan:
    mov bh, 'v'
    ret
wscan:
    mov bh, 'w'
    ret
xscan:
    mov bh, 'x'
    ret
yscan:
    mov bh, 'y'
    ret
zscan:
    mov bh, 'z'
    ret
