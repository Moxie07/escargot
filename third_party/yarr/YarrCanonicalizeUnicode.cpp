/*
* Copyright (C) 2016 Apple Inc. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1.  Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer. 
* 2.  Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the
*     documentation and/or other materials provided with the distribution. 
*
* THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
* THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// DO NO EDIT! - This file was generated by generateYarrCanonicalizeUnicode

#include "WTFBridge.h"
#include "YarrCanonicalize.h"

namespace JSC { namespace Yarr {

constexpr char32_t unicodeCharacterSet0[] = { 0x004b, 0x006b, 0x212a, 0 };
constexpr char32_t unicodeCharacterSet1[] = { 0x0053, 0x0073, 0x017f, 0 };
constexpr char32_t unicodeCharacterSet2[] = { 0x00c5, 0x00e5, 0x212b, 0 };
constexpr char32_t unicodeCharacterSet3[] = { 0x01c4, 0x01c5, 0x01c6, 0 };
constexpr char32_t unicodeCharacterSet4[] = { 0x01c7, 0x01c8, 0x01c9, 0 };
constexpr char32_t unicodeCharacterSet5[] = { 0x01ca, 0x01cb, 0x01cc, 0 };
constexpr char32_t unicodeCharacterSet6[] = { 0x01f1, 0x01f2, 0x01f3, 0 };
constexpr char32_t unicodeCharacterSet7[] = { 0x0392, 0x03b2, 0x03d0, 0 };
constexpr char32_t unicodeCharacterSet8[] = { 0x0395, 0x03b5, 0x03f5, 0 };
constexpr char32_t unicodeCharacterSet9[] = { 0x0398, 0x03b8, 0x03d1, 0x03f4, 0 };
constexpr char32_t unicodeCharacterSet10[] = { 0x0345, 0x0399, 0x03b9, 0x1fbe, 0 };
constexpr char32_t unicodeCharacterSet11[] = { 0x039a, 0x03ba, 0x03f0, 0 };
constexpr char32_t unicodeCharacterSet12[] = { 0x00b5, 0x039c, 0x03bc, 0 };
constexpr char32_t unicodeCharacterSet13[] = { 0x03a0, 0x03c0, 0x03d6, 0 };
constexpr char32_t unicodeCharacterSet14[] = { 0x03a1, 0x03c1, 0x03f1, 0 };
constexpr char32_t unicodeCharacterSet15[] = { 0x03a3, 0x03c2, 0x03c3, 0 };
constexpr char32_t unicodeCharacterSet16[] = { 0x03a6, 0x03c6, 0x03d5, 0 };
constexpr char32_t unicodeCharacterSet17[] = { 0x03a9, 0x03c9, 0x2126, 0 };
constexpr char32_t unicodeCharacterSet18[] = { 0x0412, 0x0432, 0x1c80, 0 };
constexpr char32_t unicodeCharacterSet19[] = { 0x0414, 0x0434, 0x1c81, 0 };
constexpr char32_t unicodeCharacterSet20[] = { 0x041e, 0x043e, 0x1c82, 0 };
constexpr char32_t unicodeCharacterSet21[] = { 0x0421, 0x0441, 0x1c83, 0 };
constexpr char32_t unicodeCharacterSet22[] = { 0x0422, 0x0442, 0x1c84, 0x1c85, 0 };
constexpr char32_t unicodeCharacterSet23[] = { 0x042a, 0x044a, 0x1c86, 0 };
constexpr char32_t unicodeCharacterSet24[] = { 0x0462, 0x0463, 0x1c87, 0 };
constexpr char32_t unicodeCharacterSet25[] = { 0x1e60, 0x1e61, 0x1e9b, 0 };
constexpr char32_t unicodeCharacterSet26[] = { 0x1c88, 0xa64a, 0xa64b, 0 };

const size_t UNICODE_CANONICALIZATION_SETS = 27;
const char32_t* unicodeCharacterSetInfo[UNICODE_CANONICALIZATION_SETS] = {
    unicodeCharacterSet0,
    unicodeCharacterSet1,
    unicodeCharacterSet2,
    unicodeCharacterSet3,
    unicodeCharacterSet4,
    unicodeCharacterSet5,
    unicodeCharacterSet6,
    unicodeCharacterSet7,
    unicodeCharacterSet8,
    unicodeCharacterSet9,
    unicodeCharacterSet10,
    unicodeCharacterSet11,
    unicodeCharacterSet12,
    unicodeCharacterSet13,
    unicodeCharacterSet14,
    unicodeCharacterSet15,
    unicodeCharacterSet16,
    unicodeCharacterSet17,
    unicodeCharacterSet18,
    unicodeCharacterSet19,
    unicodeCharacterSet20,
    unicodeCharacterSet21,
    unicodeCharacterSet22,
    unicodeCharacterSet23,
    unicodeCharacterSet24,
    unicodeCharacterSet25,
    unicodeCharacterSet26,
};

const size_t UNICODE_CANONICALIZATION_RANGES = 548;
const CanonicalizationRange unicodeRangeInfo[UNICODE_CANONICALIZATION_RANGES] = {
    { 0x0000, 0x0040, 0x0000, CanonicalizeUnique },
    { 0x0041, 0x004a, 0x0020, CanonicalizeRangeLo },
    { 0x004b, 0x004b, 0x0000, CanonicalizeSet },
    { 0x004c, 0x0052, 0x0020, CanonicalizeRangeLo },
    { 0x0053, 0x0053, 0x0001, CanonicalizeSet },
    { 0x0054, 0x005a, 0x0020, CanonicalizeRangeLo },
    { 0x005b, 0x0060, 0x0000, CanonicalizeUnique },
    { 0x0061, 0x006a, 0x0020, CanonicalizeRangeHi },
    { 0x006b, 0x006b, 0x0000, CanonicalizeSet },
    { 0x006c, 0x0072, 0x0020, CanonicalizeRangeHi },
    { 0x0073, 0x0073, 0x0001, CanonicalizeSet },
    { 0x0074, 0x007a, 0x0020, CanonicalizeRangeHi },
    { 0x007b, 0x00b4, 0x0000, CanonicalizeUnique },
    { 0x00b5, 0x00b5, 0x000c, CanonicalizeSet },
    { 0x00b6, 0x00bf, 0x0000, CanonicalizeUnique },
    { 0x00c0, 0x00c4, 0x0020, CanonicalizeRangeLo },
    { 0x00c5, 0x00c5, 0x0002, CanonicalizeSet },
    { 0x00c6, 0x00d6, 0x0020, CanonicalizeRangeLo },
    { 0x00d7, 0x00d7, 0x0000, CanonicalizeUnique },
    { 0x00d8, 0x00de, 0x0020, CanonicalizeRangeLo },
    { 0x00df, 0x00df, 0x1dbf, CanonicalizeRangeLo },
    { 0x00e0, 0x00e4, 0x0020, CanonicalizeRangeHi },
    { 0x00e5, 0x00e5, 0x0002, CanonicalizeSet },
    { 0x00e6, 0x00f6, 0x0020, CanonicalizeRangeHi },
    { 0x00f7, 0x00f7, 0x0000, CanonicalizeUnique },
    { 0x00f8, 0x00fe, 0x0020, CanonicalizeRangeHi },
    { 0x00ff, 0x00ff, 0x0079, CanonicalizeRangeLo },
    { 0x0100, 0x012f, 0x0000, CanonicalizeAlternatingAligned },
    { 0x0130, 0x0131, 0x0000, CanonicalizeUnique },
    { 0x0132, 0x0137, 0x0000, CanonicalizeAlternatingAligned },
    { 0x0138, 0x0138, 0x0000, CanonicalizeUnique },
    { 0x0139, 0x0148, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x0149, 0x0149, 0x0000, CanonicalizeUnique },
    { 0x014a, 0x0177, 0x0000, CanonicalizeAlternatingAligned },
    { 0x0178, 0x0178, 0x0079, CanonicalizeRangeHi },
    { 0x0179, 0x017e, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x017f, 0x017f, 0x0001, CanonicalizeSet },
    { 0x0180, 0x0180, 0x00c3, CanonicalizeRangeLo },
    { 0x0181, 0x0181, 0x00d2, CanonicalizeRangeLo },
    { 0x0182, 0x0185, 0x0000, CanonicalizeAlternatingAligned },
    { 0x0186, 0x0186, 0x00ce, CanonicalizeRangeLo },
    { 0x0187, 0x0188, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x0189, 0x018a, 0x00cd, CanonicalizeRangeLo },
    { 0x018b, 0x018c, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x018d, 0x018d, 0x0000, CanonicalizeUnique },
    { 0x018e, 0x018e, 0x004f, CanonicalizeRangeLo },
    { 0x018f, 0x018f, 0x00ca, CanonicalizeRangeLo },
    { 0x0190, 0x0190, 0x00cb, CanonicalizeRangeLo },
    { 0x0191, 0x0192, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x0193, 0x0193, 0x00cd, CanonicalizeRangeLo },
    { 0x0194, 0x0194, 0x00cf, CanonicalizeRangeLo },
    { 0x0195, 0x0195, 0x0061, CanonicalizeRangeLo },
    { 0x0196, 0x0196, 0x00d3, CanonicalizeRangeLo },
    { 0x0197, 0x0197, 0x00d1, CanonicalizeRangeLo },
    { 0x0198, 0x0199, 0x0000, CanonicalizeAlternatingAligned },
    { 0x019a, 0x019a, 0x00a3, CanonicalizeRangeLo },
    { 0x019b, 0x019b, 0xa641, CanonicalizeRangeLo },
    { 0x019c, 0x019c, 0x00d3, CanonicalizeRangeLo },
    { 0x019d, 0x019d, 0x00d5, CanonicalizeRangeLo },
    { 0x019e, 0x019e, 0x0082, CanonicalizeRangeLo },
    { 0x019f, 0x019f, 0x00d6, CanonicalizeRangeLo },
    { 0x01a0, 0x01a5, 0x0000, CanonicalizeAlternatingAligned },
    { 0x01a6, 0x01a6, 0x00da, CanonicalizeRangeLo },
    { 0x01a7, 0x01a8, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x01a9, 0x01a9, 0x00da, CanonicalizeRangeLo },
    { 0x01aa, 0x01ab, 0x0000, CanonicalizeUnique },
    { 0x01ac, 0x01ad, 0x0000, CanonicalizeAlternatingAligned },
    { 0x01ae, 0x01ae, 0x00da, CanonicalizeRangeLo },
    { 0x01af, 0x01b0, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x01b1, 0x01b2, 0x00d9, CanonicalizeRangeLo },
    { 0x01b3, 0x01b6, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x01b7, 0x01b7, 0x00db, CanonicalizeRangeLo },
    { 0x01b8, 0x01b9, 0x0000, CanonicalizeAlternatingAligned },
    { 0x01ba, 0x01bb, 0x0000, CanonicalizeUnique },
    { 0x01bc, 0x01bd, 0x0000, CanonicalizeAlternatingAligned },
    { 0x01be, 0x01be, 0x0000, CanonicalizeUnique },
    { 0x01bf, 0x01bf, 0x0038, CanonicalizeRangeLo },
    { 0x01c0, 0x01c3, 0x0000, CanonicalizeUnique },
    { 0x01c4, 0x01c6, 0x0003, CanonicalizeSet },
    { 0x01c7, 0x01c9, 0x0004, CanonicalizeSet },
    { 0x01ca, 0x01cc, 0x0005, CanonicalizeSet },
    { 0x01cd, 0x01dc, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x01dd, 0x01dd, 0x004f, CanonicalizeRangeHi },
    { 0x01de, 0x01ef, 0x0000, CanonicalizeAlternatingAligned },
    { 0x01f0, 0x01f0, 0x0000, CanonicalizeUnique },
    { 0x01f1, 0x01f3, 0x0006, CanonicalizeSet },
    { 0x01f4, 0x01f5, 0x0000, CanonicalizeAlternatingAligned },
    { 0x01f6, 0x01f6, 0x0061, CanonicalizeRangeHi },
    { 0x01f7, 0x01f7, 0x0038, CanonicalizeRangeHi },
    { 0x01f8, 0x021f, 0x0000, CanonicalizeAlternatingAligned },
    { 0x0220, 0x0220, 0x0082, CanonicalizeRangeHi },
    { 0x0221, 0x0221, 0x0000, CanonicalizeUnique },
    { 0x0222, 0x0233, 0x0000, CanonicalizeAlternatingAligned },
    { 0x0234, 0x0239, 0x0000, CanonicalizeUnique },
    { 0x023a, 0x023a, 0x2a2b, CanonicalizeRangeLo },
    { 0x023b, 0x023c, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x023d, 0x023d, 0x00a3, CanonicalizeRangeHi },
    { 0x023e, 0x023e, 0x2a28, CanonicalizeRangeLo },
    { 0x023f, 0x0240, 0x2a3f, CanonicalizeRangeLo },
    { 0x0241, 0x0242, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x0243, 0x0243, 0x00c3, CanonicalizeRangeHi },
    { 0x0244, 0x0244, 0x0045, CanonicalizeRangeLo },
    { 0x0245, 0x0245, 0x0047, CanonicalizeRangeLo },
    { 0x0246, 0x024f, 0x0000, CanonicalizeAlternatingAligned },
    { 0x0250, 0x0250, 0x2a1f, CanonicalizeRangeLo },
    { 0x0251, 0x0251, 0x2a1c, CanonicalizeRangeLo },
    { 0x0252, 0x0252, 0x2a1e, CanonicalizeRangeLo },
    { 0x0253, 0x0253, 0x00d2, CanonicalizeRangeHi },
    { 0x0254, 0x0254, 0x00ce, CanonicalizeRangeHi },
    { 0x0255, 0x0255, 0x0000, CanonicalizeUnique },
    { 0x0256, 0x0257, 0x00cd, CanonicalizeRangeHi },
    { 0x0258, 0x0258, 0x0000, CanonicalizeUnique },
    { 0x0259, 0x0259, 0x00ca, CanonicalizeRangeHi },
    { 0x025a, 0x025a, 0x0000, CanonicalizeUnique },
    { 0x025b, 0x025b, 0x00cb, CanonicalizeRangeHi },
    { 0x025c, 0x025c, 0xa54f, CanonicalizeRangeLo },
    { 0x025d, 0x025f, 0x0000, CanonicalizeUnique },
    { 0x0260, 0x0260, 0x00cd, CanonicalizeRangeHi },
    { 0x0261, 0x0261, 0xa54b, CanonicalizeRangeLo },
    { 0x0262, 0x0262, 0x0000, CanonicalizeUnique },
    { 0x0263, 0x0263, 0x00cf, CanonicalizeRangeHi },
    { 0x0264, 0x0264, 0xa567, CanonicalizeRangeLo },
    { 0x0265, 0x0265, 0xa528, CanonicalizeRangeLo },
    { 0x0266, 0x0266, 0xa544, CanonicalizeRangeLo },
    { 0x0267, 0x0267, 0x0000, CanonicalizeUnique },
    { 0x0268, 0x0268, 0x00d1, CanonicalizeRangeHi },
    { 0x0269, 0x0269, 0x00d3, CanonicalizeRangeHi },
    { 0x026a, 0x026a, 0xa544, CanonicalizeRangeLo },
    { 0x026b, 0x026b, 0x29f7, CanonicalizeRangeLo },
    { 0x026c, 0x026c, 0xa541, CanonicalizeRangeLo },
    { 0x026d, 0x026e, 0x0000, CanonicalizeUnique },
    { 0x026f, 0x026f, 0x00d3, CanonicalizeRangeHi },
    { 0x0270, 0x0270, 0x0000, CanonicalizeUnique },
    { 0x0271, 0x0271, 0x29fd, CanonicalizeRangeLo },
    { 0x0272, 0x0272, 0x00d5, CanonicalizeRangeHi },
    { 0x0273, 0x0274, 0x0000, CanonicalizeUnique },
    { 0x0275, 0x0275, 0x00d6, CanonicalizeRangeHi },
    { 0x0276, 0x027c, 0x0000, CanonicalizeUnique },
    { 0x027d, 0x027d, 0x29e7, CanonicalizeRangeLo },
    { 0x027e, 0x027f, 0x0000, CanonicalizeUnique },
    { 0x0280, 0x0280, 0x00da, CanonicalizeRangeHi },
    { 0x0281, 0x0281, 0x0000, CanonicalizeUnique },
    { 0x0282, 0x0282, 0xa543, CanonicalizeRangeLo },
    { 0x0283, 0x0283, 0x00da, CanonicalizeRangeHi },
    { 0x0284, 0x0286, 0x0000, CanonicalizeUnique },
    { 0x0287, 0x0287, 0xa52a, CanonicalizeRangeLo },
    { 0x0288, 0x0288, 0x00da, CanonicalizeRangeHi },
    { 0x0289, 0x0289, 0x0045, CanonicalizeRangeHi },
    { 0x028a, 0x028b, 0x00d9, CanonicalizeRangeHi },
    { 0x028c, 0x028c, 0x0047, CanonicalizeRangeHi },
    { 0x028d, 0x0291, 0x0000, CanonicalizeUnique },
    { 0x0292, 0x0292, 0x00db, CanonicalizeRangeHi },
    { 0x0293, 0x029c, 0x0000, CanonicalizeUnique },
    { 0x029d, 0x029d, 0xa515, CanonicalizeRangeLo },
    { 0x029e, 0x029e, 0xa512, CanonicalizeRangeLo },
    { 0x029f, 0x0344, 0x0000, CanonicalizeUnique },
    { 0x0345, 0x0345, 0x000a, CanonicalizeSet },
    { 0x0346, 0x036f, 0x0000, CanonicalizeUnique },
    { 0x0370, 0x0373, 0x0000, CanonicalizeAlternatingAligned },
    { 0x0374, 0x0375, 0x0000, CanonicalizeUnique },
    { 0x0376, 0x0377, 0x0000, CanonicalizeAlternatingAligned },
    { 0x0378, 0x037a, 0x0000, CanonicalizeUnique },
    { 0x037b, 0x037d, 0x0082, CanonicalizeRangeLo },
    { 0x037e, 0x037e, 0x0000, CanonicalizeUnique },
    { 0x037f, 0x037f, 0x0074, CanonicalizeRangeLo },
    { 0x0380, 0x0385, 0x0000, CanonicalizeUnique },
    { 0x0386, 0x0386, 0x0026, CanonicalizeRangeLo },
    { 0x0387, 0x0387, 0x0000, CanonicalizeUnique },
    { 0x0388, 0x038a, 0x0025, CanonicalizeRangeLo },
    { 0x038b, 0x038b, 0x0000, CanonicalizeUnique },
    { 0x038c, 0x038c, 0x0040, CanonicalizeRangeLo },
    { 0x038d, 0x038d, 0x0000, CanonicalizeUnique },
    { 0x038e, 0x038f, 0x003f, CanonicalizeRangeLo },
    { 0x0390, 0x0390, 0x1c43, CanonicalizeRangeLo },
    { 0x0391, 0x0391, 0x0020, CanonicalizeRangeLo },
    { 0x0392, 0x0392, 0x0007, CanonicalizeSet },
    { 0x0393, 0x0394, 0x0020, CanonicalizeRangeLo },
    { 0x0395, 0x0395, 0x0008, CanonicalizeSet },
    { 0x0396, 0x0397, 0x0020, CanonicalizeRangeLo },
    { 0x0398, 0x0398, 0x0009, CanonicalizeSet },
    { 0x0399, 0x0399, 0x000a, CanonicalizeSet },
    { 0x039a, 0x039a, 0x000b, CanonicalizeSet },
    { 0x039b, 0x039b, 0x0020, CanonicalizeRangeLo },
    { 0x039c, 0x039c, 0x000c, CanonicalizeSet },
    { 0x039d, 0x039f, 0x0020, CanonicalizeRangeLo },
    { 0x03a0, 0x03a0, 0x000d, CanonicalizeSet },
    { 0x03a1, 0x03a1, 0x000e, CanonicalizeSet },
    { 0x03a2, 0x03a2, 0x0000, CanonicalizeUnique },
    { 0x03a3, 0x03a3, 0x000f, CanonicalizeSet },
    { 0x03a4, 0x03a5, 0x0020, CanonicalizeRangeLo },
    { 0x03a6, 0x03a6, 0x0010, CanonicalizeSet },
    { 0x03a7, 0x03a8, 0x0020, CanonicalizeRangeLo },
    { 0x03a9, 0x03a9, 0x0011, CanonicalizeSet },
    { 0x03aa, 0x03ab, 0x0020, CanonicalizeRangeLo },
    { 0x03ac, 0x03ac, 0x0026, CanonicalizeRangeHi },
    { 0x03ad, 0x03af, 0x0025, CanonicalizeRangeHi },
    { 0x03b0, 0x03b0, 0x1c33, CanonicalizeRangeLo },
    { 0x03b1, 0x03b1, 0x0020, CanonicalizeRangeHi },
    { 0x03b2, 0x03b2, 0x0007, CanonicalizeSet },
    { 0x03b3, 0x03b4, 0x0020, CanonicalizeRangeHi },
    { 0x03b5, 0x03b5, 0x0008, CanonicalizeSet },
    { 0x03b6, 0x03b7, 0x0020, CanonicalizeRangeHi },
    { 0x03b8, 0x03b8, 0x0009, CanonicalizeSet },
    { 0x03b9, 0x03b9, 0x000a, CanonicalizeSet },
    { 0x03ba, 0x03ba, 0x000b, CanonicalizeSet },
    { 0x03bb, 0x03bb, 0x0020, CanonicalizeRangeHi },
    { 0x03bc, 0x03bc, 0x000c, CanonicalizeSet },
    { 0x03bd, 0x03bf, 0x0020, CanonicalizeRangeHi },
    { 0x03c0, 0x03c0, 0x000d, CanonicalizeSet },
    { 0x03c1, 0x03c1, 0x000e, CanonicalizeSet },
    { 0x03c2, 0x03c3, 0x000f, CanonicalizeSet },
    { 0x03c4, 0x03c5, 0x0020, CanonicalizeRangeHi },
    { 0x03c6, 0x03c6, 0x0010, CanonicalizeSet },
    { 0x03c7, 0x03c8, 0x0020, CanonicalizeRangeHi },
    { 0x03c9, 0x03c9, 0x0011, CanonicalizeSet },
    { 0x03ca, 0x03cb, 0x0020, CanonicalizeRangeHi },
    { 0x03cc, 0x03cc, 0x0040, CanonicalizeRangeHi },
    { 0x03cd, 0x03ce, 0x003f, CanonicalizeRangeHi },
    { 0x03cf, 0x03cf, 0x0008, CanonicalizeRangeLo },
    { 0x03d0, 0x03d0, 0x0007, CanonicalizeSet },
    { 0x03d1, 0x03d1, 0x0009, CanonicalizeSet },
    { 0x03d2, 0x03d4, 0x0000, CanonicalizeUnique },
    { 0x03d5, 0x03d5, 0x0010, CanonicalizeSet },
    { 0x03d6, 0x03d6, 0x000d, CanonicalizeSet },
    { 0x03d7, 0x03d7, 0x0008, CanonicalizeRangeHi },
    { 0x03d8, 0x03ef, 0x0000, CanonicalizeAlternatingAligned },
    { 0x03f0, 0x03f0, 0x000b, CanonicalizeSet },
    { 0x03f1, 0x03f1, 0x000e, CanonicalizeSet },
    { 0x03f2, 0x03f2, 0x0007, CanonicalizeRangeLo },
    { 0x03f3, 0x03f3, 0x0074, CanonicalizeRangeHi },
    { 0x03f4, 0x03f4, 0x0009, CanonicalizeSet },
    { 0x03f5, 0x03f5, 0x0008, CanonicalizeSet },
    { 0x03f6, 0x03f6, 0x0000, CanonicalizeUnique },
    { 0x03f7, 0x03f8, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x03f9, 0x03f9, 0x0007, CanonicalizeRangeHi },
    { 0x03fa, 0x03fb, 0x0000, CanonicalizeAlternatingAligned },
    { 0x03fc, 0x03fc, 0x0000, CanonicalizeUnique },
    { 0x03fd, 0x03ff, 0x0082, CanonicalizeRangeHi },
    { 0x0400, 0x040f, 0x0050, CanonicalizeRangeLo },
    { 0x0410, 0x0411, 0x0020, CanonicalizeRangeLo },
    { 0x0412, 0x0412, 0x0012, CanonicalizeSet },
    { 0x0413, 0x0413, 0x0020, CanonicalizeRangeLo },
    { 0x0414, 0x0414, 0x0013, CanonicalizeSet },
    { 0x0415, 0x041d, 0x0020, CanonicalizeRangeLo },
    { 0x041e, 0x041e, 0x0014, CanonicalizeSet },
    { 0x041f, 0x0420, 0x0020, CanonicalizeRangeLo },
    { 0x0421, 0x0421, 0x0015, CanonicalizeSet },
    { 0x0422, 0x0422, 0x0016, CanonicalizeSet },
    { 0x0423, 0x0429, 0x0020, CanonicalizeRangeLo },
    { 0x042a, 0x042a, 0x0017, CanonicalizeSet },
    { 0x042b, 0x042f, 0x0020, CanonicalizeRangeLo },
    { 0x0430, 0x0431, 0x0020, CanonicalizeRangeHi },
    { 0x0432, 0x0432, 0x0012, CanonicalizeSet },
    { 0x0433, 0x0433, 0x0020, CanonicalizeRangeHi },
    { 0x0434, 0x0434, 0x0013, CanonicalizeSet },
    { 0x0435, 0x043d, 0x0020, CanonicalizeRangeHi },
    { 0x043e, 0x043e, 0x0014, CanonicalizeSet },
    { 0x043f, 0x0440, 0x0020, CanonicalizeRangeHi },
    { 0x0441, 0x0441, 0x0015, CanonicalizeSet },
    { 0x0442, 0x0442, 0x0016, CanonicalizeSet },
    { 0x0443, 0x0449, 0x0020, CanonicalizeRangeHi },
    { 0x044a, 0x044a, 0x0017, CanonicalizeSet },
    { 0x044b, 0x044f, 0x0020, CanonicalizeRangeHi },
    { 0x0450, 0x045f, 0x0050, CanonicalizeRangeHi },
    { 0x0460, 0x0461, 0x0000, CanonicalizeAlternatingAligned },
    { 0x0462, 0x0463, 0x0018, CanonicalizeSet },
    { 0x0464, 0x0481, 0x0000, CanonicalizeAlternatingAligned },
    { 0x0482, 0x0489, 0x0000, CanonicalizeUnique },
    { 0x048a, 0x04bf, 0x0000, CanonicalizeAlternatingAligned },
    { 0x04c0, 0x04c0, 0x000f, CanonicalizeRangeLo },
    { 0x04c1, 0x04ce, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x04cf, 0x04cf, 0x000f, CanonicalizeRangeHi },
    { 0x04d0, 0x052f, 0x0000, CanonicalizeAlternatingAligned },
    { 0x0530, 0x0530, 0x0000, CanonicalizeUnique },
    { 0x0531, 0x0556, 0x0030, CanonicalizeRangeLo },
    { 0x0557, 0x0560, 0x0000, CanonicalizeUnique },
    { 0x0561, 0x0586, 0x0030, CanonicalizeRangeHi },
    { 0x0587, 0x109f, 0x0000, CanonicalizeUnique },
    { 0x10a0, 0x10c5, 0x1c60, CanonicalizeRangeLo },
    { 0x10c6, 0x10c6, 0x0000, CanonicalizeUnique },
    { 0x10c7, 0x10c7, 0x1c60, CanonicalizeRangeLo },
    { 0x10c8, 0x10cc, 0x0000, CanonicalizeUnique },
    { 0x10cd, 0x10cd, 0x1c60, CanonicalizeRangeLo },
    { 0x10ce, 0x10cf, 0x0000, CanonicalizeUnique },
    { 0x10d0, 0x10fa, 0x0bc0, CanonicalizeRangeLo },
    { 0x10fb, 0x10fc, 0x0000, CanonicalizeUnique },
    { 0x10fd, 0x10ff, 0x0bc0, CanonicalizeRangeLo },
    { 0x1100, 0x139f, 0x0000, CanonicalizeUnique },
    { 0x13a0, 0x13ef, 0x97d0, CanonicalizeRangeLo },
    { 0x13f0, 0x13f5, 0x0008, CanonicalizeRangeLo },
    { 0x13f6, 0x13f7, 0x0000, CanonicalizeUnique },
    { 0x13f8, 0x13fd, 0x0008, CanonicalizeRangeHi },
    { 0x13fe, 0x1c7f, 0x0000, CanonicalizeUnique },
    { 0x1c80, 0x1c80, 0x0012, CanonicalizeSet },
    { 0x1c81, 0x1c81, 0x0013, CanonicalizeSet },
    { 0x1c82, 0x1c82, 0x0014, CanonicalizeSet },
    { 0x1c83, 0x1c83, 0x0015, CanonicalizeSet },
    { 0x1c84, 0x1c85, 0x0016, CanonicalizeSet },
    { 0x1c86, 0x1c86, 0x0017, CanonicalizeSet },
    { 0x1c87, 0x1c87, 0x0018, CanonicalizeSet },
    { 0x1c88, 0x1c88, 0x001a, CanonicalizeSet },
    { 0x1c89, 0x1c8a, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x1c8b, 0x1c8f, 0x0000, CanonicalizeUnique },
    { 0x1c90, 0x1cba, 0x0bc0, CanonicalizeRangeHi },
    { 0x1cbb, 0x1cbc, 0x0000, CanonicalizeUnique },
    { 0x1cbd, 0x1cbf, 0x0bc0, CanonicalizeRangeHi },
    { 0x1cc0, 0x1d78, 0x0000, CanonicalizeUnique },
    { 0x1d79, 0x1d79, 0x8a04, CanonicalizeRangeLo },
    { 0x1d7a, 0x1d7c, 0x0000, CanonicalizeUnique },
    { 0x1d7d, 0x1d7d, 0x0ee6, CanonicalizeRangeLo },
    { 0x1d7e, 0x1d8d, 0x0000, CanonicalizeUnique },
    { 0x1d8e, 0x1d8e, 0x8a38, CanonicalizeRangeLo },
    { 0x1d8f, 0x1dff, 0x0000, CanonicalizeUnique },
    { 0x1e00, 0x1e5f, 0x0000, CanonicalizeAlternatingAligned },
    { 0x1e60, 0x1e61, 0x0019, CanonicalizeSet },
    { 0x1e62, 0x1e95, 0x0000, CanonicalizeAlternatingAligned },
    { 0x1e96, 0x1e9a, 0x0000, CanonicalizeUnique },
    { 0x1e9b, 0x1e9b, 0x0019, CanonicalizeSet },
    { 0x1e9c, 0x1e9d, 0x0000, CanonicalizeUnique },
    { 0x1e9e, 0x1e9e, 0x1dbf, CanonicalizeRangeHi },
    { 0x1e9f, 0x1e9f, 0x0000, CanonicalizeUnique },
    { 0x1ea0, 0x1eff, 0x0000, CanonicalizeAlternatingAligned },
    { 0x1f00, 0x1f07, 0x0008, CanonicalizeRangeLo },
    { 0x1f08, 0x1f0f, 0x0008, CanonicalizeRangeHi },
    { 0x1f10, 0x1f15, 0x0008, CanonicalizeRangeLo },
    { 0x1f16, 0x1f17, 0x0000, CanonicalizeUnique },
    { 0x1f18, 0x1f1d, 0x0008, CanonicalizeRangeHi },
    { 0x1f1e, 0x1f1f, 0x0000, CanonicalizeUnique },
    { 0x1f20, 0x1f27, 0x0008, CanonicalizeRangeLo },
    { 0x1f28, 0x1f2f, 0x0008, CanonicalizeRangeHi },
    { 0x1f30, 0x1f37, 0x0008, CanonicalizeRangeLo },
    { 0x1f38, 0x1f3f, 0x0008, CanonicalizeRangeHi },
    { 0x1f40, 0x1f45, 0x0008, CanonicalizeRangeLo },
    { 0x1f46, 0x1f47, 0x0000, CanonicalizeUnique },
    { 0x1f48, 0x1f4d, 0x0008, CanonicalizeRangeHi },
    { 0x1f4e, 0x1f50, 0x0000, CanonicalizeUnique },
    { 0x1f51, 0x1f51, 0x0008, CanonicalizeRangeLo },
    { 0x1f52, 0x1f52, 0x0000, CanonicalizeUnique },
    { 0x1f53, 0x1f53, 0x0008, CanonicalizeRangeLo },
    { 0x1f54, 0x1f54, 0x0000, CanonicalizeUnique },
    { 0x1f55, 0x1f55, 0x0008, CanonicalizeRangeLo },
    { 0x1f56, 0x1f56, 0x0000, CanonicalizeUnique },
    { 0x1f57, 0x1f57, 0x0008, CanonicalizeRangeLo },
    { 0x1f58, 0x1f58, 0x0000, CanonicalizeUnique },
    { 0x1f59, 0x1f59, 0x0008, CanonicalizeRangeHi },
    { 0x1f5a, 0x1f5a, 0x0000, CanonicalizeUnique },
    { 0x1f5b, 0x1f5b, 0x0008, CanonicalizeRangeHi },
    { 0x1f5c, 0x1f5c, 0x0000, CanonicalizeUnique },
    { 0x1f5d, 0x1f5d, 0x0008, CanonicalizeRangeHi },
    { 0x1f5e, 0x1f5e, 0x0000, CanonicalizeUnique },
    { 0x1f5f, 0x1f5f, 0x0008, CanonicalizeRangeHi },
    { 0x1f60, 0x1f67, 0x0008, CanonicalizeRangeLo },
    { 0x1f68, 0x1f6f, 0x0008, CanonicalizeRangeHi },
    { 0x1f70, 0x1f71, 0x004a, CanonicalizeRangeLo },
    { 0x1f72, 0x1f75, 0x0056, CanonicalizeRangeLo },
    { 0x1f76, 0x1f77, 0x0064, CanonicalizeRangeLo },
    { 0x1f78, 0x1f79, 0x0080, CanonicalizeRangeLo },
    { 0x1f7a, 0x1f7b, 0x0070, CanonicalizeRangeLo },
    { 0x1f7c, 0x1f7d, 0x007e, CanonicalizeRangeLo },
    { 0x1f7e, 0x1f7f, 0x0000, CanonicalizeUnique },
    { 0x1f80, 0x1f87, 0x0008, CanonicalizeRangeLo },
    { 0x1f88, 0x1f8f, 0x0008, CanonicalizeRangeHi },
    { 0x1f90, 0x1f97, 0x0008, CanonicalizeRangeLo },
    { 0x1f98, 0x1f9f, 0x0008, CanonicalizeRangeHi },
    { 0x1fa0, 0x1fa7, 0x0008, CanonicalizeRangeLo },
    { 0x1fa8, 0x1faf, 0x0008, CanonicalizeRangeHi },
    { 0x1fb0, 0x1fb1, 0x0008, CanonicalizeRangeLo },
    { 0x1fb2, 0x1fb2, 0x0000, CanonicalizeUnique },
    { 0x1fb3, 0x1fb3, 0x0009, CanonicalizeRangeLo },
    { 0x1fb4, 0x1fb7, 0x0000, CanonicalizeUnique },
    { 0x1fb8, 0x1fb9, 0x0008, CanonicalizeRangeHi },
    { 0x1fba, 0x1fbb, 0x004a, CanonicalizeRangeHi },
    { 0x1fbc, 0x1fbc, 0x0009, CanonicalizeRangeHi },
    { 0x1fbd, 0x1fbd, 0x0000, CanonicalizeUnique },
    { 0x1fbe, 0x1fbe, 0x000a, CanonicalizeSet },
    { 0x1fbf, 0x1fc2, 0x0000, CanonicalizeUnique },
    { 0x1fc3, 0x1fc3, 0x0009, CanonicalizeRangeLo },
    { 0x1fc4, 0x1fc7, 0x0000, CanonicalizeUnique },
    { 0x1fc8, 0x1fcb, 0x0056, CanonicalizeRangeHi },
    { 0x1fcc, 0x1fcc, 0x0009, CanonicalizeRangeHi },
    { 0x1fcd, 0x1fcf, 0x0000, CanonicalizeUnique },
    { 0x1fd0, 0x1fd1, 0x0008, CanonicalizeRangeLo },
    { 0x1fd2, 0x1fd2, 0x0000, CanonicalizeUnique },
    { 0x1fd3, 0x1fd3, 0x1c43, CanonicalizeRangeHi },
    { 0x1fd4, 0x1fd7, 0x0000, CanonicalizeUnique },
    { 0x1fd8, 0x1fd9, 0x0008, CanonicalizeRangeHi },
    { 0x1fda, 0x1fdb, 0x0064, CanonicalizeRangeHi },
    { 0x1fdc, 0x1fdf, 0x0000, CanonicalizeUnique },
    { 0x1fe0, 0x1fe1, 0x0008, CanonicalizeRangeLo },
    { 0x1fe2, 0x1fe2, 0x0000, CanonicalizeUnique },
    { 0x1fe3, 0x1fe3, 0x1c33, CanonicalizeRangeHi },
    { 0x1fe4, 0x1fe4, 0x0000, CanonicalizeUnique },
    { 0x1fe5, 0x1fe5, 0x0007, CanonicalizeRangeLo },
    { 0x1fe6, 0x1fe7, 0x0000, CanonicalizeUnique },
    { 0x1fe8, 0x1fe9, 0x0008, CanonicalizeRangeHi },
    { 0x1fea, 0x1feb, 0x0070, CanonicalizeRangeHi },
    { 0x1fec, 0x1fec, 0x0007, CanonicalizeRangeHi },
    { 0x1fed, 0x1ff2, 0x0000, CanonicalizeUnique },
    { 0x1ff3, 0x1ff3, 0x0009, CanonicalizeRangeLo },
    { 0x1ff4, 0x1ff7, 0x0000, CanonicalizeUnique },
    { 0x1ff8, 0x1ff9, 0x0080, CanonicalizeRangeHi },
    { 0x1ffa, 0x1ffb, 0x007e, CanonicalizeRangeHi },
    { 0x1ffc, 0x1ffc, 0x0009, CanonicalizeRangeHi },
    { 0x1ffd, 0x2125, 0x0000, CanonicalizeUnique },
    { 0x2126, 0x2126, 0x0011, CanonicalizeSet },
    { 0x2127, 0x2129, 0x0000, CanonicalizeUnique },
    { 0x212a, 0x212a, 0x0000, CanonicalizeSet },
    { 0x212b, 0x212b, 0x0002, CanonicalizeSet },
    { 0x212c, 0x2131, 0x0000, CanonicalizeUnique },
    { 0x2132, 0x2132, 0x001c, CanonicalizeRangeLo },
    { 0x2133, 0x214d, 0x0000, CanonicalizeUnique },
    { 0x214e, 0x214e, 0x001c, CanonicalizeRangeHi },
    { 0x214f, 0x215f, 0x0000, CanonicalizeUnique },
    { 0x2160, 0x216f, 0x0010, CanonicalizeRangeLo },
    { 0x2170, 0x217f, 0x0010, CanonicalizeRangeHi },
    { 0x2180, 0x2182, 0x0000, CanonicalizeUnique },
    { 0x2183, 0x2184, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x2185, 0x24b5, 0x0000, CanonicalizeUnique },
    { 0x24b6, 0x24cf, 0x001a, CanonicalizeRangeLo },
    { 0x24d0, 0x24e9, 0x001a, CanonicalizeRangeHi },
    { 0x24ea, 0x2bff, 0x0000, CanonicalizeUnique },
    { 0x2c00, 0x2c2f, 0x0030, CanonicalizeRangeLo },
    { 0x2c30, 0x2c5f, 0x0030, CanonicalizeRangeHi },
    { 0x2c60, 0x2c61, 0x0000, CanonicalizeAlternatingAligned },
    { 0x2c62, 0x2c62, 0x29f7, CanonicalizeRangeHi },
    { 0x2c63, 0x2c63, 0x0ee6, CanonicalizeRangeHi },
    { 0x2c64, 0x2c64, 0x29e7, CanonicalizeRangeHi },
    { 0x2c65, 0x2c65, 0x2a2b, CanonicalizeRangeHi },
    { 0x2c66, 0x2c66, 0x2a28, CanonicalizeRangeHi },
    { 0x2c67, 0x2c6c, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x2c6d, 0x2c6d, 0x2a1c, CanonicalizeRangeHi },
    { 0x2c6e, 0x2c6e, 0x29fd, CanonicalizeRangeHi },
    { 0x2c6f, 0x2c6f, 0x2a1f, CanonicalizeRangeHi },
    { 0x2c70, 0x2c70, 0x2a1e, CanonicalizeRangeHi },
    { 0x2c71, 0x2c71, 0x0000, CanonicalizeUnique },
    { 0x2c72, 0x2c73, 0x0000, CanonicalizeAlternatingAligned },
    { 0x2c74, 0x2c74, 0x0000, CanonicalizeUnique },
    { 0x2c75, 0x2c76, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x2c77, 0x2c7d, 0x0000, CanonicalizeUnique },
    { 0x2c7e, 0x2c7f, 0x2a3f, CanonicalizeRangeHi },
    { 0x2c80, 0x2ce3, 0x0000, CanonicalizeAlternatingAligned },
    { 0x2ce4, 0x2cea, 0x0000, CanonicalizeUnique },
    { 0x2ceb, 0x2cee, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0x2cef, 0x2cf1, 0x0000, CanonicalizeUnique },
    { 0x2cf2, 0x2cf3, 0x0000, CanonicalizeAlternatingAligned },
    { 0x2cf4, 0x2cff, 0x0000, CanonicalizeUnique },
    { 0x2d00, 0x2d25, 0x1c60, CanonicalizeRangeHi },
    { 0x2d26, 0x2d26, 0x0000, CanonicalizeUnique },
    { 0x2d27, 0x2d27, 0x1c60, CanonicalizeRangeHi },
    { 0x2d28, 0x2d2c, 0x0000, CanonicalizeUnique },
    { 0x2d2d, 0x2d2d, 0x1c60, CanonicalizeRangeHi },
    { 0x2d2e, 0xa63f, 0x0000, CanonicalizeUnique },
    { 0xa640, 0xa649, 0x0000, CanonicalizeAlternatingAligned },
    { 0xa64a, 0xa64b, 0x001a, CanonicalizeSet },
    { 0xa64c, 0xa66d, 0x0000, CanonicalizeAlternatingAligned },
    { 0xa66e, 0xa67f, 0x0000, CanonicalizeUnique },
    { 0xa680, 0xa69b, 0x0000, CanonicalizeAlternatingAligned },
    { 0xa69c, 0xa721, 0x0000, CanonicalizeUnique },
    { 0xa722, 0xa72f, 0x0000, CanonicalizeAlternatingAligned },
    { 0xa730, 0xa731, 0x0000, CanonicalizeUnique },
    { 0xa732, 0xa76f, 0x0000, CanonicalizeAlternatingAligned },
    { 0xa770, 0xa778, 0x0000, CanonicalizeUnique },
    { 0xa779, 0xa77c, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0xa77d, 0xa77d, 0x8a04, CanonicalizeRangeHi },
    { 0xa77e, 0xa787, 0x0000, CanonicalizeAlternatingAligned },
    { 0xa788, 0xa78a, 0x0000, CanonicalizeUnique },
    { 0xa78b, 0xa78c, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0xa78d, 0xa78d, 0xa528, CanonicalizeRangeHi },
    { 0xa78e, 0xa78f, 0x0000, CanonicalizeUnique },
    { 0xa790, 0xa793, 0x0000, CanonicalizeAlternatingAligned },
    { 0xa794, 0xa794, 0x0030, CanonicalizeRangeLo },
    { 0xa795, 0xa795, 0x0000, CanonicalizeUnique },
    { 0xa796, 0xa7a9, 0x0000, CanonicalizeAlternatingAligned },
    { 0xa7aa, 0xa7aa, 0xa544, CanonicalizeRangeHi },
    { 0xa7ab, 0xa7ab, 0xa54f, CanonicalizeRangeHi },
    { 0xa7ac, 0xa7ac, 0xa54b, CanonicalizeRangeHi },
    { 0xa7ad, 0xa7ad, 0xa541, CanonicalizeRangeHi },
    { 0xa7ae, 0xa7ae, 0xa544, CanonicalizeRangeHi },
    { 0xa7af, 0xa7af, 0x0000, CanonicalizeUnique },
    { 0xa7b0, 0xa7b0, 0xa512, CanonicalizeRangeHi },
    { 0xa7b1, 0xa7b1, 0xa52a, CanonicalizeRangeHi },
    { 0xa7b2, 0xa7b2, 0xa515, CanonicalizeRangeHi },
    { 0xa7b3, 0xa7b3, 0x03a0, CanonicalizeRangeLo },
    { 0xa7b4, 0xa7c3, 0x0000, CanonicalizeAlternatingAligned },
    { 0xa7c4, 0xa7c4, 0x0030, CanonicalizeRangeHi },
    { 0xa7c5, 0xa7c5, 0xa543, CanonicalizeRangeHi },
    { 0xa7c6, 0xa7c6, 0x8a38, CanonicalizeRangeHi },
    { 0xa7c7, 0xa7ca, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0xa7cb, 0xa7cb, 0xa567, CanonicalizeRangeHi },
    { 0xa7cc, 0xa7cd, 0x0000, CanonicalizeAlternatingAligned },
    { 0xa7ce, 0xa7cf, 0x0000, CanonicalizeUnique },
    { 0xa7d0, 0xa7d1, 0x0000, CanonicalizeAlternatingAligned },
    { 0xa7d2, 0xa7d5, 0x0000, CanonicalizeUnique },
    { 0xa7d6, 0xa7db, 0x0000, CanonicalizeAlternatingAligned },
    { 0xa7dc, 0xa7dc, 0xa641, CanonicalizeRangeHi },
    { 0xa7dd, 0xa7f4, 0x0000, CanonicalizeUnique },
    { 0xa7f5, 0xa7f6, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0xa7f7, 0xab52, 0x0000, CanonicalizeUnique },
    { 0xab53, 0xab53, 0x03a0, CanonicalizeRangeHi },
    { 0xab54, 0xab6f, 0x0000, CanonicalizeUnique },
    { 0xab70, 0xabbf, 0x97d0, CanonicalizeRangeHi },
    { 0xabc0, 0xfb04, 0x0000, CanonicalizeUnique },
    { 0xfb05, 0xfb06, 0x0000, CanonicalizeAlternatingUnaligned },
    { 0xfb07, 0xff20, 0x0000, CanonicalizeUnique },
    { 0xff21, 0xff3a, 0x0020, CanonicalizeRangeLo },
    { 0xff3b, 0xff40, 0x0000, CanonicalizeUnique },
    { 0xff41, 0xff5a, 0x0020, CanonicalizeRangeHi },
    { 0xff5b, 0x103ff, 0x0000, CanonicalizeUnique },
    { 0x10400, 0x10427, 0x0028, CanonicalizeRangeLo },
    { 0x10428, 0x1044f, 0x0028, CanonicalizeRangeHi },
    { 0x10450, 0x104af, 0x0000, CanonicalizeUnique },
    { 0x104b0, 0x104d3, 0x0028, CanonicalizeRangeLo },
    { 0x104d4, 0x104d7, 0x0000, CanonicalizeUnique },
    { 0x104d8, 0x104fb, 0x0028, CanonicalizeRangeHi },
    { 0x104fc, 0x1056f, 0x0000, CanonicalizeUnique },
    { 0x10570, 0x1057a, 0x0027, CanonicalizeRangeLo },
    { 0x1057b, 0x1057b, 0x0000, CanonicalizeUnique },
    { 0x1057c, 0x1058a, 0x0027, CanonicalizeRangeLo },
    { 0x1058b, 0x1058b, 0x0000, CanonicalizeUnique },
    { 0x1058c, 0x10592, 0x0027, CanonicalizeRangeLo },
    { 0x10593, 0x10593, 0x0000, CanonicalizeUnique },
    { 0x10594, 0x10595, 0x0027, CanonicalizeRangeLo },
    { 0x10596, 0x10596, 0x0000, CanonicalizeUnique },
    { 0x10597, 0x105a1, 0x0027, CanonicalizeRangeHi },
    { 0x105a2, 0x105a2, 0x0000, CanonicalizeUnique },
    { 0x105a3, 0x105b1, 0x0027, CanonicalizeRangeHi },
    { 0x105b2, 0x105b2, 0x0000, CanonicalizeUnique },
    { 0x105b3, 0x105b9, 0x0027, CanonicalizeRangeHi },
    { 0x105ba, 0x105ba, 0x0000, CanonicalizeUnique },
    { 0x105bb, 0x105bc, 0x0027, CanonicalizeRangeHi },
    { 0x105bd, 0x10c7f, 0x0000, CanonicalizeUnique },
    { 0x10c80, 0x10cb2, 0x0040, CanonicalizeRangeLo },
    { 0x10cb3, 0x10cbf, 0x0000, CanonicalizeUnique },
    { 0x10cc0, 0x10cf2, 0x0040, CanonicalizeRangeHi },
    { 0x10cf3, 0x10d4f, 0x0000, CanonicalizeUnique },
    { 0x10d50, 0x10d65, 0x0020, CanonicalizeRangeLo },
    { 0x10d66, 0x10d6f, 0x0000, CanonicalizeUnique },
    { 0x10d70, 0x10d85, 0x0020, CanonicalizeRangeHi },
    { 0x10d86, 0x1189f, 0x0000, CanonicalizeUnique },
    { 0x118a0, 0x118bf, 0x0020, CanonicalizeRangeLo },
    { 0x118c0, 0x118df, 0x0020, CanonicalizeRangeHi },
    { 0x118e0, 0x16e3f, 0x0000, CanonicalizeUnique },
    { 0x16e40, 0x16e5f, 0x0020, CanonicalizeRangeLo },
    { 0x16e60, 0x16e7f, 0x0020, CanonicalizeRangeHi },
    { 0x16e80, 0x1e8ff, 0x0000, CanonicalizeUnique },
    { 0x1e900, 0x1e921, 0x0022, CanonicalizeRangeLo },
    { 0x1e922, 0x1e943, 0x0022, CanonicalizeRangeHi },
    { 0x1e944, 0x10ffff, 0x0000, CanonicalizeUnique },
};

} } // JSC::Yarr
