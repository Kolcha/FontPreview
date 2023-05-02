Font Preview
============

This application is a simple font viewer program. It allows to list all fonts installed in a system and see what styles they provide and how they look (focused on Latin characters, but some other writing systems are also supported).

Viewing a single font file is also possible. The application supports both TrueType (.ttf) and OpenType (.otf) fonts and their so-called collections (.ttc files), maybe a few more font formats (depending on Qt backend).

Primary it was written for Linux running "Qt-rich" environments like KDE or LXQT, but can be used in any other environments, very likely even on other OS (not tested, but should work as so as only Qt API is used).

Why
---

Mostly just because [default KDE' font viewer utility doesn't work under Wayland](https://bugs.kde.org/show_bug.cgi?id=439470) (due to the reasons known to me). Fonts preview in System Settings where all available fonts are listed doesn't work either, because it uses the same code. But I needed such tool pretty often.

Also, even KDE' KFontView has amazing font preview, but it only provides the ability to view individual font files, not all fonts installed in the system, and the place where all system fonts can be viewed is too inconvenient for me.

Usage
-----

There are no binary distributions for this tool and they are even not planned. Building from the source is the only way to get it, but it is extremely easy, just because no dependencies are required except Qt itself. Both Qt5 and Qt6 are supported and work in the same way.

Build it as any other sources which use CMake build system:

```bash
# in sources root
cmake -B build .
cmake --build build
```

The commands provided above are too generic, adjust them depending on your needs/preferences/environment.

The build process will not take long, and when it completes, everything is ready to go:

```bash
# still in sources root
./build/font_preview
```

This will list all fonts available in your system and show the default font for the applications. To view a specific font file (not necessarily installed in the system), just pass a path to it as a command line argument:

```bash
# still in sources root
./build/font_preview <path to font file>
```

The examples above are for Linux (or compatible) environments, as so as it was primarily written for Linux. Some adjustments may be required for other environments.

In Linux (or compatible) environment you may create a .desktop file for convenience. It will allow you to launch the application conveniently (as any other GUI application) and even associate font files with it (it would be possible to open font files with this application). But no such file is provided (as so as no `make install` is assumed), so write it by yourself.
