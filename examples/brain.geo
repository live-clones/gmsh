Point(newp) = {0,0,0,0.1};  /* Point 1 */
Point(newp) = {1,0,0,0.1};  /* Point 2 */
Point(newp) = {-1,0,0,0.1};  /* Point 3 */

Point(newp) = {0,.8,0,0.1};  /* Point 4 */
Point(newp) = {0,0,.8,0.1};  /* Point 5 */
Point(newp) = {0,0,-.8,0.1};  /* Point 6 */

Point(newp) = {.1,0,-.79,.1};  /* Point 7 */
Point(newp) = {.3,0,-.73,.1};  /* Point 8 */
Point(newp) = {.65,0,-.55,.1};  /* Point 9 */
Point(newp) = {.9,0,-.38,.1};  /* Point 10 */

Point(newp) = {.1,0,.79,.1};  /* Point 11 */
Point(newp) = {.3,0,.73,.1};  /* Point 12 */
Point(newp) = {.65,0,.55,.1};  /* Point 13 */
Point(newp) = {.9,0,.38,.1};  /* Point 14 */

Spline(1) = {6,7,8,9,10,2};
Circle(2) = {6,1,4};
Circle(3) = {2,1,1,4};
Line Loop(4) = {3,-2,1};
Ruled Surface(5) = {4};

Spline(6) = {5,11,12,13,14,2};
Circle(7) = {5,1,4};
Line Loop(8) = {3,-7,6};
Ruled Surface(9) = {8};
Line(10) = {6,5};
Line Loop(11) = {7,-2,10};
Plane Surface(12) = {11};
Line Loop(13) = {-1,10,6};
Plane Surface(14) = {13};
Surface Loop(15) = {12,9,-5,-14};
Complex Volume(16) = {15};
