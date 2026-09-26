// Plugin(NearestNeighbor): distance from each point of a list view to the
// nearest other one, alone and mixed with other elements, several steps

View "points" {
  SP(0, 0, 0){1, 1};
  SP(1, 0, 0){2, 2};
  SP(0, 2, 0){3, 3};
  SP(0.5, 0.5, 0.5){4, 4};
  SP(3, 3, 3){5, 5};
};
Plugin(NearestNeighbor).View = 0;
Plugin(NearestNeighbor).Run;

Merge "data/cube.pos"; // views 1-4: 8 points among other elements
Plugin(NearestNeighbor).View = 1;
Plugin(NearestNeighbor).Run;
