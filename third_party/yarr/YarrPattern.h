/*
 * Copyright (C) 2009-2023 Apple Inc. All rights reserved.
 * Copyright (C) 2010 Peter Varga (pvarga@inf.u-szeged.hu), University of Szeged
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#pragma once

#include "YarrErrorCode.h"
#include "YarrFlags.h"
#include "YarrUnicodeProperties.h"

namespace JSC { namespace Yarr {

struct YarrPattern;
struct PatternDisjunction;

enum class CompileMode : uint8_t {
    Legacy,
    Unicode,
    UnicodeSets
};

struct CharacterRange {
    char32_t begin { 0 };
    char32_t end { UCHAR_MAX_VALUE };

    CharacterRange(char32_t begin, char32_t end)
        : begin(begin)
        , end(end)
    {
    }
};

enum struct CharacterClassWidths : unsigned char {
    Unknown = 0x0,
    HasBMPChars = 0x1,
    HasNonBMPChars = 0x2,
    HasBothBMPAndNonBMP = HasBMPChars | HasNonBMPChars
};

inline CharacterClassWidths operator|(CharacterClassWidths lhs, CharacterClassWidths rhs)
{
    return static_cast<CharacterClassWidths>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs));
}

inline bool operator&(CharacterClassWidths lhs, CharacterClassWidths rhs)
{
    return static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs);
}

inline CharacterClassWidths& operator|=(CharacterClassWidths& lhs, CharacterClassWidths rhs)
{
    lhs = lhs | rhs;
    return lhs;
}

struct CharacterClass {
    WTF_MAKE_TZONE_ALLOCATED(CharacterClass);
public:
    using Table = const char*;

    // All CharacterClass instances have to have the full set of matches and ranges,
    // they may have an optional m_table for faster lookups (which must match the
    // specified matches and ranges)
    CharacterClass()
        : m_table(nullptr)
        , m_characterWidths(CharacterClassWidths::Unknown)
        , m_anyCharacter(false)
    {
    }

    CharacterClass(Table table, bool inverted)
        : m_table(table)
        , m_characterWidths(CharacterClassWidths::Unknown)
        , m_tableInverted(inverted)
        , m_anyCharacter(false)
    {
    }

    CharacterClass(std::initializer_list<char32_t> matches, std::initializer_list<CharacterRange> ranges, std::initializer_list<char32_t> matchesUnicode, std::initializer_list<CharacterRange> rangesUnicode, CharacterClassWidths widths)
        : m_matches(matches)
        , m_ranges(ranges)
        , m_matchesUnicode(matchesUnicode)
        , m_rangesUnicode(rangesUnicode)
        , m_table(nullptr)
        , m_characterWidths(widths)
        , m_tableInverted(false)
        , m_anyCharacter(false)
    {
    }

    CharacterClass(Vector<Vector<char32_t>> strings, std::initializer_list<char32_t> matches, std::initializer_list<CharacterRange> ranges,std::initializer_list<char32_t> matchesUnicode, std::initializer_list<CharacterRange> rangesUnicode, CharacterClassWidths widths, bool inCanonicalForm)
        : m_strings(std::move(strings))
        , m_matches(matches)
        , m_ranges(ranges)
        , m_matchesUnicode(matchesUnicode)
        , m_rangesUnicode(rangesUnicode)
        , m_table(nullptr)
        , m_characterWidths(widths)
        , m_tableInverted(false)
        , m_anyCharacter(false)
        , m_inCanonicalForm(inCanonicalForm)
    {
    }

    void copyOnly8BitCharacterData(const CharacterClass& other);

    bool hasNonBMPCharacters() const { return m_characterWidths & CharacterClassWidths::HasNonBMPChars; }

    bool hasOneCharacterSize() const { return m_characterWidths == CharacterClassWidths::HasBMPChars || m_characterWidths == CharacterClassWidths::HasNonBMPChars; }
    bool hasOnlyNonBMPCharacters() const { return m_characterWidths == CharacterClassWidths::HasNonBMPChars; }
    bool hasStrings() const { return !m_strings.isEmpty(); }
    bool hasSingleCharacters() const { return !m_matches.isEmpty() || !m_ranges.isEmpty() || !m_matchesUnicode.isEmpty() || !m_rangesUnicode.isEmpty(); }
    
    Vector<Vector<char32_t>> m_strings;
    Vector<char32_t> m_matches;
    Vector<CharacterRange> m_ranges;
    Vector<char32_t> m_matchesUnicode;
    Vector<CharacterRange> m_rangesUnicode;

    Table m_table;
    CharacterClassWidths m_characterWidths;
    bool m_tableInverted : 1;
    bool m_anyCharacter : 1;
    bool m_inCanonicalForm : 1;
};

struct ClassSet : public CharacterClass {
    WTF_MAKE_TZONE_ALLOCATED(ClassSet);
public:
    ClassSet()
        : CharacterClass()
        , m_inCanonicalForm(true)
    {
    }

    ClassSet(const char* table, bool inverted)
        : CharacterClass(table, inverted)
        , m_inCanonicalForm(true)
    {
    }

    ClassSet(std::initializer_list<char32_t> matches, std::initializer_list<CharacterRange> ranges, std::initializer_list<char32_t> matchesUnicode, std::initializer_list<CharacterRange> rangesUnicode, CharacterClassWidths widths)
        : CharacterClass(matches, ranges, matchesUnicode, rangesUnicode, widths)
        , m_inCanonicalForm(true)
    {
    }

    ClassSet(std::initializer_list<Vector<char32_t>> strings, std::initializer_list<char32_t> matches, std::initializer_list<CharacterRange> ranges, std::initializer_list<char32_t> matchesUnicode, std::initializer_list<CharacterRange> rangesUnicode, CharacterClassWidths widths)
        : CharacterClass(matches, ranges, matchesUnicode, rangesUnicode, widths)
        , m_strings(strings)
        , m_inCanonicalForm(true)
    {
    }

    ClassSet(std::initializer_list<Vector<char32_t>> strings, bool inCanonicalForm)
        : m_strings(strings)
        , m_inCanonicalForm(inCanonicalForm)
    {
    }

    Vector<Vector<char32_t>> m_strings;
    bool m_inCanonicalForm : 1;
};

enum class QuantifierType : uint8_t {
    FixedCount,
    Greedy,
    NonGreedy,
};

enum MatchDirection : uint8_t {
    // The code assumes that Forward is 0 and Backward is 1.
    Forward = 0,
    Backward = 1
};

struct PatternTerm {
    enum class Type : uint8_t {
        AssertionBOL,
        AssertionEOL,
        AssertionWordBoundary,
        PatternCharacter,
        CharacterClass,
        BackReference,
        ForwardReference,
        ParenthesesSubpattern,
        ParentheticalAssertion,
        DotStarEnclosure,
    };
    Type type;
    OptionSet<Flags> m_currentFlags;
    bool m_capture : 1;
    bool m_invert : 1;
    MatchDirection m_matchDirection : 1;
    QuantifierType quantityType;
    Checked<unsigned> quantityMinCount;
    Checked<unsigned> quantityMaxCount;
    union {
        char32_t patternCharacter;
        CharacterClass* characterClass;
        unsigned backReferenceSubpatternId;
        struct {
            PatternDisjunction* disjunction;
            unsigned subpatternId;
            unsigned lastSubpatternId;
            bool isCopy : 1;
            bool isTerminal : 1;
        } parentheses;
        struct {
            bool bolAnchor : 1;
            bool eolAnchor : 1;
        } anchors;
    };
    unsigned inputPosition;
    unsigned frameLocation;

    // ctor for optional wrapper
    PatternTerm()
    {
        type = Type::AssertionBOL;
        m_capture = m_invert = false;
        m_matchDirection = MatchDirection::Backward;
        quantityType = QuantifierType::FixedCount;
        patternCharacter = 0;
        inputPosition = frameLocation = 0;
    }

    // ctor for optional wrapper
    PatternTerm(const JSC::Yarr::PatternTerm& src)
    {
        *this = src;
    }

    PatternTerm(const std::optional<JSC::Yarr::PatternTerm>& src)
        : PatternTerm()
    {
        if (src) {
            *this = src.value();
        }
    }

    PatternTerm(char32_t ch, OptionSet<Flags> currFlags, MatchDirection matchDirection = Forward)
        : type(PatternTerm::Type::PatternCharacter)
        , m_currentFlags(currFlags)
        , m_capture(false)
        , m_invert(false)
        , m_matchDirection(matchDirection)
    {
        patternCharacter = ch;
        quantityType = QuantifierType::FixedCount;
        quantityMinCount = quantityMaxCount = 1;
    }

    PatternTerm(CharacterClass* charClass, bool invert, OptionSet<Flags> currFlags, MatchDirection matchDirection = Forward)
        : type(PatternTerm::Type::CharacterClass)
        , m_currentFlags(currFlags)
        , m_capture(false)
        , m_invert(invert)
        , m_matchDirection(matchDirection)
    {
        characterClass = charClass;
        quantityType = QuantifierType::FixedCount;
        quantityMinCount = quantityMaxCount = 1;
    }

    PatternTerm(Type type, unsigned subpatternId, PatternDisjunction* disjunction, OptionSet<Flags> currFlags, bool capture = false, bool invert = false, MatchDirection matchDirection = Forward)
        : type(type)
        , m_currentFlags(currFlags)
        , m_capture(capture)
        , m_invert(invert)
        , m_matchDirection(matchDirection)
    {
        parentheses.disjunction = disjunction;
        parentheses.subpatternId = subpatternId;
        parentheses.isCopy = false;
        parentheses.isTerminal = false;
        quantityType = QuantifierType::FixedCount;
        quantityMinCount = quantityMaxCount = 1;
    }
    
    PatternTerm(Type type, OptionSet<Flags> currFlags, bool invert = false)
        : type(type)
        , m_currentFlags(currFlags)
        , m_capture(false)
        , m_invert(invert)
        , m_matchDirection(Forward)
    {
        quantityType = QuantifierType::FixedCount;
        quantityMinCount = quantityMaxCount = 1;
    }

    PatternTerm(unsigned spatternId, OptionSet<Flags> currFlags)
        : type(Type::BackReference)
        , m_currentFlags(currFlags)
        , m_capture(false)
        , m_invert(false)
        , m_matchDirection(Forward)
    {
        backReferenceSubpatternId = spatternId;
        quantityType = QuantifierType::FixedCount;
        quantityMinCount = quantityMaxCount = 1;
    }

    PatternTerm(bool bolAnchor, bool eolAnchor, OptionSet<Flags> currFlags)
        : type(Type::DotStarEnclosure)
        , m_currentFlags(currFlags)
        , m_capture(false)
        , m_invert(false)
        , m_matchDirection(Forward)
    {
        anchors.bolAnchor = bolAnchor;
        anchors.eolAnchor = eolAnchor;
        quantityType = QuantifierType::FixedCount;
        quantityMinCount = quantityMaxCount = 1;
    }

    static PatternTerm ForwardReference(OptionSet<Flags> currFlags)
    {
        auto term = PatternTerm(Type::ForwardReference, currFlags);
        term.backReferenceSubpatternId = 0;
        return term;
    }

    static PatternTerm BOL(OptionSet<Flags> currFlags)
    {
        return PatternTerm(Type::AssertionBOL, currFlags);
    }

    static PatternTerm EOL(OptionSet<Flags> currFlags)
    {
        return PatternTerm(Type::AssertionEOL, currFlags);
    }

    static PatternTerm WordBoundary(bool invert, OptionSet<Flags> currFlags)
    {
        return PatternTerm(Type::AssertionWordBoundary, currFlags, invert);
    }

    void convertToBackreference()
    {
        ASSERT(type == Type::ForwardReference);
        type = Type::BackReference;
    }

    bool invert() const
    {
        return m_invert;
    }

    void setMatchDirection(MatchDirection matchDirection)
    {
        m_matchDirection = matchDirection;
    }

    MatchDirection matchDirection() const
    {
        return m_matchDirection;
    }

    bool capture()
    {
        return m_capture;
    }

    bool ignoreCase()
    {
        return m_currentFlags.contains(Flags::IgnoreCase);
    }

    bool multiline()
    {
        return m_currentFlags.contains(Flags::Multiline);
    }

    bool dotAll()
    {
        return m_currentFlags.contains(Flags::DotAll);
    }

    bool isFixedWidthCharacterClass() const
    {
        return type == Type::CharacterClass && characterClass->hasOneCharacterSize() && !invert();
    }

    bool containsAnyCaptures()
    {
        ASSERT(this->type == Type::ParenthesesSubpattern
            || this->type == Type::ParentheticalAssertion);
        return parentheses.lastSubpatternId && parentheses.lastSubpatternId >= parentheses.subpatternId;
    }

    void quantify(unsigned count, QuantifierType type)
    {
        quantityMinCount = 0;
        quantityMaxCount = count;
        quantityType = type;
    }

    void quantify(unsigned minCount, unsigned maxCount, QuantifierType type)
    {
        // Currently only Parentheses can specify a non-zero min with a different max.
        ASSERT(this->type == Type::ParenthesesSubpattern || !minCount || minCount == maxCount);
        ASSERT(minCount <= maxCount);
        quantityMinCount = minCount;
        quantityMaxCount = maxCount;
        quantityType = type;
    }
};

struct PatternAlternative {
    WTF_MAKE_TZONE_ALLOCATED(PatternAlternative);
public:
    PatternAlternative(PatternDisjunction* disjunction, unsigned firstSubpatternId, MatchDirection matchDirection = Forward)
        : m_parent(disjunction)
        , m_firstSubpatternId(firstSubpatternId)
        , m_lastSubpatternId(0)
        , m_direction(matchDirection)
        , m_onceThrough(false)
        , m_hasFixedSize(false)
        , m_startsWithBOL(false)
        , m_containsBOL(false)
    {
    }

    unsigned lastTermIndex()
    {
        ASSERT(m_terms.size());
        return m_terms.size() - 1;
    }

    PatternTerm& lastTerm()
    {
        return m_terms[lastTermIndex()];
    }
    
    void removeLastTerm()
    {
        ASSERT(m_terms.size());
        m_terms.shrink(m_terms.size() - 1);
    }
    
    void setOnceThrough()
    {
        m_onceThrough = true;
    }
    
    bool onceThrough()
    {
        return m_onceThrough;
    }

    bool needToCleanupCaptures() const
    {
        return !!m_lastSubpatternId;
    }

    unsigned firstCleanupSubpatternId()
    {
        unsigned firstSubpatternIdToClear = m_firstSubpatternId;

        // We want to clear subpatterns, which start at 1.
        if (!firstSubpatternIdToClear)
            firstSubpatternIdToClear++;
        
        ASSERT(firstSubpatternIdToClear <= m_lastSubpatternId);

        return firstSubpatternIdToClear;
    }

    MatchDirection matchDirection() const
    {
        return m_direction;
    }

    void dump(PrintStream&, YarrPattern*, unsigned);

    Vector<PatternTerm> m_terms;
    PatternDisjunction* m_parent;
    unsigned m_minimumSize;
    unsigned m_firstSubpatternId;
    unsigned m_lastSubpatternId;
    MatchDirection m_direction;
    bool m_onceThrough : 1;
    bool m_hasFixedSize : 1;
    bool m_startsWithBOL : 1;
    bool m_containsBOL : 1;
};

struct PatternDisjunction {
    WTF_MAKE_TZONE_ALLOCATED(PatternDisjunction);
public:
    PatternDisjunction(PatternAlternative* parent = nullptr)
        : m_parent(parent)
        , m_hasFixedSize(false)
    {
    }
    
    PatternAlternative* addNewAlternative(unsigned firstSubpatternId = 1, MatchDirection matchDirection = Forward)
    {
        m_alternatives.append(makeUnique<PatternAlternative>(this, firstSubpatternId, matchDirection));
        return static_cast<PatternAlternative*>(m_alternatives.last().get());
    }

    void dump(PrintStream&, YarrPattern*, unsigned);

    Vector<std::unique_ptr<PatternAlternative>> m_alternatives;
    PatternAlternative* m_parent;
    unsigned m_minimumSize;
    unsigned m_callFrameSize;
    bool m_hasFixedSize;
};

// You probably don't want to be calling these functions directly
// (please to be calling newlineCharacterClass() et al on your
// friendly neighborhood YarrPattern instance to get nicely
// cached copies).

std::unique_ptr<CharacterClass> anycharCreate();
std::unique_ptr<CharacterClass> newlineCreate();
std::unique_ptr<CharacterClass> digitsCreate();
std::unique_ptr<CharacterClass> spacesCreate();
std::unique_ptr<CharacterClass> wordcharCreate();
std::unique_ptr<CharacterClass> wordUnicodeIgnoreCaseCharCreate();
std::unique_ptr<CharacterClass> nondigitsCreate();
std::unique_ptr<CharacterClass> nonspacesCreate();
std::unique_ptr<CharacterClass> nonwordcharCreate();
std::unique_ptr<CharacterClass> nonwordUnicodeIgnoreCaseCharCreate();

struct TermChain {
    TermChain(PatternTerm term = PatternTerm())
        : term(term)
    {}

    PatternTerm term;
    Vector<TermChain> hotTerms;
};


struct YarrPattern : public gc {
    JS_EXPORT_PRIVATE YarrPattern(StringView pattern, OptionSet<Flags>, ErrorCode&);

    void resetForReparsing()
    {
        m_numSubpatterns = 0;
        m_initialStartValueFrameLocation = 0;
        m_numDuplicateNamedCaptureGroups = 0;

        m_containsBackreferences = false;
        m_containsBOL = false;
        m_containsLookbehinds = false;
        m_containsUnsignedLengthPattern = false;
        m_hasCopiedParenSubexpressions = false;
        m_hasNamedCaptureGroups = false;
        m_saveInitialStartValue = false;

        anycharCached = nullptr;
        newlineCached = nullptr;
        digitsCached = nullptr;
        spacesCached = nullptr;
        wordcharCached = nullptr;
        wordUnicodeIgnoreCaseCharCached = nullptr;
        nondigitsCached = nullptr;
        nonspacesCached = nullptr;
        nonwordcharCached = nullptr;
        nonwordUnicodeIgnoreCasecharCached = nullptr;
        unicodePropertiesCached.clear();

        m_disjunctions.clear();
        m_userCharacterClasses.clear();
        m_captureGroupNames.clear();
        m_namedGroupToParenIndices.clear();
        m_duplicateNamedGroupForSubpatternId.clear();
    }

    bool containsUnsignedLengthPattern()
    {
        return m_containsUnsignedLengthPattern;
    }

    CharacterClass* anyCharacterClass()
    {
        if (!anycharCached) {
            m_userCharacterClasses.append(anycharCreate());
            anycharCached = m_userCharacterClasses.last().get();
        }
        return anycharCached;
    }
    CharacterClass* newlineCharacterClass()
    {
        if (!newlineCached) {
            m_userCharacterClasses.append(newlineCreate());
            newlineCached = m_userCharacterClasses.last().get();
        }
        return newlineCached;
    }
    CharacterClass* digitsCharacterClass()
    {
        if (!digitsCached) {
            m_userCharacterClasses.append(digitsCreate());
            digitsCached = m_userCharacterClasses.last().get();
        }
        return digitsCached;
    }
    CharacterClass* spacesCharacterClass()
    {
        if (!spacesCached) {
            m_userCharacterClasses.append(spacesCreate());
            spacesCached = m_userCharacterClasses.last().get();
        }
        return spacesCached;
    }
    CharacterClass* wordcharCharacterClass()
    {
        if (!wordcharCached) {
            m_userCharacterClasses.append(wordcharCreate());
            wordcharCached = m_userCharacterClasses.last().get();
        }
        return wordcharCached;
    }
    CharacterClass* wordUnicodeIgnoreCaseCharCharacterClass()
    {
        if (!wordUnicodeIgnoreCaseCharCached) {
            m_userCharacterClasses.append(wordUnicodeIgnoreCaseCharCreate());
            wordUnicodeIgnoreCaseCharCached = m_userCharacterClasses.last().get();
        }
        return wordUnicodeIgnoreCaseCharCached;
    }
    CharacterClass* nondigitsCharacterClass()
    {
        if (!nondigitsCached) {
            m_userCharacterClasses.append(nondigitsCreate());
            nondigitsCached = m_userCharacterClasses.last().get();
        }
        return nondigitsCached;
    }
    CharacterClass* nonspacesCharacterClass()
    {
        if (!nonspacesCached) {
            m_userCharacterClasses.append(nonspacesCreate());
            nonspacesCached = m_userCharacterClasses.last().get();
        }
        return nonspacesCached;
    }
    CharacterClass* nonwordcharCharacterClass()
    {
        if (!nonwordcharCached) {
            m_userCharacterClasses.append(nonwordcharCreate());
            nonwordcharCached = m_userCharacterClasses.last().get();
        }
        return nonwordcharCached;
    }
    CharacterClass* nonwordUnicodeIgnoreCaseCharCharacterClass()
    {
        if (!nonwordUnicodeIgnoreCasecharCached) {
            m_userCharacterClasses.append(nonwordUnicodeIgnoreCaseCharCreate());
            nonwordUnicodeIgnoreCasecharCached = m_userCharacterClasses.last().get();
        }
        return nonwordUnicodeIgnoreCasecharCached;
    }
    CharacterClass* unicodeCharacterClassFor(BuiltInCharacterClassID unicodeClassID)
    {
        ASSERT(unicodeClassID >= BuiltInCharacterClassID::BaseUnicodePropertyID);

        unsigned classID = static_cast<unsigned>(unicodeClassID);

        if (unicodePropertiesCached.find(classID) == unicodePropertiesCached.end()) {
            m_userCharacterClasses.append(createUnicodeCharacterClassFor(unicodeClassID));
            CharacterClass* result = m_userCharacterClasses.last().get();
            unicodePropertiesCached.add(classID, result);
            return result;
        }

        return unicodePropertiesCached.get(classID);
    }

    unsigned offsetVectorBaseForNamedCaptures() const
    {
        return (m_numSubpatterns + 1) * 2;
    }

    unsigned offsetsSize() const
    {
        return offsetVectorBaseForNamedCaptures() + m_numDuplicateNamedCaptureGroups;
    }

    unsigned offsetForDuplicateNamedGroupId(unsigned duplicateNamedGroupId)
    {
        ASSERT(duplicateNamedGroupId);
        return offsetVectorBaseForNamedCaptures() + duplicateNamedGroupId - 1;
    }

    void dumpPatternString(PrintStream& out, StringView patternString);
    void dumpPattern(StringView pattern);
    void dumpPattern(PrintStream& out, StringView pattern);

    bool global() const { return m_flags.contains(Flags::Global); }
    bool ignoreCase() const { return m_flags.contains(Flags::IgnoreCase); }
    bool multiline() const { return m_flags.contains(Flags::Multiline); }
    bool hasIndices() const { return m_flags.contains(Flags::HasIndices); }
    bool sticky() const { return m_flags.contains(Flags::Sticky); }
    bool unicode() const { return m_flags.contains(Flags::Unicode); }
    bool unicodeSets() const { return m_flags.contains(Flags::UnicodeSets); }
    bool eitherUnicode() const { return unicode() || unicodeSets(); }
    bool dotAll() const { return m_flags.contains(Flags::DotAll); }

    bool hasDuplicateNamedCaptureGroups() const { return !!m_numDuplicateNamedCaptureGroups; }

    CompileMode compileMode() const
    {
        if (unicode())
            return CompileMode::Unicode;

        if (unicodeSets())
            return CompileMode::UnicodeSets;

        return CompileMode::Legacy;
    }

    bool m_containsBackreferences : 1;
    bool m_containsBOL : 1;
    bool m_containsLookbehinds : 1;
    bool m_containsUnsignedLengthPattern : 1;
    bool m_containsModifiers : 1;
    bool m_hasCopiedParenSubexpressions : 1;
    bool m_hasNamedCaptureGroups : 1;
    bool m_saveInitialStartValue : 1;
    OptionSet<Flags> m_flags;
    unsigned m_numSubpatterns { 0 };
    unsigned m_initialStartValueFrameLocation { 0 };
    unsigned m_numDuplicateNamedCaptureGroups { 0 };
    PatternDisjunction* m_body { nullptr };
    Vector<std::unique_ptr<PatternDisjunction>, 4> m_disjunctions;
    Vector<std::unique_ptr<CharacterClass>> m_userCharacterClasses;
    ::Escargot::Vector<String, GCUtil::gc_malloc_allocator<String>> m_captureGroupNames;
    // The contents of the RHS Vector of m_namedGroupToParenIndices depends on whether the String is a
    // duplicate named group or not.
    // For a named group that is only used once in the pattern, the vector size is one and the only entry
    // is the subpatterenId for a non-duplicate named group.
    // For a duplicate named group, the size will be greater than 2. The first vector entry it is the
    // duplicateNamedGroupId. Subsequent vector entries are the subpatternId's for that duplicateNamedGroupId.
    HashMap<String, Vector<unsigned>> m_namedGroupToParenIndices;
    Vector<unsigned> m_duplicateNamedGroupForSubpatternId;
    String m_atom;

    void* operator new(size_t size)
    {
        static MAY_THREAD_LOCAL bool typeInited = false;
        static MAY_THREAD_LOCAL GC_descr descr;
        if (!typeInited) {
            GC_word obj_bitmap[GC_BITMAP_SIZE(YarrPattern)] = { 0 };
            GC_set_bit(obj_bitmap, GC_WORD_OFFSET(YarrPattern, m_captureGroupNames));
            GC_set_bit(obj_bitmap, GC_WORD_OFFSET(YarrPattern, m_atom));
            descr = GC_make_descriptor(obj_bitmap, GC_WORD_LEN(YarrPattern));
            typeInited = true;
        }
        return GC_MALLOC_EXPLICITLY_TYPED(size, descr);
    }

private:
    ErrorCode compile(StringView patternString);

    CharacterClass* anycharCached { nullptr };
    CharacterClass* newlineCached { nullptr };
    CharacterClass* digitsCached { nullptr };
    CharacterClass* spacesCached { nullptr };
    CharacterClass* wordcharCached { nullptr };
    CharacterClass* wordUnicodeIgnoreCaseCharCached { nullptr };
    CharacterClass* nondigitsCached { nullptr };
    CharacterClass* nonspacesCached { nullptr };
    CharacterClass* nonwordcharCached { nullptr };
    CharacterClass* nonwordUnicodeIgnoreCasecharCached { nullptr };
    HashMap<unsigned, CharacterClass*> unicodePropertiesCached;
};

    void indentForNestingLevel(PrintStream&, unsigned);
    void dumpUChar32(PrintStream&, char32_t);
    void dumpCharacterClass(PrintStream&, YarrPattern*, CharacterClass*);

    struct BackTrackInfoPatternCharacter {
        uintptr_t begin; // Only needed for unicode patterns
        uintptr_t matchAmount;

        static unsigned beginIndex() { return offsetof(BackTrackInfoPatternCharacter, begin) / sizeof(uintptr_t); }
        static unsigned matchAmountIndex() { return offsetof(BackTrackInfoPatternCharacter, matchAmount) / sizeof(uintptr_t); }
    };

    struct BackTrackInfoCharacterClass {
        uintptr_t begin; // Only needed for unicode patterns
        uintptr_t matchAmount;

        static unsigned beginIndex() { return offsetof(BackTrackInfoCharacterClass, begin) / sizeof(uintptr_t); }
        static unsigned matchAmountIndex() { return offsetof(BackTrackInfoCharacterClass, matchAmount) / sizeof(uintptr_t); }
    };

    struct BackTrackInfoBackReference {
        uintptr_t begin; // Not really needed for greedy quantifiers.
        uintptr_t matchAmount; // Not really needed for fixed quantifiers.
        uintptr_t backReferenceSize; // Used by greedy quantifiers to backtrack.

        static unsigned beginIndex() { return offsetof(BackTrackInfoBackReference, begin) / sizeof(uintptr_t); }
        static unsigned matchAmountIndex() { return offsetof(BackTrackInfoBackReference, matchAmount) / sizeof(uintptr_t); }
        static unsigned backReferenceSizeIndex() { return offsetof(BackTrackInfoBackReference, backReferenceSize) / sizeof(uintptr_t); }
    };

    struct BackTrackInfoAlternative {
        union {
            uintptr_t offset;
        };
    };

    struct BackTrackInfoParentheticalAssertion {
        uintptr_t begin;

        static unsigned beginIndex() { return offsetof(BackTrackInfoParentheticalAssertion, begin) / sizeof(uintptr_t); }
    };

    struct BackTrackInfoParenthesesOnce {
        uintptr_t begin;
        uintptr_t returnAddress;

        static unsigned beginIndex() { return offsetof(BackTrackInfoParenthesesOnce, begin) / sizeof(uintptr_t); }
        static unsigned returnAddressIndex() { return offsetof(BackTrackInfoParenthesesOnce, returnAddress) / sizeof(uintptr_t); }
    };

    struct BackTrackInfoParenthesesTerminal {
        uintptr_t begin;

        static unsigned beginIndex() { return offsetof(BackTrackInfoParenthesesTerminal, begin) / sizeof(uintptr_t); }
    };

    struct BackTrackInfoParentheses {
        uintptr_t begin;
        uintptr_t returnAddress;
        uintptr_t matchAmount;
        uintptr_t parenContextHead;

        static unsigned beginIndex() { return offsetof(BackTrackInfoParentheses, begin) / sizeof(uintptr_t); }
        static unsigned returnAddressIndex() { return offsetof(BackTrackInfoParentheses, returnAddress) / sizeof(uintptr_t); }
        static unsigned matchAmountIndex() { return offsetof(BackTrackInfoParentheses, matchAmount) / sizeof(uintptr_t); }
        static unsigned parenContextHeadIndex() { return offsetof(BackTrackInfoParentheses, parenContextHead) / sizeof(uintptr_t); }
    };

} } // namespace JSC::Yarr

using JSC::Yarr::MatchDirection;
