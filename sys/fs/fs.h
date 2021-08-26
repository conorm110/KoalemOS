/**
 * Copyright (c) 2021, Conor Mika
 * All rights reserved.
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. 
 */

#include "ahci.h"
#include "flp.h"

FIS_REG_H2D fs_init();
void debug_fis(FIS_REG_H2D fis);