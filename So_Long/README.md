# 🎮 ABOUT so_long

The **so_long** project is a simple 2D game developed in C using the MiniLibX graphics library. The goal of the game is to guide a character through a maze, collecting items along the way and avoiding obstacles. The player must complete the game with the fewest number of moves possible.

## Prerequisites
Before compiling and running the project, make sure you have the MiniLibX installed in project folder. For that, after cloning, it's necessary to extract the contents of the `minilibx-Linux.tgz` file, rename the folder with the name `mlx`, and copy and paste this in the folder `lib`.

## 🛠️ Testing Instructions
To compile the project, run:
```bash
make or make bonus
```
This will compile the source files and generate the `so_long` or `so_long_bonus` executable.

## Execution
After compilation, you can run the game using the following command:

```bash
./so_long maps/valid/mandatory/small.ber  or  medium.ber  or  big.ber
./so_long_bonus maps/valid/bonus/small.ber  or  medium.ber  or  big.ber
```

#### MAKEFILE RULES

`make` - Compile so_long files.

`make bonus` - Compile so_long_bonus files.

`make all`  - Compile mandatory + bonus files.

`make clean`  - Delete all .o (object files) files.

`make fclean`  - Delete all .o (object files) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

## Game Rules
- The player starts at an initial position marked by a character.
- The goal is to collect a	ll the items represented by collectibles (`C`) on the map.
- The player must avoid obstacles represented by walls (`1`) and enemies (`E`).
- The player can move in the up, down, left, and right directions using the arrow keys.
- The game ends when the player collects all the items and returns to the initial position or is captured by an enemy.
- The number of moves made by the player is displayed in the game window.

## Controls
- `W`, `S`, `D`, `A` and `Arrow keys`: move the character in the up, down, left, and right directions.
- `ESC` key: exit the game.

## Sprites
The sprites used in the game were created by me using the GIMP application. Here a small tutorial on how to create sprites using GIMP: https://thegimptutorials.com/how-to-make-pixel-art/.
If you want to use the sprites that I created, or modify them, you can use the sprites.xcf file.


## Used tests
so_long_invalidator: https://github.com/Nuno-Jesus/so_long_invalidator

**2.** If your directory tree looks like this...

```txt
	│
	├── so_long_map_validator	(this directory)
	├── so_long 				(your repository)
	│
	...
```
then you can skip this step. Otherwise, you must change the **PROJ** variable on the **Makefile of so_long_invalidator**. It should look something like this:

```Makefile
	#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FOLDERS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
	PROJ = ../so_long
```


| Resource                                                                                             | Source     |
| :--------------------------------------------------------------------------------------------------- | :-------- |
| [How to Make Pixel Art in GIMP](https://thegimptutorials.com/how-to-make-pixel-art)                  | `Website` |
| [itch.io](https://itch.io)                                                                           | `Website` |
| [OpenGameArt.org](https://opengameart.org)                                                           | `Website` |
| [8-Bit Dungeon Tileset/Sprites](https://jamiecross.itch.io/8-bit-dungeon-tilesetsprites)             | `Website` |
| [42: A Comprehensive Guide to So Long](https://reactive.so/post/42-a-comprehensive-guide-to-so_long) | `Website` |

| Project                                             | Source    | User |
| :-------------------------------------------------- | :-------- | :--- |
| [so_long](https://github.com/madebypixel02/so_long) | `GitHub`  | `madebypixel02` |

| Tester                                                                   | Source    | User |
| :----------------------------------------------------------------------- | :-------- | :--- |
| [so_long_invalidator](https://github.com/Nuno-Jesus/so_long_invalidator) | `GitHub`  | `Nuno-Jesus` |
| [so_long_tester](https://github.com/augustobecker/so_long_tester)        | `GitHub`  | `augustobecker` |

| Tool                                                                       | Source  | User           |
| :------------------------------------------------------------------------- | :------ | :------------- |
| [so_long Map Creator](https://github.com/bennamrouche/so_long-Map-Creator) | `GitHub`  | `bennamrouche` |

----