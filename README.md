# Fractol

`fractol` is a small graphical program that renders and explores fractals in real time.
This project, part of the 42 curriculum, introduces computer graphics fundamentals using the **MiniLibX** library, complex numbers, and interactive event handling.

## 🎯 Project Objectives

* Render mathematical fractals using pixel-by-pixel iterations.
* Handle zooming, panning, and color variation smoothly.
* Work with complex numbers and iterative formulas (e.g., Mandelbrot, Julia).
* Learn basics of computer graphics, event loops, and low-level rendering with MiniLibX.
* Write clean, modular C code without global variables.

## 🌀 Implemented Fractals

Mandatory sets:

* **Mandelbrot**
* **Julia** (multiple variants via parameters)

Bonus sets included:

* **Burning Ship**
* **Tricorn**

## 🎮 Features & Controls

The program includes an interactive exploration UI:

**Navigation & Display**

* **Scroll wheel** → Zoom in/out
* **Arrow keys** → Move the viewport
* **0** → Reset the fractal

**Fractal Selection**

* **1–4** → Switch between fractals

**Color Management**

* **Q / W** → Increase color intensity
* **A / S** → Decrease color intensity

**Julia Controls**

* **L** → Lock/unlock Julia parameter updates

**Exit**

* **ESC** → Close the window cleanly

## 🔧 Usage

```bash
./fractol [m | j | b | t]
```

Examples:

```bash
./fractol m            # Mandelbrot  
./fractol j            # Julia  
./fractol b            # Burning Ship  
./fractol t            # Tricorn  
```

Invalid or missing parameters display a built-in help menu.

## 🖼️ Technical Notes

* Written in **C**, using **MiniLibX** for windowing, images, and events.
* Uses complex-number iterations to compute escape times.
* Implements smooth window handling and colored depth rendering.
* All required memory is properly managed (no leaks).

## 📚 What I Learned

This project significantly improved my skills in:

* graphical programming and pixel rendering
* numerical methods with complex numbers
* event-driven programming (keyboard & mouse hooks)
* optimization for iterative graphics
* clean architecture without global state
  
