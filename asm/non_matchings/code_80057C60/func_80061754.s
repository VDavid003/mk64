glabel func_80061754
/* 062354 80061754 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 062358 80061758 AFB20030 */  sw    $s2, 0x30($sp)
/* 06235C 8006175C 00809025 */  move  $s2, $a0
/* 062360 80061760 AFBF0034 */  sw    $ra, 0x34($sp)
/* 062364 80061764 AFB1002C */  sw    $s1, 0x2c($sp)
/* 062368 80061768 AFB00028 */  sw    $s0, 0x28($sp)
/* 06236C 8006176C AFA5005C */  sw    $a1, 0x5c($sp)
/* 062370 80061770 AFA60060 */  sw    $a2, 0x60($sp)
/* 062374 80061774 AFA70064 */  sw    $a3, 0x64($sp)
/* 062378 80061778 0C0ADF8D */  jal   random_int
/* 06237C 8006177C 24040168 */   li    $a0, 360
/* 062380 80061780 244EFF4C */  addiu $t6, $v0, -0xb4
/* 062384 80061784 AFAE0054 */  sw    $t6, 0x54($sp)
/* 062388 80061788 0C0ADF8D */  jal   random_int
/* 06238C 8006178C 24040006 */   li    $a0, 6
/* 062390 80061790 AFA2004C */  sw    $v0, 0x4c($sp)
/* 062394 80061794 0C0ADF8D */  jal   random_int
/* 062398 80061798 24040060 */   li    $a0, 96
/* 06239C 8006179C 00028C00 */  sll   $s1, $v0, 0x10
/* 0623A0 800617A0 00117C03 */  sra   $t7, $s1, 0x10
/* 0623A4 800617A4 01E08825 */  move  $s1, $t7
/* 0623A8 800617A8 0C0ADF8D */  jal   random_int
/* 0623AC 800617AC 24040006 */   li    $a0, 6
/* 0623B0 800617B0 44822000 */  mtc1  $v0, $f4
/* 0623B4 800617B4 24040002 */  li    $a0, 2
/* 0623B8 800617B8 04410005 */  bgez  $v0, .L800617D0
/* 0623BC 800617BC 468021A0 */   cvt.s.w $f6, $f4
/* 0623C0 800617C0 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0623C4 800617C4 44814000 */  mtc1  $at, $f8
/* 0623C8 800617C8 00000000 */  nop   
/* 0623CC 800617CC 46083180 */  add.s $f6, $f6, $f8
.L800617D0:
/* 0623D0 800617D0 0C0ADF8D */  jal   random_int
/* 0623D4 800617D4 E7A60044 */   swc1  $f6, 0x44($sp)
/* 0623D8 800617D8 44825000 */  mtc1  $v0, $f10
/* 0623DC 800617DC 44800000 */  mtc1  $zero, $f0
/* 0623E0 800617E0 04410005 */  bgez  $v0, .L800617F8
/* 0623E4 800617E4 46805420 */   cvt.s.w $f16, $f10
/* 0623E8 800617E8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0623EC 800617EC 44819000 */  mtc1  $at, $f18
/* 0623F0 800617F0 00000000 */  nop   
/* 0623F4 800617F4 46128400 */  add.s $f16, $f16, $f18
.L800617F8:
/* 0623F8 800617F8 87B8005E */  lh    $t8, 0x5e($sp)
/* 0623FC 800617FC 44060000 */  mfc1  $a2, $f0
/* 062400 80061800 44070000 */  mfc1  $a3, $f0
/* 062404 80061804 0018C8C0 */  sll   $t9, $t8, 3
/* 062408 80061808 0338C821 */  addu  $t9, $t9, $t8
/* 06240C 8006180C 0019C8C0 */  sll   $t9, $t9, 3
/* 062410 80061810 02598021 */  addu  $s0, $s2, $t9
/* 062414 80061814 26050AC8 */  addiu $a1, $s0, 0xac8
/* 062418 80061818 E7B00048 */  swc1  $f16, 0x48($sp)
/* 06241C 8006181C AFA5003C */  sw    $a1, 0x3c($sp)
/* 062420 80061820 02402025 */  move  $a0, $s2
/* 062424 80061824 E7A00010 */  swc1  $f0, 0x10($sp)
/* 062428 80061828 AFA00014 */  sw    $zero, 0x14($sp)
/* 06242C 8006182C 0C0175E5 */  jal   func_8005D794
/* 062430 80061830 AFA00018 */   sw    $zero, 0x18($sp)
/* 062434 80061834 8FA4003C */  lw    $a0, 0x3c($sp)
/* 062438 80061838 24050006 */  li    $a1, 6
/* 06243C 8006183C 0C0175F6 */  jal   func_8005D7D8
/* 062440 80061840 3C063F80 */   lui   $a2, 0x3f80
/* 062444 80061844 8E4300BC */  lw    $v1, 0xbc($s2)
/* 062448 80061848 8FA4003C */  lw    $a0, 0x3c($sp)
/* 06244C 8006184C 3C0500FF */  lui   $a1, (0x00FFFFFF >> 16) # lui $a1, 0xff
/* 062450 80061850 00034180 */  sll   $t0, $v1, 6
/* 062454 80061854 05000007 */  bltz  $t0, .L80061874
/* 062458 80061858 000349C0 */   sll   $t1, $v1, 7
/* 06245C 8006185C 05200005 */  bltz  $t1, .L80061874
/* 062460 80061860 306A0400 */   andi  $t2, $v1, 0x400
/* 062464 80061864 15400003 */  bnez  $t2, .L80061874
/* 062468 80061868 00035800 */   sll   $t3, $v1, 0
/* 06246C 8006186C 0561000E */  bgez  $t3, .L800618A8
/* 062470 80061870 240600A0 */   li    $a2, 160
.L80061874:
/* 062474 80061874 34A5FFFF */  ori   $a1, (0x00FFFFFF & 0xFFFF) # ori $a1, $a1, 0xffff
/* 062478 80061878 0C017600 */  jal   func_8005D800
/* 06247C 8006187C 240600A0 */   li    $a2, 160
/* 062480 80061880 860C0B00 */  lh    $t4, 0xb00($s0)
/* 062484 80061884 860E0B02 */  lh    $t6, 0xb02($s0)
/* 062488 80061888 86180B04 */  lh    $t8, 0xb04($s0)
/* 06248C 8006188C 01916823 */  subu  $t5, $t4, $s1
/* 062490 80061890 01D17823 */  subu  $t7, $t6, $s1
/* 062494 80061894 0311C823 */  subu  $t9, $t8, $s1
/* 062498 80061898 A60D0B00 */  sh    $t5, 0xb00($s0)
/* 06249C 8006189C A60F0B02 */  sh    $t7, 0xb02($s0)
/* 0624A0 800618A0 1000000C */  b     .L800618D4
/* 0624A4 800618A4 A6190B04 */   sh    $t9, 0xb04($s0)
.L800618A8:
/* 0624A8 800618A8 0C017600 */  jal   func_8005D800
/* 0624AC 800618AC 00002825 */   move  $a1, $zero
/* 0624B0 800618B0 86080B00 */  lh    $t0, 0xb00($s0)
/* 0624B4 800618B4 860A0B02 */  lh    $t2, 0xb02($s0)
/* 0624B8 800618B8 860C0B04 */  lh    $t4, 0xb04($s0)
/* 0624BC 800618BC 01114821 */  addu  $t1, $t0, $s1
/* 0624C0 800618C0 01515821 */  addu  $t3, $t2, $s1
/* 0624C4 800618C4 01916821 */  addu  $t5, $t4, $s1
/* 0624C8 800618C8 A6090B00 */  sh    $t1, 0xb00($s0)
/* 0624CC 800618CC A60B0B02 */  sh    $t3, 0xb02($s0)
/* 0624D0 800618D0 A60D0B04 */  sh    $t5, 0xb04($s0)
.L800618D4:
/* 0624D4 800618D4 8FB10054 */  lw    $s1, 0x54($sp)
/* 0624D8 800618D8 00117080 */  sll   $t6, $s1, 2
/* 0624DC 800618DC 01D17023 */  subu  $t6, $t6, $s1
/* 0624E0 800618E0 000E70C0 */  sll   $t6, $t6, 3
/* 0624E4 800618E4 01D17023 */  subu  $t6, $t6, $s1
/* 0624E8 800618E8 000E7080 */  sll   $t6, $t6, 2
/* 0624EC 800618EC 01D17023 */  subu  $t6, $t6, $s1
/* 0624F0 800618F0 000E7040 */  sll   $t6, $t6, 1
/* 0624F4 800618F4 31D1FFFF */  andi  $s1, $t6, 0xffff
/* 0624F8 800618F8 0C0AE00E */  jal   coss
/* 0624FC 800618FC 3224FFFF */   andi  $a0, $s1, 0xffff
/* 062500 80061900 3C01C0A0 */  li    $at, 0xC0A00000 # -5.000000
/* 062504 80061904 44812000 */  mtc1  $at, $f4
/* 062508 80061908 C646001C */  lwc1  $f6, 0x1c($s2)
/* 06250C 8006190C 3224FFFF */  andi  $a0, $s1, 0xffff
/* 062510 80061910 46040202 */  mul.s $f8, $f0, $f4
/* 062514 80061914 46064280 */  add.s $f10, $f8, $f6
/* 062518 80061918 0C0AE006 */  jal   sins
/* 06251C 8006191C E60A0AD0 */   swc1  $f10, 0xad0($s0)
/* 062520 80061920 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 062524 80061924 44811000 */  mtc1  $at, $f2
/* 062528 80061928 3C01C0A0 */  li    $at, 0xC0A00000 # -5.000000
/* 06252C 8006192C 44819000 */  mtc1  $at, $f18
/* 062530 80061930 C6440014 */  lwc1  $f4, 0x14($s2)
/* 062534 80061934 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 062538 80061938 46120402 */  mul.s $f16, $f0, $f18
/* 06253C 8006193C 46048200 */  add.s $f8, $f16, $f4
/* 062540 80061940 E6080AC8 */  swc1  $f8, 0xac8($s0)
/* 062544 80061944 8FB8004C */  lw    $t8, 0x4c($sp)
/* 062548 80061948 C64A0070 */  lwc1  $f10, 0x70($s2)
/* 06254C 8006194C C6460018 */  lwc1  $f6, 0x18($s2)
/* 062550 80061950 44988000 */  mtc1  $t8, $f16
/* 062554 80061954 460A3481 */  sub.s $f18, $f6, $f10
/* 062558 80061958 44813000 */  mtc1  $at, $f6
/* 06255C 8006195C 46808120 */  cvt.s.w $f4, $f16
/* 062560 80061960 46049200 */  add.s $f8, $f18, $f4
/* 062564 80061964 46064280 */  add.s $f10, $f8, $f6
/* 062568 80061968 E60A0ACC */  swc1  $f10, 0xacc($s0)
/* 06256C 8006196C C7B00044 */  lwc1  $f16, 0x44($sp)
/* 062570 80061970 46028480 */  add.s $f18, $f16, $f2
/* 062574 80061974 E6120AE0 */  swc1  $f18, 0xae0($s0)
/* 062578 80061978 C7A40048 */  lwc1  $f4, 0x48($sp)
/* 06257C 8006197C 46022200 */  add.s $f8, $f4, $f2
/* 062580 80061980 E6080AD4 */  swc1  $f8, 0xad4($s0)
/* 062584 80061984 8FBF0034 */  lw    $ra, 0x34($sp)
/* 062588 80061988 8FB20030 */  lw    $s2, 0x30($sp)
/* 06258C 8006198C 8FB1002C */  lw    $s1, 0x2c($sp)
/* 062590 80061990 8FB00028 */  lw    $s0, 0x28($sp)
/* 062594 80061994 03E00008 */  jr    $ra
/* 062598 80061998 27BD0058 */   addiu $sp, $sp, 0x58
