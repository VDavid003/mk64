glabel func_80099EC4
/* 09AAC4 80099EC4 27BDFF70 */  addiu $sp, $sp, -0x90
/* 09AAC8 80099EC8 AFB1002C */  sw    $s1, 0x2c($sp)
/* 09AACC 80099ECC 3C028019 */  lui   $v0, %hi(D_8018E0E8) # 0x8019
/* 09AAD0 80099ED0 2451E0E8 */  addiu $s1, $v0, %lo(D_8018E0E8) # -0x1f18
/* 09AAD4 80099ED4 AFBF004C */  sw    $ra, 0x4c($sp)
/* 09AAD8 80099ED8 AFBE0048 */  sw    $fp, 0x48($sp)
/* 09AADC 80099EDC AFB70044 */  sw    $s7, 0x44($sp)
/* 09AAE0 80099EE0 AFB60040 */  sw    $s6, 0x40($sp)
/* 09AAE4 80099EE4 AFB5003C */  sw    $s5, 0x3c($sp)
/* 09AAE8 80099EE8 AFB40038 */  sw    $s4, 0x38($sp)
/* 09AAEC 80099EEC AFB30034 */  sw    $s3, 0x34($sp)
/* 09AAF0 80099EF0 AFB20030 */  sw    $s2, 0x30($sp)
/* 09AAF4 80099EF4 AFB00028 */  sw    $s0, 0x28($sp)
/* 09AAF8 80099EF8 8E320000 */  lw    $s2, ($s1)
/* 09AAFC 80099EFC 3C138019 */  lui   $s3, %hi(D_8018D9B4) # $s3, 0x8019
/* 09AB00 80099F00 0000A025 */  move  $s4, $zero
/* 09AB04 80099F04 124000C0 */  beqz  $s2, .L8009A208
/* 09AB08 80099F08 2673D9B4 */   addiu $s3, %lo(D_8018D9B4) # addiu $s3, $s3, -0x264c
/* 09AB0C 80099F0C 96430010 */  lhu   $v1, 0x10($s2)
/* 09AB10 80099F10 24101400 */  li    $s0, 5120
/* 09AB14 80099F14 10600003 */  beqz  $v1, .L80099F24
/* 09AB18 80099F18 00000000 */   nop   
/* 09AB1C 80099F1C 10000001 */  b     .L80099F24
/* 09AB20 80099F20 00608025 */   move  $s0, $v1
.L80099F24:
/* 09AB24 80099F24 06010004 */  bgez  $s0, .L80099F38
/* 09AB28 80099F28 320E0007 */   andi  $t6, $s0, 7
/* 09AB2C 80099F2C 11C00002 */  beqz  $t6, .L80099F38
/* 09AB30 80099F30 00000000 */   nop   
/* 09AB34 80099F34 25CEFFF8 */  addiu $t6, $t6, -8
.L80099F38:
/* 09AB38 80099F38 51C00008 */  beql  $t6, $zero, .L80099F5C
/* 09AB3C 80099F3C 8E640000 */   lw    $a0, ($s3)
/* 09AB40 80099F40 06010003 */  bgez  $s0, .L80099F50
/* 09AB44 80099F44 001078C3 */   sra   $t7, $s0, 3
/* 09AB48 80099F48 26010007 */  addiu $at, $s0, 7
/* 09AB4C 80099F4C 000178C3 */  sra   $t7, $at, 3
.L80099F50:
/* 09AB50 80099F50 000FC0C0 */  sll   $t8, $t7, 3
/* 09AB54 80099F54 27100008 */  addiu $s0, $t8, 8
/* 09AB58 80099F58 8E640000 */  lw    $a0, ($s3)
.L80099F5C:
/* 09AB5C 80099F5C 0C0336E0 */  jal   osInvalDCache
/* 09AB60 80099F60 02002825 */   move  $a1, $s0
/* 09AB64 80099F64 8E590004 */  lw    $t9, 4($s2)
/* 09AB68 80099F68 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 09AB6C 80099F6C 8E690000 */  lw    $t1, ($s3)
/* 09AB70 80099F70 3C158015 */  lui   $s5, %hi(gDmaMesgQueue) # $s5, 0x8015
/* 09AB74 80099F74 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 09AB78 80099F78 3C1E0073 */  lui   $fp, %hi(_textures_0aSegmentRomStart) # $fp, 0x73
/* 09AB7C 80099F7C 26B5EF58 */  addiu $s5, %lo(gDmaMesgQueue) # addiu $s5, $s5, -0x10a8
/* 09AB80 80099F80 27DE9A30 */  addiu $fp, %lo(_textures_0aSegmentRomStart) # addiu $fp, $fp, -0x65d0
/* 09AB84 80099F84 03214024 */  and   $t0, $t9, $at
/* 09AB88 80099F88 03C83821 */  addu  $a3, $fp, $t0
/* 09AB8C 80099F8C AFB50018 */  sw    $s5, 0x18($sp)
/* 09AB90 80099F90 AFB00014 */  sw    $s0, 0x14($sp)
/* 09AB94 80099F94 27A40068 */  addiu $a0, $sp, 0x68
/* 09AB98 80099F98 00002825 */  move  $a1, $zero
/* 09AB9C 80099F9C 00003025 */  move  $a2, $zero
/* 09ABA0 80099FA0 0C03370C */  jal   osPiStartDma
/* 09ABA4 80099FA4 AFA90010 */   sw    $t1, 0x10($sp)
/* 09ABA8 80099FA8 27B60064 */  addiu $s6, $sp, 0x64
/* 09ABAC 80099FAC 02C02825 */  move  $a1, $s6
/* 09ABB0 80099FB0 02A02025 */  move  $a0, $s5
/* 09ABB4 80099FB4 0C0335D4 */  jal   osRecvMesg
/* 09ABB8 80099FB8 24060001 */   li    $a2, 1
/* 09ABBC 80099FBC 3C17802C */  lui   $s7, %hi(D_802BFB80) # $s7, 0x802c
/* 09ABC0 80099FC0 26F7FB80 */  addiu $s7, %lo(D_802BFB80) # addiu $s7, $s7, -0x480
/* 09ABC4 80099FC4 8E220008 */  lw    $v0, 8($s1)
.L80099FC8:
/* 09ABC8 80099FC8 54400006 */  bnel  $v0, $zero, .L80099FE4
/* 09ABCC 80099FCC 94430010 */   lhu   $v1, 0x10($v0)
/* 09ABD0 80099FD0 26940001 */  addiu $s4, $s4, 1
/* 09ABD4 80099FD4 00145600 */  sll   $t2, $s4, 0x18
/* 09ABD8 80099FD8 10000027 */  b     .L8009A078
/* 09ABDC 80099FDC 000AA603 */   sra   $s4, $t2, 0x18
/* 09ABE0 80099FE0 94430010 */  lhu   $v1, 0x10($v0)
.L80099FE4:
/* 09ABE4 80099FE4 00409025 */  move  $s2, $v0
/* 09ABE8 80099FE8 24101400 */  li    $s0, 5120
/* 09ABEC 80099FEC 10600003 */  beqz  $v1, .L80099FFC
/* 09ABF0 80099FF0 00000000 */   nop   
/* 09ABF4 80099FF4 10000001 */  b     .L80099FFC
/* 09ABF8 80099FF8 00608025 */   move  $s0, $v1
.L80099FFC:
/* 09ABFC 80099FFC 06010004 */  bgez  $s0, .L8009A010
/* 09AC00 8009A000 320C0007 */   andi  $t4, $s0, 7
/* 09AC04 8009A004 11800002 */  beqz  $t4, .L8009A010
/* 09AC08 8009A008 00000000 */   nop   
/* 09AC0C 8009A00C 258CFFF8 */  addiu $t4, $t4, -8
.L8009A010:
/* 09AC10 8009A010 51800008 */  beql  $t4, $zero, .L8009A034
/* 09AC14 8009A014 8E640000 */   lw    $a0, ($s3)
/* 09AC18 8009A018 06010003 */  bgez  $s0, .L8009A028
/* 09AC1C 8009A01C 001068C3 */   sra   $t5, $s0, 3
/* 09AC20 8009A020 26010007 */  addiu $at, $s0, 7
/* 09AC24 8009A024 000168C3 */  sra   $t5, $at, 3
.L8009A028:
/* 09AC28 8009A028 000D70C0 */  sll   $t6, $t5, 3
/* 09AC2C 8009A02C 25D00008 */  addiu $s0, $t6, 8
/* 09AC30 8009A030 8E640000 */  lw    $a0, ($s3)
.L8009A034:
/* 09AC34 8009A034 02002825 */  move  $a1, $s0
/* 09AC38 8009A038 0C0336E0 */  jal   osInvalDCache
/* 09AC3C 8009A03C 24841400 */   addiu $a0, $a0, 0x1400
/* 09AC40 8009A040 8E4F0004 */  lw    $t7, 4($s2)
/* 09AC44 8009A044 8E790000 */  lw    $t9, ($s3)
/* 09AC48 8009A048 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 09AC4C 8009A04C 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 09AC50 8009A050 01E1C024 */  and   $t8, $t7, $at
/* 09AC54 8009A054 27281400 */  addiu $t0, $t9, 0x1400
/* 09AC58 8009A058 AFA80010 */  sw    $t0, 0x10($sp)
/* 09AC5C 8009A05C 03D83821 */  addu  $a3, $fp, $t8
/* 09AC60 8009A060 AFB50018 */  sw    $s5, 0x18($sp)
/* 09AC64 8009A064 AFB00014 */  sw    $s0, 0x14($sp)
/* 09AC68 8009A068 27A40068 */  addiu $a0, $sp, 0x68
/* 09AC6C 8009A06C 00002825 */  move  $a1, $zero
/* 09AC70 8009A070 0C03370C */  jal   osPiStartDma
/* 09AC74 8009A074 00003025 */   move  $a2, $zero
.L8009A078:
/* 09AC78 8009A078 86220004 */  lh    $v0, 4($s1)
/* 09AC7C 8009A07C 86290006 */  lh    $t1, 6($s1)
/* 09AC80 8009A080 8E640000 */  lw    $a0, ($s3)
/* 09AC84 8009A084 00095400 */  sll   $t2, $t1, 0x10
/* 09AC88 8009A088 02EA5821 */  addu  $t3, $s7, $t2
/* 09AC8C 8009A08C 04410003 */  bgez  $v0, .L8009A09C
/* 09AC90 8009A090 00026043 */   sra   $t4, $v0, 1
/* 09AC94 8009A094 24410001 */  addiu $at, $v0, 1
/* 09AC98 8009A098 00016043 */  sra   $t4, $at, 1
.L8009A09C:
/* 09AC9C 8009A09C 000C6BC0 */  sll   $t5, $t4, 0xf
/* 09ACA0 8009A0A0 016D7021 */  addu  $t6, $t3, $t5
/* 09ACA4 8009A0A4 04410004 */  bgez  $v0, .L8009A0B8
/* 09ACA8 8009A0A8 304F0001 */   andi  $t7, $v0, 1
/* 09ACAC 8009A0AC 11E00002 */  beqz  $t7, .L8009A0B8
/* 09ACB0 8009A0B0 00000000 */   nop   
/* 09ACB4 8009A0B4 25EFFFFE */  addiu $t7, $t7, -2
.L8009A0B8:
/* 09ACB8 8009A0B8 000FC340 */  sll   $t8, $t7, 0xd
/* 09ACBC 8009A0BC 01D82821 */  addu  $a1, $t6, $t8
/* 09ACC0 8009A0C0 0C010034 */  jal   mio0decode
/* 09ACC4 8009A0C4 24A54000 */   addiu $a1, $a1, 0x4000
/* 09ACC8 8009A0C8 AE200000 */  sw    $zero, ($s1)
/* 09ACCC 8009A0CC 1680004E */  bnez  $s4, .L8009A208
/* 09ACD0 8009A0D0 26310008 */   addiu $s1, $s1, 8
/* 09ACD4 8009A0D4 02A02025 */  move  $a0, $s5
/* 09ACD8 8009A0D8 02C02825 */  move  $a1, $s6
/* 09ACDC 8009A0DC 0C0335D4 */  jal   osRecvMesg
/* 09ACE0 8009A0E0 24060001 */   li    $a2, 1
/* 09ACE4 8009A0E4 8E220008 */  lw    $v0, 8($s1)
/* 09ACE8 8009A0E8 54400006 */  bnel  $v0, $zero, .L8009A104
/* 09ACEC 8009A0EC 94430010 */   lhu   $v1, 0x10($v0)
/* 09ACF0 8009A0F0 26940001 */  addiu $s4, $s4, 1
/* 09ACF4 8009A0F4 0014CE00 */  sll   $t9, $s4, 0x18
/* 09ACF8 8009A0F8 10000025 */  b     .L8009A190
/* 09ACFC 8009A0FC 0019A603 */   sra   $s4, $t9, 0x18
/* 09AD00 8009A100 94430010 */  lhu   $v1, 0x10($v0)
.L8009A104:
/* 09AD04 8009A104 00409025 */  move  $s2, $v0
/* 09AD08 8009A108 24101400 */  li    $s0, 5120
/* 09AD0C 8009A10C 10600003 */  beqz  $v1, .L8009A11C
/* 09AD10 8009A110 00000000 */   nop   
/* 09AD14 8009A114 10000001 */  b     .L8009A11C
/* 09AD18 8009A118 00608025 */   move  $s0, $v1
.L8009A11C:
/* 09AD1C 8009A11C 06010004 */  bgez  $s0, .L8009A130
/* 09AD20 8009A120 32090007 */   andi  $t1, $s0, 7
/* 09AD24 8009A124 11200002 */  beqz  $t1, .L8009A130
/* 09AD28 8009A128 00000000 */   nop   
/* 09AD2C 8009A12C 2529FFF8 */  addiu $t1, $t1, -8
.L8009A130:
/* 09AD30 8009A130 51200008 */  beql  $t1, $zero, .L8009A154
/* 09AD34 8009A134 8E640000 */   lw    $a0, ($s3)
/* 09AD38 8009A138 06010003 */  bgez  $s0, .L8009A148
/* 09AD3C 8009A13C 001050C3 */   sra   $t2, $s0, 3
/* 09AD40 8009A140 26010007 */  addiu $at, $s0, 7
/* 09AD44 8009A144 000150C3 */  sra   $t2, $at, 3
.L8009A148:
/* 09AD48 8009A148 000A60C0 */  sll   $t4, $t2, 3
/* 09AD4C 8009A14C 25900008 */  addiu $s0, $t4, 8
/* 09AD50 8009A150 8E640000 */  lw    $a0, ($s3)
.L8009A154:
/* 09AD54 8009A154 0C0336E0 */  jal   osInvalDCache
/* 09AD58 8009A158 02002825 */   move  $a1, $s0
/* 09AD5C 8009A15C 8E4B0004 */  lw    $t3, 4($s2)
/* 09AD60 8009A160 3C0100FF */  lui   $at, (0x00FFFFFF >> 16) # lui $at, 0xff
/* 09AD64 8009A164 8E6F0000 */  lw    $t7, ($s3)
/* 09AD68 8009A168 3421FFFF */  ori   $at, (0x00FFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 09AD6C 8009A16C 01616824 */  and   $t5, $t3, $at
/* 09AD70 8009A170 03CD3821 */  addu  $a3, $fp, $t5
/* 09AD74 8009A174 AFB50018 */  sw    $s5, 0x18($sp)
/* 09AD78 8009A178 AFB00014 */  sw    $s0, 0x14($sp)
/* 09AD7C 8009A17C 27A40068 */  addiu $a0, $sp, 0x68
/* 09AD80 8009A180 00002825 */  move  $a1, $zero
/* 09AD84 8009A184 00003025 */  move  $a2, $zero
/* 09AD88 8009A188 0C03370C */  jal   osPiStartDma
/* 09AD8C 8009A18C AFAF0010 */   sw    $t7, 0x10($sp)
.L8009A190:
/* 09AD90 8009A190 86220004 */  lh    $v0, 4($s1)
/* 09AD94 8009A194 862E0006 */  lh    $t6, 6($s1)
/* 09AD98 8009A198 8E640000 */  lw    $a0, ($s3)
/* 09AD9C 8009A19C 000EC400 */  sll   $t8, $t6, 0x10
/* 09ADA0 8009A1A0 02F8C821 */  addu  $t9, $s7, $t8
/* 09ADA4 8009A1A4 24841400 */  addiu $a0, $a0, 0x1400
/* 09ADA8 8009A1A8 04410003 */  bgez  $v0, .L8009A1B8
/* 09ADAC 8009A1AC 00024043 */   sra   $t0, $v0, 1
/* 09ADB0 8009A1B0 24410001 */  addiu $at, $v0, 1
/* 09ADB4 8009A1B4 00014043 */  sra   $t0, $at, 1
.L8009A1B8:
/* 09ADB8 8009A1B8 00084BC0 */  sll   $t1, $t0, 0xf
/* 09ADBC 8009A1BC 03295021 */  addu  $t2, $t9, $t1
/* 09ADC0 8009A1C0 04410004 */  bgez  $v0, .L8009A1D4
/* 09ADC4 8009A1C4 304C0001 */   andi  $t4, $v0, 1
/* 09ADC8 8009A1C8 11800002 */  beqz  $t4, .L8009A1D4
/* 09ADCC 8009A1CC 00000000 */   nop   
/* 09ADD0 8009A1D0 258CFFFE */  addiu $t4, $t4, -2
.L8009A1D4:
/* 09ADD4 8009A1D4 000C5B40 */  sll   $t3, $t4, 0xd
/* 09ADD8 8009A1D8 014B2821 */  addu  $a1, $t2, $t3
/* 09ADDC 8009A1DC 0C010034 */  jal   mio0decode
/* 09ADE0 8009A1E0 24A54000 */   addiu $a1, $a1, 0x4000
/* 09ADE4 8009A1E4 AE200000 */  sw    $zero, ($s1)
/* 09ADE8 8009A1E8 16800007 */  bnez  $s4, .L8009A208
/* 09ADEC 8009A1EC 26310008 */   addiu $s1, $s1, 8
/* 09ADF0 8009A1F0 02A02025 */  move  $a0, $s5
/* 09ADF4 8009A1F4 02C02825 */  move  $a1, $s6
/* 09ADF8 8009A1F8 0C0335D4 */  jal   osRecvMesg
/* 09ADFC 8009A1FC 24060001 */   li    $a2, 1
/* 09AE00 8009A200 1000FF71 */  b     .L80099FC8
/* 09AE04 8009A204 8E220008 */   lw    $v0, 8($s1)
.L8009A208:
/* 09AE08 8009A208 8FBF004C */  lw    $ra, 0x4c($sp)
/* 09AE0C 8009A20C 8FB00028 */  lw    $s0, 0x28($sp)
/* 09AE10 8009A210 8FB1002C */  lw    $s1, 0x2c($sp)
/* 09AE14 8009A214 8FB20030 */  lw    $s2, 0x30($sp)
/* 09AE18 8009A218 8FB30034 */  lw    $s3, 0x34($sp)
/* 09AE1C 8009A21C 8FB40038 */  lw    $s4, 0x38($sp)
/* 09AE20 8009A220 8FB5003C */  lw    $s5, 0x3c($sp)
/* 09AE24 8009A224 8FB60040 */  lw    $s6, 0x40($sp)
/* 09AE28 8009A228 8FB70044 */  lw    $s7, 0x44($sp)
/* 09AE2C 8009A22C 8FBE0048 */  lw    $fp, 0x48($sp)
/* 09AE30 8009A230 03E00008 */  jr    $ra
/* 09AE34 8009A234 27BD0090 */   addiu $sp, $sp, 0x90

/* 09AE38 8009A238 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 09AE3C 8009A23C AFBF0014 */  sw    $ra, 0x14($sp)
/* 09AE40 8009A240 8C980004 */  lw    $t8, 4($a0)
/* 09AE44 8009A244 3C0F8019 */  lui   $t7, %hi(D_8018E118) # $t7, 0x8019
/* 09AE48 8009A248 25EFE118 */  addiu $t7, %lo(D_8018E118) # addiu $t7, $t7, -0x1ee8
/* 09AE4C 8009A24C AFB80024 */  sw    $t8, 0x24($sp)
/* 09AE50 8009A250 94870010 */  lhu   $a3, 0x10($a0)
/* 09AE54 8009A254 000570C0 */  sll   $t6, $a1, 3
/* 09AE58 8009A258 01CF1021 */  addu  $v0, $t6, $t7
/* 09AE5C 8009A25C 8C430004 */  lw    $v1, 4($v0)
/* 09AE60 8009A260 04E10004 */  bgez  $a3, .L8009A274
/* 09AE64 8009A264 30F90007 */   andi  $t9, $a3, 7
/* 09AE68 8009A268 13200002 */  beqz  $t9, .L8009A274
/* 09AE6C 8009A26C 00000000 */   nop   
/* 09AE70 8009A270 2739FFF8 */  addiu $t9, $t9, -8
.L8009A274:
/* 09AE74 8009A274 13200007 */  beqz  $t9, .L8009A294
/* 09AE78 8009A278 8FA40024 */   lw    $a0, 0x24($sp)
/* 09AE7C 8009A27C 04E10003 */  bgez  $a3, .L8009A28C
/* 09AE80 8009A280 000740C3 */   sra   $t0, $a3, 3
/* 09AE84 8009A284 24E10007 */  addiu $at, $a3, 7
/* 09AE88 8009A288 000140C3 */  sra   $t0, $at, 3
.L8009A28C:
/* 09AE8C 8009A28C 000848C0 */  sll   $t1, $t0, 3
/* 09AE90 8009A290 25270008 */  addiu $a3, $t1, 8
.L8009A294:
/* 09AE94 8009A294 3C068019 */  lui   $a2, %hi(D_8018D9B4) # $a2, 0x8019
/* 09AE98 8009A298 8CC6D9B4 */  lw    $a2, %lo(D_8018D9B4)($a2)
/* 09AE9C 8009A29C 00E02825 */  move  $a1, $a3
/* 09AEA0 8009A2A0 AFA2001C */  sw    $v0, 0x1c($sp)
/* 09AEA4 8009A2A4 0C026422 */  jal   dma_copy_base_7fa3c0
/* 09AEA8 8009A2A8 AFA30028 */   sw    $v1, 0x28($sp)
/* 09AEAC 8009A2AC 8FA30028 */  lw    $v1, 0x28($sp)
/* 09AEB0 8009A2B0 3C0B8019 */  lui   $t3, %hi(D_8018D9B0) # $t3, 0x8019
/* 09AEB4 8009A2B4 8D6BD9B0 */  lw    $t3, %lo(D_8018D9B0)($t3)
/* 09AEB8 8009A2B8 3C048019 */  lui   $a0, %hi(D_8018D9B4) # $a0, 0x8019
/* 09AEBC 8009A2BC 3C058019 */  lui   $a1, %hi(D_8018D9B8) # $a1, 0x8019
/* 09AEC0 8009A2C0 00035040 */  sll   $t2, $v1, 1
/* 09AEC4 8009A2C4 8CA5D9B8 */  lw    $a1, %lo(D_8018D9B8)($a1)
/* 09AEC8 8009A2C8 8C84D9B4 */  lw    $a0, %lo(D_8018D9B4)($a0)
/* 09AECC 8009A2CC 24070001 */  li    $a3, 1
/* 09AED0 8009A2D0 0C010174 */  jal   tkmk00decode
/* 09AED4 8009A2D4 014B3021 */   addu  $a2, $t2, $t3
/* 09AED8 8009A2D8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 09AEDC 8009A2DC 8FA2001C */  lw    $v0, 0x1c($sp)
/* 09AEE0 8009A2E0 8FAC0024 */  lw    $t4, 0x24($sp)
/* 09AEE4 8009A2E4 27BD0030 */  addiu $sp, $sp, 0x30
/* 09AEE8 8009A2E8 03E00008 */  jr    $ra
/* 09AEEC 8009A2EC AC4C0000 */   sw    $t4, ($v0)

/* 09AEF0 8009A2F0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 09AEF4 8009A2F4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 09AEF8 8009A2F8 0C026455 */  jal   segmented_to_virtual_dupe
/* 09AEFC 8009A2FC AFB00018 */   sw    $s0, 0x18($sp)
/* 09AF00 8009A300 8C440000 */  lw    $a0, ($v0)
/* 09AF04 8009A304 00408025 */  move  $s0, $v0
/* 09AF08 8009A308 5080000A */  beql  $a0, $zero, .L8009A334
/* 09AF0C 8009A30C 8FBF001C */   lw    $ra, 0x1c($sp)
.L8009A310:
/* 09AF10 8009A310 50800008 */  beql  $a0, $zero, .L8009A334
/* 09AF14 8009A314 8FBF001C */   lw    $ra, 0x1c($sp)
/* 09AF18 8009A318 0C0265AF */  jal   func_800996BC
/* 09AF1C 8009A31C 00002825 */   move  $a1, $zero
/* 09AF20 8009A320 8E040008 */  lw    $a0, 8($s0)
/* 09AF24 8009A324 26100008 */  addiu $s0, $s0, 8
/* 09AF28 8009A328 1480FFF9 */  bnez  $a0, .L8009A310
/* 09AF2C 8009A32C 00000000 */   nop   
/* 09AF30 8009A330 8FBF001C */  lw    $ra, 0x1c($sp)
.L8009A334:
/* 09AF34 8009A334 8FB00018 */  lw    $s0, 0x18($sp)
/* 09AF38 8009A338 27BD0020 */  addiu $sp, $sp, 0x20
/* 09AF3C 8009A33C 03E00008 */  jr    $ra
/* 09AF40 8009A340 00000000 */   nop   
