# ASCII Donut

A spinning 3D torus rendered entirely in the terminal using pure C and standard ASCII characters. This project explores the intersection of trigonometry, perspective projection, and the constraints of fixed-width terminal rendering.

## How It Works

The donut is a mathematical torus defined by parametric equations. Every frame, the program calculates the 3D coordinates of thousands of points on the torus's surface, rotates them, and projects them onto your 2D terminal screen.

### 1. The Torus Math
We define the torus using two angles: $\theta$ (the circle representing the donut's cross-section) and $\phi$ (the larger circle of the donut itself).
- $x = (R2 + R1 \cos \theta) \cos \phi$
- $y = (R2 + R1 \cos \theta) \sin \phi$
- $z = R1 \sin \theta$

$R1$ is the radius of the cross-section, and $R2$ is the distance from the center of the torus to the center of that cross-section.

### 2. Rotation & Projection
To make it spin, we apply rotation matrices for the X and Z axes. The 3D coordinates are then projected onto a 2D plane using a simple perspective projection:
- $x' = K1 \cdot \frac{x}{K2 + z}$
- $y' = K1 \cdot \frac{y}{K2 + z}$

A **Z-buffer** (depth buffer) ensures that points closer to the "camera" overwrite points further away, preventing the donut from appearing transparent.

### 3. Luminance Shading
The "lighting" is calculated by taking the dot product of the surface normal and a fixed light source. This gives us a luminance value, which we map to a 12-level ASCII character set:
`.,-~:;=!*#$@`
The `@` character represents the brightest highlights, while `.` represents the dimmest edges.

## The RGB Trials

During development, we experimented extensively with adding color to the donut. It turned out to be a classic case of "more is less."

- **The Gradient Phase:** We first implemented a dynamic 24-bit TrueColor gradient that flowed diagonally across the screen. While visually striking, the high-contrast rainbow colors clashed with the ASCII shading, making the 3D depth harder to perceive.
- **The Uniform Pulse:** We then tried a global color cycle where the entire donut changed color in unison. This was cleaner, but it lacked the "grit" and technical aesthetic of pure ASCII.

**The Verdict:** We ultimately returned to grayscale. The original black-and-white terminal look provides the best contrast for the 12-level shading system, making the 3D form pop without the distraction of a flickering spectrum.

## Build & Run

Ensure you have `gcc` installed.

```bash
make
./donut
```

Use `Ctrl+C` to exit the animation.
