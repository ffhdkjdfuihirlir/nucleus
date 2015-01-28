/**
 * (c) 2015 Nucleus project. All rights reserved.
 * Released under GPL v2 license. Read LICENSE for more details.
 */

#include "nucleus/common.h"
#include "nucleus/cpu/ppu/ppu_instruction.h"

namespace cpu {
namespace ppu {

enum AnalyzerEvent : u8 {
    REG_NONE = 0,  // Original register was not accessed
    REG_READ,      // Original register was read
    REG_WRITE,     // Original register was written
};

class Analyzer
{
    // PPU UISA Registers
    AnalyzerEvent gpr[32] = {};
    AnalyzerEvent fpr[32] = {};
    AnalyzerEvent cr[8] = {};
    AnalyzerEvent fpscr = REG_NONE;
    AnalyzerEvent xer = REG_NONE;

    void setFlag(AnalyzerEvent& reg, AnalyzerEvent evt);

public:
    // Integer Instructions
    void addx(Instruction code);
    void addcx(Instruction code);
    void addex(Instruction code);
    void addi(Instruction code);
    void addic(Instruction code);
    void addic_(Instruction code);
    void addis(Instruction code);
    void addmex(Instruction code);
    void addzex(Instruction code);
    void andx(Instruction code);
    void andcx(Instruction code);
    void andi_(Instruction code);
    void andis_(Instruction code);
    void cmp(Instruction code);
    void cmpi(Instruction code);
    void cmpl(Instruction code);
    void cmpli(Instruction code);
    void cntlzdx(Instruction code);
    void cntlzwx(Instruction code);
    void divdx(Instruction code);
    void divdux(Instruction code);
    void divwx(Instruction code);
    void divwux(Instruction code);
    void eqvx(Instruction code);
    void extsbx(Instruction code);
    void extshx(Instruction code);
    void extswx(Instruction code);
    void mulhdx(Instruction code);
    void mulhdux(Instruction code);
    void mulhwx(Instruction code);
    void mulhwux(Instruction code);
    void mulldx(Instruction code);
    void mulli(Instruction code);
    void mullwx(Instruction code);
    void nandx(Instruction code);
    void negx(Instruction code);
    void norx(Instruction code);
    void orx(Instruction code);
    void orcx(Instruction code);
    void ori(Instruction code);
    void oris(Instruction code);
    void rldc_lr(Instruction code);
    void rldicx(Instruction code);
    void rldiclx(Instruction code);
    void rldicrx(Instruction code);
    void rldimix(Instruction code);
    void rlwimix(Instruction code);
    void rlwinmx(Instruction code);
    void rlwnmx(Instruction code);
    void sldx(Instruction code);
    void slwx(Instruction code);
    void sradx(Instruction code);
    void sradix(Instruction code);
    void srawx(Instruction code);
    void srawix(Instruction code);
    void srdx(Instruction code);
    void srwx(Instruction code);
    void subfx(Instruction code);
    void subfcx(Instruction code);
    void subfex(Instruction code);
    void subfic(Instruction code);
    void subfmex(Instruction code);
    void subfzex(Instruction code);
    void xorx(Instruction code);
    void xori(Instruction code);
    void xoris(Instruction code);

    // Floating-Point Instructions
    void fabsx(Instruction code);
    void faddx(Instruction code);
    void faddsx(Instruction code);
    void fcfidx(Instruction code);
    void fcmpo(Instruction code);
    void fcmpu(Instruction code);
    void fctidx(Instruction code);
    void fctidzx(Instruction code);
    void fctiwx(Instruction code);
    void fctiwzx(Instruction code);
    void fdivx(Instruction code);
    void fdivsx(Instruction code);
    void fmaddx(Instruction code);
    void fmaddsx(Instruction code);
    void fmrx(Instruction code);
    void fmsubx(Instruction code);
    void fmsubsx(Instruction code);
    void fmulx(Instruction code);
    void fmulsx(Instruction code);
    void fnabsx(Instruction code);
    void fnegx(Instruction code);
    void fnmaddx(Instruction code);
    void fnmaddsx(Instruction code);
    void fnmsubx(Instruction code);
    void fnmsubsx(Instruction code);
    void fresx(Instruction code);
    void frspx(Instruction code);
    void frsqrtex(Instruction code);
    void fselx(Instruction code);
    void fsqrtx(Instruction code);
    void fsqrtsx(Instruction code);
    void fsubx(Instruction code);
    void fsubsx(Instruction code);
    void mcrfs(Instruction code);
    void mffsx(Instruction code);
    void mtfsb0x(Instruction code);
    void mtfsb1x(Instruction code);
    void mtfsfix(Instruction code);
    void mtfsfx(Instruction code);

    // Load and Store Instructions
    // TODO: ?

    // Branch and Flow Control Instructions
    void bx(Instruction code);
    void bcx(Instruction code);
    void bcctrx(Instruction code);
    void bclrx(Instruction code);

    // TODO: ?
    void crand(Instruction code);
    void crandc(Instruction code);
    void creqv(Instruction code);
    void crnand(Instruction code);
    void crnor(Instruction code);
    void cror(Instruction code);
    void crorc(Instruction code);
    void crxor(Instruction code);
    void dcbf(Instruction code);
    void dcbst(Instruction code);
    void dcbt(Instruction code);
    void dcbtst(Instruction code);
    void dcbz(Instruction code);
    void dss(Instruction code);
    void dst(Instruction code);
    void dstst(Instruction code);
    void eciwx(Instruction code);
    void ecowx(Instruction code);
    void eieio(Instruction code);
    void icbi(Instruction code);
    void isync(Instruction code);
    void lbz(Instruction code);
    void lbzu(Instruction code);
    void lbzux(Instruction code);
    void lbzx(Instruction code);
    void ld(Instruction code);
    void ldarx(Instruction code);
    void ldbrx(Instruction code);
    void ldu(Instruction code);
    void ldux(Instruction code);
    void ldx(Instruction code);
    void lha(Instruction code);
    void lhau(Instruction code);
    void lhaux(Instruction code);
    void lhax(Instruction code);
    void lhbrx(Instruction code);
    void lhz(Instruction code);
    void lhzu(Instruction code);
    void lhzux(Instruction code);
    void lhzx(Instruction code);
    void lmw(Instruction code);
    void lswi(Instruction code);
    void lswx(Instruction code);
    void lwa(Instruction code);
    void lwarx(Instruction code);
    void lwaux(Instruction code);
    void lwax(Instruction code);
    void lwbrx(Instruction code);
    void lwz(Instruction code);
    void lwzu(Instruction code);
    void lwzux(Instruction code);
    void lwzx(Instruction code);
    void mcrf(Instruction code);
    void mfocrf(Instruction code);
    void mfspr(Instruction code);
    void mftb(Instruction code);
    void mtocrf(Instruction code);
    void mtspr(Instruction code);
    void nop(Instruction code);
    void sc(Instruction code_code);
    void stb(Instruction code);
    void stbu(Instruction code);
    void stbux(Instruction code);
    void stbx(Instruction code);
    void std(Instruction code);
    void stdcx_(Instruction code);
    void stdu(Instruction code);
    void stdux(Instruction code);
    void stdx(Instruction code);
    void sth(Instruction code);
    void sthbrx(Instruction code);
    void sthu(Instruction code);
    void sthux(Instruction code);
    void sthx(Instruction code);
    void stmw(Instruction code);
    void stswi(Instruction code);
    void stswx(Instruction code);
    void stvrxl(Instruction code);
    void stw(Instruction code);
    void stwbrx(Instruction code);
    void stwcx_(Instruction code);
    void stwu(Instruction code);
    void stwux(Instruction code);
    void stwx(Instruction code);
    void sync(Instruction code);
    void td(Instruction code);
    void tdi(Instruction code);
    void tw(Instruction code);
    void twi(Instruction code);
};

}  // namespace ppu
}  // namespace cpu