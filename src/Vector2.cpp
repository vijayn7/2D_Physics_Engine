#include "Vector2.hpp"
#include <cmath>

Vector2::Vector2(float x, float y) : x(x), y(y) {}

float Vector2::magnitude() const {
    return std::sqrt(x * x + y * y);
}

float Vector2::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vector2 Vector2::normalized() const {
    float mag = magnitude();
    return Vector2(x / mag, y / mag);
}

Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(float scalar) const {
    return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(float scalar) const {
    return Vector2(x / scalar, y / scalar);
}

Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2& Vector2::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2& Vector2::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

bool Vector2::operator==(const Vector2& other) const {
    return x == other.x && y == other.y;
}

bool Vector2::operator!=(const Vector2& other) const {
    return x != other.x || y != other.y;
}

bool Vector2::operator<(const Vector2& other) const {
    return x < other.x && y < other.y;
}

bool Vector2::operator<=(const Vector2& other) const {
    return x <= other.x && y <= other.y;
}

bool Vector2::operator>(const Vector2& other) const {
    return x > other.x && y > other.y;
}

bool Vector2::operator>=(const Vector2& other) const {
    return x >= other.x && y >= other.y;
}

Vector2 Vector2::operator-() const {
    return Vector2(-x, -y);
}

float Vector2::dot(const Vector2& other) const {
    return x * other.x + y * other.y;
}

float Vector2::cross(const Vector2& other) const {
    return x * other.y - y * other.x;
}