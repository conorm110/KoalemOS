; pixel draw
draw_black_pixel:
    mov cx,320
    mul cx; multiply AX by 320 (cx value)
    add ax,bx ; and add X
    mov di,ax
    mov dl,8
    mov [es:di],dl
    ret
draw_blue_pixel:
    mov cx,320
    mul cx; multiply AX by 320 (cx value)
    add ax,bx ; and add X
    mov di,ax
    mov dl,9
    mov [es:di],dl
    ret
draw_green_pixel:
    mov cx,320
    mul cx; multiply AX by 320 (cx value)
    add ax,bx ; and add X
    mov di,ax
    mov dl,10
    mov [es:di],dl
    ret
draw_cyan_pixel:
    mov cx,320
    mul cx; multiply AX by 320 (cx value)
    add ax,bx ; and add X
    mov di,ax
    mov dl,11
    mov [es:di],dl
    ret
draw_red_pixel:
    mov cx,320
    mul cx; multiply AX by 320 (cx value)
    add ax,bx ; and add X
    mov di,ax
    mov dl,12
    mov [es:di],dl
    ret
draw_magenta_pixel:
    mov cx,320
    mul cx; multiply AX by 320 (cx value)
    add ax,bx ; and add X
    mov di,ax
    mov dl,13
    mov [es:di],dl
    ret
draw_brown_pixel:
    mov cx,320
    mul cx; multiply AX by 320 (cx value)
    add ax,bx ; and add X
    mov di,ax
    mov dl,14
    mov [es:di],dl
    ret
draw_lightgray_pixel:
    mov cx,320
    mul cx; multiply AX by 320 (cx value)
    add ax,bx ; and add X
    mov di,ax
    mov dl,15
    mov [es:di],dl
    ret