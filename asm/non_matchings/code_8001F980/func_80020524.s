glabel func_80020524
/* 021124 80020524 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 021128 80020528 3C038016 */  lui   $v1, %hi(D_80164AC0) # $v1, 0x8016
/* 02112C 8002052C 84634AC0 */  lh    $v1, %lo(D_80164AC0)($v1)
/* 021130 80020530 3C028016 */  lui   $v0, %hi(D_80164AB0) # $v0, 0x8016
/* 021134 80020534 84424AB0 */  lh    $v0, %lo(D_80164AB0)($v0)
/* 021138 80020538 AFB3002C */  sw    $s3, 0x2c($sp)
/* 02113C 8002053C 3C138016 */  lui   $s3, %hi(D_801651D0) # $s3, 0x8016
/* 021140 80020540 267351D0 */  addiu $s3, %lo(D_801651D0) # addiu $s3, $s3, 0x51d0
/* 021144 80020544 0003C900 */  sll   $t9, $v1, 4
/* 021148 80020548 02794821 */  addu  $t1, $s3, $t9
/* 02114C 8002054C 00033600 */  sll   $a2, $v1, 0x18
/* 021150 80020550 00025040 */  sll   $t2, $v0, 1
/* 021154 80020554 AFBF0044 */  sw    $ra, 0x44($sp)
/* 021158 80020558 AFBE0040 */  sw    $fp, 0x40($sp)
/* 02115C 8002055C AFB7003C */  sw    $s7, 0x3c($sp)
/* 021160 80020560 AFB60038 */  sw    $s6, 0x38($sp)
/* 021164 80020564 AFB50034 */  sw    $s5, 0x34($sp)
/* 021168 80020568 AFB40030 */  sw    $s4, 0x30($sp)
/* 02116C 8002056C AFB20028 */  sw    $s2, 0x28($sp)
/* 021170 80020570 AFB10024 */  sw    $s1, 0x24($sp)
/* 021174 80020574 AFB00020 */  sw    $s0, 0x20($sp)
/* 021178 80020578 012A5821 */  addu  $t3, $t1, $t2
/* 02117C 8002057C 00067E03 */  sra   $t7, $a2, 0x18
/* 021180 80020580 856C0000 */  lh    $t4, ($t3)
/* 021184 80020584 000F3E00 */  sll   $a3, $t7, 0x18
/* 021188 80020588 00022E00 */  sll   $a1, $v0, 0x18
/* 02118C 8002058C 00057603 */  sra   $t6, $a1, 0x18
/* 021190 80020590 0007C603 */  sra   $t8, $a3, 0x18
/* 021194 80020594 3C048016 */  lui   $a0, %hi(D_80164AD0) # $a0, 0x8016
/* 021198 80020598 8C844AD0 */  lw    $a0, %lo(D_80164AD0)($a0)
/* 02119C 8002059C 03003825 */  move  $a3, $t8
/* 0211A0 800205A0 01C02825 */  move  $a1, $t6
/* 0211A4 800205A4 01E03025 */  move  $a2, $t7
/* 0211A8 800205A8 0C009D58 */  jal   func_80027560
/* 0211AC 800205AC AFAC0010 */   sw    $t4, 0x10($sp)
/* 0211B0 800205B0 3C04800E */  lui   $a0, %hi(D_800DC4FC) # $a0, 0x800e
/* 0211B4 800205B4 8C84C4FC */  lw    $a0, %lo(D_800DC4FC)($a0)
/* 0211B8 800205B8 00002825 */  move  $a1, $zero
/* 0211BC 800205BC 0C01B96B */  jal   func_8006E5AC
/* 0211C0 800205C0 00003025 */   move  $a2, $zero
/* 0211C4 800205C4 3C04800E */  lui   $a0, %hi(D_800DC4E0) # $a0, 0x800e
/* 0211C8 800205C8 8C84C4E0 */  lw    $a0, %lo(D_800DC4E0)($a0)
/* 0211CC 800205CC 24050001 */  li    $a1, 1
/* 0211D0 800205D0 0C01B96B */  jal   func_8006E5AC
/* 0211D4 800205D4 00003025 */   move  $a2, $zero
/* 0211D8 800205D8 3C04800E */  lui   $a0, %hi(D_800DC4E4) # $a0, 0x800e
/* 0211DC 800205DC 8C84C4E4 */  lw    $a0, %lo(D_800DC4E4)($a0)
/* 0211E0 800205E0 24050002 */  li    $a1, 2
/* 0211E4 800205E4 0C01B96B */  jal   func_8006E5AC
/* 0211E8 800205E8 00003025 */   move  $a2, $zero
/* 0211EC 800205EC 3C04800E */  lui   $a0, %hi(D_800DC4E8) # $a0, 0x800e
/* 0211F0 800205F0 8C84C4E8 */  lw    $a0, %lo(D_800DC4E8)($a0)
/* 0211F4 800205F4 24050003 */  li    $a1, 3
/* 0211F8 800205F8 0C01B96B */  jal   func_8006E5AC
/* 0211FC 800205FC 00003025 */   move  $a2, $zero
/* 021200 80020600 3C0D800E */  lui   $t5, %hi(D_800DC52C) # $t5, 0x800e
/* 021204 80020604 8DADC52C */  lw    $t5, %lo(D_800DC52C)($t5)
/* 021208 80020608 24010003 */  li    $at, 3
/* 02120C 8002060C 3C04800E */  lui   $a0, %hi(D_800DC4EC) # $a0, 0x800e
/* 021210 80020610 11A10013 */  beq   $t5, $at, .L80020660
/* 021214 80020614 24050004 */   li    $a1, 4
/* 021218 80020618 8C84C4EC */  lw    $a0, %lo(D_800DC4EC)($a0)
/* 02121C 8002061C 0C01B96B */  jal   func_8006E5AC
/* 021220 80020620 00003025 */   move  $a2, $zero
/* 021224 80020624 3C04800E */  lui   $a0, %hi(D_800DC4F0) # $a0, 0x800e
/* 021228 80020628 8C84C4F0 */  lw    $a0, %lo(D_800DC4F0)($a0)
/* 02122C 8002062C 24050005 */  li    $a1, 5
/* 021230 80020630 0C01B96B */  jal   func_8006E5AC
/* 021234 80020634 00003025 */   move  $a2, $zero
/* 021238 80020638 3C04800E */  lui   $a0, %hi(D_800DC4F4) # $a0, 0x800e
/* 02123C 8002063C 8C84C4F4 */  lw    $a0, %lo(D_800DC4F4)($a0)
/* 021240 80020640 24050006 */  li    $a1, 6
/* 021244 80020644 0C01B96B */  jal   func_8006E5AC
/* 021248 80020648 00003025 */   move  $a2, $zero
/* 02124C 8002064C 3C04800E */  lui   $a0, %hi(D_800DC4F8) # $a0, 0x800e
/* 021250 80020650 8C84C4F8 */  lw    $a0, %lo(D_800DC4F8)($a0)
/* 021254 80020654 24050007 */  li    $a1, 7
/* 021258 80020658 0C01B96B */  jal   func_8006E5AC
/* 02125C 8002065C 00003025 */   move  $a2, $zero
.L80020660:
/* 021260 80020660 3C148015 */  lui   $s4, %hi(gDmaMesgQueue) # $s4, 0x8015
/* 021264 80020664 3C158015 */  lui   $s5, %hi(gMainReceivedMesg) # $s5, 0x8015
/* 021268 80020668 26B5F098 */  addiu $s5, %lo(gMainReceivedMesg) # addiu $s5, $s5, -0xf68
/* 02126C 8002066C 2694EF58 */  addiu $s4, %lo(gDmaMesgQueue) # addiu $s4, $s4, -0x10a8
/* 021270 80020670 02802025 */  move  $a0, $s4
/* 021274 80020674 02A02825 */  move  $a1, $s5
/* 021278 80020678 0C0335D4 */  jal   osRecvMesg
/* 02127C 8002067C 24060001 */   li    $a2, 1
/* 021280 80020680 3C16800E */  lui   $s6, %hi(D_800DDB58) # $s6, 0x800e
/* 021284 80020684 26D6DB58 */  addiu $s6, %lo(D_800DDB58) # addiu $s6, $s6, -0x24a8
/* 021288 80020688 8EC20000 */  lw    $v0, ($s6)
/* 02128C 8002068C 24100001 */  li    $s0, 1
/* 021290 80020690 241E0920 */  li    $fp, 2336
/* 021294 80020694 28410002 */  slti  $at, $v0, 2
/* 021298 80020698 14200049 */  bnez  $at, .L800207C0
/* 02129C 8002069C 3C17802E */   lui   $s7, %hi(D_802DFB80) # $s7, 0x802e
/* 0212A0 800206A0 26F7FB80 */  addiu $s7, %lo(D_802DFB80) # addiu $s7, $s7, -0x480
.L800206A4:
/* 0212A4 800206A4 3C198016 */  lui   $t9, %hi(D_80164AC0) # $t9, 0x8016
/* 0212A8 800206A8 27394AC0 */  addiu $t9, %lo(D_80164AC0) # addiu $t9, $t9, 0x4ac0
/* 0212AC 800206AC 00101040 */  sll   $v0, $s0, 1
/* 0212B0 800206B0 3C0F8016 */  lui   $t7, %hi(D_80164AB0) # $t7, 0x8016
/* 0212B4 800206B4 25EF4AB0 */  addiu $t7, %lo(D_80164AB0) # addiu $t7, $t7, 0x4ab0
/* 0212B8 800206B8 00599021 */  addu  $s2, $v0, $t9
/* 0212BC 800206BC 86480000 */  lh    $t0, ($s2)
/* 0212C0 800206C0 004F8821 */  addu  $s1, $v0, $t7
/* 0212C4 800206C4 86230000 */  lh    $v1, ($s1)
/* 0212C8 800206C8 00107080 */  sll   $t6, $s0, 2
/* 0212CC 800206CC 3C048016 */  lui   $a0, %hi(D_80164AD0) # 0x8016
/* 0212D0 800206D0 00085900 */  sll   $t3, $t0, 4
/* 0212D4 800206D4 026B6021 */  addu  $t4, $s3, $t3
/* 0212D8 800206D8 008E2021 */  addu  $a0, $a0, $t6
/* 0212DC 800206DC 00083600 */  sll   $a2, $t0, 0x18
/* 0212E0 800206E0 00036840 */  sll   $t5, $v1, 1
/* 0212E4 800206E4 018D7021 */  addu  $t6, $t4, $t5
/* 0212E8 800206E8 00064E03 */  sra   $t1, $a2, 0x18
/* 0212EC 800206EC 85CF0000 */  lh    $t7, ($t6)
/* 0212F0 800206F0 00093E00 */  sll   $a3, $t1, 0x18
/* 0212F4 800206F4 00032E00 */  sll   $a1, $v1, 0x18
/* 0212F8 800206F8 0005C603 */  sra   $t8, $a1, 0x18
/* 0212FC 800206FC 00075603 */  sra   $t2, $a3, 0x18
/* 021300 80020700 01403825 */  move  $a3, $t2
/* 021304 80020704 03002825 */  move  $a1, $t8
/* 021308 80020708 01203025 */  move  $a2, $t1
/* 02130C 8002070C 8C844AD0 */  lw    $a0, %lo(D_80164AD0)($a0) # 0x4ad0
/* 021310 80020710 0C009D58 */  jal   func_80027560
/* 021314 80020714 AFAF0010 */   sw    $t7, 0x10($sp)
/* 021318 80020718 8642FFFE */  lh    $v0, -2($s2)
/* 02131C 8002071C 8623FFFE */  lh    $v1, -2($s1)
/* 021320 80020720 0002C100 */  sll   $t8, $v0, 4
/* 021324 80020724 0278C821 */  addu  $t9, $s3, $t8
/* 021328 80020728 00034840 */  sll   $t1, $v1, 1
/* 02132C 8002072C 03295021 */  addu  $t2, $t9, $t1
/* 021330 80020730 85460000 */  lh    $a2, ($t2)
/* 021334 80020734 007E0019 */  multu $v1, $fp
/* 021338 80020738 000268C0 */  sll   $t5, $v0, 3
/* 02133C 8002073C 000658C0 */  sll   $t3, $a2, 3
/* 021340 80020740 01665821 */  addu  $t3, $t3, $a2
/* 021344 80020744 000B58C0 */  sll   $t3, $t3, 3
/* 021348 80020748 01A26821 */  addu  $t5, $t5, $v0
/* 02134C 8002074C 000D68C0 */  sll   $t5, $t5, 3
/* 021350 80020750 01665821 */  addu  $t3, $t3, $a2
/* 021354 80020754 000B5A40 */  sll   $t3, $t3, 9
/* 021358 80020758 01A26821 */  addu  $t5, $t5, $v0
/* 02135C 8002075C 000D6A00 */  sll   $t5, $t5, 8
/* 021360 80020760 02EB6021 */  addu  $t4, $s7, $t3
/* 021364 80020764 018D7021 */  addu  $t6, $t4, $t5
/* 021368 80020768 0002CBC0 */  sll   $t9, $v0, 0xf
/* 02136C 8002076C 0006C400 */  sll   $t8, $a2, 0x10
/* 021370 80020770 03194821 */  addu  $t1, $t8, $t9
/* 021374 80020774 3C0C802C */  lui   $t4, %hi(D_802BFB80) # $t4, 0x802c
/* 021378 80020778 00035300 */  sll   $t2, $v1, 0xc
/* 02137C 8002077C 012A5821 */  addu  $t3, $t1, $t2
/* 021380 80020780 258CFB80 */  addiu $t4, %lo(D_802BFB80) # addiu $t4, $t4, -0x480
/* 021384 80020784 00007812 */  mflo  $t7
/* 021388 80020788 01CF2021 */  addu  $a0, $t6, $t7
/* 02138C 8002078C 0C010034 */  jal   mio0decode
/* 021390 80020790 016C2821 */   addu  $a1, $t3, $t4
/* 021394 80020794 02802025 */  move  $a0, $s4
/* 021398 80020798 02A02825 */  move  $a1, $s5
/* 02139C 8002079C 0C0335D4 */  jal   osRecvMesg
/* 0213A0 800207A0 24060001 */   li    $a2, 1
/* 0213A4 800207A4 8EC20000 */  lw    $v0, ($s6)
/* 0213A8 800207A8 26100001 */  addiu $s0, $s0, 1
/* 0213AC 800207AC 00106C00 */  sll   $t5, $s0, 0x10
/* 0213B0 800207B0 000D8403 */  sra   $s0, $t5, 0x10
/* 0213B4 800207B4 0202082A */  slt   $at, $s0, $v0
/* 0213B8 800207B8 1420FFBA */  bnez  $at, .L800206A4
/* 0213BC 800207BC 00000000 */   nop   
.L800207C0:
/* 0213C0 800207C0 00023840 */  sll   $a3, $v0, 1
/* 0213C4 800207C4 3C038016 */  lui   $v1, %hi(D_80164ABE) # 0x8016
/* 0213C8 800207C8 00671821 */  addu  $v1, $v1, $a3
/* 0213CC 800207CC 3C068016 */  lui   $a2, %hi(D_80164AAE) # 0x8016
/* 0213D0 800207D0 84634ABE */  lh    $v1, %lo(D_80164ABE)($v1) # 0x4abe
/* 0213D4 800207D4 00C73021 */  addu  $a2, $a2, $a3
/* 0213D8 800207D8 84C64AAE */  lh    $a2, %lo(D_80164AAE)($a2) # 0x4aae($a2)
/* 0213DC 800207DC 00037900 */  sll   $t7, $v1, 4
/* 0213E0 800207E0 026FC021 */  addu  $t8, $s3, $t7
/* 0213E4 800207E4 0006C840 */  sll   $t9, $a2, 1
/* 0213E8 800207E8 03194821 */  addu  $t1, $t8, $t9
/* 0213EC 800207EC 85280000 */  lh    $t0, ($t1)
/* 0213F0 800207F0 241E0920 */  li    $fp, 2336
/* 0213F4 800207F4 00DE0019 */  multu $a2, $fp
/* 0213F8 800207F8 000850C0 */  sll   $t2, $t0, 3
/* 0213FC 800207FC 000360C0 */  sll   $t4, $v1, 3
/* 021400 80020800 01485021 */  addu  $t2, $t2, $t0
/* 021404 80020804 000A50C0 */  sll   $t2, $t2, 3
/* 021408 80020808 01836021 */  addu  $t4, $t4, $v1
/* 02140C 8002080C 3C17802E */  lui   $s7, %hi(D_802DFB80) # $s7, 0x802e
/* 021410 80020810 000C60C0 */  sll   $t4, $t4, 3
/* 021414 80020814 01485021 */  addu  $t2, $t2, $t0
/* 021418 80020818 26F7FB80 */  addiu $s7, %lo(D_802DFB80) # addiu $s7, $s7, -0x480
/* 02141C 8002081C 000A5240 */  sll   $t2, $t2, 9
/* 021420 80020820 01836021 */  addu  $t4, $t4, $v1
/* 021424 80020824 000C6200 */  sll   $t4, $t4, 8
/* 021428 80020828 02EA5821 */  addu  $t3, $s7, $t2
/* 02142C 8002082C 016C6821 */  addu  $t5, $t3, $t4
/* 021430 80020830 0003C3C0 */  sll   $t8, $v1, 0xf
/* 021434 80020834 00087C00 */  sll   $t7, $t0, 0x10
/* 021438 80020838 01F8C821 */  addu  $t9, $t7, $t8
/* 02143C 8002083C 3C0B802C */  lui   $t3, %hi(D_802BFB80) # $t3, 0x802c
/* 021440 80020840 00064B00 */  sll   $t1, $a2, 0xc
/* 021444 80020844 03295021 */  addu  $t2, $t9, $t1
/* 021448 80020848 256BFB80 */  addiu $t3, %lo(D_802BFB80) # addiu $t3, $t3, -0x480
/* 02144C 8002084C 00007012 */  mflo  $t6
/* 021450 80020850 01AE2021 */  addu  $a0, $t5, $t6
/* 021454 80020854 0C010034 */  jal   mio0decode
/* 021458 80020858 014B2821 */   addu  $a1, $t2, $t3
/* 02145C 8002085C 8FBF0044 */  lw    $ra, 0x44($sp)
/* 021460 80020860 8FB00020 */  lw    $s0, 0x20($sp)
/* 021464 80020864 8FB10024 */  lw    $s1, 0x24($sp)
/* 021468 80020868 8FB20028 */  lw    $s2, 0x28($sp)
/* 02146C 8002086C 8FB3002C */  lw    $s3, 0x2c($sp)
/* 021470 80020870 8FB40030 */  lw    $s4, 0x30($sp)
/* 021474 80020874 8FB50034 */  lw    $s5, 0x34($sp)
/* 021478 80020878 8FB60038 */  lw    $s6, 0x38($sp)
/* 02147C 8002087C 8FB7003C */  lw    $s7, 0x3c($sp)
/* 021480 80020880 8FBE0040 */  lw    $fp, 0x40($sp)
/* 021484 80020884 03E00008 */  jr    $ra
/* 021488 80020888 27BD0048 */   addiu $sp, $sp, 0x48
