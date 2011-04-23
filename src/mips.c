/* This is free and unencumbered software released into the public domain. */

#include "mips.h"
#include "config.h"
#include <assert.h>
#include <errno.h>

ssize_t
mips_encode_r_insn(mips_insn_t* insn, const mips_op_t op, const mips_reg_t rs, const mips_reg_t rt, const mips_reg_t rd,
                                      const mips_shamt_t shamt, const mips_funct_t funct) {
  if (insn == NULL)
    return -(errno = EINVAL); // invalid argument

  insn->r.op    = op;
  insn->r.rs    = rs;
  insn->r.rt    = rt;
  insn->r.rd    = rd;
  insn->r.shamt = shamt;
  insn->r.funct = funct;

  return sizeof(mips_insn_t);
}

ssize_t
mips_encode_i_insn(mips_insn_t* insn, const mips_op_t op, const mips_reg_t rs, const mips_reg_t rt, const mips_imm_t imm) {
  if (insn == NULL)
    return -(errno = EINVAL); // invalid argument

  insn->i.op  = op;
  insn->i.rs  = rs;
  insn->i.rt  = rt;
  insn->i.imm = imm;

  return sizeof(mips_insn_t);
}

ssize_t
mips_encode_j_insn(mips_insn_t* insn, const mips_op_t op, const mips_addr_t addr) {
  if (insn == NULL)
    return -(errno = EINVAL); // invalid argument

  insn->j.op   = op;
  insn->j.addr = addr;

  return sizeof(mips_insn_t);
}

ssize_t
mips_emit_nop(mips_insn_t* insn) {
  return mips_encode_r_insn(insn, 0, 0, 0, 0, 0, 0);
}

ssize_t
mips_emit_add(mips_insn_t* insn, const mips_reg_t rd, const mips_reg_t rs, const mips_reg_t rt) {
  return mips_encode_r_insn(insn, 0, rs, rt, rd, 0, 32);
}

ssize_t
mips_emit_addu(mips_insn_t* insn, const mips_reg_t rd, const mips_reg_t rs, const mips_reg_t rt) {
  return mips_encode_r_insn(insn, 0, rs, rt, rd, 0, 33);
}