glabel func_800C5578
/* 0C6178 800C5578 27BDFF68 */  addiu $sp, $sp, -0x98
/* 0C617C 800C557C 3C01F000 */  lui   $at, 0xf000
/* 0C6180 800C5580 00A17024 */  and   $t6, $a1, $at
/* 0C6184 800C5584 000E7F02 */  srl   $t7, $t6, 0x1c
/* 0C6188 800C5588 31F800FF */  andi  $t8, $t7, 0xff
/* 0C618C 800C558C 0018C900 */  sll   $t9, $t8, 4
/* 0C6190 800C5590 0338C823 */  subu  $t9, $t9, $t8
/* 0C6194 800C5594 3C088019 */  lui   $t0, %hi(sSoundBanks) # $t0, 0x8019
/* 0C6198 800C5598 25081420 */  addiu $t0, %lo(sSoundBanks) # addiu $t0, $t0, 0x1420
/* 0C619C 800C559C 0019C980 */  sll   $t9, $t9, 6
/* 0C61A0 800C55A0 AFBF004C */  sw    $ra, 0x4c($sp)
/* 0C61A4 800C55A4 AFBE0048 */  sw    $fp, 0x48($sp)
/* 0C61A8 800C55A8 AFB70044 */  sw    $s7, 0x44($sp)
/* 0C61AC 800C55AC AFB60040 */  sw    $s6, 0x40($sp)
/* 0C61B0 800C55B0 AFB5003C */  sw    $s5, 0x3c($sp)
/* 0C61B4 800C55B4 AFB40038 */  sw    $s4, 0x38($sp)
/* 0C61B8 800C55B8 AFB30034 */  sw    $s3, 0x34($sp)
/* 0C61BC 800C55BC AFB20030 */  sw    $s2, 0x30($sp)
/* 0C61C0 800C55C0 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0C61C4 800C55C4 AFB00028 */  sw    $s0, 0x28($sp)
/* 0C61C8 800C55C8 AFA40098 */  sw    $a0, 0x98($sp)
/* 0C61CC 800C55CC AFA5009C */  sw    $a1, 0x9c($sp)
/* 0C61D0 800C55D0 03284821 */  addu  $t1, $t9, $t0
/* 0C61D4 800C55D4 9131002B */  lbu   $s1, 0x2b($t1)
/* 0C61D8 800C55D8 241500FF */  li    $s5, 255
/* 0C61DC 800C55DC 03A0F025 */  move  $fp, $sp
/* 0C61E0 800C55E0 0300B025 */  move  $s6, $t8
/* 0C61E4 800C55E4 00009825 */  move  $s3, $zero
/* 0C61E8 800C55E8 12B1002D */  beq   $s5, $s1, .L800C56A0
/* 0C61EC 800C55EC 02201025 */   move  $v0, $s1
/* 0C61F0 800C55F0 00185100 */  sll   $t2, $t8, 4
/* 0C61F4 800C55F4 01585023 */  subu  $t2, $t2, $t8
/* 0C61F8 800C55F8 000A5180 */  sll   $t2, $t2, 6
/* 0C61FC 800C55FC 0148A021 */  addu  $s4, $t2, $t0
/* 0C6200 800C5600 3C170602 */  lui   $s7, 0x602
/* 0C6204 800C5604 24120030 */  li    $s2, 48
.L800C5608:
/* 0C6208 800C5608 02320019 */  multu $s1, $s2
/* 0C620C 800C560C 8FCC0098 */  lw    $t4, 0x98($fp)
/* 0C6210 800C5610 00005812 */  mflo  $t3
/* 0C6214 800C5614 028B8021 */  addu  $s0, $s4, $t3
/* 0C6218 800C5618 8E0D0000 */  lw    $t5, ($s0)
/* 0C621C 800C561C 558D0017 */  bnel  $t4, $t5, .L800C567C
/* 0C6220 800C5620 323300FF */   andi  $s3, $s1, 0xff
/* 0C6224 800C5624 8FCE009C */  lw    $t6, 0x9c($fp)
/* 0C6228 800C5628 8E0F0024 */  lw    $t7, 0x24($s0)
/* 0C622C 800C562C 55CF0013 */  bnel  $t6, $t7, .L800C567C
/* 0C6230 800C5630 323300FF */   andi  $s3, $s1, 0xff
/* 0C6234 800C5634 92020028 */  lbu   $v0, 0x28($s0)
/* 0C6238 800C5638 28410003 */  slti  $at, $v0, 3
/* 0C623C 800C563C 14200007 */  bnez  $at, .L800C565C
/* 0C6240 800C5640 00000000 */   nop   
/* 0C6244 800C5644 9219002C */  lbu   $t9, 0x2c($s0)
/* 0C6248 800C5648 00002825 */  move  $a1, $zero
/* 0C624C 800C564C 00194A00 */  sll   $t1, $t9, 8
/* 0C6250 800C5650 0C032EFA */  jal   func_800CBBE8
/* 0C6254 800C5654 01372025 */   or    $a0, $t1, $s7
/* 0C6258 800C5658 92020028 */  lbu   $v0, 0x28($s0)
.L800C565C:
/* 0C625C 800C565C 10400003 */  beqz  $v0, .L800C566C
/* 0C6260 800C5660 32C400FF */   andi  $a0, $s6, 0xff
/* 0C6264 800C5664 0C0311CF */  jal   delete_sound_from_bank
/* 0C6268 800C5668 322500FF */   andi  $a1, $s1, 0xff
.L800C566C:
/* 0C626C 800C566C 241100FF */  li    $s1, 255
/* 0C6270 800C5670 10000002 */  b     .L800C567C
/* 0C6274 800C5674 240200FF */   li    $v0, 255
/* 0C6278 800C5678 323300FF */  andi  $s3, $s1, 0xff
.L800C567C:
/* 0C627C 800C567C 12A20006 */  beq   $s5, $v0, .L800C5698
/* 0C6280 800C5680 00000000 */   nop   
/* 0C6284 800C5684 02720019 */  multu $s3, $s2
/* 0C6288 800C5688 00005012 */  mflo  $t2
/* 0C628C 800C568C 028A4021 */  addu  $t0, $s4, $t2
/* 0C6290 800C5690 9111002B */  lbu   $s1, 0x2b($t0)
/* 0C6294 800C5694 02201025 */  move  $v0, $s1
.L800C5698:
/* 0C6298 800C5698 16A2FFDB */  bne   $s5, $v0, .L800C5608
/* 0C629C 800C569C 00000000 */   nop   
.L800C56A0:
/* 0C62A0 800C56A0 8FCB0098 */  lw    $t3, 0x98($fp)
/* 0C62A4 800C56A4 8FCC009C */  lw    $t4, 0x9c($fp)
/* 0C62A8 800C56A8 24040003 */  li    $a0, 3
/* 0C62AC 800C56AC 27C50060 */  addiu $a1, $fp, 0x60
/* 0C62B0 800C56B0 AFCB0060 */  sw    $t3, 0x60($fp)
/* 0C62B4 800C56B4 0C031073 */  jal   func_800C41CC
/* 0C62B8 800C56B8 AFCC0084 */   sw    $t4, 0x84($fp)
/* 0C62BC 800C56BC 8FDF004C */  lw    $ra, 0x4c($fp)
/* 0C62C0 800C56C0 03C0E825 */  move  $sp, $fp
/* 0C62C4 800C56C4 8FD00028 */  lw    $s0, 0x28($fp)
/* 0C62C8 800C56C8 8FD1002C */  lw    $s1, 0x2c($fp)
/* 0C62CC 800C56CC 8FD20030 */  lw    $s2, 0x30($fp)
/* 0C62D0 800C56D0 8FD30034 */  lw    $s3, 0x34($fp)
/* 0C62D4 800C56D4 8FD40038 */  lw    $s4, 0x38($fp)
/* 0C62D8 800C56D8 8FD5003C */  lw    $s5, 0x3c($fp)
/* 0C62DC 800C56DC 8FD60040 */  lw    $s6, 0x40($fp)
/* 0C62E0 800C56E0 8FD70044 */  lw    $s7, 0x44($fp)
/* 0C62E4 800C56E4 8FDE0048 */  lw    $fp, 0x48($fp)
/* 0C62E8 800C56E8 03E00008 */  jr    $ra
/* 0C62EC 800C56EC 27BD0098 */   addiu $sp, $sp, 0x98
