# ASCII Donut

A spinning 3D torus rendered in your terminal using pure C and ASCII characters.

### How It Works
The program calculates the surface points of a 3D torus, applies rotation matrices, and projects them onto a 2D grid. We use a 12-level character set (`.,-~:;=!*#$@`) to create depth and shading.

### Installation & Run
Ensure you have `gcc` installed on your system.

1. **Clone or Open the Directory:**
   Open your terminal and navigate to the project folder:
   ```bash
   cd /path/to/ascii-donut
   ```

2. **Build the Project:**
   Paste and run this command to compile the source code:
   ```bash
   make
   ```

3. **Run the Animation:**
   Start the spinning donut by running:
   ```bash
   ./donut
   ```

Use `Ctrl+C` to exit the animation.

---
*tried implementing rgb. did NOT work...*
