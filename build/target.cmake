# default set of each flag
SET (ESCARGOT_CXXFLAGS -fno-rtti) # build escargot without rtti
SET (ESCARGOT_CXXFLAGS_DEBUG)
SET (ESCARGOT_CXXFLAGS_RELEASE)
SET (ESCARGOT_LDFLAGS)
SET (ESCARGOT_DEFINITIONS)
SET (ESCARGOT_THIRDPARTY_CFLAGS)

SET (ESCARGOT_BUILD_32BIT OFF)

IF (${ESCARGOT_HOST} STREQUAL "linux")
    # default set of LDFLAGS
    SET (ESCARGOT_LDFLAGS -lpthread -lrt -Wl,--gc-sections)
    IF (${ESCARGOT_ARCH} STREQUAL "x64")
    ELSEIF ((${ESCARGOT_ARCH} STREQUAL "x86") OR (${ESCARGOT_ARCH} STREQUAL "i686"))
        SET (ESCARGOT_BUILD_32BIT ON)
        SET (ESCARGOT_CXXFLAGS ${ESCARGOT_CXXFLAGS} -m32 -mfpmath=sse -msse -msse2)                                                                                                                              
        SET (ESCARGOT_LDFLAGS ${ESCARGOT_LDFLAGS} -m32)
        SET (ESCARGOT_THIRDPARTY_CFLAGS -m32)
    ELSEIF (${ESCARGOT_ARCH} STREQUAL "arm")
        SET (ESCARGOT_BUILD_32BIT ON)
        SET (ESCARGOT_CXXFLAGS ${ESCARGOT_CXXFLAGS} -march=armv7-a -mthumb)
    ELSEIF (${ESCARGOT_ARCH} STREQUAL "aarch64")
    ELSE()
        MESSAGE (FATAL_ERROR ${ESCARGOT_ARCH} " is unsupported")
    ENDIF()
ELSEIF (${ESCARGOT_HOST} STREQUAL "tizen_obs")
    # default set of LDFLAGS
    SET (ESCARGOT_LDFLAGS -lpthread -lrt -Wl,--gc-sections)
    SET (ESCARGOT_DEFINITIONS -DESCARGOT_TIZEN)
    IF (${ESCARGOT_ARCH} STREQUAL "x64")
    ELSEIF ((${ESCARGOT_ARCH} STREQUAL "x86") OR (${ESCARGOT_ARCH} STREQUAL "i686"))
        SET (ESCARGOT_BUILD_32BIT ON)
        SET (ESCARGOT_CXXFLAGS ${ESCARGOT_CXXFLAGS} -m32 -mfpmath=sse -msse -msse2)
        SET (ESCARGOT_LDFLAGS ${ESCARGOT_LDFLAGS} -m32)
        SET (ESCARGOT_THIRDPARTY_CFLAGS -m32)
    ELSEIF (${ESCARGOT_ARCH} STREQUAL "arm")
        SET (ESCARGOT_BUILD_32BIT ON)
        SET (ESCARGOT_CXXFLAGS_DEBUG -O1)
        SET (ESCARGOT_CXXFLAGS_RELEASE -O2)
    ELSEIF (${ESCARGOT_ARCH} STREQUAL "aarch64")
    ELSE()
        MESSAGE (FATAL_ERROR ${ESCARGOT_ARCH} " is unsupported")
    ENDIF()
ELSEIF (${ESCARGOT_HOST} STREQUAL "android" AND ${ESCARGOT_ARCH} STREQUAL "arm")
    SET (ESCARGOT_BUILD_32BIT ON)
    SET (ESCARGOT_LDFLAGS -fPIE -pie -march=armv7-a -Wl,--fix-cortex-a8 -llog -Wl,--gc-sections)
    SET (ESCARGOT_DEFINITIONS -DANDROID=1)
ELSEIF (${ESCARGOT_HOST} STREQUAL "darwin" AND ${ESCARGOT_ARCH} STREQUAL "x64")
    SET (ESCARGOT_LDFLAGS -lpthread -Wl,-dead_strip)
ELSE()
    MESSAGE (FATAL_ERROR ${ESCARGOT_HOST} " with " ${ESCARGOT_ARCH} " is unsupported")
ENDIF()

IF (ESCARGOT_BUILD_32BIT)
    # 32bit build
    SET (ESCARGOT_DEFINITIONS ${ESCARGOT_DEFINITIONS} -DESCARGOT_32=1)
ELSE()
    # 64bit build
    SET (ESCARGOT_DEFINITIONS ${ESCARGOT_DEFINITIONS} -DESCARGOT_64=1 -DESCARGOT_USE_32BIT_IN_64BIT)
    SET (ESCARGOT_THIRDPARTY_CFLAGS ${ESCARGOT_THIRDPARTY_CFLAGS} -DESCARGOT_USE_32BIT_IN_64BIT)
ENDIF()
