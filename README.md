# 🚀 Apollo 11 Lunar Lander Simulator

A physics-based simulation of the Apollo 11 lunar module descent, built in C++. Guide the lander safely to the Moon's surface by managing thrust, angle, and velocity  just like the real mission.

---

## 📖 Description

This project simulates the final descent phase of the Apollo 11 lunar module. The player controls the lander's thrust and orientation while realistic physics  including lunar gravity, acceleration, and momentum  work against them. The goal is to touch down on the designated landing pad at a safe speed and angle. Land too fast or at the wrong angle and the mission fails.

The simulation features a starfield background, procedurally generated lunar terrain, a landing platform, and a live HUD displaying speed, fuel, and altitude. The project was built with an emphasis on clean object-oriented design and thorough unit testing.

---

## 🎮 Controls

| Key         | Action                        |
|-------------|-------------------------------|
| `↑` / `Space` | Fire main thruster (up)     |
| `←`         | Rotate lander left            |
| `→`         | Rotate lander right           |

---

## 🧠 Physics & Simulation

- **Lunar gravity:** 1.625 m/s² downward acceleration applied each frame
- **Thrust:** Applies directional force based on the lander's current angle
- **Velocity:** Updated each tick using Newtonian kinematics
- **Landing check:** Safe landing requires low vertical/horizontal speed and near-level orientation

---

## 🏗️ Project Structure

| File | Responsibility |
|---|---|
| `simulator.cpp` | Main game loop and entry point |
| `lander.cpp / .h` | Lander state: position, fuel, status |
| `acceleration.cpp / .h` | Acceleration vector calculations |
| `velocity.cpp / .h` | Velocity tracking and updates |
| `angle.cpp / .h` | Angle/rotation management |
| `thrust.cpp / .h` | Thrust force application |
| `position.cpp / .h` | 2D position representation |
| `ground.cpp / .h` | Lunar terrain and landing pad generation |
| `star.cpp / .h` | Background star rendering |
| `uiDraw.cpp / .h` | OpenGL-based rendering utilities |
| `uiInteract.cpp / .h` | Keyboard input handling |
| `test.cpp / .h` | Test runner |
| `testAcceleration.h` | Unit tests for acceleration |
| `testAngle.h` | Unit tests for angle |
| `testLander.h` | Unit tests for lander |
| `testPosition.h` | Unit tests for position |
| `testThrust.h` | Unit tests for thrust |
| `testVelocity.h` | Unit tests for velocity |

---

## 🛠️ Build & Run

### Requirements

- C++17 or later
- OpenGL + GLUT (for rendering)
- Visual Studio (Windows) or Xcode (macOS)

### Windows (Visual Studio)

1. Open `lab05.sln` in Visual Studio
2. Build the solution (`Ctrl+Shift+B`)
3. Run (`F5`)

### macOS (Xcode)

1. Open `lab05.xcodeproj` in Xcode
2. Build and run (`Cmd+R`)

---

## ✅ Running Tests

Unit tests are included for all core physics components. To run them, build and execute the project  the test suite runs automatically on startup and reports results to the console.

---

## 🌕 Gameplay

- The lander spawns at the top of the screen and begins falling under lunar gravity
- Use thrust to slow your descent and rotate to steer horizontally
- Find the flat landing pad on the surface and touch down gently
- **Safe landing:** slow vertical speed, minimal horizontal drift, lander near-vertical
- **Crash:** too much speed or a bad angle and the lander is destroyed

---

## 👨‍💻 Author

**Kevin Gonzalez** — [github.com/kevingonmed](https://github.com/kevingonmed)
