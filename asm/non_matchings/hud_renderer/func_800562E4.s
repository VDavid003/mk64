glabel func_800562E4
/* 056EE4 800562E4 00047880 */  sll   $t7, $a0, 2
/* 056EE8 800562E8 01E47823 */  subu  $t7, $t7, $a0
/* 056EEC 800562EC 3C18800E */  lui   $t8, %hi(D_800E46F8) # $t8, 0x800e
/* 056EF0 800562F0 271846F8 */  addiu $t8, %lo(D_800E46F8) # addiu $t8, $t8, 0x46f8
/* 056EF4 800562F4 000F7880 */  sll   $t7, $t7, 2
/* 056EF8 800562F8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 056EFC 800562FC 01F81021 */  addu  $v0, $t7, $t8
/* 056F00 80056300 AFA40018 */  sw    $a0, 0x18($sp)
/* 056F04 80056304 AFA5001C */  sw    $a1, 0x1c($sp)
/* 056F08 80056308 00C03825 */  move  $a3, $a2
/* 056F0C 8005630C 8C440000 */  lw    $a0, ($v0)
/* 056F10 80056310 8C450004 */  lw    $a1, 4($v0)
/* 056F14 80056314 8C460008 */  lw    $a2, 8($v0)
/* 056F18 80056318 3C038016 */  lui   $v1, %hi(D_80165860) # $v1, 0x8016
/* 056F1C 8005631C 3C088016 */  lui   $t0, %hi(D_8016586C) # $t0, 0x8016
/* 056F20 80056320 3C098016 */  lui   $t1, %hi(D_80165878) # $t1, 0x8016
/* 056F24 80056324 25295878 */  addiu $t1, %lo(D_80165878) # addiu $t1, $t1, 0x5878
/* 056F28 80056328 2508586C */  addiu $t0, %lo(D_8016586C) # addiu $t0, $t0, 0x586c
/* 056F2C 8005632C 24635860 */  addiu $v1, %lo(D_80165860) # addiu $v1, $v1, 0x5860
/* 056F30 80056330 AFBF0014 */  sw    $ra, 0x14($sp)
/* 056F34 80056334 AC640000 */  sw    $a0, ($v1)
/* 056F38 80056338 AD050000 */  sw    $a1, ($t0)
/* 056F3C 8005633C 0C012C4E */  jal   func_8004B138
/* 056F40 80056340 AD260000 */   sw    $a2, ($t1)
/* 056F44 80056344 3C048018 */  lui   $a0, %hi(D_80183E40) # $a0, 0x8018
/* 056F48 80056348 3C058018 */  lui   $a1, %hi(D_80183E80) # $a1, 0x8018
/* 056F4C 8005634C 3C063E4C */  lui   $a2, (0x3E4CCCCD >> 16) # lui $a2, 0x3e4c
/* 056F50 80056350 34C6CCCD */  ori   $a2, (0x3E4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
/* 056F54 80056354 24A53E80 */  addiu $a1, %lo(D_80183E80) # addiu $a1, $a1, 0x3e80
/* 056F58 80056358 0C010B80 */  jal   rsp_set_matrix_transformation
/* 056F5C 8005635C 24843E40 */   addiu $a0, %lo(D_80183E40) # addiu $a0, $a0, 0x3e40
/* 056F60 80056360 8FAC001C */  lw    $t4, 0x1c($sp)
/* 056F64 80056364 3C0E0D03 */  lui   $t6, %hi(D_0D02AC58) # $t6, 0xd03
/* 056F68 80056368 25CEAC58 */  addiu $t6, %lo(D_0D02AC58) # addiu $t6, $t6, -0x53a8
/* 056F6C 8005636C 000C6A80 */  sll   $t5, $t4, 0xa
/* 056F70 80056370 01AE2021 */  addu  $a0, $t5, $t6
/* 056F74 80056374 24050020 */  li    $a1, 32
/* 056F78 80056378 0C0112FE */  jal   func_80044BF8
/* 056F7C 8005637C 24060020 */   li    $a2, 32
/* 056F80 80056380 3C058015 */  lui   $a1, %hi(gDisplayListHead) # $a1, 0x8015
/* 056F84 80056384 24A50298 */  addiu $a1, %lo(gDisplayListHead) # addiu $a1, $a1, 0x298
/* 056F88 80056388 8CA20000 */  lw    $v0, ($a1)
/* 056F8C 8005638C 3C180400 */  lui   $t8, (0x0400103F >> 16) # lui $t8, 0x400
/* 056F90 80056390 3C190D00 */  lui   $t9, %hi(D_0D005AE0) # $t9, 0xd00
/* 056F94 80056394 244F0008 */  addiu $t7, $v0, 8
/* 056F98 80056398 ACAF0000 */  sw    $t7, ($a1)
/* 056F9C 8005639C 27395AE0 */  addiu $t9, %lo(D_0D005AE0) # addiu $t9, $t9, 0x5ae0
/* 056FA0 800563A0 3718103F */  ori   $t8, (0x0400103F & 0xFFFF) # ori $t8, $t8, 0x103f
/* 056FA4 800563A4 AC580000 */  sw    $t8, ($v0)
/* 056FA8 800563A8 AC590004 */  sw    $t9, 4($v0)
/* 056FAC 800563AC 8CA20000 */  lw    $v0, ($a1)
/* 056FB0 800563B0 3C0C0D00 */  lui   $t4, %hi(common_rectangle_display) # $t4, 0xd00
/* 056FB4 800563B4 258C6940 */  addiu $t4, %lo(common_rectangle_display) # addiu $t4, $t4, 0x6940
/* 056FB8 800563B8 244A0008 */  addiu $t2, $v0, 8
/* 056FBC 800563BC ACAA0000 */  sw    $t2, ($a1)
/* 056FC0 800563C0 3C0B0600 */  lui   $t3, 0x600
/* 056FC4 800563C4 AC4B0000 */  sw    $t3, ($v0)
/* 056FC8 800563C8 AC4C0004 */  sw    $t4, 4($v0)
/* 056FCC 800563CC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 056FD0 800563D0 27BD0018 */  addiu $sp, $sp, 0x18
/* 056FD4 800563D4 03E00008 */  jr    $ra
/* 056FD8 800563D8 00000000 */   nop   
