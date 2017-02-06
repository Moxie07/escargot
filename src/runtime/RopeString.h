#ifndef __EscargotRopeString__
#define __EscargotRopeString__

#include "runtime/String.h"

namespace Escargot {

#define ESCARGOT_ROPE_STRING_MIN_LENGTH 24

class RopeString : public String {
public:
    RopeString()
        : String()
    {
        m_contentLength = 0;
        m_has8BitContent = false;
        m_left = nullptr;
        m_right = nullptr;
    }

    // this function not always create RopeString.
    // if (l+r).length() < ESCARGOT_ROPE_STRING_MIN_LENGTH
    // then create just normalString
    static String* createRopeString(String* lstr, String* rstr);
    virtual size_t length() const
    {
        return m_contentLength;
    }
    virtual char16_t charAt(const size_t& idx) const
    {
        return normalString()->charAt(idx);
    }
    virtual UTF16StringData toUTF16StringData() const
    {
        return normalString()->toUTF16StringData();
    }
    virtual UTF8StringData toUTF8StringData() const
    {
        return normalString()->toUTF8StringData();
    }

    virtual bool has8BitContent() const
    {
        return m_has8BitContent;
    }

    virtual bool isRopeString()
    {
        return true;
    }

    virtual const LChar* characters8() const
    {
        return normalString()->characters8();
    }

    virtual const char16_t* characters16() const
    {
        return normalString()->characters16();
    }

    virtual StringBufferAccessData bufferAccessData() const
    {
        return normalString()->bufferAccessData();
    }

    void* operator new(size_t size);
    void* operator new[](size_t size) = delete;

protected:
    String* normalString() const
    {
        const_cast<RopeString*>(this)->flattenRopeString();
        return m_left;
    }
    template <typename A, typename B>
    void flattenRopeStringWorker();
    void flattenRopeString();

    bool m_has8BitContent;
    String* m_left;
    String* m_right;
    size_t m_contentLength;
};
}

#endif
