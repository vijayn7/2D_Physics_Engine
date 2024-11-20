#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>

struct Vector2 {
    float x, y;

    Vector2(float x = 0, float y = 0);
    float magnitude() const; // Compute the magnitude of the vector.
    Vector2 normalized() const; // Return the unit vector.
    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(float scalar) const;
    Vector2 operator/(float scalar) const;
};

#endif // VECTOR2_HPP
