glabel func_80066BAC
/* 0677AC 80066BAC 27BDFF18 */  addiu $sp, $sp, -0xe8
/* 0677B0 80066BB0 00067400 */  sll   $t6, $a2, 0x10
/* 0677B4 80066BB4 000E7C03 */  sra   $t7, $t6, 0x10
/* 0677B8 80066BB8 000FC0C0 */  sll   $t8, $t7, 3
/* 0677BC 80066BBC 030FC021 */  addu  $t8, $t8, $t7
/* 0677C0 80066BC0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0677C4 80066BC4 0018C0C0 */  sll   $t8, $t8, 3
/* 0677C8 80066BC8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0677CC 80066BCC AFA500EC */  sw    $a1, 0xec($sp)
/* 0677D0 80066BD0 AFA600F0 */  sw    $a2, 0xf0($sp)
/* 0677D4 80066BD4 AFA700F4 */  sw    $a3, 0xf4($sp)
/* 0677D8 80066BD8 0098F821 */  addu  $ra, $a0, $t8
/* 0677DC 80066BDC 87F90274 */  lh    $t9, 0x274($ra)
/* 0677E0 80066BE0 24010001 */  li    $at, 1
/* 0677E4 80066BE4 00808025 */  move  $s0, $a0
/* 0677E8 80066BE8 572101A1 */  bnel  $t9, $at, .L80067270
/* 0677EC 80066BEC 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0677F0 80066BF0 87EE0290 */  lh    $t6, 0x290($ra)
/* 0677F4 80066BF4 240100FF */  li    $at, 255
/* 0677F8 80066BF8 11C1019C */  beq   $t6, $at, .L8006726C
/* 0677FC 80066BFC 3C014396 */   li    $at, 0x43960000 # 300.000000
/* 067800 80066C00 44813000 */  mtc1  $at, $f6
/* 067804 80066C04 C4840124 */  lwc1  $f4, 0x124($a0)
/* 067808 80066C08 3C014040 */  li    $at, 0x40400000 # 3.000000
/* 06780C 80066C0C 4604303E */  c.le.s $f6, $f4
/* 067810 80066C10 00000000 */  nop   
/* 067814 80066C14 45020008 */  bc1fl .L80066C38
/* 067818 80066C18 C6120018 */   lwc1  $f18, 0x18($s0)
/* 06781C 80066C1C 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 067820 80066C20 44815000 */  mtc1  $at, $f10
/* 067824 80066C24 C4880018 */  lwc1  $f8, 0x18($a0)
/* 067828 80066C28 460A4400 */  add.s $f16, $f8, $f10
/* 06782C 80066C2C 10000006 */  b     .L80066C48
/* 067830 80066C30 E7B000E0 */   swc1  $f16, 0xe0($sp)
/* 067834 80066C34 C6120018 */  lwc1  $f18, 0x18($s0)
.L80066C38:
/* 067838 80066C38 44812000 */  mtc1  $at, $f4
/* 06783C 80066C3C 00000000 */  nop   
/* 067840 80066C40 46049181 */  sub.s $f6, $f18, $f4
/* 067844 80066C44 E7A600E0 */  swc1  $f6, 0xe0($sp)
.L80066C48:
/* 067848 80066C48 83AF00F7 */  lb    $t7, 0xf7($sp)
/* 06784C 80066C4C 000FC040 */  sll   $t8, $t7, 1
/* 067850 80066C50 02181021 */  addu  $v0, $s0, $t8
/* 067854 80066C54 94440048 */  lhu   $a0, 0x48($v0)
/* 067858 80066C58 AFBF0024 */  sw    $ra, 0x24($sp)
/* 06785C 80066C5C 0C0AE00E */  jal   func_802B8038
/* 067860 80066C60 AFA20020 */   sw    $v0, 0x20($sp)
/* 067864 80066C64 3C01C120 */  li    $at, 0xC1200000 # -10.000000
/* 067868 80066C68 44814000 */  mtc1  $at, $f8
/* 06786C 80066C6C C610001C */  lwc1  $f16, 0x1c($s0)
/* 067870 80066C70 8FB90020 */  lw    $t9, 0x20($sp)
/* 067874 80066C74 46080282 */  mul.s $f10, $f0, $f8
/* 067878 80066C78 46105480 */  add.s $f18, $f10, $f16
/* 06787C 80066C7C E7B200E4 */  swc1  $f18, 0xe4($sp)
/* 067880 80066C80 0C0AE006 */  jal   func_802B8018
/* 067884 80066C84 97240048 */   lhu   $a0, 0x48($t9)
/* 067888 80066C88 3C01C120 */  li    $at, 0xC1200000 # -10.000000
/* 06788C 80066C8C 44812000 */  mtc1  $at, $f4
/* 067890 80066C90 C6080014 */  lwc1  $f8, 0x14($s0)
/* 067894 80066C94 83AE00F7 */  lb    $t6, 0xf7($sp)
/* 067898 80066C98 46040182 */  mul.s $f6, $f0, $f4
/* 06789C 80066C9C 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0678A0 80066CA0 44819000 */  mtc1  $at, $f18
/* 0678A4 80066CA4 000E7880 */  sll   $t7, $t6, 2
/* 0678A8 80066CA8 01EE7823 */  subu  $t7, $t7, $t6
/* 0678AC 80066CAC 000F78C0 */  sll   $t7, $t7, 3
/* 0678B0 80066CB0 01EE7823 */  subu  $t7, $t7, $t6
/* 0678B4 80066CB4 46083280 */  add.s $f10, $f6, $f8
/* 0678B8 80066CB8 000F78C0 */  sll   $t7, $t7, 3
/* 0678BC 80066CBC 3C188016 */  lui   $t8, %hi(cameras+0x24)
/* 0678C0 80066CC0 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0678C4 80066CC4 E7AA00DC */  swc1  $f10, 0xdc($sp)
/* 0678C8 80066CC8 C6100124 */  lwc1  $f16, 0x124($s0)
/* 0678CC 80066CCC 030FC021 */  addu  $t8, $t8, $t7
/* 0678D0 80066CD0 4610903E */  c.le.s $f18, $f16
/* 0678D4 80066CD4 00000000 */  nop   
/* 0678D8 80066CD8 45020006 */  bc1fl .L80066CF4
/* 0678DC 80066CDC A7A000D4 */   sh    $zero, 0xd4($sp)
/* 0678E0 80066CE0 87184714 */  lh    $t8, %lo(cameras+0x24)($t8)
/* 0678E4 80066CE4 2719C000 */  addiu $t9, $t8, -0x4000
/* 0678E8 80066CE8 10000002 */  b     .L80066CF4
/* 0678EC 80066CEC A7B900D4 */   sh    $t9, 0xd4($sp)
/* 0678F0 80066CF0 A7A000D4 */  sh    $zero, 0xd4($sp)
.L80066CF4:
/* 0678F4 80066CF4 8FAE0020 */  lw    $t6, 0x20($sp)
/* 0678F8 80066CF8 27A400DC */  addiu $a0, $sp, 0xdc
/* 0678FC 80066CFC 27A500D4 */  addiu $a1, $sp, 0xd4
/* 067900 80066D00 85CF0048 */  lh    $t7, 0x48($t6)
/* 067904 80066D04 A7A000D8 */  sh    $zero, 0xd8($sp)
/* 067908 80066D08 A7AF00D6 */  sh    $t7, 0xd6($sp)
/* 06790C 80066D0C C6060224 */  lwc1  $f6, 0x224($s0)
/* 067910 80066D10 C7E40264 */  lwc1  $f4, 0x264($ra)
/* 067914 80066D14 AFBF0024 */  sw    $ra, 0x24($sp)
/* 067918 80066D18 46062202 */  mul.s $f8, $f4, $f6
/* 06791C 80066D1C 44064000 */  mfc1  $a2, $f8
/* 067920 80066D20 0C0194B5 */  jal   func_800652D4
/* 067924 80066D24 00000000 */   nop   
/* 067928 80066D28 8FBF0024 */  lw    $ra, 0x24($sp)
/* 06792C 80066D2C 3C038015 */  lui   $v1, %hi(gDisplayListHead) # $v1, 0x8015
/* 067930 80066D30 3C0E0D01 */  lui   $t6, %hi(D_0D008DB8) # $t6, 0xd01
/* 067934 80066D34 87F80290 */  lh    $t8, 0x290($ra)
/* 067938 80066D38 24630298 */  addiu $v1, %lo(gDisplayListHead) # addiu $v1, $v1, 0x298
/* 06793C 80066D3C 3C100600 */  lui   $s0, 0x600
/* 067940 80066D40 170000A5 */  bnez  $t8, .L80066FD8
/* 067944 80066D44 3C190D01 */   lui   $t9, 0xd01
/* 067948 80066D48 3C038015 */  lui   $v1, %hi(gDisplayListHead) # $v1, 0x8015
/* 06794C 80066D4C 24630298 */  addiu $v1, %lo(gDisplayListHead) # addiu $v1, $v1, 0x298
/* 067950 80066D50 8C620000 */  lw    $v0, ($v1)
/* 067954 80066D54 3C100600 */  lui   $s0, 0x600
/* 067958 80066D58 25CE8DB8 */  addiu $t6, %lo(D_0D008DB8) # addiu $t6, $t6, -0x7248
/* 06795C 80066D5C 24590008 */  addiu $t9, $v0, 8
/* 067960 80066D60 AC790000 */  sw    $t9, ($v1)
/* 067964 80066D64 AC4E0004 */  sw    $t6, 4($v0)
/* 067968 80066D68 AC500000 */  sw    $s0, ($v0)
/* 06796C 80066D6C 8C620000 */  lw    $v0, ($v1)
/* 067970 80066D70 3C18FC12 */  lui   $t8, (0xFC127E24 >> 16) # lui $t8, 0xfc12
/* 067974 80066D74 37187E24 */  ori   $t8, (0xFC127E24 & 0xFFFF) # ori $t8, $t8, 0x7e24
/* 067978 80066D78 244F0008 */  addiu $t7, $v0, 8
/* 06797C 80066D7C AC6F0000 */  sw    $t7, ($v1)
/* 067980 80066D80 2419F3F9 */  li    $t9, -3079
/* 067984 80066D84 AC590004 */  sw    $t9, 4($v0)
/* 067988 80066D88 AC580000 */  sw    $t8, ($v0)
/* 06798C 80066D8C 8C620000 */  lw    $v0, ($v1)
/* 067990 80066D90 3C180050 */  lui   $t8, (0x00504B50 >> 16) # lui $t8, 0x50
/* 067994 80066D94 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 067998 80066D98 244E0008 */  addiu $t6, $v0, 8
/* 06799C 80066D9C AC6E0000 */  sw    $t6, ($v1)
/* 0679A0 80066DA0 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 0679A4 80066DA4 37184B50 */  ori   $t8, (0x00504B50 & 0xFFFF) # ori $t8, $t8, 0x4b50
/* 0679A8 80066DA8 AC580004 */  sw    $t8, 4($v0)
/* 0679AC 80066DAC AC4F0000 */  sw    $t7, ($v0)
/* 0679B0 80066DB0 8C620000 */  lw    $v0, ($v1)
/* 0679B4 80066DB4 3C0EFD70 */  lui   $t6, 0xfd70
/* 0679B8 80066DB8 3C0F8019 */  lui   $t7, %hi(D_8018D4C4) # $t7, 0x8019
/* 0679BC 80066DBC 24590008 */  addiu $t9, $v0, 8
/* 0679C0 80066DC0 AC790000 */  sw    $t9, ($v1)
/* 0679C4 80066DC4 AC4E0000 */  sw    $t6, ($v0)
/* 0679C8 80066DC8 8DEFD4C4 */  lw    $t7, %lo(D_8018D4C4)($t7)
/* 0679CC 80066DCC 3C0E0700 */  lui   $t6, 0x700
/* 0679D0 80066DD0 3C19F570 */  lui   $t9, 0xf570
/* 0679D4 80066DD4 AC4F0004 */  sw    $t7, 4($v0)
/* 0679D8 80066DD8 8C620000 */  lw    $v0, ($v1)
/* 0679DC 80066DDC 3C0D0400 */  lui   $t5, (0x0400103F >> 16) # lui $t5, 0x400
/* 0679E0 80066DE0 35AD103F */  ori   $t5, (0x0400103F & 0xFFFF) # ori $t5, $t5, 0x103f
/* 0679E4 80066DE4 24580008 */  addiu $t8, $v0, 8
/* 0679E8 80066DE8 AC780000 */  sw    $t8, ($v1)
/* 0679EC 80066DEC AC4E0004 */  sw    $t6, 4($v0)
/* 0679F0 80066DF0 AC590000 */  sw    $t9, ($v0)
/* 0679F4 80066DF4 8C620000 */  lw    $v0, ($v1)
/* 0679F8 80066DF8 3C18E600 */  lui   $t8, 0xe600
/* 0679FC 80066DFC 3C0EF300 */  lui   $t6, 0xf300
/* 067A00 80066E00 244F0008 */  addiu $t7, $v0, 8
/* 067A04 80066E04 AC6F0000 */  sw    $t7, ($v1)
/* 067A08 80066E08 AC400004 */  sw    $zero, 4($v0)
/* 067A0C 80066E0C AC580000 */  sw    $t8, ($v0)
/* 067A10 80066E10 8C620000 */  lw    $v0, ($v1)
/* 067A14 80066E14 3C0F073F */  lui   $t7, (0x073FF200 >> 16) # lui $t7, 0x73f
/* 067A18 80066E18 35EFF200 */  ori   $t7, (0x073FF200 & 0xFFFF) # ori $t7, $t7, 0xf200
/* 067A1C 80066E1C 24590008 */  addiu $t9, $v0, 8
/* 067A20 80066E20 AC790000 */  sw    $t9, ($v1)
/* 067A24 80066E24 AC4F0004 */  sw    $t7, 4($v0)
/* 067A28 80066E28 AC4E0000 */  sw    $t6, ($v0)
/* 067A2C 80066E2C 8C620000 */  lw    $v0, ($v1)
/* 067A30 80066E30 3C19E700 */  lui   $t9, 0xe700
/* 067A34 80066E34 3C0FF568 */  lui   $t7, (0xF5680800 >> 16) # lui $t7, 0xf568
/* 067A38 80066E38 24580008 */  addiu $t8, $v0, 8
/* 067A3C 80066E3C AC780000 */  sw    $t8, ($v1)
/* 067A40 80066E40 AC400004 */  sw    $zero, 4($v0)
/* 067A44 80066E44 AC590000 */  sw    $t9, ($v0)
/* 067A48 80066E48 8C620000 */  lw    $v0, ($v1)
/* 067A4C 80066E4C 35EF0800 */  ori   $t7, (0xF5680800 & 0xFFFF) # ori $t7, $t7, 0x800
/* 067A50 80066E50 3C19F200 */  lui   $t9, 0xf200
/* 067A54 80066E54 244E0008 */  addiu $t6, $v0, 8
/* 067A58 80066E58 AC6E0000 */  sw    $t6, ($v1)
/* 067A5C 80066E5C AC400004 */  sw    $zero, 4($v0)
/* 067A60 80066E60 AC4F0000 */  sw    $t7, ($v0)
/* 067A64 80066E64 8C620000 */  lw    $v0, ($v1)
/* 067A68 80066E68 3C0E0007 */  lui   $t6, (0x0007C0FC >> 16) # lui $t6, 7
/* 067A6C 80066E6C 35CEC0FC */  ori   $t6, (0x0007C0FC & 0xFFFF) # ori $t6, $t6, 0xc0fc
/* 067A70 80066E70 24580008 */  addiu $t8, $v0, 8
/* 067A74 80066E74 AC780000 */  sw    $t8, ($v1)
/* 067A78 80066E78 AC4E0004 */  sw    $t6, 4($v0)
/* 067A7C 80066E7C AC590000 */  sw    $t9, ($v0)
/* 067A80 80066E80 8C620000 */  lw    $v0, ($v1)
/* 067A84 80066E84 3C0E800F */  lui   $t6, %hi(D_800E8900) # $t6, 0x800f
/* 067A88 80066E88 25CE8900 */  addiu $t6, %lo(D_800E8900) # addiu $t6, $t6, -0x7700
/* 067A8C 80066E8C 244F0008 */  addiu $t7, $v0, 8
/* 067A90 80066E90 AC6F0000 */  sw    $t7, ($v1)
/* 067A94 80066E94 AC4D0000 */  sw    $t5, ($v0)
/* 067A98 80066E98 87F80290 */  lh    $t8, 0x290($ra)
/* 067A9C 80066E9C 0018C900 */  sll   $t9, $t8, 4
/* 067AA0 80066EA0 032E7821 */  addu  $t7, $t9, $t6
/* 067AA4 80066EA4 AC4F0004 */  sw    $t7, 4($v0)
/* 067AA8 80066EA8 8C620000 */  lw    $v0, ($v1)
/* 067AAC 80066EAC 3C190D01 */  lui   $t9, %hi(D_0D008C78) # $t9, 0xd01
/* 067AB0 80066EB0 27398C78 */  addiu $t9, %lo(D_0D008C78) # addiu $t9, $t9, -0x7388
/* 067AB4 80066EB4 24580008 */  addiu $t8, $v0, 8
/* 067AB8 80066EB8 AC780000 */  sw    $t8, ($v1)
/* 067ABC 80066EBC AC590004 */  sw    $t9, 4($v0)
/* 067AC0 80066EC0 AC500000 */  sw    $s0, ($v0)
/* 067AC4 80066EC4 8C620000 */  lw    $v0, ($v1)
/* 067AC8 80066EC8 3C0FFD70 */  lui   $t7, 0xfd70
/* 067ACC 80066ECC 3C188019 */  lui   $t8, %hi(D_8018D4C8) # $t8, 0x8019
/* 067AD0 80066ED0 244E0008 */  addiu $t6, $v0, 8
/* 067AD4 80066ED4 AC6E0000 */  sw    $t6, ($v1)
/* 067AD8 80066ED8 AC4F0000 */  sw    $t7, ($v0)
/* 067ADC 80066EDC 8F18D4C8 */  lw    $t8, %lo(D_8018D4C8)($t8)
/* 067AE0 80066EE0 3C0F0700 */  lui   $t7, 0x700
/* 067AE4 80066EE4 3C0EF570 */  lui   $t6, 0xf570
/* 067AE8 80066EE8 AC580004 */  sw    $t8, 4($v0)
/* 067AEC 80066EEC 8C620000 */  lw    $v0, ($v1)
/* 067AF0 80066EF0 24590008 */  addiu $t9, $v0, 8
/* 067AF4 80066EF4 AC790000 */  sw    $t9, ($v1)
/* 067AF8 80066EF8 AC4F0004 */  sw    $t7, 4($v0)
/* 067AFC 80066EFC AC4E0000 */  sw    $t6, ($v0)
/* 067B00 80066F00 8C620000 */  lw    $v0, ($v1)
/* 067B04 80066F04 3C19E600 */  lui   $t9, 0xe600
/* 067B08 80066F08 3C0FF300 */  lui   $t7, 0xf300
/* 067B0C 80066F0C 24580008 */  addiu $t8, $v0, 8
/* 067B10 80066F10 AC780000 */  sw    $t8, ($v1)
/* 067B14 80066F14 AC400004 */  sw    $zero, 4($v0)
/* 067B18 80066F18 AC590000 */  sw    $t9, ($v0)
/* 067B1C 80066F1C 8C620000 */  lw    $v0, ($v1)
/* 067B20 80066F20 3C18073F */  lui   $t8, (0x073FF200 >> 16) # lui $t8, 0x73f
/* 067B24 80066F24 3718F200 */  ori   $t8, (0x073FF200 & 0xFFFF) # ori $t8, $t8, 0xf200
/* 067B28 80066F28 244E0008 */  addiu $t6, $v0, 8
/* 067B2C 80066F2C AC6E0000 */  sw    $t6, ($v1)
/* 067B30 80066F30 AC580004 */  sw    $t8, 4($v0)
/* 067B34 80066F34 AC4F0000 */  sw    $t7, ($v0)
/* 067B38 80066F38 8C620000 */  lw    $v0, ($v1)
/* 067B3C 80066F3C 3C0EE700 */  lui   $t6, 0xe700
/* 067B40 80066F40 3C18F568 */  lui   $t8, (0xF5680800 >> 16) # lui $t8, 0xf568
/* 067B44 80066F44 24590008 */  addiu $t9, $v0, 8
/* 067B48 80066F48 AC790000 */  sw    $t9, ($v1)
/* 067B4C 80066F4C AC400004 */  sw    $zero, 4($v0)
/* 067B50 80066F50 AC4E0000 */  sw    $t6, ($v0)
/* 067B54 80066F54 8C620000 */  lw    $v0, ($v1)
/* 067B58 80066F58 37180800 */  ori   $t8, (0xF5680800 & 0xFFFF) # ori $t8, $t8, 0x800
/* 067B5C 80066F5C 3C0EF200 */  lui   $t6, 0xf200
/* 067B60 80066F60 244F0008 */  addiu $t7, $v0, 8
/* 067B64 80066F64 AC6F0000 */  sw    $t7, ($v1)
/* 067B68 80066F68 AC400004 */  sw    $zero, 4($v0)
/* 067B6C 80066F6C AC580000 */  sw    $t8, ($v0)
/* 067B70 80066F70 8C620000 */  lw    $v0, ($v1)
/* 067B74 80066F74 3C0F0007 */  lui   $t7, (0x0007C0FC >> 16) # lui $t7, 7
/* 067B78 80066F78 35EFC0FC */  ori   $t7, (0x0007C0FC & 0xFFFF) # ori $t7, $t7, 0xc0fc
/* 067B7C 80066F7C 24590008 */  addiu $t9, $v0, 8
/* 067B80 80066F80 AC790000 */  sw    $t9, ($v1)
/* 067B84 80066F84 AC4F0004 */  sw    $t7, 4($v0)
/* 067B88 80066F88 AC4E0000 */  sw    $t6, ($v0)
/* 067B8C 80066F8C 8C620000 */  lw    $v0, ($v1)
/* 067B90 80066F90 24580008 */  addiu $t8, $v0, 8
/* 067B94 80066F94 AC780000 */  sw    $t8, ($v1)
/* 067B98 80066F98 AC4D0000 */  sw    $t5, ($v0)
/* 067B9C 80066F9C 87F90290 */  lh    $t9, 0x290($ra)
/* 067BA0 80066FA0 3C18800F */  lui   $t8, %hi(D_800E8900) # $t8, 0x800f
/* 067BA4 80066FA4 27188900 */  addiu $t8, %lo(D_800E8900) # addiu $t8, $t8, -0x7700
/* 067BA8 80066FA8 00197100 */  sll   $t6, $t9, 4
/* 067BAC 80066FAC 25CF0040 */  addiu $t7, $t6, 0x40
/* 067BB0 80066FB0 01F8C821 */  addu  $t9, $t7, $t8
/* 067BB4 80066FB4 AC590004 */  sw    $t9, 4($v0)
/* 067BB8 80066FB8 8C620000 */  lw    $v0, ($v1)
/* 067BBC 80066FBC 3C0F0D01 */  lui   $t7, %hi(D_0D008DA0) # $t7, 0xd01
/* 067BC0 80066FC0 25EF8DA0 */  addiu $t7, %lo(D_0D008DA0) # addiu $t7, $t7, -0x7260
/* 067BC4 80066FC4 244E0008 */  addiu $t6, $v0, 8
/* 067BC8 80066FC8 AC6E0000 */  sw    $t6, ($v1)
/* 067BCC 80066FCC AC4F0004 */  sw    $t7, 4($v0)
/* 067BD0 80066FD0 100000A1 */  b     .L80067258
/* 067BD4 80066FD4 AC500000 */   sw    $s0, ($v0)
.L80066FD8:
/* 067BD8 80066FD8 8C620000 */  lw    $v0, ($v1)
/* 067BDC 80066FDC 27398DB8 */  addiu $t9, $t9, -0x7248
/* 067BE0 80066FE0 3C0FFC12 */  lui   $t7, (0xFC127E24 >> 16) # lui $t7, 0xfc12
/* 067BE4 80066FE4 24580008 */  addiu $t8, $v0, 8
/* 067BE8 80066FE8 AC780000 */  sw    $t8, ($v1)
/* 067BEC 80066FEC AC590004 */  sw    $t9, 4($v0)
/* 067BF0 80066FF0 AC500000 */  sw    $s0, ($v0)
/* 067BF4 80066FF4 8C620000 */  lw    $v0, ($v1)
/* 067BF8 80066FF8 2418F3F9 */  li    $t8, -3079
/* 067BFC 80066FFC 35EF7E24 */  ori   $t7, (0xFC127E24 & 0xFFFF) # ori $t7, $t7, 0x7e24
/* 067C00 80067000 244E0008 */  addiu $t6, $v0, 8
/* 067C04 80067004 AC6E0000 */  sw    $t6, ($v1)
/* 067C08 80067008 AC580004 */  sw    $t8, 4($v0)
/* 067C0C 8006700C AC4F0000 */  sw    $t7, ($v0)
/* 067C10 80067010 8C620000 */  lw    $v0, ($v1)
/* 067C14 80067014 3C0F0050 */  lui   $t7, (0x00504B50 >> 16) # lui $t7, 0x50
/* 067C18 80067018 3C0EB900 */  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
/* 067C1C 8006701C 24590008 */  addiu $t9, $v0, 8
/* 067C20 80067020 AC790000 */  sw    $t9, ($v1)
/* 067C24 80067024 35CE031D */  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
/* 067C28 80067028 35EF4B50 */  ori   $t7, (0x00504B50 & 0xFFFF) # ori $t7, $t7, 0x4b50
/* 067C2C 8006702C AC4F0004 */  sw    $t7, 4($v0)
/* 067C30 80067030 AC4E0000 */  sw    $t6, ($v0)
/* 067C34 80067034 8C620000 */  lw    $v0, ($v1)
/* 067C38 80067038 3C19FD70 */  lui   $t9, 0xfd70
/* 067C3C 8006703C 3C0E8019 */  lui   $t6, %hi(D_8018D4C8) # $t6, 0x8019
/* 067C40 80067040 24580008 */  addiu $t8, $v0, 8
/* 067C44 80067044 AC780000 */  sw    $t8, ($v1)
/* 067C48 80067048 AC590000 */  sw    $t9, ($v0)
/* 067C4C 8006704C 8DCED4C8 */  lw    $t6, %lo(D_8018D4C8)($t6)
/* 067C50 80067050 3C190700 */  lui   $t9, 0x700
/* 067C54 80067054 3C18F570 */  lui   $t8, 0xf570
/* 067C58 80067058 AC4E0004 */  sw    $t6, 4($v0)
/* 067C5C 8006705C 8C620000 */  lw    $v0, ($v1)
/* 067C60 80067060 3C0D0400 */  lui   $t5, (0x0400103F >> 16) # lui $t5, 0x400
/* 067C64 80067064 35AD103F */  ori   $t5, (0x0400103F & 0xFFFF) # ori $t5, $t5, 0x103f
/* 067C68 80067068 244F0008 */  addiu $t7, $v0, 8
/* 067C6C 8006706C AC6F0000 */  sw    $t7, ($v1)
/* 067C70 80067070 AC590004 */  sw    $t9, 4($v0)
/* 067C74 80067074 AC580000 */  sw    $t8, ($v0)
/* 067C78 80067078 8C620000 */  lw    $v0, ($v1)
/* 067C7C 8006707C 3C0FE600 */  lui   $t7, 0xe600
/* 067C80 80067080 3C19F300 */  lui   $t9, 0xf300
/* 067C84 80067084 244E0008 */  addiu $t6, $v0, 8
/* 067C88 80067088 AC6E0000 */  sw    $t6, ($v1)
/* 067C8C 8006708C AC400004 */  sw    $zero, 4($v0)
/* 067C90 80067090 AC4F0000 */  sw    $t7, ($v0)
/* 067C94 80067094 8C620000 */  lw    $v0, ($v1)
/* 067C98 80067098 3C0E073F */  lui   $t6, (0x073FF200 >> 16) # lui $t6, 0x73f
/* 067C9C 8006709C 35CEF200 */  ori   $t6, (0x073FF200 & 0xFFFF) # ori $t6, $t6, 0xf200
/* 067CA0 800670A0 24580008 */  addiu $t8, $v0, 8
/* 067CA4 800670A4 AC780000 */  sw    $t8, ($v1)
/* 067CA8 800670A8 AC4E0004 */  sw    $t6, 4($v0)
/* 067CAC 800670AC AC590000 */  sw    $t9, ($v0)
/* 067CB0 800670B0 8C620000 */  lw    $v0, ($v1)
/* 067CB4 800670B4 3C18E700 */  lui   $t8, 0xe700
/* 067CB8 800670B8 3C0EF568 */  lui   $t6, (0xF5680800 >> 16) # lui $t6, 0xf568
/* 067CBC 800670BC 244F0008 */  addiu $t7, $v0, 8
/* 067CC0 800670C0 AC6F0000 */  sw    $t7, ($v1)
/* 067CC4 800670C4 AC400004 */  sw    $zero, 4($v0)
/* 067CC8 800670C8 AC580000 */  sw    $t8, ($v0)
/* 067CCC 800670CC 8C620000 */  lw    $v0, ($v1)
/* 067CD0 800670D0 35CE0800 */  ori   $t6, (0xF5680800 & 0xFFFF) # ori $t6, $t6, 0x800
/* 067CD4 800670D4 3C18F200 */  lui   $t8, 0xf200
/* 067CD8 800670D8 24590008 */  addiu $t9, $v0, 8
/* 067CDC 800670DC AC790000 */  sw    $t9, ($v1)
/* 067CE0 800670E0 AC400004 */  sw    $zero, 4($v0)
/* 067CE4 800670E4 AC4E0000 */  sw    $t6, ($v0)
/* 067CE8 800670E8 8C620000 */  lw    $v0, ($v1)
/* 067CEC 800670EC 3C190007 */  lui   $t9, (0x0007C0FC >> 16) # lui $t9, 7
/* 067CF0 800670F0 3739C0FC */  ori   $t9, (0x0007C0FC & 0xFFFF) # ori $t9, $t9, 0xc0fc
/* 067CF4 800670F4 244F0008 */  addiu $t7, $v0, 8
/* 067CF8 800670F8 AC6F0000 */  sw    $t7, ($v1)
/* 067CFC 800670FC AC590004 */  sw    $t9, 4($v0)
/* 067D00 80067100 AC580000 */  sw    $t8, ($v0)
/* 067D04 80067104 8C620000 */  lw    $v0, ($v1)
/* 067D08 80067108 3C19800F */  lui   $t9, %hi(D_800E8900) # $t9, 0x800f
/* 067D0C 8006710C 27398900 */  addiu $t9, %lo(D_800E8900) # addiu $t9, $t9, -0x7700
/* 067D10 80067110 244E0008 */  addiu $t6, $v0, 8
/* 067D14 80067114 AC6E0000 */  sw    $t6, ($v1)
/* 067D18 80067118 AC4D0000 */  sw    $t5, ($v0)
/* 067D1C 8006711C 87EF0290 */  lh    $t7, 0x290($ra)
/* 067D20 80067120 000FC100 */  sll   $t8, $t7, 4
/* 067D24 80067124 03197021 */  addu  $t6, $t8, $t9
/* 067D28 80067128 AC4E0004 */  sw    $t6, 4($v0)
/* 067D2C 8006712C 8C620000 */  lw    $v0, ($v1)
/* 067D30 80067130 3C180D01 */  lui   $t8, %hi(D_0D008C78) # $t8, 0xd01
/* 067D34 80067134 27188C78 */  addiu $t8, %lo(D_0D008C78) # addiu $t8, $t8, -0x7388
/* 067D38 80067138 244F0008 */  addiu $t7, $v0, 8
/* 067D3C 8006713C AC6F0000 */  sw    $t7, ($v1)
/* 067D40 80067140 AC580004 */  sw    $t8, 4($v0)
/* 067D44 80067144 AC500000 */  sw    $s0, ($v0)
/* 067D48 80067148 8C620000 */  lw    $v0, ($v1)
/* 067D4C 8006714C 3C0EFD70 */  lui   $t6, 0xfd70
/* 067D50 80067150 3C0F8019 */  lui   $t7, %hi(D_8018D4C4) # $t7, 0x8019
/* 067D54 80067154 24590008 */  addiu $t9, $v0, 8
/* 067D58 80067158 AC790000 */  sw    $t9, ($v1)
/* 067D5C 8006715C AC4E0000 */  sw    $t6, ($v0)
/* 067D60 80067160 8DEFD4C4 */  lw    $t7, %lo(D_8018D4C4)($t7)
/* 067D64 80067164 3C0E0700 */  lui   $t6, 0x700
/* 067D68 80067168 3C19F570 */  lui   $t9, 0xf570
/* 067D6C 8006716C AC4F0004 */  sw    $t7, 4($v0)
/* 067D70 80067170 8C620000 */  lw    $v0, ($v1)
/* 067D74 80067174 24580008 */  addiu $t8, $v0, 8
/* 067D78 80067178 AC780000 */  sw    $t8, ($v1)
/* 067D7C 8006717C AC4E0004 */  sw    $t6, 4($v0)
/* 067D80 80067180 AC590000 */  sw    $t9, ($v0)
/* 067D84 80067184 8C620000 */  lw    $v0, ($v1)
/* 067D88 80067188 3C18E600 */  lui   $t8, 0xe600
/* 067D8C 8006718C 3C0EF300 */  lui   $t6, 0xf300
/* 067D90 80067190 244F0008 */  addiu $t7, $v0, 8
/* 067D94 80067194 AC6F0000 */  sw    $t7, ($v1)
/* 067D98 80067198 AC400004 */  sw    $zero, 4($v0)
/* 067D9C 8006719C AC580000 */  sw    $t8, ($v0)
/* 067DA0 800671A0 8C620000 */  lw    $v0, ($v1)
/* 067DA4 800671A4 3C0F073F */  lui   $t7, (0x073FF200 >> 16) # lui $t7, 0x73f
/* 067DA8 800671A8 35EFF200 */  ori   $t7, (0x073FF200 & 0xFFFF) # ori $t7, $t7, 0xf200
/* 067DAC 800671AC 24590008 */  addiu $t9, $v0, 8
/* 067DB0 800671B0 AC790000 */  sw    $t9, ($v1)
/* 067DB4 800671B4 AC4F0004 */  sw    $t7, 4($v0)
/* 067DB8 800671B8 AC4E0000 */  sw    $t6, ($v0)
/* 067DBC 800671BC 8C620000 */  lw    $v0, ($v1)
/* 067DC0 800671C0 3C19E700 */  lui   $t9, 0xe700
/* 067DC4 800671C4 3C0FF568 */  lui   $t7, (0xF5680800 >> 16) # lui $t7, 0xf568
/* 067DC8 800671C8 24580008 */  addiu $t8, $v0, 8
/* 067DCC 800671CC AC780000 */  sw    $t8, ($v1)
/* 067DD0 800671D0 AC400004 */  sw    $zero, 4($v0)
/* 067DD4 800671D4 AC590000 */  sw    $t9, ($v0)
/* 067DD8 800671D8 8C620000 */  lw    $v0, ($v1)
/* 067DDC 800671DC 35EF0800 */  ori   $t7, (0xF5680800 & 0xFFFF) # ori $t7, $t7, 0x800
/* 067DE0 800671E0 3C19F200 */  lui   $t9, 0xf200
/* 067DE4 800671E4 244E0008 */  addiu $t6, $v0, 8
/* 067DE8 800671E8 AC6E0000 */  sw    $t6, ($v1)
/* 067DEC 800671EC AC400004 */  sw    $zero, 4($v0)
/* 067DF0 800671F0 AC4F0000 */  sw    $t7, ($v0)
/* 067DF4 800671F4 8C620000 */  lw    $v0, ($v1)
/* 067DF8 800671F8 3C0E0007 */  lui   $t6, (0x0007C0FC >> 16) # lui $t6, 7
/* 067DFC 800671FC 35CEC0FC */  ori   $t6, (0x0007C0FC & 0xFFFF) # ori $t6, $t6, 0xc0fc
/* 067E00 80067200 24580008 */  addiu $t8, $v0, 8
/* 067E04 80067204 AC780000 */  sw    $t8, ($v1)
/* 067E08 80067208 AC4E0004 */  sw    $t6, 4($v0)
/* 067E0C 8006720C AC590000 */  sw    $t9, ($v0)
/* 067E10 80067210 8C620000 */  lw    $v0, ($v1)
/* 067E14 80067214 244F0008 */  addiu $t7, $v0, 8
/* 067E18 80067218 AC6F0000 */  sw    $t7, ($v1)
/* 067E1C 8006721C AC4D0000 */  sw    $t5, ($v0)
/* 067E20 80067220 87F80290 */  lh    $t8, 0x290($ra)
/* 067E24 80067224 3C0F800F */  lui   $t7, %hi(D_800E8900) # $t7, 0x800f
/* 067E28 80067228 25EF8900 */  addiu $t7, %lo(D_800E8900) # addiu $t7, $t7, -0x7700
/* 067E2C 8006722C 0018C900 */  sll   $t9, $t8, 4
/* 067E30 80067230 272E0040 */  addiu $t6, $t9, 0x40
/* 067E34 80067234 01CFC021 */  addu  $t8, $t6, $t7
/* 067E38 80067238 AC580004 */  sw    $t8, 4($v0)
/* 067E3C 8006723C 8C620000 */  lw    $v0, ($v1)
/* 067E40 80067240 3C0E0D01 */  lui   $t6, %hi(D_0D008DA0) # $t6, 0xd01
/* 067E44 80067244 25CE8DA0 */  addiu $t6, %lo(D_0D008DA0) # addiu $t6, $t6, -0x7260
/* 067E48 80067248 24590008 */  addiu $t9, $v0, 8
/* 067E4C 8006724C AC790000 */  sw    $t9, ($v1)
/* 067E50 80067250 AC4E0004 */  sw    $t6, 4($v0)
/* 067E54 80067254 AC500000 */  sw    $s0, ($v0)
.L80067258:
/* 067E58 80067258 3C028016 */  lui   $v0, %hi(D_80164AF0) # $v0, 0x8016
/* 067E5C 8006725C 24424AF0 */  addiu $v0, %lo(D_80164AF0) # addiu $v0, $v0, 0x4af0
/* 067E60 80067260 844F0000 */  lh    $t7, ($v0)
/* 067E64 80067264 25F80001 */  addiu $t8, $t7, 1
/* 067E68 80067268 A4580000 */  sh    $t8, ($v0)
.L8006726C:
/* 067E6C 8006726C 8FBF001C */  lw    $ra, 0x1c($sp)
.L80067270:
/* 067E70 80067270 8FB00018 */  lw    $s0, 0x18($sp)
/* 067E74 80067274 27BD00E8 */  addiu $sp, $sp, 0xe8
/* 067E78 80067278 03E00008 */  jr    $ra
/* 067E7C 8006727C 00000000 */   nop   
