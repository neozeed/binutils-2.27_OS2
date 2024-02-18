/* Copyright (C) 2006-2016 Free Software Foundation, Inc.

   This file is part of the GNU opcodes library.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this file; see the file COPYING.  If not, write to the
   Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

struct score_opcode
{
  bfd_vma value;
  bfd_vma mask;           /* Recognise instruction if (op & mask) == value.  */
  char *assembler;        /* Disassembly string.  */
};

/* Note: There is a partial ordering in this table - it must be searched from
   the top to obtain a correct match.  */

static struct score_opcode score_opcodes[] =
{
  /* Score Instructions.  */
  {0x3800000a, 0x3e007fff, "abs\t\t%20-24r, %15-19r"},
  {0x3800004b, 0x3e007fff, "abs.s\t\t%20-24r, %15-19r"},
  {0x00000010, 0x3e0003ff, "add\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000011, 0x3e0003ff, "add.c\t\t%20-24r, %15-19r, %10-14r"},
  {0x38000048, 0x3e0003ff, "add.s\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000012, 0x3e0003ff, "addc\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000013, 0x3e0003ff, "addc.c\t\t%20-24r, %15-19r, %10-14r"},
  {0x02000000, 0x3e0e0001, "addi\t\t%20-24r, %1-16i"},
  {0x02000001, 0x3e0e0001, "addi.c\t\t%20-24r, %1-16i"},
  {0x0a000000, 0x3e0e0001, "addis\t\t%20-24r, %1-16d(0x%1-16x)"},
  {0x0a000001, 0x3e0e0001, "addis.c\t\t%20-24r, %1-16d(0x%1-16x)"},
  {0x10000000, 0x3e000001, "addri\t\t%20-24r, %15-19r, %1-14i"},
  {0x10000001, 0x3e000001, "addri.c\t\t%20-24r, %15-19r, %1-14i"},
  {0x00004800, 0x00007f00, "add!\t\t%4-7r, %0-3r"},
  {0x00005c00, 0x00007c00, "addi!\t\t%6-9r, %0-5i"},
  {0x00000020, 0x3e0003ff, "and\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000021, 0x3e0003ff, "and.c\t\t%20-24r, %15-19r, %10-14r"},
  {0x040000000000LL, 0x1c0000000003LL, "andri48\t\t%38-41r,%34-37r, 0x%2-33x"},
  {0x040000000001LL, 0x1c0000000003LL, "andri48.c\t\t%38-41r,%34-37r, 0x%2-33x"},
  {0x02080000, 0x3e0e0001, "andi\t\t%20-24r, 0x%1-16x"},
  {0x02080001, 0x3e0e0001, "andi.c\t\t%20-24r, 0x%1-16x"},
  {0x0a080000, 0x3e0e0001, "andis\t\t%20-24r, 0x%1-16x"},
  {0x0a080001, 0x3e0e0001, "andis.c\t\t%20-24r, 0x%1-16x"},
  {0x18000000, 0x3e000001, "andri\t\t%20-24r, %15-19r, 0x%1-14x"},
  {0x18000001, 0x3e000001, "andri.c\t\t%20-24r, %15-19r,0x%1-14x"},
  {0x00004b00, 0x00007f00, "and!\t\t%4-7r, %0-3r"},
  {0x08000000, 0x3e007c01, "bcs\t\t%b"},
  {0x08000400, 0x3e007c01, "bcc\t\t%b"},
  {0x08003800, 0x3e007c01, "bcnz\t\t%b"},
  {0x08000001, 0x3e007c01, "bcsl\t\t%b"},
  {0x08000401, 0x3e007c01, "bccl\t\t%b"},
  {0x08003801, 0x3e007c01, "bcnzl\t\t%b"},
  {0x0000004c, 0x3e00007e, "bcmpeqz\t\t%15-19r, %z"},
  {0x0000004c, 0x3e00007e, "bcmpeq\t\t%15-19r,  %z"},
  {0x0000004e, 0x3e00007e, "bcmpnez\t\t%15-19r, %z"},
  {0x0000004e, 0x3e00007e, "bcmpne\t\t%15-19r,  %z"},
  {0x00003200, 0x00007e00, "bcnz!\t\t%b"},
  {0x08001000, 0x3e007c01, "beq\t\t%b"},
  {0x08001001, 0x3e007c01, "beql\t\t%b"},
  {0x00003800, 0x00007e00, "beq!\t\t%b"},
  {0x08000800, 0x3e007c01, "bgtu\t\t%b"},
  {0x08001800, 0x3e007c01, "bgt\t\t%b"},
  {0x08002000, 0x3e007c01, "bge\t\t%b"},
  {0x08000801, 0x3e007c01, "bgtul\t\t%b"},
  {0x08001801, 0x3e007c01, "bgtl\t\t%b"},
  {0x08002001, 0x3e007c01, "bgel\t\t%b"},
  {0x00003400, 0x00007e00, "bgtu!\t\t%b"},
  {0x00003c00, 0x00007e00, "bgt!\t\t%b"},
  {0x00000029, 0x3e0003ff, "bitclr.c\t%20-24r, %15-19r, 0x%10-14x"},
  {0x00000028, 0x3e0003ff, "bitclr\t%20-24r, %15-19r, 0x%10-14x"},
  {0x0000002b, 0x3e0003ff, "bitset.c\t%20-24r, %15-19r, 0x%10-14x"},
  {0x0000002a, 0x3e0003ff, "bitset\t%20-24r, %15-19r, 0x%10-14x"},
  {0x0000002d, 0x3e0003ff, "bittst.c\t%15-19r, 0x%10-14x"},
  {0x0000002f, 0x3e0003ff, "bittgl.c\t%20-24r, %15-19r, 0x%10-14x"},
  {0x0000002e, 0x3e0003ff, "bittgl\t%20-24r, %15-19r, 0x%10-14x"},
  {0x00005000, 0x00007e00, "bitclr!\t\t%5-8r, 0x%0-4x"},
  {0x3800000c, 0x3e0003ff, "bitrev\t\t%20-24r, %15-19r,%10-14r"},
  {0x00005200, 0x00007e00, "bitset!\t\t%5-8r, 0x%0-4x"},
  {0x00005400, 0x00007e00, "bittst!\t\t%5-8r, 0x%0-4x"},
  {0x00005600, 0x00007e00, "bittgl!\t\t%5-8r, 0x%0-4x"},
  {0x08000c00, 0x3e007c01, "bleu\t\t%b"},
  {0x08001c00, 0x3e007c01, "ble\t\t%b"},
  {0x08002400, 0x3e007c01, "blt\t\t%b"},
  {0x08000c01, 0x3e007c01, "bleul\t\t%b"},
  {0x08001c01, 0x3e007c01, "blel\t\t%b"},
  {0x08002401, 0x3e007c01, "bltl\t\t%b"},
  {0x08003c01, 0x3e007c01, "bl\t\t%b"},
  {0x00003600, 0x00007e00, "bleu!\t\t%b"},
  {0x00003e00, 0x00007e00, "ble!\t\t%b"},
  {0x08002800, 0x3e007c01, "bmi\t\t%b"},
  {0x08002801, 0x3e007c01, "bmil\t\t%b"},
  {0x08001400, 0x3e007c01, "bne\t\t%b"},
  {0x08001401, 0x3e007c01, "bnel\t\t%b"},
  {0x00003a00, 0x00007e00, "bne!\t\t%b"},
  {0x08002c00, 0x3e007c01, "bpl\t\t%b"},
  {0x08002c01, 0x3e007c01, "bpll\t\t%b"},
  {0x00000008, 0x3e007fff, "brcs\t\t%15-19r"},
  {0x00000408, 0x3e007fff, "brcc\t\t%15-19r"},
  {0x00000808, 0x3e007fff, "brgtu\t\t%15-19r"},
  {0x00000c08, 0x3e007fff, "brleu\t\t%15-19r"},
  {0x00001008, 0x3e007fff, "breq\t\t%15-19r"},
  {0x00001408, 0x3e007fff, "brne\t\t%15-19r"},
  {0x00001808, 0x3e007fff, "brgt\t\t%15-19r"},
  {0x00001c08, 0x3e007fff, "brle\t\t%15-19r"},
  {0x00002008, 0x3e007fff, "brge\t\t%15-19r"},
  {0x00002408, 0x3e007fff, "brlt\t\t%15-19r"},
  {0x00002808, 0x3e007fff, "brmi\t\t%15-19r"},
  {0x00002c08, 0x3e007fff, "brpl\t\t%15-19r"},
  {0x00003008, 0x3e007fff, "brvs\t\t%15-19r"},
  {0x00003408, 0x3e007fff, "brvc\t\t%15-19r"},
  {0x00003808, 0x3e007fff, "brcnz\t\t%15-19r"},
  {0x00003c08, 0x3e007fff, "br\t\t%15-19r"},
  {0x00000009, 0x3e007fff, "brcsl\t\t%15-19r"},
  {0x00000409, 0x3e007fff, "brccl\t\t%15-19r"},
  {0x00000809, 0x3e007fff, "brgtul\t\t%15-19r"},
  {0x00000c09, 0x3e007fff, "brleul\t\t%15-19r"},
  {0x00001009, 0x3e007fff, "breql\t\t%15-19r"},
  {0x00001409, 0x3e007fff, "brnel\t\t%15-19r"},
  {0x00001809, 0x3e007fff, "brgtl\t\t%15-19r"},
  {0x00001c09, 0x3e007fff, "brlel\t\t%15-19r"},
  {0x00002009, 0x3e007fff, "brgel\t\t%15-19r"},
  {0x00002409, 0x3e007fff, "brltl\t\t%15-19r"},
  {0x00002809, 0x3e007fff, "brmil\t\t%15-19r"},
  {0x00002c09, 0x3e007fff, "brpll\t\t%15-19r"},
  {0x00003009, 0x3e007fff, "brvsl\t\t%15-19r"},
  {0x00003409, 0x3e007fff, "brvcl\t\t%15-19r"},
  {0x00003809, 0x3e007fff, "brcnzl\t\t%15-19r"},
  {0x00003c09, 0x3e007fff, "brl\t\t%15-19r"},
  {0x00000080, 0x00007fe0, "br!\t\t%0-4r"},
  {0x000000a0, 0x00007fe0, "brl!\t\t%0-4r"},
  {0x000000c0, 0x00007fe0, "brr!\t\t%0-4r"},
  {0x08003000, 0x3e007c01, "bvs\t\t%b"},
  {0x08003400, 0x3e007c01, "bvc\t\t%b"},
  {0x08003001, 0x3e007c01, "bvsl\t\t%b"},
  {0x08003401, 0x3e007c01, "bvcl\t\t%b"},
  {0x00003000, 0x00007e00, "b!\t\t%b"},
  {0x08003c00, 0x3e007c01, "b\t\t%b"},
  {0x30000000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x30100000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x30200000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x30300000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x30400000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x30800000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x30900000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x30a00000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x30b00000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x30c00000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x30d00000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x30e00000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x31000000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x31100000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x31800000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x31a00000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x31b00000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x31c00000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x31d00000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x31e00000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x31f00000, 0x3ff00000, "cache\t\t%20-24d, [%15-19r, %0-14i]"},
  {0x38000000, 0x3ff003ff, "mad\t\t%15-19r, %10-14r"},
  {0x38000020, 0x3ff003ff, "madu\t\t%15-19r, %10-14r"},
  {0x38000080, 0x3ff003ff, "mad.f\t\t%15-19r, %10-14r"},
  {0x38000001, 0x3ff003ff, "msb\t\t%15-19r, %10-14r"},
  {0x38000021, 0x3ff003ff, "msbu\t\t%15-19r, %10-14r"},
  {0x38000081, 0x3ff003ff, "msb.f\t\t%15-19r, %10-14r"},
  {0x38000102, 0x3ff003ff, "mazl\t\t%15-19r, %10-14r"},
  {0x38000182, 0x3ff003ff, "mazl.f\t\t%15-19r, %10-14r"},
  {0x38000002, 0x3ff003ff, "madl\t\t%15-19r, %10-14r"},
  {0x380000c2, 0x3ff003ff, "madl.fs\t\t%15-19r, %10-14r"},
  {0x38000303, 0x3ff003ff, "mazh\t\t%15-19r, %10-14r"},
  {0x38000383, 0x3ff003ff, "mazh.f\t\t%15-19r, %10-14r"},
  {0x38000203, 0x3ff003ff, "madh\t\t%15-19r, %10-14r"},
  {0x380002c3, 0x3ff003ff, "madh.fs\t\t%15-19r, %10-14r"},
  {0x38000007, 0x3e0003ff, "max\t\t%20-24r, %15-19r, %10-14r"},

  {0x00000064, 0x3e00007e, "mbitclr\t\t[%15-19r, %m], %10-14d"},
  {0x0000006c, 0x3e00007e, "mbitset\t\t[%20-24r, %m], %10-14d"},

  {0x38000006, 0x3e0003ff, "min\t\t%20-24r, %15-19r, %10-14r"},
  {0x38000104, 0x3ff003ff, "mszl\t\t%15-19r, %10-14r"},
  {0x38000184, 0x3ff003ff, "mszl.f\t\t%15-19r, %10-14r"},
  {0x38000004, 0x3ff003ff, "msbl\t\t%15-19r, %10-14r"},
  {0x380000c4, 0x3ff003ff, "msbl.fs\t\t%15-19r, %10-14r"},
  {0x38000305, 0x3ff003ff, "mszh\t\t%15-19r, %10-14r"},
  {0x38000385, 0x3ff003ff, "mszh.f\t\t%15-19r, %10-14r"},
  {0x38000205, 0x3ff003ff, "msbh\t\t%15-19r, %10-14r"},
  {0x380002c5, 0x3ff003ff, "msbh.fs\t\t%15-19r, %10-14r"},
  {0x3800004e, 0x3e0003ff, "sll.s\t\t%20-24r, %15-19r, %10-14r"},
  {0x38000049, 0x3e0003ff, "sub.s\t\t%20-24r, %15-19r, %10-14r"},
  {0x0000001c, 0x3e007fff, "clz\t\t%20-24r, %15-19r"},
  {0x38000000, 0x3e000000, "ceinst\t\t%20-24d, %15-19r, %10-14r, %5-9d, %0-4d"},
  {0x00000019, 0x3ff003ff, "cmpteq.c\t\t%15-19r, %10-14r"},
  {0x00100019, 0x3ff003ff, "cmptmi.c\t\t%15-19r, %10-14r"},
  {0x00300019, 0x3ff003ff, "cmp.c\t\t%15-19r, %10-14r"},
  {0x0000001b, 0x3ff07fff, "cmpzteq.c\t%15-19r"},
  {0x0010001b, 0x3ff07fff, "cmpztmi.c\t%15-19r"},
  {0x0030001b, 0x3ff07fff, "cmpz.c\t\t%15-19r"},
  {0x02040001, 0x3e0e0001, "cmpi.c\t\t%20-24r, %1-16i"},
  {0x00004400, 0x00007c00, "cmp!\t\t%5-9r, %0-4r"},
  {0x00006000, 0x00007c00, "cmpi!\t\t%5-9r, %0-4i"},
  {0x0c00000c, 0x3e00001f, "cop1\t\tc%20-24r, c%15-19r, c%10-14r, %5-9d"},
  {0x0c000014, 0x3e00001f, "cop2\t\tc%20-24r, c%15-19r, c%10-14r, %5-9d"},
  {0x0c00001c, 0x3e00001f, "cop3\t\tc%20-24r, c%15-19r, c%10-14r, %5-9d"},
  {0x00000044, 0x3e0003ff, "div\t\t%15-19r, %10-14r"},
  {0x00000144, 0x3e0003ff, "divr.q\t\t%20-24r,%15-19r, %10-14r"},
  {0x00000244, 0x3e0003ff, "divr.r\t\t%20-24r,%15-19r, %10-14r"},
  {0x00000344, 0x3e0003ff, "divr\t\t%20-24r,%15-19r, %10-14r"},
  {0x00000046, 0x3e0003ff, "divu\t\t%15-19r, %10-14r"},
  {0x00000146, 0x3e0003ff, "divur.q\t\t%20-24r,%15-19r, %10-14r"},
  {0x00000246, 0x3e0003ff, "divur.r\t\t%20-24r,%15-19r, %10-14r"},
  {0x00000346, 0x3e0003ff, "divur\t\t%20-24r,%15-19r, %10-14r"},
  {0x0c0000a4, 0x3e0003ff, "drte"},
  {0x00e0,     0xffe1,     "disint!"},
  {0x00e1,     0xffe1,     "enint!"},
  {0x00000058, 0x3e0003ff, "extsb\t\t%20-24r, %15-19r"},
  {0x00000059, 0x3e0003ff, "extsb.c\t\t%20-24r, %15-19r"},
  {0x0000005a, 0x3e0003ff, "extsh\t\t%20-24r, %15-19r"},
  {0x0000005b, 0x3e0003ff, "extsh.c\t\t%20-24r, %15-19r"},
  {0x0000005c, 0x3e0003ff, "extzb\t\t%20-24r, %15-19r"},
  {0x0000005d, 0x3e0003ff, "extzb.c\t\t%20-24r, %15-19r"},
  {0x0000005e, 0x3e0003ff, "extzh\t\t%20-24r, %15-19r"},
  {0x0000005f, 0x3e0003ff, "extzh.c\t\t%20-24r, %15-19r"},
  {0x04000001, 0x3e000001, "jl\t\t%j"},
  {0x04000000, 0x3e000001, "j\t\t%j"},
  {0x26000000, 0x3e000000, "lb\t\t%20-24r, [%15-19r, %0-14i]"},
  {0x2c000000, 0x3e000000, "lbu\t\t%20-24r, [%15-19r, %0-14i]"},
  {0x06000003, 0x3e000007, "lb\t\t%20-24r, [%15-19r, %3-14i]+"},
  {0x06000006, 0x3e000007, "lbu\t\t%20-24r, [%15-19r, %3-14i]+"},
  {0x0e000003, 0x3e000007, "lb\t\t%20-24r, [%15-19r]+, %3-14i"},
  {0x0e000006, 0x3e000007, "lbu\t\t%20-24r, [%15-19r]+, %3-14i"},
  {0x00000060, 0x3e0003ff, "lcb\t\t[%15-19r]+"},
  {0x00000062, 0x3e0003ff, "lcw\t\t%20-24r, [%15-19r]+"},
  {0x00000066, 0x3e0003ff, "lce\t\t%20-24r, [%15-19r]+"},
  {0x0c00000a, 0x3e00001f, "ldc1\t\tc%15-19r, [%20-24r, %5-14i]"},
  {0x0c000012, 0x3e00001f, "ldc2\t\tc%15-19r, [%20-24r, %5-14i]"},
  {0x0c00001a, 0x3e00001f, "ldc3\t\tc%15-19r, [%20-24r, %5-14i]"},
  {0x000000000001LL, 0x1c000000001fLL, "ldi48\t\t%37-41r, %5-36i"},
  {0x22000000, 0x3e000000, "lh\t\t%20-24r, [%15-19r, %0-14i]"},
  {0x24000000, 0x3e000000, "lhu\t\t%20-24r, [%15-19r, %0-14i]"},
  {0x06000001, 0x3e000007, "lh\t\t%20-24r, [%15-19r, %3-14i]+"},
  {0x06000002, 0x3e000007, "lhu\t\t%20-24r, [%15-19r, %3-14i]+"},
  {0x0e000001, 0x3e000007, "lh\t\t%20-24r, [%15-19r]+, %3-14i"},
  {0x0e000002, 0x3e000007, "lhu\t\t%20-24r, [%15-19r]+, %3-14i"},
  {0x020c0000, 0x3e0e0000, "ldi\t\t%20-24r, 0x%1-16x(%1-16i)"},
  {0x0a0c0000, 0x3e0e0000, "ldis\t\t%20-24r, 0x%1-16x(%1-16i)"},
  {0x00006400, 0x00007c00, "ldiu!\t\t%5-9r, %0-4d"},
  {0x00000032, 0x3e0003ff, "ltbw\t\t%20-24r, [%15-19r, %10-14r]"},
  {0x00000132, 0x3e0003ff, "ltbh\t\t%20-24r, [%15-19r, %10-14r]"},
  {0x00000332, 0x3e0003ff, "ltbb\t\t%20-24r, [%15-19r, %10-14r]"},
  {0x0000000c, 0x3e0003ff, "alw\t\t%20-24r, [%15-19r]"},
  {0x20000000, 0x3e000000, "lw\t\t%20-24r, [%15-19r, %0-14i]"},
  {0x06000000, 0x3e000007, "lw\t\t%20-24r, [%15-19r, %3-14i]+"},
  {0x0e000000, 0x3e000007, "lw\t\t%20-24r, [%15-19r]+, %3-14i"},
  {0x00001000, 0x00007000, "lw!\t\t%8-11r, [%5-7r,%0-4d2]"},
  {0x000000000002LL, 0x1c000000001fLL, "lw48\t\t%37-41r,[0x%7-36w]"},
  {0x00007b00, 0x00007f00, "madh.fs!\t\t%8-11r, %4-7r"},
  {0x00007a00, 0x00007f00, "madl.fs!\t\t%8-11r, %4-7r"},
  {0x00007500, 0x00007f00, "madu!\t\t%8-11r, %4-7r"},
  {0x00007400, 0x00007f00, "mad.f!\t\t%8-11r, %4-7r"},
  {0x00007900, 0x00007f00, "mazh.f!\t\t%8-11r, %4-7r"},
  {0x00007800, 0x00007f00, "mazl.f!\t\t%8-11r, %4-7r"},
  {0x00000448, 0x3e007fff, "mfcel\t\t%20-24r"},
  {0x00007100, 0x00007ff0, "mfcel!\t\t%4-7r"},
  {0x00000848, 0x3e007fff, "mfceh\t\t%20-24r"},
  {0x00007110, 0x00007ff0, "mfceh!\t\t%4-7r"},
  {0x00000c48, 0x3e007fff, "mfcehl\t\t%20-24r, %15-19r"},
  {0x00000048, 0x3e0003ff, "mfce\t\t%20-24r, er%10-14d"},
  {0x00000050, 0x3e0003ff, "mfsr\t\t%20-24r, sr%10-14d"},
  {0x0c000001, 0x3e00001f, "mfcr\t\t%20-24r, c%15-19r"},
  {0x0c000009, 0x3e00001f, "mfc1\t\t%20-24r, c%15-19r"},
  {0x0c000011, 0x3e00001f, "mfc2\t\t%20-24r, c%15-19r"},
  {0x0c000019, 0x3e00001f, "mfc3\t\t%20-24r, c%15-19r"},
  {0x0c00000f, 0x3e00001f, "mfcc1\t\t%20-24r, c%15-19r"},
  {0x0c000017, 0x3e00001f, "mfcc2\t\t%20-24r, c%15-19r"},
  {0x0c00001f, 0x3e00001f, "mfcc3\t\t%20-24r, c%15-19r"},
  /* confilct: push! mhfl!.  */
  {0x00000040, 0x00007fe0, "pop!\t\t%0-4r"},
  {0x00000060, 0x00007fe0, "push!\t\t%0-4r"},
  {0x00006800, 0x00007c00, "rpop!\t\t%5-9r, %0-4d"},
  {0x00006c00, 0x00007c00, "rpush!\t\t%5-9r, %0-4d"},
  {0x00007600, 0x00007f00, "msb.f!\t\t%8-11r, %4-7r"},
  {0x00007f00, 0x00007f00, "msbh.fs!\t\t%8-11r, %4-7r"},
  {0x00007e00, 0x00007f00, "msbl.fs!\t\t%8-11r, %4-7r"},
  {0x00007700, 0x00007f00, "msbu!\t\t%8-11r, %4-7r"},
  {0x00007d00, 0x00007f00, "mszh.f!\t\t%8-11r, %4-7r"},
  {0x00007c00, 0x00007f00, "mszl.f!\t\t%8-11r, %4-7r"},
  {0x0000044a, 0x3e007fff, "mtcel\t\t%20-24r"},
  {0x00007000, 0x00007ff0, "mtcel!\t\t%4-7r"},
  {0x0000084a, 0x3e007fff, "mtceh\t\t%20-24r"},
  {0x00007010, 0x00007ff0, "mtceh!\t\t%4-7r"},
  {0x00000c4a, 0x3e007fff, "mtcehl\t\t%20-24r, %15-19r"},
  {0x0000004a, 0x3e0003ff, "mtce\t\t%20-24r, er%10-14d"},
  {0x00000052, 0x3e0003ff, "mtsr\t\t%15-19r, sr%10-14d"},
  {0x0c000000, 0x3e00001f, "mtcr\t\t%20-24r, c%15-19r"},
  {0x0c000008, 0x3e00001f, "mtc1\t\t%20-24r, c%15-19r"},
  {0x0c000010, 0x3e00001f, "mtc2\t\t%20-24r, c%15-19r"},
  {0x0c000018, 0x3e00001f, "mtc3\t\t%20-24r, c%15-19r"},
  {0x0c00000e, 0x3e00001f, "mtcc1\t\t%20-24r, c%15-19r"},
  {0x0c000016, 0x3e00001f, "mtcc2\t\t%20-24r, c%15-19r"},
  {0x0c00001e, 0x3e00001f, "mtcc3\t\t%20-24r, c%15-19r"},
  {0x00000040, 0x3e0003ff, "mul\t\t%15-19r, %10-14r"},
  {0x00000140, 0x3e0003ff, "mulr.l\t\t%20-24r,%15-19r, %10-14r"},
  {0x00000240, 0x3e0003ff, "mulr.h\t\t%20-24r,%15-19r, %10-14r"},
  {0x00000340, 0x3e0003ff, "mulr\t\t%20-24r,%15-19r, %10-14r"},
  {0x00000041, 0x3e0003ff, "mul.f\t\t%15-19r, %10-14r"},
  {0x00000141, 0x3e0003ff, "mulr.lf\t\t%20-24r,%15-19r, %10-14r"},
  {0x00000241, 0x3e0003ff, "mulr.hf\t\t%20-24r,%15-19r, %10-14r"},
  {0x00000341, 0x3e0003ff, "mulr.f\t\t%20-24r,%15-19r, %10-14r"},
  {0x00000040, 0x3e0003ff, "maz\t\t%15-19r, %10-14r"},
  {0x00000041, 0x3e0003ff, "maz.f\t\t%15-19r, %10-14r"},
  {0x00007200, 0x00007f00, "mul.f!\t\t%8-11r, %4-7r"},
  {0x00000042, 0x3e0003ff, "mulu\t\t%15-19r, %10-14r"},
  {0x00000142, 0x3e0003ff, "mulur.l\t\t%20-24r,%15-19r, %10-14r"},
  {0x00000242, 0x3e0003ff, "mulur.h\t\t%20-24r,%15-19r, %10-14r"},
  {0x00000342, 0x3e0003ff, "mulur\t\t%20-24r,%15-19r, %10-14r"},
  {0x00000042, 0x3e0003ff, "mazu\t\t%15-19r, %10-14r"},
  {0x00007300, 0x00007f00, "mulu!\t\t%8-11r, %4-7r"},
  {0x00000056, 0x3e007fff, "mvcs\t\t%20-24r, %15-19r"},
  {0x00000456, 0x3e007fff, "mvcc\t\t%20-24r, %15-19r"},
  {0x00000856, 0x3e007fff, "mvgtu\t\t%20-24r, %15-19r"},
  {0x00000c56, 0x3e007fff, "mvleu\t\t%20-24r, %15-19r"},
  {0x00001056, 0x3e007fff, "mveq\t\t%20-24r, %15-19r"},
  {0x00001456, 0x3e007fff, "mvne\t\t%20-24r, %15-19r"},
  {0x00001856, 0x3e007fff, "mvgt\t\t%20-24r, %15-19r"},
  {0x00001c56, 0x3e007fff, "mvle\t\t%20-24r, %15-19r"},
  {0x00002056, 0x3e007fff, "mvge\t\t%20-24r, %15-19r"},
  {0x00002456, 0x3e007fff, "mvlt\t\t%20-24r, %15-19r"},
  {0x00002856, 0x3e007fff, "mvmi\t\t%20-24r, %15-19r"},
  {0x00002c56, 0x3e007fff, "mvpl\t\t%20-24r, %15-19r"},
  {0x00003056, 0x3e007fff, "mvvs\t\t%20-24r, %15-19r"},
  {0x00003456, 0x3e007fff, "mvvc\t\t%20-24r, %15-19r"},
  {0x00003c56, 0x3e007fff, "mv\t\t%20-24r, %15-19r"},
  {0x00004000, 0x00007c00, "mv!\t\t%5-9r, %0-4r"},
  {0x0000001e, 0x3e0003ff, "neg\t\t%20-24r, %10-14r"},
  {0x0000001f, 0x3e0003ff, "neg.c\t\t%20-24r, %10-14r"},
  {0x00000000, 0x3e0003ff, "nop"},
  {0x00000024, 0x3e0003ff, "not\t\t%20-24r, %15-19r"},
  {0x00000025, 0x3e0003ff, "not.c\t\t%20-24r, %15-19r"},
  {0x00000000, 0x00007fff, "nop!"},
  {0x00000022, 0x3e0003ff, "or\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000023, 0x3e0003ff, "or.c\t\t%20-24r, %15-19r, %10-14r"},
  {0x020a0000, 0x3e0e0001, "ori\t\t%20-24r, 0x%1-16x"},
  {0x020a0001, 0x3e0e0001, "ori.c\t\t%20-24r, 0x%1-16x"},
  {0x0a0a0000, 0x3e0e0001, "oris\t\t%20-24r, 0x%1-16x"},
  {0x0a0a0001, 0x3e0e0001, "oris.c\t\t%20-24r, 0x%1-16x"},
  {0x1a000000, 0x3e000001, "orri\t\t%20-24r, %15-19r, 0x%1-14x"},
  {0x1a000001, 0x3e000001, "orri.c\t\t%20-24r, %15-19r, 0x%1-14x"},
  {0x00004a00, 0x00007f00, "or!\t\t%4-7r, %0-3r"},
  {0x040000000002LL, 0x1c0000000003LL, "orri48\t\t%38-41r,%34-37r, 0x%2-33x"},
  {0x040000000003LL, 0x1c0000000003LL, "orri48.c\t\t%38-41r,%34-37r, 0x%2-33x"},
  {0x0000000a, 0x3e0003ff, "pflush"},
  {0x00000038, 0x3e0003ff, "ror\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000039, 0x3e0003ff, "ror.c\t\t%20-24r, %15-19r, %10-14r"},
  {0x0000003b, 0x3e0003ff, "rorc.c\t\t%20-24r, %15-19r, %10-14r"},
  {0x0000003c, 0x3e0003ff, "rol\t\t%20-24r, %15-19r, %10-14r"},
  {0x0000003d, 0x3e0003ff, "rol.c\t\t%20-24r, %15-19r, %10-14r"},
  {0x0000003f, 0x3e0003ff, "rolc.c\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000078, 0x3e0003ff, "rori\t\t%20-24r, %15-19r, %10-14d"},
  {0x00000079, 0x3e0003ff, "rori.c\t\t%20-24r, %15-19r, %10-14d"},
  {0x0000007b, 0x3e0003ff, "roric.c\t\t%20-24r, %15-19r, %10-14d"},
  {0x0000007c, 0x3e0003ff, "roli\t\t%20-24r, %15-19r, %10-14d"},
  {0x0000007d, 0x3e0003ff, "roli.c\t\t%20-24r, %15-19r, %10-14d"},
  {0x0000007f, 0x3e0003ff, "rolic.c\t\t%20-24r, %15-19r, %10-14d"},
  {0x0c000084, 0x3e0003ff, "rte"},
  {0x2e000000, 0x3e000000, "sb\t\t%20-24r, [%15-19r, %0-14i]"},
  {0x06000007, 0x3e000007, "sb\t\t%20-24r, [%15-19r, %3-14i]+"},
  {0x0e000007, 0x3e000007, "sb\t\t%20-24r, [%15-19r]+, %3-14i"},
  {0x0000000e, 0x3e0003ff, "asw\t\t%20-24r, [%15-19r]"},
  {0x00000068, 0x3e0003ff, "scb\t\t%20-24r, [%15-19r]+"},
  {0x0000006a, 0x3e0003ff, "scw\t\t%20-24r, [%15-19r]+"},
  {0x0000006e, 0x3e0003ff, "sce\t\t[%15-19r]+"},
  {0x00000006, 0x3e0003ff, "sdbbp\t\t%15-19d"},
  {0x00000020, 0x00007fe0, "sdbbp!\t\t%0-4d"},
  {0x000000000000LL, 0x1c000000001fLL, "sdbbp48\t\t%5-9d"},
  {0x2a000000, 0x3e000000, "sh\t\t%20-24r, [%15-19r, %0-14i]"},
  {0x06000005, 0x3e000007, "sh\t\t%20-24r, [%15-19r, %3-14i]+"},
  {0x0e000005, 0x3e000007, "sh\t\t%20-24r, [%15-19r]+, %3-14i"},
  {0x0c0000c4, 0x3e0003ff, "sleep"},
  {0x00000030, 0x3e0003ff, "sll\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000031, 0x3e0003ff, "sll.c\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000070, 0x3e0003ff, "slli\t\t%20-24r, %15-19r, %10-14d"},
  {0x00000071, 0x3e0003ff, "slli.c\t\t%20-24r, %15-19r, %10-14d"},
  {0x00005800, 0x00007e00, "slli!\t\t%5-8r, %0-4d"},
  {0x00000034, 0x3e0003ff, "srl\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000035, 0x3e0003ff, "srl.c\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000036, 0x3e0003ff, "sra\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000037, 0x3e0003ff, "sra.c\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000074, 0x3e0003ff, "srli\t\t%20-24r, %15-19r, %10-14d"},
  {0x00000075, 0x3e0003ff, "srli.c\t\t%20-24r, %15-19r, %10-14d"},
  {0x00000076, 0x3e0003ff, "srai\t\t%20-24r, %15-19r, %10-14d"},
  {0x00000077, 0x3e0003ff, "srai.c\t\t%20-24r, %15-19r, %10-14d"},
  {0x00005a00, 0x00007e00, "srli!\t\t%5-8r, %0-4d"},
  {0x0c00000b, 0x3e00001f, "stc1\t\tc%15-19r, [%20-24r, %5-14i]"},
  {0x0c000013, 0x3e00001f, "stc2\t\tc%15-19r, [%20-24r, %5-14i]"},
  {0x0c00001b, 0x3e00001f, "stc3\t\tc%15-19r, [%20-24r, %5-14i]"},
  {0x00000014, 0x3e0003ff, "sub\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000015, 0x3e0003ff, "sub.c\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000016, 0x3e0003ff, "subc\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000017, 0x3e0003ff, "subc.c\t\t%20-24r, %15-19r, %10-14r"},
  {0x00004900, 0x00007f00, "sub!\t\t%4-7r, %0-3r"},
  {0x28000000, 0x3e000000, "sw\t\t%20-24r, [%15-19r, %0-14i]"},
  {0x06000004, 0x3e000007, "sw\t\t%20-24r, [%15-19r, %3-14i]+"},
  {0x0e000004, 0x3e000007, "sw\t\t%20-24r, [%15-19r]+, %3-14i"},
  {0x00002000, 0x00007000, "sw!\t\t%8-11r, [%5-7r,%0-4d2]"},
  {0x000000000003LL, 0x1c000000001fLL, "sw48\t\t%37-41r, [0x%7-36w]"},
  {0x00000002, 0x3e0003ff, "syscall\t\t%10-24d"},
  {0x00000054, 0x3e007fff, "tcs"},
  {0x00000454, 0x3e007fff, "tcc"},
  {0x00003854, 0x3e007fff, "tcnz"},
  {0x00001054, 0x3e007fff, "teq"},
  {0x00000854, 0x3e007fff, "tgtu"},
  {0x00001854, 0x3e007fff, "tgt"},
  {0x00002054, 0x3e007fff, "tge"},
  {0x00000c54, 0x3e007fff, "tleu"},
  {0x00001c54, 0x3e007fff, "tle"},
  {0x00002454, 0x3e007fff, "tlt"},
  {0x0c000004, 0x3e0003ff, "stlb"},
  {0x0c000024, 0x3e0003ff, "mftlb"},
  {0x0c000044, 0x3e0003ff, "mtptlb"},
  {0x0c000064, 0x3e0003ff, "mtrtlb"},
  {0x00002854, 0x3e007fff, "tmi"},
  {0x00001454, 0x3e007fff, "tne"},
  {0x00002c54, 0x3e007fff, "tpl"},
  {0x00000004, 0x3e007fff, "trapcs\t\t%15-19d"},
  {0x00000404, 0x3e007fff, "trapcc\t\t%15-19d"},
  {0x00000804, 0x3e007fff, "trapgtu\t\t%15-19d"},
  {0x00000c04, 0x3e007fff, "trapleu\t\t%15-19d"},
  {0x00001004, 0x3e007fff, "trapeq\t\t%15-19d"},
  {0x00001404, 0x3e007fff, "trapne\t\t%15-19d"},
  {0x00001804, 0x3e007fff, "trapgt\t\t%15-19d"},
  {0x00001c04, 0x3e007fff, "traple\t\t%15-19d"},
  {0x00002004, 0x3e007fff, "trapge\t\t%15-19d"},
  {0x00002404, 0x3e007fff, "traplt\t\t%15-19d"},
  {0x00002804, 0x3e007fff, "trapmi\t\t%15-19d"},
  {0x00002c04, 0x3e007fff, "trappl\t\t%15-19d"},
  {0x00003004, 0x3e007fff, "trapvs\t\t%15-19d"},
  {0x00003404, 0x3e007fff, "trapvc\t\t%15-19d"},
  {0x00003c04, 0x3e007fff, "trap\t\t%15-19d"},
  {0x00003c54, 0x3e007fff, "tset"},
  {0x00003054, 0x3e007fff, "tvs"},
  {0x00003454, 0x3e007fff, "tvc"},
  {0x00000026, 0x3e0003ff, "xor\t\t%20-24r, %15-19r, %10-14r"},
  {0x00000027, 0x3e0003ff, "xor.c\t\t%20-24r, %15-19r, %10-14r"},
};