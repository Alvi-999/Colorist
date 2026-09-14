# Colorist

A 2D boss-fight game developed in **C using raylib**.

The game includes player movement, combat, defense, boss collision detection, animated sprites, a boss health system, and boss attacks.

## Features

* 2D game developed using C
* raylib-based rendering
* Player movement
* Player attack system
* Player defense system
* Boss collision detection
* Boss health system
* Boss damage and defeat system
* Animated player and boss sprites
* Boss ground-slam attack
* Attack hitbox detection
* Player and boss collision handling
* Desktop notification functionality
* Makefile-based build system

## Technologies Used

* **C**
* **raylib**
* **Makefile**
* **PowerShell**
* **Git**
* **GitHub**

## Controls

| Action     | Control           |
| ---------- | ----------------- |
| Move left  | `A`               |
| Move right | `D`               |
| Attack     | Left Mouse Button |
| Defend     | `Space`           |
| Exit game  | `ESC`             |

> If any control changes in the future, update this table.

## Boss System

The boss uses a health-icon-based health system.

Current boss configuration:

* Maximum health icons: `10`
* Hits required to remove one health icon: `3`
* Total hits required to defeat the boss: `30`

```text
10 health icons × 3 hits per icon = 30 total hits
```

The boss is defeated when all health icons are removed.

## Boss Attack

The boss can perform a ground-slam attack.

The attack system includes:

1. Boss attack preparation
2. Boss movement toward the player
3. Ground-slam attack hitbox
4. Player damage detection
5. Attack cooldown
6. Attack completion

The attack system prevents the same ground-slam attack from damaging the player repeatedly during one attack.

## Project Structure

```text
Colorist/
│
├── .git/
│
├── assets/
│
├── fall/
│
├── idlel/
│
├── idler/
│
├── jump/
│
├── Main Menu/
│
├── main_menu/
│
├── map-objects/
│
├── runl/
│
├── runr/
│
├── src/
│
├── start/
│
├── .gitignore
│
├── Colorist.exe
│
├── Makefile
│
└── README.md
```

### Folder Description

| Folder/File    | Purpose                                                 |
| -------------- | ------------------------------------------------------- |
| `assets/`      | Game assets such as images, sounds, and other resources |
| `fall/`        | Falling animation resources                             |
| `idlel/`       | Left-facing idle animation resources                    |
| `idler/`       | Right-facing idle animation resources                   |
| `jump/`        | Jump animation resources                                |
| `Main Menu/`   | Main menu-related resources                             |
| `main_menu/`   | Main menu-related files                                 |
| `map-objects/` | Map and level object resources                          |
| `runl/`        | Left-facing running animation resources                 |
| `runr/`        | Right-facing running animation resources                |
| `src/`         | C source code                                           |
| `start/`       | Starting screen or starting game resources              |
| `Colorist.exe` | Compiled Windows executable                             |
| `Makefile`     | Build instructions                                      |
| `.gitignore`   | Files and folders excluded from Git                     |
| `README.md`    | Project documentation                                   |

## Requirements

To build the game from source, you need:

* A C compiler such as GCC or MinGW
* raylib
* GNU Make
* Windows
* All required game asset folders

## How to Build

Clone the repository:

```bash
git clone https://github.com/YOUR_USERNAME/YOUR_REPOSITORY.git
```

Enter the project directory:

```bash
cd YOUR_REPOSITORY
```

Build the project using the Makefile:

```bash
make
```

> The exact command may depend on your compiler and Makefile configuration.

## How to Run

### Run the Existing Executable

The project already contains a Windows executable:

```text
Colorist.exe
```

To run the game:

1. Open the project folder.
2. Make sure all asset folders are present.
3. Double-click `Colorist.exe`.

You can also run it from the terminal:

```powershell
.\Colorist.exe
```

## Important Asset Information

The game uses relative paths to load images, sounds, and other resources.

Therefore, the following folders must remain available:

```text
assets/
fall/
idlel/
idler/
jump/
Main Menu/
main_menu/
map-objects/
runl/
runr/
start/
```

Do not move the executable away from these folders unless the resource paths in the source code are updated.

## Windows Release

A Windows release should contain the executable and every folder required by the game.

Example release structure:

```text
Colorist-Windows/
│
├── Colorist.exe
│
├── assets/
├── fall/
├── idlel/
├── idler/
├── jump/
├── Main Menu/
├── main_menu/
├── map-objects/
├── runl/
├── runr/
└── start/
```

### How to Play the Release Version

1. Download the release ZIP file.
2. Extract the complete ZIP file.
3. Open the extracted folder.
4. Run `Colorist.exe`.

> Do not copy only the `.exe` file. The required asset folders must also be included.

## Current Platform

The current executable is intended for:

* Windows PC

Other platforms may require separate builds and platform-specific configuration.

## Project Status

**Status:** Playable development version

**Version:** `v1.0.0`

## Future Improvements

Possible future improvements include:

* More levels
* Additional enemies
* More boss attacks
* Sound effects and background music
* Improved character animations
* Better menus and user interface
* Save and load system
* Controller support
* Mobile touch controls
* Linux and macOS builds
* Improved resource management
* Improved performance

## Known Limitations

* The current executable is designed for Windows.
* The game requires its asset folders to run correctly.
* Moving or renaming asset folders may cause missing-resource errors.
* Other platforms require separate compilation and testing.
* The current project is still under development.

## Credits

Developed by Jaber Al Siddique Alvi, Niamul Mahbub, Ilham Hasinur.

Built with **C** and **raylib**.

## License

This project is currently provided for educational and development purposes.

If you decide to publish it as an open-source project, you may add a license such as the MIT License.
