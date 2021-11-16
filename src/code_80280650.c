#include <ultra64.h>
#include <macros.h>

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_80280650(void) {

}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80280650.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_80280658(void *arg0) {
    void *temp_v0;

    temp_v0 = arg0->unk28;
    arg0->unk10 = temp_v0->unk2;
    arg0->unk14 = temp_v0->unk4;
    arg0->unk18 = temp_v0->unk6;
    arg0->unkA = temp_v0->unk8 << 8;
    arg0->unkC = temp_v0->unk9 << 8;
    arg0->unkE = temp_v0->unkA << 8;
    arg0->unk4 = temp_v0->unk0;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80280658.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern void *D_802874F8;

void *func_802806C8(void) {
    void *sp1C;
    s32 temp_v0;
    void *phi_a0;
    s32 phi_v0;

    phi_a0 = D_802874F8;
    phi_v0 = 0;
loop_1:
    temp_v0 = phi_v0 + 1;
    phi_v0 = temp_v0;
    if ((*phi_a0 & 1) == 0) {
        sp1C = phi_a0;
        bzero(phi_a0, 0x4C);
        sp1C->unk0 = 1;
        sp1C->unk24 = 1.0f;
        return sp1C;
    }
    phi_a0 += 0x4C;
    if (temp_v0 == 0xC8) {
        return NULL;
    }
    goto loop_1;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_802806C8.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_80280658(void *); // extern
void *func_802806C8(); // extern

void *func_80280734(s32 arg0) {
    void *sp1C;
    void *temp_v0;

    temp_v0 = func_802806C8();
    sp1C = temp_v0;
    temp_v0->unk28 = arg0;
    func_80280658(temp_v0);
    return temp_v0;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80280734.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern u16 D_80284E60;

u16 func_8028076C(void) {
    s32 temp_a1;
    s32 temp_t5;
    s32 temp_t8;
    s32 temp_v0_2;
    u16 temp_t4;
    u16 temp_v0;
    u16 phi_v0;

    temp_v0 = D_80284E60;
    phi_v0 = temp_v0;
    if (temp_v0 == 0x560A) {
        D_80284E60 = 0;
        phi_v0 = 0 & 0xFFFF;
    }
    temp_t8 = (phi_v0 << 8) ^ phi_v0;
    temp_a1 = temp_t8 & 0xFF;
    temp_t4 = (temp_a1 << 8) + ((temp_t8 & 0xFF00) >> 8);
    temp_t5 = ((temp_a1 * 2) ^ temp_t4) & 0xFFFF;
    D_80284E60 = temp_t4;
    if ((temp_t5 & 1) == 0) {
        temp_v0_2 = ((temp_t5 >> 1) ^ 0xFF80) & 0xFFFF;
        if (temp_v0_2 == 0xAA55) {
            D_80284E60 = 0;
        } else {
            D_80284E60 = temp_v0_2 ^ 0x1FF4;
        }
    } else {
        D_80284E60 = (temp_t5 >> 1) ^ 0xFF80 ^ 0x8180;
    }
    return D_80284E60;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_8028076C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
u32 func_8028076C(); // extern

f32 func_8028080C(void) {
    return func_8028076C() / 65536.0f;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_8028080C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
f32 func_8028080C(); // extern

f32 func_80280850(f32 arg0) {
    return (func_8028080C() * arg0) - (arg0 * 0.5f);
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80280850.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_80280884(void) {

}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80280884.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_8006BB34(void *, ?, s16, s16); // extern
f32 func_802B8018(u16); // extern
extern f32 D_80286B70;
extern s16 D_802874CA;

void func_8028088C(void *arg0) {
    f32 temp_f0;
    s32 temp_at;
    s32 temp_t3;

    func_8006BB34(arg0 + 0x10, 0x3F800000, arg0->unk2E, arg0->unk2C);
    arg0->unk14 = arg0->unk14 + D_80286B70;
    temp_f0 = func_802B8018(arg0->unk30);
    temp_t3 = arg0->unk3C + 1;
    temp_at = temp_t3 < 0x321;
    arg0->unk30 = arg0->unk30 + arg0->unk32;
    arg0->unk3C = temp_t3;
    arg0->unk2E = temp_f0 * arg0->unk34;
    if (temp_at == 0) {
        arg0->unk0 = 0;
    }
    if (D_802874CA == 1) {
        arg0->unk0 = 0;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_8028088C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void *func_80280734(? *); // extern
f32 func_80280850(f32); // extern
extern ? D_80284E40;
extern ? D_80284E7C;
extern f32 D_80286B74;
extern f32 D_80286B78;
extern f32 D_80286B7C;

void func_8028093C(void *arg0) {
    f32 temp_f0;
    void *temp_v0;

    if (arg0->unk44 < 0x1E) {
        arg0->unk14 = arg0->unk14 + 2.5f;
        arg0->unk10 = arg0->unk10 + func_80280850(D_80286B74);
        arg0->unk18 = arg0->unk18 + func_80280850(D_80286B78);
        return;
    }
    if (arg0->unk2C == 4) {
        temp_v0 = func_80280734(&D_80284E7C);
        temp_f0 = D_80286B7C;
        temp_v0->unk10 = arg0->unk10;
        temp_v0->unk14 = arg0->unk14;
        temp_v0->unk18 = arg0->unk18;
        temp_v0->unk3C = 0xFF;
        temp_v0->unk40 = -0x11;
        temp_v0->unk44 = 0x64;
        temp_v0->unk34 = temp_f0;
        temp_v0->unk38 = temp_f0;
        temp_v0->unk30 = *(&D_80284E40 + (arg0->unk48 * 4));
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_8028093C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_80021E10(f32, f32 *, s32, s32); // extern
? func_80022180(f32, void *, f32 *); // extern
extern s16 D_80164AF0;
extern ? D_80287500;
extern void *gDisplayListHead;

void func_80280A28(s32 arg0, s32 arg1, f32 arg2) {
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 temp_f12;
    void *temp_v1;

    temp_f12 = arg2;
    arg2 = temp_f12;
    func_80021E10(temp_f12, &sp20, arg0, arg1);
    sp20 = D_80287500.unk0 * arg2;
    sp24 = D_80287500.unk10 * arg2;
    sp28 = D_80287500.unk20 * arg2;
    sp30 = D_80287500.unk4 * arg2;
    sp34 = D_80287500.unk14 * arg2;
    sp38 = D_80287500.unk24 * arg2;
    sp40 = D_80287500.unk8 * arg2;
    sp44 = D_80287500.unk18 * arg2;
    sp48 = D_80287500.unk28 * arg2;
    func_80022180(arg2, gGfxPool + (D_80164AF0 << 6) + 0xFAC0, &sp20);
    temp_v1 = gDisplayListHead;
    gDisplayListHead = temp_v1 + 8;
    temp_v1->unk0 = 0x1020040;
    temp_v1->unk4 = (gGfxPool + (D_80164AF0 << 6) + 0xFAC0) & 0x1FFFFFFF;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80280A28.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_8004B35C(s16, s16, s16, s16); // extern
? func_80280A28(?, f32 *, s16 *, ?); // extern
extern ? D_0D008DB8;
extern ? D_0D008E48;
extern s16 D_80164AF0;
extern s32 D_8018D48C;
extern void *gDisplayListHead;

void func_80280B50(void *arg0, ? arg1, s32 arg2, s16 arg3) {
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    s16 sp48;
    s16 sp46;
    s16 sp44;
    void *sp1C;
    s16 *temp_a1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;

    sp4C = arg0->unk0;
    temp_a1 = &sp44;
    sp50 = arg0->unk4;
    sp44 = 0;
    sp54 = arg0->unk8;
    sp48 = 0;
    sp46 = camera1->unk26;
    func_80280A28(arg1, &sp4C, temp_a1, arg1);
    temp_v0 = gDisplayListHead;
    gDisplayListHead = temp_v0 + 8;
    temp_v0->unk0 = 0x6000000;
    temp_v0->unk4 = &D_0D008DB8;
    temp_v0_2 = gDisplayListHead;
    gDisplayListHead = temp_v0_2 + 8;
    temp_v0_2->unk0 = 0xFD700000;
    temp_v0_2->unk4 = D_8018D48C;
    temp_v0_3 = gDisplayListHead;
    gDisplayListHead = temp_v0_3 + 8;
    temp_v0_3->unk4 = 0x7000000;
    temp_v0_3->unk0 = 0xF5700000;
    temp_v0_4 = gDisplayListHead;
    gDisplayListHead = temp_v0_4 + 8;
    temp_v0_4->unk4 = 0;
    temp_v0_4->unk0 = 0xE6000000;
    temp_v0_5 = gDisplayListHead;
    gDisplayListHead = temp_v0_5 + 8;
    temp_v0_5->unk4 = 0x71FF200;
    temp_v0_5->unk0 = 0xF3000000;
    temp_v0_6 = gDisplayListHead;
    gDisplayListHead = temp_v0_6 + 8;
    temp_v0_6->unk4 = 0;
    temp_v0_6->unk0 = 0xE7000000;
    temp_v0_7 = gDisplayListHead;
    gDisplayListHead = temp_v0_7 + 8;
    temp_v0_7->unk4 = 0;
    temp_v0_7->unk0 = 0xF5680800;
    temp_v0_8 = gDisplayListHead;
    gDisplayListHead = temp_v0_8 + 8;
    sp1C = temp_v0_8;
    temp_v0_8->unk4 = 0x7C07C;
    temp_v0_8->unk0 = 0xF2000000;
    func_8004B35C((arg2 >> 0x10) & 0xFF, (arg2 >> 8) & 0xFF, arg2 & 0xFF, arg3);
    temp_v0_9 = gDisplayListHead;
    gDisplayListHead = temp_v0_9 + 8;
    temp_v0_9->unk0 = 0x6000000;
    temp_v0_9->unk4 = &D_0D008E48;
    D_80164AF0 = D_80164AF0 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80280B50.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_80280B50(f32 *, f32, s32, s16); // extern
extern ? D_80284E50;

void func_80280D1C(void *arg0) {
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 *temp_s4;
    f32 temp_f0;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 phi_s1;
    s32 phi_s0;
    s32 phi_v1;

    phi_s1 = 0;
    phi_s0 = 0;
    if (arg0->unk44 < 0x1E) {
        temp_s4 = &sp58;
        do {
            sp58 = arg0->unk10;
            sp5C = arg0->unk14 - phi_s1;
            sp60 = arg0->unk18;
            func_80280B50(temp_s4, ((0xA - phi_s0) / 10.0f) * 2.0f, *(&D_80284E50 + (arg0->unk48 * 4)), ((0x1E - arg0->unk44) * 0x64) / 30.0f);
            temp_s0 = phi_s0 + 1;
            phi_s1 += 2;
            phi_s0 = temp_s0;
        } while (temp_s0 != 0xA);
    } else {
        temp_v0 = arg0->unk2C;
        if (temp_v0 < 5) {
            temp_v1 = arg0->unk3C + (arg0->unk40 * 2);
            arg0->unk3C = temp_v1;
            arg0->unk34 = arg0->unk34 + (arg0->unk38 * 2.0f);
            phi_v1 = temp_v1;
        } else {
            temp_f0 = 1.0f + (((temp_v0 * 7) - 0x23) / 10.0f);
            temp_v1_2 = arg0->unk3C + (arg0->unk40 / temp_f0);
            arg0->unk3C = temp_v1_2;
            arg0->unk34 = arg0->unk34 + (arg0->unk38 / temp_f0);
            phi_v1 = temp_v1_2;
            if (temp_v1_2 < 0) {
                arg0->unk3C = 0;
                phi_v1 = 0;
            }
        }
        arg0->unk2C = arg0->unk2C + 1;
        if ((phi_v1 <= 0) || !(arg0->unk34 > 0.0f)) {
            if (arg0->unk2C < 0x1E) {
                goto block_12;
            }
            arg0->unk0 = 0;
        } else {
block_12:
            func_80280B50(arg0 + 0x10, arg0->unk34, arg0->unk30, phi_v1);
        }
    }
    arg0->unk44 = arg0->unk44 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80280D1C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_80280FA0(s32 arg0) {

}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80280FA0.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_80280FA8(s32 arg0) {

}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80280FA8.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_80280734(? *); // extern
extern ? D_80284E88;
extern s32 D_802874E0;
extern s32 D_802874F8;

void func_80280FB0(void) {
    s32 temp_v0;

    D_802874E0 = 0;
    temp_v0 = func_802A7B70(0x3B60);
    D_802874F8 = temp_v0;
    bzero(temp_v0, 0x3B60);
    func_80280734(&D_80284E88);
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80280FB0.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern s8 D_802874F4;

void func_80280FFC(void) {
    D_802874F4 = 1;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80280FFC.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_8028100C(s32 arg0, ? arg1, ? arg2) {

}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_8028100C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void *func_80280734(? *); // extern
s16 func_8028076C(); // extern
f32 func_8028080C(); // extern
f32 func_80280850(?); // extern
extern ? D_80284E64;
extern f32 D_80286B80;

void func_8028101C(s32 arg0, s32 arg1, s32 arg2) {
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    s32 temp_s1;
    void *temp_s0;
    s32 phi_s1;

    sp5C = arg2;
    sp60 = arg1;
    sp64 = arg0;
    phi_s1 = 0;
    do {
        temp_s0 = func_80280734(&D_80284E64);
        temp_s0->unk10 = func_80280850(0x43480000) + sp64;
        temp_s0->unk14 = func_80280850(0x43BE0000) + sp60;
        temp_s0->unk18 = func_80280850(0x44160000) + sp5C;
        temp_s0->unk2C = func_8028080C() * 7.0f;
        temp_s0->unk30 = func_8028076C();
        temp_s0->unk32 = func_80280850(0x43C80000) + 900.0f;
        temp_s1 = phi_s1 + 1;
        temp_s0->unk34 = func_80280850(0x44FA0000) + D_80286B80;
        phi_s1 = temp_s1;
    } while (temp_s1 != 0x64);
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_8028101C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void *func_80280734(? *); // extern
f32 func_8028080C(); // extern
f32 func_80280850(f32); // extern
extern ? D_80284E50;
extern ? D_80284E70;
extern f32 D_80286B84;
extern s16 D_802874BE;
extern s16 D_802874C6;
extern s16 D_802874C8;
extern s32 D_80287540;

void func_8028118C(s32 arg0, s32 arg1, s32 arg2) {
    f32 temp_f0;
    f32 temp_f2;
    s32 temp_v0;
    s32 temp_v1;
    void *temp_s0;

    if (((D_802874BE + 0xD) * func_8028080C()) < 1.0f) {
        temp_s0 = func_80280734(&D_80284E70);
        temp_s0->unk10 = func_80280850(0.0f) + arg0;
        temp_s0->unk14 = func_80280850(D_802874C6 + 0x64) + arg1;
        temp_f0 = func_80280850(D_802874C8 + 0x2BC);
        temp_v1 = D_80287540;
        temp_f2 = D_80286B84;
        temp_v0 = temp_v1 & 3;
        temp_s0->unk48 = temp_v0;
        temp_s0->unk18 = temp_f0 + arg2;
        temp_s0->unk3C = 0xFF;
        temp_s0->unk40 = -0x11;
        temp_s0->unk34 = temp_f2;
        temp_s0->unk38 = temp_f2;
        temp_s0->unk30 = *(&D_80284E50 + (temp_v0 * 4));
        D_80287540 = temp_v1 + 1;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_8028118C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_8028101C(?, s32, ?); // extern
? func_8028118C(?, s32, ?); // extern
? guLookAtF(? *, s32, s32, s32, f32, f32, f32, f32, f32, f32); // extern
extern ? cameras;
extern f32 D_801646F4;
extern s16 D_802874C4;
extern s32 D_802874E0;
extern s8 D_802874F5;
extern ? D_80287500;

void func_802812C8(void) {
    f32 temp_f0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 phi_v0;
    s32 phi_v0_2;

    guLookAtF(&D_80287500, cameras.unk0, cameras.unk4, cameras.unk8, cameras.unkC, cameras.unk10, cameras.unk14, cameras.unk18, cameras.unk1C, cameras.unk20);
    if (D_802874F5 < 3) {
        temp_v0 = D_802874E0;
        phi_v0 = temp_v0;
        if (temp_v0 < 0x12C) {
            temp_f0 = D_80164700;
            func_8028118C(-0xE0E, ((temp_f0 - D_801646F4) * 1.5f) + temp_f0, -0x258);
            phi_v0 = D_802874E0;
        }
        phi_v0_2 = phi_v0;
        if (phi_v0 == 0x78) {
            func_8028101C(-0xC6C, D_802874C4 + 210.0f, -0x1EF);
            goto block_7;
        }
    } else {
        temp_v0_2 = D_802874E0;
        phi_v0_2 = temp_v0_2;
        if (temp_v0_2 == 2) {
            func_8028101C(-0xC6C, D_802874C4 + 210.0f, -0x1EF);
block_7:
            phi_v0_2 = D_802874E0;
        }
    }
    D_802874E0 = phi_v0_2 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_802812C8.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_802812C8(); // extern
extern ? D_80284E94;
extern s16 D_802874D0;
extern void *D_802874F8;

void func_80281438(void) {
    ? (*temp_v0)(void *);
    s32 temp_s1;
    s32 temp_s2;
    void *phi_s0;
    s32 phi_s2;
    s32 phi_s1;

    func_802812C8();
    D_802874D0 = 0;
    phi_s2 = 0;
    do {
        phi_s0 = D_802874F8;
        phi_s1 = 0;
loop_2:
        if ((phi_s0->unk0 & 1) != 0) {
            temp_v0 = *(&D_80284E94 + (phi_s0->unk4 * 0xC) + (phi_s2 * 4));
            if (temp_v0 != 0) {
                temp_v0(phi_s0);
            }
        }
        temp_s1 = phi_s1 + 1;
        phi_s0 += 0x4C;
        phi_s1 = temp_s1;
        if (temp_s1 != 0xC8) {
            goto loop_2;
        }
        temp_s2 = phi_s2 + 1;
        phi_s2 = temp_s2;
    } while (temp_s2 != 3);
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80281438.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
extern s32 D_802874D4;
extern s32 gDisplayListHead;

void func_8028150C(void) {
    D_802874D4 = gDisplayListHead;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_8028150C.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_80281520(void) {

}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80281520.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_80281528(void) {

}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80281528.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_80281530(void) {

}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80281530.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_80281538(void) {

}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80281538.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_80281540(void) {

}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80281540.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
? func_800097E0(); // extern
? func_8001C14C(); // extern
? func_80022744(); // extern
? func_80028F70(); // extern
? func_80059AC8(); // extern
? func_8005A070(); // extern
? func_80281540(); // extern
? func_80281610(); // extern
? func_80281D00(); // extern
extern s16 D_80150112;
extern s8 D_802874F4;
extern s32 D_802874FC;
extern void *gDisplayListHead;

void func_80281548(void) {
    void *temp_v0;
    void *temp_v0_2;

    D_80150112 = 0;
    D_802874FC = 0;
    func_80281610();
    func_80028F70();
    func_80022744();
    func_80059AC8();
    func_80059AC8();
    func_8005A070();
    if (D_802874F4 != 0) {
        func_8001C14C();
        func_800097E0();
    }
    func_80281D00();
    func_80281540();
    temp_v0 = gDisplayListHead;
    gDisplayListHead = temp_v0 + 8;
    temp_v0->unk4 = 0;
    temp_v0->unk0 = 0xE9000000;
    temp_v0_2 = gDisplayListHead;
    gDisplayListHead = temp_v0_2 + 8;
    temp_v0_2->unk4 = 0;
    temp_v0_2->unk0 = 0xB8000000;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80281548.s")
#endif
