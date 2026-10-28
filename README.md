<h1 align="center"> cub3D</h1>

<p align="center">
  <b>A raycasting 3D engine inspired by Wolfenstein 3D</b><br>
  Written in C with MiniLibX · 1337 / 42 Network
</p>

<p align="center">
  <img src="https://img.shields.io/badge/language-C-blue" alt="C">
  <img src="https://img.shields.io/badge/graphics-MiniLibX-purple" alt="MLX">
  <img src="https://img.shields.io/badge/school-1337%20%7C%2042-black" alt="1337">
  <img src="https://img.shields.io/badge/status-completed-success" alt="Status">
</p>

---

## About

**cub3D** renders a first-person 3D view of a maze from a simple 2D map, using the **raycasting** technique made famous by *Wolfenstein 3D* (1992).
The project teaches the math behind raycasting, parsing, textures, event handling, and working with a low-level graphics library.

---

## ✨ Features

-  Raycasting with the **DDA algorithm**
-  Textured walls, with a different texture per cardinal direction (N / S / E / W)
-  Custom floor and ceiling colors
-  Map parsing and validation from a `.cub` file
-  Smooth movement and camera rotation
-  Wall collision handling
-  Clean exit (`ESC` or window close button) with no memory leaks

---

## 📂 Project Structure

```
.
├── libft/        # Custom C library
├── mlx/          # MiniLibX graphics library
├── parsing/      # .cub file parsing & map validation
├── rays/         # Raycasting engine & rendering
├── tex/          # Textures (.xpm)
├── cub3d.h       # Main header
├── main.c        # Entry point
├── map.cub       # Example map
└── Makefile
```

---

##  Installation & Usage

### Requirements

- A Linux (or macOS) system
- `gcc` / `cc`, `make`
- X11 development libraries (Linux):
  ```bash
  sudo apt install xorg libxext-dev libbsd-dev
  ```

### Build

```bash
git clone https://github.com/sbouaa/cub3D.git
cd cub3D
make
```

| Rule | Description |
|------|-------------|
| `make` | Compile the project |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and executable |
| `make re` | Rebuild from scratch |

### Run

```bash
./cub3D map.cub
```

---

##  Controls

| Key | Action |
|-----|--------|
| `W` / `S` | Move forward / backward |
| `A` / `D` | Strafe left / right |
| `←` / `→` | Rotate camera left / right |
| `ESC` | Quit the game |

---

##  Map File (`.cub`)

The scene is described in a `.cub` file: texture paths and colors first, then the map.

```
NO ./tex/north.xpm
SO ./tex/south.xpm
WE ./tex/west.xpm
EA ./tex/east.xpm

F 220,100,0
C 225,30,0

111111
100001
10N001
100001
111111
```

| Element | Meaning |
|---------|---------|
| `NO` `SO` `WE` `EA` | Path to the wall texture for each direction |
| `F` / `C` | Floor / ceiling color as `R,G,B` (0–255) |
| `1` | Wall |
| `0` | Empty space |
| `N` `S` `E` `W` | Player start position and facing direction |

**Validation rules:**

- The map must be **closed/surrounded by walls**
- Exactly **one** player start position
- Only valid characters are allowed
- Valid texture paths and RGB values
- Elements can appear in any order before the map; the map is always last
- Any error must print `Error\n` followed by a clear message

---

##  How It Works

1. **Parsing** — read the `.cub` file, validate elements, build the 2D map grid.
2. **Initialization** — create the MLX window and image, load the textures.
3. **Raycasting** — for every screen column, cast a ray from the player:
   - compute the ray direction from the camera plane
   - step through the grid with **DDA** until a wall is hit
   - compute the perpendicular distance (to avoid the fisheye effect)
   - derive the wall height and draw the vertical strip
4. **Texturing** — pick the texture by wall side, compute the texture X coordinate from the hit position, and sample each pixel along the strip.
5. **Events** — handle key presses and window events in the MLX loop, update the player position/angle, re-render.

---

## 📏 Constraints

- Written in **C**, following the **42 Norm**
- Compiled with `-Wall -Wextra -Werror`
- Allowed functions: `open`, `close`, `read`, `write`, `printf`, `malloc`, `free`, `perror`, `strerror`, `exit`, `gettimeofday`, all functions of the math library (`-lm`) and MiniLibX
- No memory leaks

---

##  Resources

- [Lode's Computer Graphics Tutorial — Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Permadi's Raycasting Tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)

---

##  Author

**sbouaa** — [@sbouaa](https://github.com/sbouaa)

🏫 1337 School

<p align="center">⭐ If you found this useful, feel free to star the repo!</p>
