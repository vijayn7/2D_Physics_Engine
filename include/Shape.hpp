#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape {
public:
    virtual ~Shape() = default;

    virtual bool intersects(const Shape& other) const = 0; // Check if this shape intersects another.
    virtual void debugDraw() const = 0; // Debug visualization of the shape.
};

class Circle : public Shape {
public:
    Circle(float radius);

    bool intersects(const Shape& other) const override; // Circle-specific collision.
    void debugDraw() const override; // Visualize as a circle.

private:
    float radius;
};

class Rectangle : public Shape {
public:
    Rectangle(float width, float height);

    bool intersects(const Shape& other) const override; // Rectangle-specific collision.
    void debugDraw() const override; // Visualize as a rectangle.

private:
    float width, height;
};

#endif // SHAPE_HPP
