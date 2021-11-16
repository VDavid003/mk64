# Mario Kart 64 (U) disassembly and split file
# generated by n64split v0.4a - N64 ROM splitter

.include "macros.inc"

.section .data

glabel D_800DC600
.word osAppNmiBuffer

glabel gIsMirrorMode
.word 0x00000000

glabel D_800DC608
.float 1.0
.word 0x00000000

glabel D_800DC610
.word 0xafafaf00, 0xafafaf00, 0xffffff00, 0xffffff00
.word 0x00007800, 0x00000000

glabel D_800DC628
.word 0x73737300, 0x73737300

glabel D_800DC630
.word 0xffffff00, 0xffffff00, 0x00007800, 0x00000000
.word 0x80000000

glabel D_800DC644
.hword 0x0008, 0x0000

glabel D_800DC648
.hword 0x0001, 0x0000

glabel D_800DC64C
.word 0x00000000, 0x00000000, 0x00000000

glabel D_800DC658
.word 0x00000000, 0x00000000

glabel gEnableResourceMeters
.word 0x00000000

glabel D_800DC664
.hword 0x0000, 0x0000

glabel D_800DC668
.hword 0x0001, 0x0000

glabel D_800DC66C
.hword 0x0000, 0x0000

#glabel D_800DC670
#.word 0x00000000

#glabel crashScreenFont
#.byte 0x1c, 0x22, 0x26, 0x2a, 0x32, 0x22, 0x1c, 0x00, 0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x1c, 0x00
#.byte 0x3c, 0x02, 0x02, 0x1c, 0x20, 0x20, 0x3e, 0x00, 0x3c, 0x02, 0x02, 0x1c, 0x02, 0x02, 0x3c, 0x00
#.byte 0x24, 0x24, 0x24, 0x3e, 0x04, 0x04, 0x04, 0x00, 0x3e, 0x20, 0x20, 0x3c, 0x02, 0x02, 0x3c, 0x00
#.byte 0x1c, 0x20, 0x20, 0x3c, 0x22, 0x22, 0x1c, 0x00, 0x3e, 0x22, 0x02, 0x04, 0x04, 0x08, 0x08, 0x00
#.byte 0x1c, 0x22, 0x22, 0x1c, 0x22, 0x22, 0x1c, 0x00, 0x1c, 0x22, 0x22, 0x1c, 0x04, 0x04, 0x04, 0x00
#.byte 0x1c, 0x22, 0x22, 0x3e, 0x22, 0x22, 0x22, 0x00, 0x3c, 0x22, 0x22, 0x3c, 0x22, 0x22, 0x3c, 0x00
#.byte 0x0e, 0x10, 0x20, 0x20, 0x20, 0x10, 0x0e, 0x00, 0x38, 0x24, 0x22, 0x22, 0x22, 0x24, 0x38, 0x00
#.byte 0x3e, 0x20, 0x20, 0x3c, 0x20, 0x20, 0x3e, 0x00, 0x3e, 0x20, 0x20, 0x3c, 0x20, 0x20, 0x20, 0x00
#.byte 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00
