#include "PhysicsWorld.hpp"
#include "Renderer.hpp"

int main() {
    PhysicsWorld world;
    Renderer renderer;

    // Create shapes and rigid bodies.
    Circle* circle = new Circle(5.0f);
    RigidBody* body1 = new RigidBody(circle, 10.0f);
    world.addRigidBody(body1);

    // Main loop (simplified).
    float deltaTime = 0.016f; // Assume 60 FPS.
    while (true) {
        world.step(deltaTime); // Update physics world.
        renderer.draw(world.getRigidBodies()); // Render the world.
    }

    return 0;
}
