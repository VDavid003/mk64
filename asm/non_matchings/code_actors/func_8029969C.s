glabel func_8029969C
/* 102CAC 8029969C 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 102CB0 802996A0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 102CB4 802996A4 AFB00020 */  sw    $s0, 0x20($sp)
/* 102CB8 802996A8 AFA50054 */  sw    $a1, 0x54($sp)
/* 102CBC 802996AC 84C20002 */  lh    $v0, 2($a2)
/* 102CC0 802996B0 00C08025 */  move  $s0, $a2
/* 102CC4 802996B4 24C50018 */  addiu $a1, $a2, 0x18
/* 102CC8 802996B8 304E0800 */  andi  $t6, $v0, 0x800
/* 102CCC 802996BC 15C00064 */  bnez  $t6, .L80299850
/* 102CD0 802996C0 24070000 */   li    $a3, 0
/* 102CD4 802996C4 3C0F800E */  lui   $t7, %hi(camera1) # $t7, 0x800e
/* 102CD8 802996C8 8DEFDB40 */  lw    $t7, %lo(camera1)($t7)
/* 102CDC 802996CC 240100B8 */  li    $at, 184
/* 102CE0 802996D0 94860026 */  lhu   $a2, 0x26($a0)
/* 102CE4 802996D4 008FC023 */  subu  $t8, $a0, $t7
/* 102CE8 802996D8 0301001A */  div   $zero, $t8, $at
/* 102CEC 802996DC 0000C812 */  mflo  $t9
/* 102CF0 802996E0 00195880 */  sll   $t3, $t9, 2
/* 102CF4 802996E4 3C018015 */  lui   $at, %hi(D_80150130)
/* 102CF8 802996E8 002B0821 */  addu  $at, $at, $t3
/* 102CFC 802996EC C4240130 */  lwc1  $f4, %lo(D_80150130)($at)
/* 102D00 802996F0 3C01802C */  lui   $at, %hi(D_802B9670) # $at, 0x802c
/* 102D04 802996F4 C4269670 */  lwc1  $f6, %lo(D_802B9670)($at)
/* 102D08 802996F8 AFA50028 */  sw    $a1, 0x28($sp)
/* 102D0C 802996FC A7A2004A */  sh    $v0, 0x4a($sp)
/* 102D10 80299700 E7A40010 */  swc1  $f4, 0x10($sp)
/* 102D14 80299704 0C0AE034 */  jal   func_802B80D0
/* 102D18 80299708 E7A60014 */   swc1  $f6, 0x14($sp)
/* 102D1C 8029970C 44804000 */  mtc1  $zero, $f8
/* 102D20 80299710 87A2004A */  lh    $v0, 0x4a($sp)
/* 102D24 80299714 8FA70054 */  lw    $a3, 0x54($sp)
/* 102D28 80299718 4608003C */  c.lt.s $f0, $f8
/* 102D2C 8029971C 304C0400 */  andi  $t4, $v0, 0x400
/* 102D30 80299720 4503004C */  bc1tl .L80299854
/* 102D34 80299724 8FBF0024 */   lw    $ra, 0x24($sp)
/* 102D38 80299728 1580000B */  bnez  $t4, .L80299758
/* 102D3C 8029972C 3C014416 */   li    $at, 0x44160000 # 600.000000
/* 102D40 80299730 44815000 */  mtc1  $at, $f10
/* 102D44 80299734 8FA40028 */  lw    $a0, 0x28($sp)
/* 102D48 80299738 26050010 */  addiu $a1, $s0, 0x10
/* 102D4C 8029973C 460A003C */  c.lt.s $f0, $f10
/* 102D50 80299740 00000000 */  nop   
/* 102D54 80299744 45020005 */  bc1fl .L8029975C
/* 102D58 80299748 C6100018 */   lwc1  $f16, 0x18($s0)
/* 102D5C 8029974C 0C0A5E53 */  jal   func_8029794C
/* 102D60 80299750 3C0640A0 */   lui   $a2, 0x40a0
/* 102D64 80299754 8FA70054 */  lw    $a3, 0x54($sp)
.L80299758:
/* 102D68 80299758 C6100018 */  lwc1  $f16, 0x18($s0)
.L8029975C:
/* 102D6C 8029975C 00E02025 */  move  $a0, $a3
/* 102D70 80299760 00002825 */  move  $a1, $zero
/* 102D74 80299764 E4F00030 */  swc1  $f16, 0x30($a3)
/* 102D78 80299768 C612001C */  lwc1  $f18, 0x1c($s0)
/* 102D7C 8029976C E4F20034 */  swc1  $f18, 0x34($a3)
/* 102D80 80299770 C6040020 */  lwc1  $f4, 0x20($s0)
/* 102D84 80299774 0C0AD3FE */  jal   func_802B4FF8
/* 102D88 80299778 E4E40038 */   swc1  $f4, 0x38($a3)
/* 102D8C 8029977C 10400034 */  beqz  $v0, .L80299850
/* 102D90 80299780 3C038015 */   lui   $v1, %hi(gDisplayListHead) # $v1, 0x8015
/* 102D94 80299784 24630298 */  addiu $v1, %lo(gDisplayListHead) # addiu $v1, $v1, 0x298
/* 102D98 80299788 8C620000 */  lw    $v0, ($v1)
/* 102D9C 8029978C 3C0F0D00 */  lui   $t7, %hi(D_0D004C68) # $t7, 0xd00
/* 102DA0 80299790 25EF4C68 */  addiu $t7, %lo(D_0D004C68) # addiu $t7, $t7, 0x4c68
/* 102DA4 80299794 244D0008 */  addiu $t5, $v0, 8
/* 102DA8 80299798 AC6D0000 */  sw    $t5, ($v1)
/* 102DAC 8029979C 3C0EFD10 */  lui   $t6, 0xfd10
/* 102DB0 802997A0 AC4E0000 */  sw    $t6, ($v0)
/* 102DB4 802997A4 AC4F0004 */  sw    $t7, 4($v0)
/* 102DB8 802997A8 8C620000 */  lw    $v0, ($v1)
/* 102DBC 802997AC 3C19E800 */  lui   $t9, 0xe800
/* 102DC0 802997B0 3C0CF500 */  lui   $t4, (0xF5000100 >> 16) # lui $t4, 0xf500
/* 102DC4 802997B4 24580008 */  addiu $t8, $v0, 8
/* 102DC8 802997B8 AC780000 */  sw    $t8, ($v1)
/* 102DCC 802997BC AC400004 */  sw    $zero, 4($v0)
/* 102DD0 802997C0 AC590000 */  sw    $t9, ($v0)
/* 102DD4 802997C4 8C620000 */  lw    $v0, ($v1)
/* 102DD8 802997C8 358C0100 */  ori   $t4, (0xF5000100 & 0xFFFF) # ori $t4, $t4, 0x100
/* 102DDC 802997CC 3C0D0700 */  lui   $t5, 0x700
/* 102DE0 802997D0 244B0008 */  addiu $t3, $v0, 8
/* 102DE4 802997D4 AC6B0000 */  sw    $t3, ($v1)
/* 102DE8 802997D8 AC4D0004 */  sw    $t5, 4($v0)
/* 102DEC 802997DC AC4C0000 */  sw    $t4, ($v0)
/* 102DF0 802997E0 8C620000 */  lw    $v0, ($v1)
/* 102DF4 802997E4 3C0FE600 */  lui   $t7, 0xe600
/* 102DF8 802997E8 3C0B073F */  lui   $t3, (0x073FC000 >> 16) # lui $t3, 0x73f
/* 102DFC 802997EC 244E0008 */  addiu $t6, $v0, 8
/* 102E00 802997F0 AC6E0000 */  sw    $t6, ($v1)
/* 102E04 802997F4 AC400004 */  sw    $zero, 4($v0)
/* 102E08 802997F8 AC4F0000 */  sw    $t7, ($v0)
/* 102E0C 802997FC 8C620000 */  lw    $v0, ($v1)
/* 102E10 80299800 356BC000 */  ori   $t3, (0x073FC000 & 0xFFFF) # ori $t3, $t3, 0xc000
/* 102E14 80299804 3C19F000 */  lui   $t9, 0xf000
/* 102E18 80299808 24580008 */  addiu $t8, $v0, 8
/* 102E1C 8029980C AC780000 */  sw    $t8, ($v1)
/* 102E20 80299810 AC4B0004 */  sw    $t3, 4($v0)
/* 102E24 80299814 AC590000 */  sw    $t9, ($v0)
/* 102E28 80299818 8C620000 */  lw    $v0, ($v1)
/* 102E2C 8029981C 3C0DE700 */  lui   $t5, 0xe700
/* 102E30 80299820 3C180601 */  lui   $t8, %hi(D_06013F20) # $t8, 0x601
/* 102E34 80299824 244C0008 */  addiu $t4, $v0, 8
/* 102E38 80299828 AC6C0000 */  sw    $t4, ($v1)
/* 102E3C 8029982C AC400004 */  sw    $zero, 4($v0)
/* 102E40 80299830 AC4D0000 */  sw    $t5, ($v0)
/* 102E44 80299834 8C620000 */  lw    $v0, ($v1)
/* 102E48 80299838 27183F20 */  addiu $t8, %lo(D_06013F20) # addiu $t8, $t8, 0x3f20
/* 102E4C 8029983C 3C0F0600 */  lui   $t7, 0x600
/* 102E50 80299840 244E0008 */  addiu $t6, $v0, 8
/* 102E54 80299844 AC6E0000 */  sw    $t6, ($v1)
/* 102E58 80299848 AC580004 */  sw    $t8, 4($v0)
/* 102E5C 8029984C AC4F0000 */  sw    $t7, ($v0)
.L80299850:
/* 102E60 80299850 8FBF0024 */  lw    $ra, 0x24($sp)
.L80299854:
/* 102E64 80299854 8FB00020 */  lw    $s0, 0x20($sp)
/* 102E68 80299858 27BD0050 */  addiu $sp, $sp, 0x50
/* 102E6C 8029985C 03E00008 */  jr    $ra
/* 102E70 80299860 00000000 */   nop   
