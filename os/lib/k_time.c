/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "k_time.h"
#include "ports.h"
#include "k_stdio.h"
/**
 * delay() - delays execution
 * 
 * Super shitty delay, temporary DO 
 * NOT USE. NOP for n cycles then 
 * return
 */
void delay(int n) {
    for (int i = 0; i < n; i++)
        delay_cycle();
    return;
}
