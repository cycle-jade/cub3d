*This project has been created as part of the 42 curriculum by glicciar.*

# cub3D

> A first-person 3D maze renderer using ray-casting, inspired by Wolfenstein 3D.

## Description

cub3D renders a "realistic" 3D view of a maze from a first-person perspective, using the ray-casting technique, and drawing everything with the MiniLibX graphics library. The map is described in a `.cub` scene file. The goal is to explore graphics programming, event handling and the practical use of mathematics.

**Key features**
- Ray-casting engine with textured walls, with a different texture for each facing (North, South, East, West)
- Configurable floor and ceiling colours
- Movement with `W`, `A`, `S`, `D` and camera rotation with the left and right arrow keys
- Clean exit with `ESC` or by closing the window
- Smooth window handling (minimising, switching windows)
- Scene file parsing and validation: invalid files make the program exit with `Error` and an explicit message

**Bonus:** wall collisions

## Instructions

**Requirements**
- Linux with `cc`, `make`, the math library, and MiniLibX (and its dependencies: X11 and Xext)

**Build and run**
```bash
make
./cub3D maps/example.cub
```
For the bonus version: `make bonus`.

**Scene file format**
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0

111111
100001
10N001
111111
```
The map uses only `0` (empty), `1` (wall), and `N`, `S`, `E`, `W` (player start and orientation). It must be closed by walls.

**Controls**

| Key | Action |
|---|---|
| `W` `A` `S` `D` | Move |
| `←` `→` | Rotate the view |
| `ESC` | Quit |

## Technical choices
- ray-casting algorithm
- textures loading and drawing into images
- Map validation and flood fill

## Resources
- [Lode's Computer Graphics Tutorial: Raycasting](https://lodev.org/cgtutor/raycasting.html)
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)

**Use of AI**
- Code assistence and debugging
