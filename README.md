# ecole_42-fillit

Read `subject.pdf`

Display the smallest possible square with a given list of tetriminos. The result should be the first possible solution when placing them recursively giving top left (top priority then left).

## Compiling
Run `make`, an executable called `fillit` should compile directly. Submit
an issue if you run into any.

## Usage
`./fillit [file]`

## Explanation

Fillit is one of the projects on the global branch at 42 Silicon Valley. The objective of this project is to implement a backtracking algorithm. The program will take in file name as an argument. The file would contain characters that represent Tertis shapes which is followed by a new line. The program will be write a grid with the shapes placed together to stdout. The placement should be such that the output grid is the smallest possible grid while give top alinement over bottom alignment then left alignment over right alignment.
The argument should be a path to a valid file. This input file should will represent shapes int the form of cells with characters '.' (Empty cell) and '#' (Valid cell). Any other characters flags an invalid input file. A '/n' character should be found between each shape and after every row. Each shape should have exactly 4 Valid cells. And every cell should be right, left, top and/or bottom of another cell to make a valid shape.
example of valid Tetriminos
example of invalid Tetriminos
The way the program stores each shape is to initialize a array of 4 t_points structs which have values int x and int y. Each t_point represents the x and y coordinates where the top left cell is the origin (0,0). The reasoning of storing each shape as the distance form the origin is simple transformation and translation. I store every t_point *point[4] (one shape) in an array of t_point \**point[x] (array of all shape read) where x is the total number of shapes read.
The gird is a two dimensional char array that starts a width of the rounded up value of sqrt((number of shapes) * 4). The starting value represents the best case sanerio however the grid might have to be resized if shapes don't conform to the output grid priority. there are designated functions to manipulate the grid like add shape to grid, remove shape from grid, copy grid, and resize grid.
The backtracking algorithm starts by placing every shape in order from the top left. If all shapes aren't able to fit into the current grid size the program will start to remove shapes starting from the shape it was stuck on. When a shape is removed it will start to add shapes in a different order form what was passes in. Is all shapes were placed in all the possible order the grid will resize as the grids's width will increase by one and the old working grid will be copied onto the new working grid. The program will return the first working grid that is able to place the last shape.
