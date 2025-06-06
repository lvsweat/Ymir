#pragma once

/**
@file
@brief General definitions common to VDP1 and VDP2.
*/

#include "vdp1_defs.hpp"
#include "vdp2_defs.hpp"

#include <ymir/core/types.hpp>

#include <ymir/util/inline.hpp>
#include <ymir/util/size_ops.hpp>

#include <array>
#include <concepts>

namespace ymir::vdp {

// -----------------------------------------------------------------------------
// Memory chip sizes

inline constexpr std::size_t kVDP1VRAMSize = 512_KiB;
inline constexpr std::size_t kVDP1FramebufferRAMSize = 256_KiB;
inline constexpr std::size_t kVDP2VRAMSize = 512_KiB;
inline constexpr std::size_t kVDP2CRAMSize = 4_KiB;

// -----------------------------------------------------------------------------
// Common constants

inline constexpr uint32 kMaxResH = 704; // Maximum horizontal resolution
inline constexpr uint32 kMaxResV = 512; // Maximum vertical resolution

// -----------------------------------------------------------------------------
// Basic types

union Color555 {
    uint16 u16;
    struct {
        uint16 r : 5;
        uint16 g : 5;
        uint16 b : 5;
        uint16 msb : 1; // CC in CRAM, transparency in cells when using RGB format
    };
};

union Color888 {
    uint32 u32;
    struct {
        uint32 r : 8;
        uint32 g : 8;
        uint32 b : 8;
        uint32 : 7;
        uint32 msb : 1; // CC in CRAM, transparency in cells when using RGB format
    };
};

FORCE_INLINE Color888 ConvertRGB555to888(Color555 color) {
    return Color888{
        .r = static_cast<uint32>(color.r) << 3u,
        .g = static_cast<uint32>(color.g) << 3u,
        .b = static_cast<uint32>(color.b) << 3u,
        .msb = color.msb,
    };
}

template <std::integral T>
struct Coord {
    Coord() = default;

    Coord(T x, T y)
        : x(x)
        , y(y) {}

    T x = 0;
    T y = 0;
};

using CoordS32 = Coord<sint32>;
using CoordU32 = Coord<uint32>;

struct Dimensions {
    uint32 width;
    uint32 height;
};

} // namespace ymir::vdp
