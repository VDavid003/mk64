glabel func_80052F20
/* 053B20 80052F20 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 053B24 80052F24 00047880 */  sll   $t7, $a0, 2
/* 053B28 80052F28 01E47823 */  subu  $t7, $t7, $a0
/* 053B2C 80052F2C 3C18800E */  lui   $t8, %hi(camera1) # $t8, 0x800e
/* 053B30 80052F30 8F18DB40 */  lw    $t8, %lo(camera1)($t8)
/* 053B34 80052F34 000F78C0 */  sll   $t7, $t7, 3
/* 053B38 80052F38 01E47823 */  subu  $t7, $t7, $a0
/* 053B3C 80052F3C AFA40050 */  sw    $a0, 0x50($sp)
/* 053B40 80052F40 000F78C0 */  sll   $t7, $t7, 3
/* 053B44 80052F44 AFBF003C */  sw    $ra, 0x3c($sp)
/* 053B48 80052F48 3C040600 */  lui   $a0, %hi(D_06006D20) # $a0, 0x600
/* 053B4C 80052F4C 3C050600 */  lui   $a1, %hi(D_06006F20) # $a1, 0x600
/* 053B50 80052F50 01F8C821 */  addu  $t9, $t7, $t8
/* 053B54 80052F54 AFBE0038 */  sw    $fp, 0x38($sp)
/* 053B58 80052F58 AFB70034 */  sw    $s7, 0x34($sp)
/* 053B5C 80052F5C AFB60030 */  sw    $s6, 0x30($sp)
/* 053B60 80052F60 AFB5002C */  sw    $s5, 0x2c($sp)
/* 053B64 80052F64 AFB40028 */  sw    $s4, 0x28($sp)
/* 053B68 80052F68 AFB30024 */  sw    $s3, 0x24($sp)
/* 053B6C 80052F6C AFB20020 */  sw    $s2, 0x20($sp)
/* 053B70 80052F70 AFB1001C */  sw    $s1, 0x1c($sp)
/* 053B74 80052F74 AFB00018 */  sw    $s0, 0x18($sp)
/* 053B78 80052F78 AFB90044 */  sw    $t9, 0x44($sp)
/* 053B7C 80052F7C 24A56F20 */  addiu $a1, %lo(D_06006F20) # addiu $a1, $a1, 0x6f20
/* 053B80 80052F80 24846D20 */  addiu $a0, %lo(D_06006D20) # addiu $a0, $a0, 0x6d20
/* 053B84 80052F84 24060020 */  li    $a2, 32
/* 053B88 80052F88 0C011B98 */  jal   func_80046E60
/* 053B8C 80052F8C 24070020 */   li    $a3, 32
/* 053B90 80052F90 3C128019 */  lui   $s2, %hi(D_8018C3F0) # $s2, 0x8019
/* 053B94 80052F94 3C168016 */  lui   $s6, %hi(D_80165C18) # $s6, 0x8016
/* 053B98 80052F98 3C148015 */  lui   $s4, %hi(gDisplayListHead) # $s4, 0x8015
/* 053B9C 80052F9C 26940298 */  addiu $s4, %lo(gDisplayListHead) # addiu $s4, $s4, 0x298
/* 053BA0 80052FA0 26D65C18 */  addiu $s6, %lo(D_80165C18) # addiu $s6, $s6, 0x5c18
/* 053BA4 80052FA4 2652C3F0 */  addiu $s2, %lo(D_8018C3F0) # addiu $s2, $s2, -0x3c10
/* 053BA8 80052FA8 3C1E0004 */  lui   $fp, 4
/* 053BAC 80052FAC 241700E0 */  li    $s7, 224
/* 053BB0 80052FB0 2415FFFF */  li    $s5, -1
/* 053BB4 80052FB4 8E500000 */  lw    $s0, ($s2)
.L80052FB8:
/* 053BB8 80052FB8 1215001F */  beq   $s0, $s5, .L80053038
/* 053BBC 80052FBC 00000000 */   nop   
/* 053BC0 80052FC0 02170019 */  multu $s0, $s7
/* 053BC4 80052FC4 02002025 */  move  $a0, $s0
/* 053BC8 80052FC8 8FA50050 */  lw    $a1, 0x50($sp)
/* 053BCC 80052FCC 24062AAB */  li    $a2, 10923
/* 053BD0 80052FD0 00004012 */  mflo  $t0
/* 053BD4 80052FD4 02C88821 */  addu  $s1, $s6, $t0
/* 053BD8 80052FD8 862900A6 */  lh    $t1, 0xa6($s1)
/* 053BDC 80052FDC 19200016 */  blez  $t1, .L80053038
/* 053BE0 80052FE0 00000000 */   nop   
/* 053BE4 80052FE4 0C0228D9 */  jal   func_8008A364
/* 053BE8 80052FE8 240701F4 */   li    $a3, 500
/* 053BEC 80052FEC 02002025 */  move  $a0, $s0
/* 053BF0 80052FF0 0C01C88F */  jal   func_8007223C
/* 053BF4 80052FF4 03C02825 */   move  $a1, $fp
/* 053BF8 80052FF8 1040000F */  beqz  $v0, .L80053038
/* 053BFC 80052FFC 8FA60044 */   lw    $a2, 0x44($sp)
/* 053C00 80053000 3C130D00 */  lui   $s3, %hi(D_0D0069E0) # $s3, 0xd00
/* 053C04 80053004 267369E0 */  addiu $s3, %lo(D_0D0069E0) # addiu $s3, $s3, 0x69e0
/* 053C08 80053008 C62C0004 */  lwc1  $f12, 4($s1)
/* 053C0C 8005300C 0C01062B */  jal   func_800418AC
/* 053C10 80053010 C62E000C */   lwc1  $f14, 0xc($s1)
/* 053C14 80053014 A62200B4 */  sh    $v0, 0xb4($s1)
/* 053C18 80053018 0C010C41 */  jal   func_80043104
/* 053C1C 8005301C 02002025 */   move  $a0, $s0
/* 053C20 80053020 8E830000 */  lw    $v1, ($s4)
/* 053C24 80053024 3C0B0600 */  lui   $t3, 0x600
/* 053C28 80053028 246A0008 */  addiu $t2, $v1, 8
/* 053C2C 8005302C AE8A0000 */  sw    $t2, ($s4)
/* 053C30 80053030 AC730004 */  sw    $s3, 4($v1)
/* 053C34 80053034 AC6B0000 */  sw    $t3, ($v1)
.L80053038:
/* 053C38 80053038 3C0C8019 */  lui   $t4, %hi(D_8018C5F0) # $t4, 0x8019
/* 053C3C 8005303C 258CC5F0 */  addiu $t4, %lo(D_8018C5F0) # addiu $t4, $t4, -0x3a10
/* 053C40 80053040 26520004 */  addiu $s2, $s2, 4
/* 053C44 80053044 564CFFDC */  bnel  $s2, $t4, .L80052FB8
/* 053C48 80053048 8E500000 */   lw    $s0, ($s2)
/* 053C4C 8005304C 8E830000 */  lw    $v1, ($s4)
/* 053C50 80053050 3C0F0001 */  lui   $t7, (0x00010001 >> 16) # lui $t7, 1
/* 053C54 80053054 35EF0001 */  ori   $t7, (0x00010001 & 0xFFFF) # ori $t7, $t7, 1
/* 053C58 80053058 246D0008 */  addiu $t5, $v1, 8
/* 053C5C 8005305C AE8D0000 */  sw    $t5, ($s4)
/* 053C60 80053060 3C0EBB00 */  lui   $t6, 0xbb00
/* 053C64 80053064 AC6E0000 */  sw    $t6, ($v1)
/* 053C68 80053068 AC6F0004 */  sw    $t7, 4($v1)
/* 053C6C 8005306C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 053C70 80053070 8FBE0038 */  lw    $fp, 0x38($sp)
/* 053C74 80053074 8FB70034 */  lw    $s7, 0x34($sp)
/* 053C78 80053078 8FB60030 */  lw    $s6, 0x30($sp)
/* 053C7C 8005307C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 053C80 80053080 8FB40028 */  lw    $s4, 0x28($sp)
/* 053C84 80053084 8FB30024 */  lw    $s3, 0x24($sp)
/* 053C88 80053088 8FB20020 */  lw    $s2, 0x20($sp)
/* 053C8C 8005308C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 053C90 80053090 8FB00018 */  lw    $s0, 0x18($sp)
/* 053C94 80053094 03E00008 */  jr    $ra
/* 053C98 80053098 27BD0050 */   addiu $sp, $sp, 0x50
