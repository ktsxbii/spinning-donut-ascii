# ASCII Donut

A spinning 3D torus rendered in your terminal using pure C and ASCII characters.

### How It Works
The program calculates the surface points of a 3D torus, applies rotation matrices, and projects them onto a 2D grid. We use a 12-level character set (`.,-~:;=!*#$@`) to create depth and shading.

**The RGB Trials:** We experimented with dynamic RGB gradients and uniform color cycles, but ultimately returned to grayscale for maximum clarity and that classic terminal aesthetic.

### Build & Run
Ensure you have `gcc` installed.

```bash
make
./donut
```

Use `Ctrl+C` to exit the animation.
