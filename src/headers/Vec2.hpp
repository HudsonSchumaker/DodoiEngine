//
// SchumakerLab
// Dodoi Engine
// Hudson Schumaker
//

#pragma once
#include "Basic.hpp"

namespace dodoi {
    struct Vec2 {
        float x;
        float y;

        Vec2();
        Vec2(float x, float y);
        ~Vec2() = default;

        void add(const Vec2& v);
        void sub(const Vec2& v);
        void scale(const float n);
        Vec2 rotate(const float angle) const;
    
        float magnitude() const;
        float magnitudeSquared() const;
    
        Vec2& normalize();
        Vec2 unitVector() const;
        Vec2 normal() const;
    
        float dot(const Vec2& v) const;
        float cross(const Vec2& v) const;

        Vec2& operator = (const Vec2& v);
        bool operator == (const Vec2& v) const;
        bool operator != (const Vec2& v) const;

        Vec2 operator + (const Vec2& v) const;
        Vec2 operator - (const Vec2& v) const;
        Vec2 operator * (const float n) const;
        Vec2 operator / (const float n) const;

        Vec2& operator += (const Vec2& v);
        Vec2& operator -= (const Vec2& v);
        Vec2& operator *= (const float n);
        Vec2& operator /= (const float n);

        Vec2 operator - ();
    };
}
