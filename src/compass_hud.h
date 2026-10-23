#pragma once

#include <cmath>
#include <cstdio>
#include <cwchar>
#include <string>

// Pure layout and formatting helpers for the compass bar, coordinate readout
// and marker palette. No game memory or Vulkan state lives here.
namespace CompassHud
{
    constexpr float Pi = 3.14159265358979323846f;
    // Degrees of heading shown across the full width of the compass bar.
    constexpr float FieldOfViewDegrees = 180.0f;

    inline float WrapRadians(float angle)
    {
        return std::remainder(angle, 2.0f * Pi);
    }

    // Clockwise bearing from north, matching the minimap heading convention:
    // +X is east and +Z is north.
    inline float BearingRadians(float fromX, float fromZ, float toX, float toZ)
    {
        return std::atan2(toX - fromX, toZ - fromZ);
    }

    inline float HorizontalDistance(float fromX, float fromZ, float toX, float toZ)
    {
        const float dx = toX - fromX, dz = toZ - fromZ;
        return std::sqrt(dx * dx + dz * dz);
    }

    // Signed bar offset in pixels from the centre for a bearing. Returns false
    // when the bearing is outside the visible arc; outOffset is then clamped
    // to the nearest bar edge so callers can draw an edge indicator.
    inline bool BearingToBarOffset(float bearing, float heading, int barHalfWidth, float& outOffset)
    {
        const float halfFov = FieldOfViewDegrees * Pi / 360.0f;
        const float relative = WrapRadians(bearing - heading);
        const float pixelsPerRadian = static_cast<float>(barHalfWidth) / halfFov;
        if (std::fabs(relative) <= halfFov)
        {
            outOffset = relative * pixelsPerRadian;
            return true;
        }
        outOffset = relative < 0 ? -static_cast<float>(barHalfWidth) : static_cast<float>(barHalfWidth);
        return false;
    }

    inline std::wstring FormatDistance(float metres)
    {
        wchar_t buffer[32] = {};
        if (!std::isfinite(metres) || metres < 0) metres = 0;
        if (metres < 1000.0f)
            std::swprintf(buffer, 32, L"%d m", static_cast<int>(std::lround(metres)));
        else
            std::swprintf(buffer, 32, L"%.1f km", metres / 1000.0f);
        return buffer;
    }

    inline std::wstring FormatCoordinates(float x, float z, bool hasHeight, float height)
    {
        wchar_t buffer[96] = {};
        if (hasHeight)
            std::swprintf(buffer, 96, L"X %d   Y %d   Height %d", static_cast<int>(std::lround(x)),
                static_cast<int>(std::lround(z)), static_cast<int>(std::lround(height)));
        else
            std::swprintf(buffer, 96, L"X %d   Y %d", static_cast<int>(std::lround(x)),
                static_cast<int>(std::lround(z)));
        return buffer;
    }

    struct Rgb { float r, g, b; };

    // Marker colours shared by the minimap and compass bar. The colour-blind
    // palette keeps each marker type apart by hue on the blue/yellow axis,
    // brightness and shape, so it stays readable with red-green colour blindness.
    struct MarkerPalette
    {
        Rgb playerDark, playerLight;     // remote player arrow tint ramp
        Rgb pingEdge, pingRim, pingFill, pingGlyph;
        Rgb waypoint, customPin, outline;
    };

    inline const MarkerPalette& Palette(bool colorBlind)
    {
        static const MarkerPalette original = {
            {0.03f, 0.08f, 0.025f}, {0.35f, 1.00f, 0.225f},
            {0.02f, 0.10f, 0.03f}, {0.64f, 1.0f, 0.48f}, {0.12f, 0.66f, 0.18f}, {0.02f, 0.15f, 0.03f},
            {1.0f, 0.86f, 0.28f}, {1.0f, 0.20f, 0.16f}, {0.0f, 0.0f, 0.0f}
        };
        static const MarkerPalette accessible = {
            {0.02f, 0.07f, 0.16f}, {0.62f, 0.88f, 1.00f},
            {0.10f, 0.04f, 0.00f}, {1.0f, 0.90f, 0.70f}, {1.0f, 0.52f, 0.04f}, {0.16f, 0.06f, 0.00f},
            {1.0f, 0.93f, 0.22f}, {1.0f, 0.36f, 0.88f}, {0.02f, 0.02f, 0.03f}
        };
        return colorBlind ? accessible : original;
    }
}
