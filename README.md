# 🎮 C++ Game Engine

A game engine built from scratch in **C++** with a focus on understanding the underlying systems that power modern game engines.

The primary goal of this project is not to build the most feature-rich engine possible, but to **learn by implementing the systems myself** and minimize the use of third-party libraries wherever reasonably possible.

> 🚧 **Work in Progress** — This engine is being developed incrementally.

---

## 🎯 Goals

The main goals of the project are to explore:

- C++ and systems programming
- Game engine architecture
- Graphics programming
- Linear algebra
- Memory management
- Entity Component Systems
- Physics
- Resource management
- Multithreading
- Performance optimization
- Software architecture

The philosophy behind the project is:

> **If I can reasonably implement it myself, I will.**

This does not mean reinventing every existing technology. External libraries will be used when they provide functionality that is outside the main learning objectives of the project.

---

# 🔧 Dependencies

The engine is intentionally designed to have **as few external dependencies as possible**.

### Core

- **C++ Standard Library**
- **OpenGL** — graphics API
- **GLFW** — window creation, OpenGL context and basic input

### Potential future dependencies

These will only be introduced if they provide meaningful value:

- **stb_image** — image loading
- **Dear ImGui** — editor/debug interface

Libraries such as physics engines, mathematics libraries and ECS frameworks are intentionally avoided in order to implement these systems myself.

---

# 🧠 Build It Myself

Instead of relying on existing engine components, the project aims to implement the following systems from scratch:

| System              | Implementation |
| ------------------- | -------------- |
| Game loop           | 🟢 Custom      |
| Timing              | 🟢 Custom      |
| Input abstraction   | 🟢 Custom      |
| Vector mathematics  | 🟢 Custom      |
| Matrix mathematics  | 🟢 Custom      |
| Transform system    | 🟢 Custom      |
| Renderer            | 🟢 Custom      |
| Shader management   | 🟢 Custom      |
| Texture management  | 🟢 Custom      |
| Camera              | 🟢 Custom      |
| Entity system       | 🟢 Custom      |
| Component system    | 🟢 Custom      |
| Scene system        | 🟢 Custom      |
| Asset management    | 🟢 Custom      |
| Collision detection | 🟢 Custom      |
| Physics             | 🟢 Custom      |
| Event system        | 🟢 Custom      |
| Memory management   | 🟢 Custom      |
| Job system          | 🟢 Custom      |
| Editor              | 🟢 Custom      |

The exact architecture will evolve as the project develops.

---

# 🚀 Roadmap

## 1. 📦 Project Setup

- 🟢 Set up CMake
- 🟢 Configure C++ project
- 🟢 Set up Git repository
- 🟢 Create engine project structure
- 🟢 Configure Debug/Release builds
- 🟢 Create initial executable

---

## 2. 🪟 Window & Application

- 🟢 Create application class
- 🟢 Create window
- 🟢 Initialize OpenGL
- 🟢 Implement game loop
- 🟢 Implement delta time
- 🟢 Implement FPS tracking
- 🟢 Separate engine and application code

Basic structure:

```cpp
while (running)
{
    ProcessInput();
    Update();
    Render();
}
```

---

## 3. 🎮 Input System

- 🟢 Keyboard input
- 🟢 Mouse input
- 🟢 Mouse movement
- 🟢 Mouse buttons
- 🟢 Key states
- 🟢 Input abstraction
- 🟢 Configurable key bindings

The goal is to avoid coupling game code directly to GLFW.

---

## 4. 📐 Mathematics

Implement the mathematical foundations required by the engine.

### Vectors

- 🟢 `Vec2`
- 🟢 `Vec3`
- 🟢 `Vec4`
- 🟢 Addition/subtraction
- 🟢 Scalar multiplication
- 🟢 Dot product
- 🟢 Cross product
- 🟢 Length
- 🟢 Normalization

### Matrices

- 🟢 `Mat2`
- 🟢 `Mat3`
- 🟢 `Mat4`
- 🟢 Matrix multiplication
- 🟢 Translation
- 🟢 Rotation
- 🟢 Scaling
- 🟢 Projection
- 🟢 View matrices

### Transformations

- 🟢 Position
- 🟢 Rotation
- 🟢 Scale
- 🟢 Local/world transformations

No external mathematics library will be used.

---

## 5. 🎨 Renderer

Build a rendering system directly on top of OpenGL.

- [ ] OpenGL renderer
- [ ] Vertex buffers
- [ ] Index buffers
- [ ] Vertex arrays
- [ ] Shader system
- [ ] Shader compilation
- [ ] Shader error handling
- [ ] Texture system
- [ ] Camera
- [ ] 2D rendering
- [ ] 3D rendering
- [ ] Lighting

Initial rendering progression:

```text
OpenGL Context
      ↓
   Triangle
      ↓
  Rectangle
      ↓
   Texture
      ↓
   Camera
      ↓
  3D Object
      ↓
   Lighting
```

---

## 6. 🧩 Entity & Component System

Create the foundation for game objects.

- [ ] Entity management
- [ ] Component storage
- [ ] Component lifecycle
- [ ] Transform component
- [ ] Render component
- [ ] Camera component
- [ ] Physics component
- [ ] Entity IDs
- [ ] Entity creation/deletion

Example:

```cpp
Entity player;

player.AddComponent<Transform>();
player.AddComponent<PhysicsBody>();
player.AddComponent<Renderer>();
```

The ECS architecture will be designed and implemented as part of the project rather than using an existing ECS framework.

---

## 7. 🌍 Scene System

- [ ] Scene creation
- [ ] Entity creation/deletion
- [ ] Scene management
- [ ] Parent/child relationships
- [ ] Entity hierarchy
- [ ] Scene loading
- [ ] Scene saving

Example:

```cpp
Scene scene;

auto player = scene.CreateEntity("Player");
auto enemy  = scene.CreateEntity("Enemy");
```

---

## 8. 📁 Asset Management

Build a custom resource management system.

- [ ] Texture loading
- [ ] Shader loading
- [ ] Model loading
- [ ] Asset manager
- [ ] Asset caching
- [ ] Resource lifetime management
- [ ] Asset handles/IDs
- [ ] Error handling

The goal is to understand how engines manage resources rather than simply loading files directly whenever they are needed.

---

## 9. ⚙️ Physics

Implement a basic physics system from scratch.

- [ ] Velocity
- [ ] Acceleration
- [ ] Gravity
- [ ] Rigid bodies
- [ ] Collision detection
- [ ] Collision response
- [ ] AABB collision
- [ ] Physics update loop
- [ ] Broad-phase collision detection
- [ ] Basic constraints

Initial physics pipeline:

```text
Input
  ↓
Forces
  ↓
Acceleration
  ↓
Velocity
  ↓
Position
  ↓
Collision Detection
  ↓
Collision Response
```

No external physics engine will be used initially.

---

## 10. 🔊 Audio

- [ ] Audio abstraction
- [ ] Sound effects
- [ ] Background music
- [ ] Audio manager
- [ ] Volume control
- [ ] 3D positional audio

Audio libraries may be introduced later if implementing a complete audio backend is outside the scope of the project.

---

## 11. 🖥️ Debugging & Profiling

- [ ] Logging system
- [ ] FPS counter
- [ ] Frame time
- [ ] Memory statistics
- [ ] Entity statistics
- [ ] Debug rendering
- [ ] Performance profiler
- [ ] Runtime statistics

The goal is to make the engine observable while developing it.

---

## 12. 🛠️ Editor

Create an editor for working with the engine.

- [ ] Scene view
- [ ] Entity hierarchy
- [ ] Entity inspector
- [ ] Transform editing
- [ ] Asset browser
- [ ] Play
- [ ] Pause
- [ ] Stop
- [ ] Scene saving/loading

Long-term goal:

```text
┌──────────────────────────────────────────────┐
│ File   Edit   View   Scene   Help            │
├────────────┬───────────────────┬─────────────┤
│            │                   │             │
│  Entities  │    Scene View     │  Inspector  │
│            │                   │             │
│  Player    │                   │ Position    │
│  Enemy     │       🎮          │ Rotation    │
│  Camera    │                   │ Scale       │
│            │                   │             │
├────────────┴───────────────────┴─────────────┤
│                Asset Browser                 │
└──────────────────────────────────────────────┘
```

---

## 13. 📡 Event System

Create a generic event system for communication between engine systems.

- [ ] Event base class
- [ ] Event types
- [ ] Event dispatcher
- [ ] Input events
- [ ] Window events
- [ ] Entity events
- [ ] Custom game events

Example:

```cpp
EventDispatcher dispatcher;

dispatcher.Subscribe<KeyPressedEvent>(
    [](const KeyPressedEvent& event)
    {
        // Handle event
    }
);
```

---

## 14. 🧵 Multithreading & Job System

Explore concurrency and parallelism.

- [ ] Thread abstraction
- [ ] Thread pool
- [ ] Job system
- [ ] Task scheduling
- [ ] Worker threads
- [ ] Synchronization
- [ ] Locking strategies
- [ ] Parallel asset loading

The goal is to understand how game engines distribute work across CPU cores.

---

## 15. 🚄 Optimization

Optimization will be introduced after the systems are functional.

- [ ] Profiling
- [ ] Memory optimization
- [ ] Rendering optimization
- [ ] Batch rendering
- [ ] Frustum culling
- [ ] Resource caching
- [ ] Data-oriented design
- [ ] Multithreading
- [ ] Job system
- [ ] Reduce unnecessary allocations

> **Measure first, optimize second.**

## Optimization of math

- [ ] Identify performance-critical math operations
- [ ] Implement baseline/reference implementations
- [ ] Introduce SIMD optimizations
  - [ ] Vec4 operations
  - [ ] Vec4 dot product
  - [ ] Mat4 × Vec4
  - [ ] Mat4 × Mat4
- [ ] Compare SIMD implementations against baseline implementations
- [ ] Benchmark performance
- [ ] Measure whether optimizations provide meaningful improvements
- [ ] Document trade-offs between readability, portability and performance

---

## 16. 🎮 Demo Game

Build a small game using the engine.

- [ ] Player
- [ ] Enemies
- [ ] Player movement
- [ ] Gameplay mechanics
- [ ] Physics
- [ ] Audio
- [ ] UI
- [ ] Main menu
- [ ] Multiple scenes
- [ ] Win/lose conditions

The demo game will serve as a real-world test of the engine's architecture.

---

## 17. ✨ Polish & Release

- [ ] Refactor architecture
- [ ] Clean up code
- [ ] Improve documentation
- [ ] API documentation
- [ ] Example projects
- [ ] Windows build
- [ ] Linux build
- [ ] Release build
- [ ] Versioning
- [ ] First stable release

---

# 📂 Project Structure

The structure will evolve with the engine, but the initial layout is planned as:

```text
MyEngine/
│
├── Engine/
│   ├── Core/
│   ├── Window/
│   ├── Renderer/
│   ├── Math/
│   ├── Input/
│   ├── Scene/
│   ├── Entity/
│   ├── Physics/
│   ├── Audio/
│   ├── Assets/
│   └── Events/
│
├── Sandbox/
│   └── main.cpp
│
├── Assets/
│   ├── Textures/
│   ├── Models/
│   ├── Shaders/
│   └── Audio/
│
├── Tests/
│
├── CMakeLists.txt
└── README.md
```

---

# 📊 Development Philosophy

This project follows a few principles:

### 1. Build before abstracting

Don't create complex abstractions before understanding the problem they solve.

### 2. Minimize dependencies

External libraries should be introduced only when they provide functionality outside the project's core learning objectives.

### 3. Understand the low level

When possible, understand what is happening underneath the abstraction.

### 4. Measure before optimizing

Performance improvements should be based on profiling and actual measurements.

### 5. Keep the engine modular

Systems should have clear responsibilities and minimal coupling.

---

# 📈 Current Progress

```text
Project Setup       ░░░░░░░░░░  0%
Window & Game Loop  ░░░░░░░░░░  0%
Input               ░░░░░░░░░░  0%
Math                ░░░░░░░░░░  0%
Rendering           ░░░░░░░░░░  0%
Entities            ░░░░░░░░░░  0%
Scenes              ░░░░░░░░░░  0%
Assets              ░░░░░░░░░░  0%
Physics             ░░░░░░░░░░  0%
Audio               ░░░░░░░░░░  0%
Events              ░░░░░░░░░░  0%
Editor              ░░░░░░░░░░  0%
Multithreading      ░░░░░░░░░░  0%
Optimization        ░░░░░░░░░░  0%
Demo Game           ░░░░░░░░░░  0%
Release             ░░░░░░░░░░  0%
```

---

# 🗺️ Long-Term Vision

The long-term goal is to create a small but complete game engine capable of running a game built entirely on top of the engine's own systems.

```text
                         GAME
                           │
                           ▼
                     ┌───────────┐
                     │   Scene   │
                     └─────┬─────┘
                           │
                           ▼
                    ┌─────────────┐
                    │   Entity    │
                    │  Component  │
                    └──────┬──────┘
                           │
          ┌────────────────┼────────────────┐
          ▼                ▼                ▼
      Renderer         Physics            Audio
          │                │                │
          └────────────────┼────────────────┘
                           ▼
                    ┌─────────────┐
                    │    Core     │
                    │             │
                    │ Game Loop   │
                    │ Events      │
                    │ Memory      │
                    │ Jobs        │
                    └─────────────┘
```

The project is ultimately about **understanding how all of these pieces fit together**.

> **Build it. Understand it. Measure it. Improve it.**
