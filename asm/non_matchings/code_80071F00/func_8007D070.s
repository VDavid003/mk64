glabel func_8007D070
/* 07DC70 8007D070 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 07DC74 8007D074 3C0E8016 */  lui   $t6, %hi(D_8016559C) # $t6, 0x8016
/* 07DC78 8007D078 8DCE559C */  lw    $t6, %lo(D_8016559C)($t6)
/* 07DC7C 8007D07C AFBF003C */  sw    $ra, 0x3c($sp)
/* 07DC80 8007D080 AFBE0038 */  sw    $fp, 0x38($sp)
/* 07DC84 8007D084 AFB70034 */  sw    $s7, 0x34($sp)
/* 07DC88 8007D088 AFB60030 */  sw    $s6, 0x30($sp)
/* 07DC8C 8007D08C AFB5002C */  sw    $s5, 0x2c($sp)
/* 07DC90 8007D090 AFB40028 */  sw    $s4, 0x28($sp)
/* 07DC94 8007D094 AFB30024 */  sw    $s3, 0x24($sp)
/* 07DC98 8007D098 AFB20020 */  sw    $s2, 0x20($sp)
/* 07DC9C 8007D09C AFB1001C */  sw    $s1, 0x1c($sp)
/* 07DCA0 8007D0A0 AFB00018 */  sw    $s0, 0x18($sp)
/* 07DCA4 8007D0A4 15C0006C */  bnez  $t6, .L8007D258
/* 07DCA8 8007D0A8 00001025 */   move  $v0, $zero
/* 07DCAC 8007D0AC 3C0F8019 */  lui   $t7, %hi(D_8018D2A4) # $t7, 0x8019
/* 07DCB0 8007D0B0 8DEFD2A4 */  lw    $t7, %lo(D_8018D2A4)($t7)
/* 07DCB4 8007D0B4 3C038019 */  lui   $v1, %hi(D_8018CF68) # $v1, 0x8019
/* 07DCB8 8007D0B8 11E00067 */  beqz  $t7, .L8007D258
/* 07DCBC 8007D0BC 00000000 */   nop   
/* 07DCC0 8007D0C0 8463CF68 */  lh    $v1, %lo(D_8018CF68)($v1)
/* 07DCC4 8007D0C4 3C18800E */  lui   $t8, %hi(D_800E5DB4)
/* 07DCC8 8007D0C8 2861001D */  slti  $at, $v1, 0x1d
/* 07DCCC 8007D0CC 10200062 */  beqz  $at, .L8007D258
/* 07DCD0 8007D0D0 0303C021 */   addu  $t8, $t8, $v1
/* 07DCD4 8007D0D4 83185DB4 */  lb    $t8, %lo(D_800E5DB4)($t8)
/* 07DCD8 8007D0D8 24010001 */  li    $at, 1
/* 07DCDC 8007D0DC 3C198019 */  lui   $t9, %hi(D_8018C1D8) # $t9, 0x8019
/* 07DCE0 8007D0E0 1701005D */  bne   $t8, $at, .L8007D258
/* 07DCE4 8007D0E4 00000000 */   nop   
/* 07DCE8 8007D0E8 8F39C1D8 */  lw    $t9, %lo(D_8018C1D8)($t9)
/* 07DCEC 8007D0EC 241700E0 */  li    $s7, 224
/* 07DCF0 8007D0F0 3C168016 */  lui   $s6, %hi(gObjectList) # $s6, 0x8016
/* 07DCF4 8007D0F4 03370019 */  multu $t9, $s7
/* 07DCF8 8007D0F8 26D65C18 */  addiu $s6, %lo(gObjectList) # addiu $s6, $s6, 0x5c18
/* 07DCFC 8007D0FC 3C048019 */  lui   $a0, %hi(D_8018C1B0) # $a0, 0x8019
/* 07DD00 8007D100 2484C1B0 */  addiu $a0, %lo(D_8018C1B0) # addiu $a0, $a0, -0x3e50
/* 07DD04 8007D104 2403001E */  li    $v1, 30
/* 07DD08 8007D108 00004012 */  mflo  $t0
/* 07DD0C 8007D10C 02C84821 */  addu  $t1, $s6, $t0
/* 07DD10 8007D110 852A00A6 */  lh    $t2, 0xa6($t1)
/* 07DD14 8007D114 1140000C */  beqz  $t2, .L8007D148
/* 07DD18 8007D118 00000000 */   nop   
/* 07DD1C 8007D11C 24420001 */  addiu $v0, $v0, 1
.L8007D120:
/* 07DD20 8007D120 10430009 */  beq   $v0, $v1, .L8007D148
/* 07DD24 8007D124 00025880 */   sll   $t3, $v0, 2
/* 07DD28 8007D128 008B6021 */  addu  $t4, $a0, $t3
/* 07DD2C 8007D12C 8D8D0028 */  lw    $t5, 0x28($t4)
/* 07DD30 8007D130 01B70019 */  multu $t5, $s7
/* 07DD34 8007D134 00007012 */  mflo  $t6
/* 07DD38 8007D138 02CE7821 */  addu  $t7, $s6, $t6
/* 07DD3C 8007D13C 85F800A6 */  lh    $t8, 0xa6($t7)
/* 07DD40 8007D140 5700FFF7 */  bnel  $t8, $zero, .L8007D120
/* 07DD44 8007D144 24420001 */   addiu $v0, $v0, 1
.L8007D148:
/* 07DD48 8007D148 3C048019 */  lui   $a0, %hi(D_8018C1B0) # $a0, 0x8019
/* 07DD4C 8007D14C 2484C1B0 */  addiu $a0, %lo(D_8018C1B0) # addiu $a0, $a0, -0x3e50
/* 07DD50 8007D150 0002C880 */  sll   $t9, $v0, 2
/* 07DD54 8007D154 2403001E */  li    $v1, 30
/* 07DD58 8007D158 00994021 */  addu  $t0, $a0, $t9
/* 07DD5C 8007D15C 1043003E */  beq   $v0, $v1, .L8007D258
/* 07DD60 8007D160 8D110028 */   lw    $s1, 0x28($t0)
/* 07DD64 8007D164 02370019 */  multu $s1, $s7
/* 07DD68 8007D168 02202025 */  move  $a0, $s1
/* 07DD6C 8007D16C 00004812 */  mflo  $t1
/* 07DD70 8007D170 02C98021 */  addu  $s0, $s6, $t1
/* 07DD74 8007D174 860A00A6 */  lh    $t2, 0xa6($s0)
/* 07DD78 8007D178 15400037 */  bnez  $t2, .L8007D258
/* 07DD7C 8007D17C 00000000 */   nop   
/* 07DD80 8007D180 0C01C8E9 */  jal   func_800723A4
/* 07DD84 8007D184 24050001 */   li    $a1, 1
/* 07DD88 8007D188 0C0ADF8D */  jal   random_int
/* 07DD8C 8007D18C 2404012C */   li    $a0, 300
/* 07DD90 8007D190 00029400 */  sll   $s2, $v0, 0x10
/* 07DD94 8007D194 00125C03 */  sra   $t3, $s2, 0x10
/* 07DD98 8007D198 01609025 */  move  $s2, $t3
/* 07DD9C 8007D19C 0C0ADF8D */  jal   random_int
/* 07DDA0 8007D1A0 24041000 */   li    $a0, 4096
/* 07DDA4 8007D1A4 2453F800 */  addiu $s3, $v0, -0x800
/* 07DDA8 8007D1A8 326CFFFF */  andi  $t4, $s3, 0xffff
/* 07DDAC 8007D1AC 01809825 */  move  $s3, $t4
/* 07DDB0 8007D1B0 0C0ADF8D */  jal   random_int
/* 07DDB4 8007D1B4 2404000F */   li    $a0, 15
/* 07DDB8 8007D1B8 3C1E8019 */  lui   $fp, %hi(D_8018CF1C) # $fp, 0x8019
/* 07DDBC 8007D1BC 27DECF1C */  addiu $fp, %lo(D_8018CF1C) # addiu $fp, $fp, -0x30e4
/* 07DDC0 8007D1C0 8FCF0000 */  lw    $t7, ($fp)
/* 07DDC4 8007D1C4 34018000 */  li    $at, 32768
/* 07DDC8 8007D1C8 3C088019 */  lui   $t0, %hi(D_8018CF14) # $t0, 0x8019
/* 07DDCC 8007D1CC 85F8002E */  lh    $t8, 0x2e($t7)
/* 07DDD0 8007D1D0 2454FFFB */  addiu $s4, $v0, -5
/* 07DDD4 8007D1D4 00146C00 */  sll   $t5, $s4, 0x10
/* 07DDD8 8007D1D8 0301C821 */  addu  $t9, $t8, $at
/* 07DDDC 8007D1DC A61900C0 */  sh    $t9, 0xc0($s0)
/* 07DDE0 8007D1E0 8D08CF14 */  lw    $t0, %lo(D_8018CF14)($t0)
/* 07DDE4 8007D1E4 000DA403 */  sra   $s4, $t5, 0x10
/* 07DDE8 8007D1E8 85090026 */  lh    $t1, 0x26($t0)
/* 07DDEC 8007D1EC 01338821 */  addu  $s1, $t1, $s3
/* 07DDF0 8007D1F0 322AFFFF */  andi  $t2, $s1, 0xffff
/* 07DDF4 8007D1F4 01408825 */  move  $s1, $t2
/* 07DDF8 8007D1F8 0C0AE006 */  jal   sins
/* 07DDFC 8007D1FC 3144FFFF */   andi  $a0, $t2, 0xffff
/* 07DE00 8007D200 44922000 */  mtc1  $s2, $f4
/* 07DE04 8007D204 8FCB0000 */  lw    $t3, ($fp)
/* 07DE08 8007D208 44948000 */  mtc1  $s4, $f16
/* 07DE0C 8007D20C 468020A0 */  cvt.s.w $f2, $f4
/* 07DE10 8007D210 C5680014 */  lwc1  $f8, 0x14($t3)
/* 07DE14 8007D214 3224FFFF */  andi  $a0, $s1, 0xffff
/* 07DE18 8007D218 468084A0 */  cvt.s.w $f18, $f16
/* 07DE1C 8007D21C 46020182 */  mul.s $f6, $f0, $f2
/* 07DE20 8007D220 E7A20044 */  swc1  $f2, 0x44($sp)
/* 07DE24 8007D224 E6120014 */  swc1  $f18, 0x14($s0)
/* 07DE28 8007D228 46083280 */  add.s $f10, $f6, $f8
/* 07DE2C 8007D22C 0C0AE00E */  jal   coss
/* 07DE30 8007D230 E60A0010 */   swc1  $f10, 0x10($s0)
/* 07DE34 8007D234 C7A20044 */  lwc1  $f2, 0x44($sp)
/* 07DE38 8007D238 8FCC0000 */  lw    $t4, ($fp)
/* 07DE3C 8007D23C 3C0D800E */  lui   $t5, %hi(D_800E5D54) # $t5, 0x800e
/* 07DE40 8007D240 46020102 */  mul.s $f4, $f0, $f2
/* 07DE44 8007D244 C586001C */  lwc1  $f6, 0x1c($t4)
/* 07DE48 8007D248 25AD5D54 */  addiu $t5, %lo(D_800E5D54) # addiu $t5, $t5, 0x5d54
/* 07DE4C 8007D24C AE0D0080 */  sw    $t5, 0x80($s0)
/* 07DE50 8007D250 46062200 */  add.s $f8, $f4, $f6
/* 07DE54 8007D254 E6080018 */  swc1  $f8, 0x18($s0)
.L8007D258:
/* 07DE58 8007D258 3C168016 */  lui   $s6, %hi(gObjectList) # $s6, 0x8016
/* 07DE5C 8007D25C 3C1E8019 */  lui   $fp, %hi(D_8018CF1C) # $fp, 0x8019
/* 07DE60 8007D260 3C128019 */  lui   $s2, %hi(D_8018C1B0) # $s2, 0x8019
/* 07DE64 8007D264 3C15800E */  lui   $s5, %hi(D_800E4470) # $s5, 0x800e
/* 07DE68 8007D268 3C148019 */  lui   $s4, %hi(D_8018C228) # $s4, 0x8019
/* 07DE6C 8007D26C 3C13800E */  lui   $s3, %hi(D_800E44B0) # $s3, 0x800e
/* 07DE70 8007D270 27DECF1C */  addiu $fp, %lo(D_8018CF1C) # addiu $fp, $fp, -0x30e4
/* 07DE74 8007D274 26D65C18 */  addiu $s6, %lo(gObjectList) # addiu $s6, $s6, 0x5c18
/* 07DE78 8007D278 241700E0 */  li    $s7, 224
/* 07DE7C 8007D27C 267344B0 */  addiu $s3, %lo(D_800E44B0) # addiu $s3, $s3, 0x44b0
/* 07DE80 8007D280 2694C228 */  addiu $s4, %lo(D_8018C228) # addiu $s4, $s4, -0x3dd8
/* 07DE84 8007D284 26B54470 */  addiu $s5, %lo(D_800E4470) # addiu $s5, $s5, 0x4470
/* 07DE88 8007D288 2652C1B0 */  addiu $s2, %lo(D_8018C1B0) # addiu $s2, $s2, -0x3e50
/* 07DE8C 8007D28C 8E510028 */  lw    $s1, 0x28($s2)
.L8007D290:
/* 07DE90 8007D290 02370019 */  multu $s1, $s7
/* 07DE94 8007D294 00007012 */  mflo  $t6
/* 07DE98 8007D298 02CE8021 */  addu  $s0, $s6, $t6
/* 07DE9C 8007D29C 860F00A6 */  lh    $t7, 0xa6($s0)
/* 07DEA0 8007D2A0 51E00021 */  beql  $t7, $zero, .L8007D328
/* 07DEA4 8007D2A4 26520004 */   addiu $s2, $s2, 4
/* 07DEA8 8007D2A8 0C01F3B7 */  jal   func_8007CEDC
/* 07DEAC 8007D2AC 02202025 */   move  $a0, $s1
/* 07DEB0 8007D2B0 0C022DC9 */  jal   func_8008B724
/* 07DEB4 8007D2B4 02202025 */   move  $a0, $s1
/* 07DEB8 8007D2B8 C60A0028 */  lwc1  $f10, 0x28($s0)
/* 07DEBC 8007D2BC C6100010 */  lwc1  $f16, 0x10($s0)
/* 07DEC0 8007D2C0 8FC50000 */  lw    $a1, ($fp)
/* 07DEC4 8007D2C4 C6060014 */  lwc1  $f6, 0x14($s0)
/* 07DEC8 8007D2C8 46105480 */  add.s $f18, $f10, $f16
/* 07DECC 8007D2CC C60A002C */  lwc1  $f10, 0x2c($s0)
/* 07DED0 8007D2D0 3C068019 */  lui   $a2, %hi(D_8018CF14) # $a2, 0x8019
/* 07DED4 8007D2D4 02202025 */  move  $a0, $s1
/* 07DED8 8007D2D8 E6120004 */  swc1  $f18, 4($s0)
/* 07DEDC 8007D2DC C4A40074 */  lwc1  $f4, 0x74($a1)
/* 07DEE0 8007D2E0 C6120030 */  lwc1  $f18, 0x30($s0)
/* 07DEE4 8007D2E4 46062200 */  add.s $f8, $f4, $f6
/* 07DEE8 8007D2E8 C6040018 */  lwc1  $f4, 0x18($s0)
/* 07DEEC 8007D2EC 46085400 */  add.s $f16, $f10, $f8
/* 07DEF0 8007D2F0 46049180 */  add.s $f6, $f18, $f4
/* 07DEF4 8007D2F4 E6100008 */  swc1  $f16, 8($s0)
/* 07DEF8 8007D2F8 E606000C */  swc1  $f6, 0xc($s0)
/* 07DEFC 8007D2FC 0C01F108 */  jal   func_8007C420
/* 07DF00 8007D300 8CC6CF14 */   lw    $a2, %lo(D_8018CF14)($a2)
/* 07DF04 8007D304 02202025 */  move  $a0, $s1
/* 07DF08 8007D308 0C01C88F */  jal   is_obj_index_flag_unk_054_active
/* 07DF0C 8007D30C 24050080 */   li    $a1, 128
/* 07DF10 8007D310 50400004 */  beql  $v0, $zero, .L8007D324
/* 07DF14 8007D314 AE150074 */   sw    $s5, 0x74($s0)
/* 07DF18 8007D318 10000002 */  b     .L8007D324
/* 07DF1C 8007D31C AE130074 */   sw    $s3, 0x74($s0)
/* 07DF20 8007D320 AE150074 */  sw    $s5, 0x74($s0)
.L8007D324:
/* 07DF24 8007D324 26520004 */  addiu $s2, $s2, 4
.L8007D328:
/* 07DF28 8007D328 5654FFD9 */  bnel  $s2, $s4, .L8007D290
/* 07DF2C 8007D32C 8E510028 */   lw    $s1, 0x28($s2)
/* 07DF30 8007D330 8FBF003C */  lw    $ra, 0x3c($sp)
/* 07DF34 8007D334 8FB00018 */  lw    $s0, 0x18($sp)
/* 07DF38 8007D338 8FB1001C */  lw    $s1, 0x1c($sp)
/* 07DF3C 8007D33C 8FB20020 */  lw    $s2, 0x20($sp)
/* 07DF40 8007D340 8FB30024 */  lw    $s3, 0x24($sp)
/* 07DF44 8007D344 8FB40028 */  lw    $s4, 0x28($sp)
/* 07DF48 8007D348 8FB5002C */  lw    $s5, 0x2c($sp)
/* 07DF4C 8007D34C 8FB60030 */  lw    $s6, 0x30($sp)
/* 07DF50 8007D350 8FB70034 */  lw    $s7, 0x34($sp)
/* 07DF54 8007D354 8FBE0038 */  lw    $fp, 0x38($sp)
/* 07DF58 8007D358 03E00008 */  jr    $ra
/* 07DF5C 8007D35C 27BD0060 */   addiu $sp, $sp, 0x60
