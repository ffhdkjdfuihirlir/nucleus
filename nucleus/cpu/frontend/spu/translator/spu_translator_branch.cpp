/**
 * (c) 2014-2016 Alexandro Sanchez Bach. All rights reserved.
 * Released under GPL v2 license. Read LICENSE for more details.
 */

#include "spu_translator.h"
#include "nucleus/core/config.h"
#include "nucleus/assert.h"

namespace cpu {
namespace frontend {
namespace spu {

using namespace cpu::hir;

/**
 * SPU Instructions:
 *  - Compare, Branch and Halt Instructions (Chapter 7)
 *  - Hint-for-Branch Instructions (Chapter 8)
 */

// Compare, Branch and Halt Instructions (Chapter 7)
void Translator::bi(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::bihnz(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::bihz(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::binz(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::bisl(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::bisled(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::biz(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::br(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::bra(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::brasl(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::brhnz(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::brhz(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::brnz(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::brsl(Instruction code)
{
    const U32 targetAddr = currentAddress + (code.i16 << 2);
    
    Value* rt = builder.getConstantI32(currentAddress + 4);
    setGPR(code.rt, rt);

    Module* module = static_cast<Module*>(function->parent);
    if (config.spuTranslator & CPU_TRANSLATOR_IS_JIT) {
        module->addFunction(targetAddr);
    }
    auto& targetFunc = static_cast<Function&>(*module->functions.at(targetAddr));
    builder.createCall(targetFunc.hirFunction);
}

void Translator::brz(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::ceq(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::ceqb(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::ceqbi(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::ceqh(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::ceqhi(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::ceqi(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::cgt(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::cgtb(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::cgtbi(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::cgth(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::cgthi(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::cgti(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::clgt(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::clgtb(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::clgtbi(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::clgth(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::clgthi(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::clgti(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::heq(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::heqi(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::hgt(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::hgti(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::hlgt(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::hlgti(Instruction code)
{
    assert_always("Unimplemented");
}

void Translator::iret(Instruction code)
{
    assert_always("Unimplemented");
}


// Hint-for-Branch Instructions (Chapter 8)
void Translator::hbr(Instruction code)
{
    // NOTE: Not implemented.
    // Although there is no need to translate these branch hints,
    // its translation could result in performance improvements.
}

void Translator::hbra(Instruction code)
{
    // NOTE: Not implemented.
    // Although there is no need to translate these branch hints,
    // its translation could result in performance improvements.
}

void Translator::hbrr(Instruction code)
{
    // NOTE: Not implemented.
    // Although there is no need to translate these branch hints,
    // its translation could result in performance improvements.
}

}  // namespace spu
}  // namespace frontend
}  // namespace cpu
