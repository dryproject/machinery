/* This is free and unencumbered software released into the public domain. */

#ifndef MACHINERY_ARCH_X86_ENCODING_H
#define MACHINERY_ARCH_X86_ENCODING_H

/**
 * @file
 *
 * x86 instruction encoding.
 */

#include <cstdint> /* for std::uint*_t */

namespace machinery {
  namespace arch {
    union x86_imm8;
    union x86_imm16;
    union x86_imm32;
    union x86_imm64;

    /** x86 opcode byte */
    using x86_opcode = std::uint8_t;

    using x86_reg = std::uint8_t;
    enum class x86_reg8  : x86_reg;
    enum class x86_reg16 : x86_reg;
    enum class x86_reg32 : x86_reg;
    enum class x86_reg64 : x86_reg;
  }
}

/**
 * 8-bit immediate value.
 */
union machinery::arch::x86_imm8 final {
  std::int8_t s8;
  std::uint8_t u8;

  /**
   * Constructor.
   *
   * @param value the immediate value
   */
  explicit x86_imm8(const std::uint8_t value) noexcept
    : u8(value) {}
};

/**
 * 16-bit immediate value.
 */
union machinery::arch::x86_imm16 final {
  std::int16_t s16;
  std::uint16_t u16;
  std::uint8_t u8[2];

  /**
   * Constructor.
   *
   * @param value the immediate value
   */
  explicit x86_imm16(const std::uint16_t value) noexcept
    : u16(value) {}
};

/**
 * 32-bit immediate value.
 */
union machinery::arch::x86_imm32 final {
  std::int32_t s32;
  std::uint32_t u32;
  std::uint8_t u8[4];

  /**
   * Constructor.
   *
   * @param value the immediate value
   */
  explicit x86_imm32(const std::uint32_t value) noexcept
    : u32(value) {}
};

/**
 * 64-bit immediate value.
 */
union machinery::arch::x86_imm64 final {
  std::int64_t s64;
  std::uint64_t u64;
  std::uint8_t u8[8];

  /**
   * Constructor.
   *
   * @param value the immediate value
   */
  explicit x86_imm64(const std::uint64_t value) noexcept
    : u64(value) {}
};

/**
 * x86 general-purpose registers (8-bit)
 */
enum class machinery::arch::x86_reg8 : machinery::arch::x86_reg {
  al = 0,   /* 0b000 */
  cl = 1,   /* 0b001 */
  dl = 2,   /* 0b010 */
  bl = 3,   /* 0b011 */
  ah = 4,   /* 0b100 */
  ch = 5,   /* 0b101 */
  dh = 6,   /* 0b110 */
  bh = 7,   /* 0b111 */
};

/**
 * x86 general-purpose registers (16-bit)
 */
enum class machinery::arch::x86_reg16 : machinery::arch::x86_reg {
  ax = 0,   /* 0b000 */
  cx = 1,   /* 0b001 */
  dx = 2,   /* 0b010 */
  bx = 3,   /* 0b011 */
  sp = 4,   /* 0b100 */
  bp = 5,   /* 0b101 */
  si = 6,   /* 0b110 */
  di = 7,   /* 0b111 */
};

/**
 * x86 general-purpose registers (32-bit)
 */
enum class machinery::arch::x86_reg32 : machinery::arch::x86_reg {
  eax = 0,  /* 0b000 */
  ecx = 1,  /* 0b001 */
  edx = 2,  /* 0b010 */
  ebx = 3,  /* 0b011 */
  esp = 4,  /* 0b100 */
  ebp = 5,  /* 0b101 */
  esi = 6,  /* 0b110 */
  edi = 7,  /* 0b111 */
};

/**
 * x86 general-purpose registers (64-bit)
 */
enum class machinery::arch::x86_reg64 : machinery::arch::x86_reg {
  rax = 0,  /* 0b000 */
  rcx = 1,  /* 0b001 */
  rdx = 2,  /* 0b010 */
  rbx = 3,  /* 0b011 */
  rsp = 4,  /* 0b100 */
  rbp = 5,  /* 0b101 */
  rsi = 6,  /* 0b110 */
  rdi = 7,  /* 0b111 */
  r8  = 8,
  r9  = 9,
  r10 = 10,
  r11 = 11,
  r12 = 12,
  r13 = 13,
  r14 = 14,
  r15 = 15,
};

#endif /* MACHINERY_ARCH_X86_ENCODING_H */
