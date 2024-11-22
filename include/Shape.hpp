#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape {
    private:
        std::pair<float, float> position;
        std::pair<float, float> size;
    
    public:
        Shape(std::pair<float, float> position, std::pair<float, float> size);
        virtual ~Shape() = default;

        virtual bool intersects(const Shape& other) const = 0; // Check if this shape intersects another.
        virtual void debugDraw() const = 0; // Debug visualization of the shape.

        float getX() const { return position.first; }
        float getY() const { return position.second; }
        float getWidth() const { return size.first; }
        float getHeight() const { return size.second; }
};

class Circle : public Shape {
    public:
        Circle(std::pair<float, float> position, float radius);

        bool intersects(const Shape& other) const override; // Circle-specific collision.
        void debugDraw() const override; // Visualize as a circle.

        float getRadius() const { return radius; }

    private:
        float radius;
};

class Rectangle : public Shape {
    public:
        Rectangle(std::pair<float, float> position, std::pair<float, float> size);

        bool intersects(const Shape& other) const override; // Rectangle-specific collision.
        void debugDraw() const override; // Visualize as a rectangle.
};

#endif // SHAPE_HPP
