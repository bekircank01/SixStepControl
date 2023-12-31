/*
 * Copyright 2014-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __FSL_DEVICE_REGISTERS_H__
#define __FSL_DEVICE_REGISTERS_H__

/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */
#if (defined(CPU_MKV42F128VLF16) || defined(CPU_MKV42F128VLH16) || defined(CPU_MKV42F128VLL16) || \
    defined(CPU_MKV42F256VLH16) || defined(CPU_MKV42F256VLL16) || defined(CPU_MKV42F64VLF16) || \
    defined(CPU_MKV42F64VLH16))

#define KV42F16_SERIES

/* CMSIS-style register definitions */
#include "MKV42F16.h"
/* CPU specific feature definitions */
#include "MKV42F16_features.h"

#else
    #error "No valid CPU defined!"
#endif

#endif /* __FSL_DEVICE_REGISTERS_H__ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
