# fdf ('Fil de fer' aka Wireframe)
3d wireframe representation of a terrain written in C, using MLX library. Introduction project to graphics at 42Paris. 

## Description

The goal of the project is to take a map file as an argument and output an interactive representation of the map in the form of a 3d wireframe.

<img src ="http://g.recordit.co/I89fgQ39u9.gif" width =700 height =450/>
<img src ="http://g.recordit.co/4y35UxrAOF.gif" width =700 height =450/>

* Paralell/isometric projection
* Linear gradient between colors
* Color palettes according to height
* Possibility to reduce/amplify height
* Zoom in/out
* Rotation on all axis

Be aware that using isometric mode while doing rotations will distort the terrain. 

## Installation
***Only works on MacOS with provided library***<br/>
To install simply type: <br/>
`make`

OpenGL has to be installed as it is required by the MLX library.

## Usage
`./fdf <map_file> [GEO (optional color palette)]
