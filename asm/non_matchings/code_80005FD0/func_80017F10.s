glabel func_80017F10
/* 018B10 80017F10 00077400 */  sll   $t6, $a3, 0x10
/* 018B14 80017F14 000E7C03 */  sra   $t7, $t6, 0x10
/* 018B18 80017F18 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 018B1C 80017F1C 000FC040 */  sll   $t8, $t7, 1
/* 018B20 80017F20 AFA70034 */  sw    $a3, 0x34($sp)
/* 018B24 80017F24 3C028016 */  lui   $v0, %hi(D_801645C8) # 0x8016
/* 018B28 80017F28 01E03825 */  move  $a3, $t7
/* 018B2C 80017F2C 00581021 */  addu  $v0, $v0, $t8
/* 018B30 80017F30 00045080 */  sll   $t2, $a0, 2
/* 018B34 80017F34 3C018016 */  lui   $at, %hi(D_80163068)
/* 018B38 80017F38 3C188016 */  lui   $t8, %hi(D_80164438) # 0x8016
/* 018B3C 80017F3C 00047840 */  sll   $t7, $a0, 1
/* 018B40 80017F40 002A0821 */  addu  $at, $at, $t2
/* 018B44 80017F44 030FC021 */  addu  $t8, $t8, $t7
/* 018B48 80017F48 944245C8 */  lhu   $v0, %lo(D_801645C8)($v0) # 0x45c8($v0)
/* 018B4C 80017F4C C4203068 */  lwc1  $f0, %lo(D_80163068)($at)
/* 018B50 80017F50 97184438 */  lhu   $t8, %lo(D_80164438)($t8) # 0x4438($t8)
/* 018B54 80017F54 0006C880 */  sll   $t9, $a2, 2
/* 018B58 80017F58 3C018016 */  lui   $at, %hi(D_80164688)
/* 018B5C 80017F5C 00390821 */  addu  $at, $at, $t9
/* 018B60 80017F60 03201825 */  move  $v1, $t9
/* 018B64 80017F64 3C0D8016 */  lui   $t5, %hi(D_80164668) # $t5, 0x8016
/* 018B68 80017F68 25AD4668 */  addiu $t5, %lo(D_80164668) # addiu $t5, $t5, 0x4668
/* 018B6C 80017F6C 00066040 */  sll   $t4, $a2, 1
/* 018B70 80017F70 0302C821 */  addu  $t9, $t8, $v0
/* 018B74 80017F74 2729FFFE */  addiu $t1, $t9, -2
/* 018B78 80017F78 018D4021 */  addu  $t0, $t4, $t5
/* 018B7C 80017F7C E4204688 */  swc1  $f0, %lo(D_80164688)($at)
/* 018B80 80017F80 A5090000 */  sh    $t1, ($t0)
/* 018B84 80017F84 850A0000 */  lh    $t2, ($t0)
/* 018B88 80017F88 00C05825 */  move  $t3, $a2
/* 018B8C 80017F8C AFA60030 */  sw    $a2, 0x30($sp)
/* 018B90 80017F90 0142001A */  div   $zero, $t2, $v0
/* 018B94 80017F94 AFA5002C */  sw    $a1, 0x2c($sp)
/* 018B98 80017F98 00005810 */  mfhi  $t3
/* 018B9C 80017F9C 00073400 */  sll   $a2, $a3, 0x10
/* 018BA0 80017FA0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 018BA4 80017FA4 AFA40028 */  sw    $a0, 0x28($sp)
/* 018BA8 80017FA8 00807025 */  move  $t6, $a0
/* 018BAC 80017FAC 00066403 */  sra   $t4, $a2, 0x10
/* 018BB0 80017FB0 44050000 */  mfc1  $a1, $f0
/* 018BB4 80017FB4 14400002 */  bnez  $v0, .L80017FC0
/* 018BB8 80017FB8 00000000 */   nop   
/* 018BBC 80017FBC 0007000D */  break 7
.L80017FC0:
/* 018BC0 80017FC0 2401FFFF */  li    $at, -1
/* 018BC4 80017FC4 14410004 */  bne   $v0, $at, .L80017FD8
/* 018BC8 80017FC8 3C018000 */   lui   $at, 0x8000
/* 018BCC 80017FCC 15410002 */  bne   $t2, $at, .L80017FD8
/* 018BD0 80017FD0 00000000 */   nop   
/* 018BD4 80017FD4 0006000D */  break 6
.L80017FD8:
/* 018BD8 80017FD8 A50B0000 */  sh    $t3, ($t0)
/* 018BDC 80017FDC 01803025 */  move  $a2, $t4
/* 018BE0 80017FE0 3164FFFF */  andi  $a0, $t3, 0xffff
/* 018BE4 80017FE4 AFA80018 */  sw    $t0, 0x18($sp)
/* 018BE8 80017FE8 AFA3001C */  sw    $v1, 0x1c($sp)
/* 018BEC 80017FEC 0C002EF6 */  jal   func_8000BBD8
/* 018BF0 80017FF0 A7A70036 */   sh    $a3, 0x36($sp)
/* 018BF4 80017FF4 3C068016 */  lui   $a2, %hi(D_80162FA0) # $a2, 0x8016
/* 018BF8 80017FF8 8FA3001C */  lw    $v1, 0x1c($sp)
/* 018BFC 80017FFC 24C62FA0 */  addiu $a2, %lo(D_80162FA0) # addiu $a2, $a2, 0x2fa0
/* 018C00 80018000 87A70036 */  lh    $a3, 0x36($sp)
/* 018C04 80018004 C4C00000 */  lwc1  $f0, ($a2)
/* 018C08 80018008 8FA80018 */  lw    $t0, 0x18($sp)
/* 018C0C 8001800C 3C018016 */  lui   $at, %hi(D_801645F8)
/* 018C10 80018010 00230821 */  addu  $at, $at, $v1
/* 018C14 80018014 3C0F8016 */  lui   $t7, %hi(D_80164550) # 0x8016
/* 018C18 80018018 00077080 */  sll   $t6, $a3, 2
/* 018C1C 8001801C E42045F8 */  swc1  $f0, %lo(D_801645F8)($at)
/* 018C20 80018020 85180000 */  lh    $t8, ($t0)
/* 018C24 80018024 01EE7821 */  addu  $t7, $t7, $t6
/* 018C28 80018028 8DEF4550 */  lw    $t7, %lo(D_80164550)($t7) # 0x4550($t7)
/* 018C2C 8001802C 0018C8C0 */  sll   $t9, $t8, 3
/* 018C30 80018030 8FAC0028 */  lw    $t4, 0x28($sp)
/* 018C34 80018034 01F94821 */  addu  $t1, $t7, $t9
/* 018C38 80018038 852A0002 */  lh    $t2, 2($t1)
/* 018C3C 8001803C 3C0D8016 */  lui   $t5, %hi(D_80164618) # $t5, 0x8016
/* 018C40 80018040 25AD4618 */  addiu $t5, %lo(D_80164618) # addiu $t5, $t5, 0x4618
/* 018C44 80018044 448A2000 */  mtc1  $t2, $f4
/* 018C48 80018048 006D2021 */  addu  $a0, $v1, $t5
/* 018C4C 8001804C 000C68C0 */  sll   $t5, $t4, 3
/* 018C50 80018050 468021A0 */  cvt.s.w $f6, $f4
/* 018C54 80018054 01AC6823 */  subu  $t5, $t5, $t4
/* 018C58 80018058 000D6900 */  sll   $t5, $t5, 4
/* 018C5C 8001805C 01AC6823 */  subu  $t5, $t5, $t4
/* 018C60 80018060 C4C80008 */  lwc1  $f8, 8($a2)
/* 018C64 80018064 3C0B8016 */  lui   $t3, %hi(D_80164638) # $t3, 0x8016
/* 018C68 80018068 000D6880 */  sll   $t5, $t5, 2
/* 018C6C 8001806C 256B4638 */  addiu $t3, %lo(D_80164638) # addiu $t3, $t3, 0x4638
/* 018C70 80018070 01AC6823 */  subu  $t5, $t5, $t4
/* 018C74 80018074 000D68C0 */  sll   $t5, $t5, 3
/* 018C78 80018078 3C01800F */  lui   $at, %hi(gPlayers+0x94)
/* 018C7C 8001807C 006B2821 */  addu  $a1, $v1, $t3
/* 018C80 80018080 8FAE0030 */  lw    $t6, 0x30($sp)
/* 018C84 80018084 E4860000 */  swc1  $f6, ($a0)
/* 018C88 80018088 002D0821 */  addu  $at, $at, $t5
/* 018C8C 8001808C E4A80000 */  swc1  $f8, ($a1)
/* 018C90 80018090 C4226A24 */  lwc1  $f2, %lo(gPlayers+0x94)($at)
/* 018C94 80018094 3C018016 */  lui   $at, %hi(D_80164658)
/* 018C98 80018098 000EC080 */  sll   $t8, $t6, 2
/* 018C9C 8001809C 00230821 */  addu  $at, $at, $v1
/* 018CA0 800180A0 030EC023 */  subu  $t8, $t8, $t6
/* 018CA4 800180A4 0018C0C0 */  sll   $t8, $t8, 3
/* 018CA8 800180A8 E4224658 */  swc1  $f2, %lo(D_80164658)($at)
/* 018CAC 800180AC 3C018016 */  lui   $at, %hi(D_80164648)
/* 018CB0 800180B0 3C0F8016 */  lui   $t7, %hi(cameras) # $t7, 0x8016
/* 018CB4 800180B4 030EC023 */  subu  $t8, $t8, $t6
/* 018CB8 800180B8 0018C0C0 */  sll   $t8, $t8, 3
/* 018CBC 800180BC 25EF46F0 */  addiu $t7, %lo(cameras) # addiu $t7, $t7, 0x46f0
/* 018CC0 800180C0 00230821 */  addu  $at, $at, $v1
/* 018CC4 800180C4 030F1021 */  addu  $v0, $t8, $t7
/* 018CC8 800180C8 E4224648 */  swc1  $f2, %lo(D_80164648)($at)
/* 018CCC 800180CC E4400000 */  swc1  $f0, ($v0)
/* 018CD0 800180D0 C48A0000 */  lwc1  $f10, ($a0)
/* 018CD4 800180D4 E44A0004 */  swc1  $f10, 4($v0)
/* 018CD8 800180D8 C4B00000 */  lwc1  $f16, ($a1)
/* 018CDC 800180DC E4500008 */  swc1  $f16, 8($v0)
/* 018CE0 800180E0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 018CE4 800180E4 27BD0028 */  addiu $sp, $sp, 0x28
/* 018CE8 800180E8 03E00008 */  jr    $ra
/* 018CEC 800180EC 00000000 */   nop   
