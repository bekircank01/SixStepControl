/*
 * GENERATED FILE - DO NOT EDIT
 * Copyright (c) 2008-2013 Code Red Technologies Ltd,
 * Copyright 2015, 2018-2019 NXP
 * (c) NXP Semiconductors 2013-2023
 * Generated linker script file for MKV42F64xxx16
 * Created from memory.ldt by FMCreateLinkMemory
 * Using Freemarker v2.3.30
 * MCUXpresso IDE v11.6.0 [Build 8187] [2022-07-13] on 3 Ağu 2023 23:33:35
 */

MEMORY
{
  /* Define each memory region */
  PROGRAM_FLASH (rx) : ORIGIN = 0x0, LENGTH = 0x10000 /* 64K bytes (alias Flash) */  
  SRAM_UPPER (rwx) : ORIGIN = 0x20000000, LENGTH = 0x2000 /* 8K bytes (alias RAM) */  
  SRAM_LOWER (rwx) : ORIGIN = 0x1fffe000, LENGTH = 0x2000 /* 8K bytes (alias RAM2) */  
}

  /* Define a symbol for the top of each memory region */
  __base_PROGRAM_FLASH = 0x0  ; /* PROGRAM_FLASH */  
  __base_Flash = 0x0 ; /* Flash */  
  __top_PROGRAM_FLASH = 0x0 + 0x10000 ; /* 64K bytes */  
  __top_Flash = 0x0 + 0x10000 ; /* 64K bytes */  
  __base_SRAM_UPPER = 0x20000000  ; /* SRAM_UPPER */  
  __base_RAM = 0x20000000 ; /* RAM */  
  __top_SRAM_UPPER = 0x20000000 + 0x2000 ; /* 8K bytes */  
  __top_RAM = 0x20000000 + 0x2000 ; /* 8K bytes */  
  __base_SRAM_LOWER = 0x1fffe000  ; /* SRAM_LOWER */  
  __base_RAM2 = 0x1fffe000 ; /* RAM2 */  
  __top_SRAM_LOWER = 0x1fffe000 + 0x2000 ; /* 8K bytes */  
  __top_RAM2 = 0x1fffe000 + 0x2000 ; /* 8K bytes */  
