.section .late_rodata

glabel D_800EF2C8
.float 0.2
.word 0x00000000

glabel D_800EF2D0
.double -383.0

.section .text

glabel func_80084430
/* 085030 80084430 000470C0 */  sll   $t6, $a0, 3
/* 085034 80084434 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 085038 80084438 01C47023 */  subu  $t6, $t6, $a0
/* 08503C 8008443C 3C0F8016 */  lui   $t7, %hi(gObjectList) # $t7, 0x8016
/* 085040 80084440 AFB00014 */  sw    $s0, 0x14($sp)
/* 085044 80084444 25EF5C18 */  addiu $t7, %lo(gObjectList) # addiu $t7, $t7, 0x5c18
/* 085048 80084448 000E7140 */  sll   $t6, $t6, 5
/* 08504C 8008444C 01CF8021 */  addu  $s0, $t6, $t7
/* 085050 80084450 3C180601 */  lui   $t8, %hi(d_course_sherbet_land_unk_data1) # $t8, 0x601
/* 085054 80084454 3C190601 */  lui   $t9, %hi(d_course_sherbet_land_unk_data11) # $t9, 0x601
/* 085058 80084458 27188EB0 */  addiu $t8, %lo(d_course_sherbet_land_unk_data1) # addiu $t8, $t8, -0x7150
/* 08505C 8008445C 27399AC8 */  addiu $t9, %lo(d_course_sherbet_land_unk_data11) # addiu $t9, $t9, -0x6538
/* 085060 80084460 A20000D8 */  sb    $zero, 0xd8($s0)
/* 085064 80084464 AE180070 */  sw    $t8, 0x70($s0)
/* 085068 80084468 AE190074 */  sw    $t9, 0x74($s0)
/* 08506C 8008446C 3C01800F */  lui   $at, %hi(D_800EF2C8) # $at, 0x800f
/* 085070 80084470 C424F2C8 */  lwc1  $f4, %lo(D_800EF2C8)($at)
/* 085074 80084474 2408000C */  li    $t0, 12
/* 085078 80084478 24090001 */  li    $t1, 1
/* 08507C 8008447C A60800C8 */  sh    $t0, 0xc8($s0)
/* 085080 80084480 A609009C */  sh    $t1, 0x9c($s0)
/* 085084 80084484 3C018019 */  lui   $at, %hi(D_8018D01C) # $at, 0x8019
/* 085088 80084488 E6040000 */  swc1  $f4, ($s0)
/* 08508C 8008448C C426D01C */  lwc1  $f6, %lo(D_8018D01C)($at)
/* 085090 80084490 3C01800F */  lui   $at, %hi(D_800EF2D0)
/* 085094 80084494 D42AF2D0 */  ldc1  $f10, %lo(D_800EF2D0)($at)
/* 085098 80084498 46003221 */  cvt.d.s $f8, $f6
/* 08509C 8008449C AFA50024 */  sw    $a1, 0x24($sp)
/* 0850A0 800844A0 462A4402 */  mul.d $f16, $f8, $f10
/* 0850A4 800844A4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0850A8 800844A8 AFB10018 */  sw    $s1, 0x18($sp)
/* 0850AC 800844AC 3C07C42C */  lui   $a3, (0xC42C8000 >> 16) # lui $a3, 0xc42c
/* 0850B0 800844B0 00808825 */  move  $s1, $a0
/* 0850B4 800844B4 34E78000 */  ori   $a3, (0xC42C8000 & 0xFFFF) # ori $a3, $a3, 0x8000
/* 0850B8 800844B8 3C064000 */  lui   $a2, 0x4000
/* 0850BC 800844BC 462084A0 */  cvt.s.d $f18, $f16
/* 0850C0 800844C0 44059000 */  mfc1  $a1, $f18
/* 0850C4 800844C4 0C022DF5 */  jal   func_8008B7D4
/* 0850C8 800844C8 00000000 */   nop   
/* 0850CC 800844CC 02202025 */  move  $a0, $s1
/* 0850D0 800844D0 00002825 */  move  $a1, $zero
/* 0850D4 800844D4 00003025 */  move  $a2, $zero
/* 0850D8 800844D8 0C022E22 */  jal   func_8008B888
/* 0850DC 800844DC 00003825 */   move  $a3, $zero
/* 0850E0 800844E0 240A0001 */  li    $t2, 1
/* 0850E4 800844E4 A20A00DD */  sb    $t2, 0xdd($s0)
/* 0850E8 800844E8 0C021BBC */  jal   func_80086EF0
/* 0850EC 800844EC 02202025 */   move  $a0, $s1
/* 0850F0 800844F0 3C0B800E */  lui   $t3, %hi(D_800E672C) # $t3, 0x800e
/* 0850F4 800844F4 8D6B672C */  lw    $t3, %lo(D_800E672C)($t3)
/* 0850F8 800844F8 3C050400 */  lui   $a1, (0x04000800 >> 16) # lui $a1, 0x400
/* 0850FC 800844FC 34A50800 */  ori   $a1, (0x04000800 & 0xFFFF) # ori $a1, $a1, 0x800
/* 085100 80084500 02202025 */  move  $a0, $s1
/* 085104 80084504 0C01C870 */  jal   set_object_flag_unk_054_true
/* 085108 80084508 AE0B0080 */   sw    $t3, 0x80($s0)
/* 08510C 8008450C 3C040601 */  lui   $a0, %hi(d_course_sherbet_land_unk_data11) # $a0, 0x601
/* 085110 80084510 24849AC8 */  addiu $a0, %lo(d_course_sherbet_land_unk_data11) # addiu $a0, $a0, -0x6538
/* 085114 80084514 0C0013AB */  jal   func_80004EAC
/* 085118 80084518 00002825 */   move  $a1, $zero
/* 08511C 8008451C A60200A4 */  sh    $v0, 0xa4($s0)
/* 085120 80084520 0C01C922 */  jal   func_80072488
/* 085124 80084524 02202025 */   move  $a0, $s1
/* 085128 80084528 8FBF001C */  lw    $ra, 0x1c($sp)
/* 08512C 8008452C 8FB00014 */  lw    $s0, 0x14($sp)
/* 085130 80084530 8FB10018 */  lw    $s1, 0x18($sp)
/* 085134 80084534 03E00008 */  jr    $ra
/* 085138 80084538 27BD0020 */   addiu $sp, $sp, 0x20
