// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdexcept>
#include "OrthogonalPoly.h"

double OrthogonalPoly::EvalLobatto(int order, double x)
{
  double L = 0;
  double xsquare = pow(x, 2);
  switch(order) {
  case(0): L = 0.5 * (1 - 1 * x); return L;
  case(1): L = 0.5 * (1 + x); return L;
  case(2):
    L = (-1 + pow(x, 2));
    L = L * 0.5 * pow(3. / 2., 0.5);
    return L;
  case(3):
    L = x * (-1 + xsquare);
    L = L * 0.5 * pow(5. / 2., 0.5);
    return L;
  case(4):
    L = 1 + xsquare * (-6 + 5. * xsquare);
    L = L * 1. / 8. * pow(7. / 2., 0.5);
    return L;
  case(5):
    L = x * (3 + xsquare * (-10 + 7. * xsquare));
    L = L * 3. / 8. * pow(2., -0.5);
    return L;
  case(6):
    L = -1 + xsquare * (15 + xsquare * (-35 + 21 * xsquare));
    L = L * 1. / 16. * pow(11. / 2., 0.5);
    return L;
  case(7):
    L = x * (-5 + xsquare * (35 + xsquare * (-63 + 33 * xsquare)));
    L = L * 1. / 16. * pow(13. / 2., 0.5);
    return L;
  case(8):
    L =
      5 + xsquare * (-140 + xsquare * (630 + xsquare * (-924 + 429 * xsquare)));
    L = L * 1. / 128. * pow(15. / 2., 0.5);
    return L;
  case(9):
    L = x *
        (35 + xsquare *
                (-420 + xsquare * (1386 + xsquare * (-1716 + 715 * xsquare))));
    L = L * 1. / 128. * pow(17. / 2., 0.5);
    return L;
  case(10):
    L = -7 +
        xsquare *
          (315 +
           xsquare *
             (-2310 + xsquare * (6006 + xsquare * (-6435 + 2431 * xsquare))));
    L = L * 1. / 256. * pow(19. / 2., 0.5);
    return L;
  case(11):
    L =
      x *
      (-63 +
       xsquare *
         (1155 +
          xsquare *
            (-6006 + xsquare * (12870 + xsquare * (-12155 + 4199 * xsquare)))));
    L = L * 1. / 256. * pow(21. / 2., 0.5);
    return L;
  case(12):
    L = 21 +
        xsquare *
          (-1386 +
           xsquare *
             (15015 +
              xsquare *
                (-60060 +
                 xsquare * (109395 + xsquare * (-92378 + 29393 * xsquare)))));
    L = L * 1. / 1024. * pow(23. / 2., 0.5);
    return L;
  case(13):
    L =
      x *
      (231 +
       xsquare *
         (-6006 +
          xsquare *
            (45045 +
             xsquare *
               (-145860 +
                xsquare * (230945 + xsquare * (-176358 + 52003 * xsquare))))));
    L = L * 5. / 1024. * pow(2., -0.5);
    return L;
  case(14):
    L =
      -33 +
      xsquare *
        (3003 +
         xsquare *
           (-45045 +
            xsquare *
              (255255 +
               xsquare * (-692835 +
                          xsquare * (969969 + xsquare * (-676039 +
                                                         185725 * xsquare))))));
    L = L * 3. / 2048. * pow(3. / 2., 0.5);
    return L;
  case(15):
    L = x *
        (-429 +
         xsquare *
           (15015 +
            xsquare *
              (-153153 +
               xsquare *
                 (692835 +
                  xsquare *
                    (-1616615 +
                     xsquare *
                       (2028117 + xsquare * (-1300075 + 334305 * xsquare)))))));
    L = L * 1. / 2048. * pow(29. / 2., 0.5);
    return L;

  default: throw std::runtime_error("Lobatto functions are written for orders =< 15");
  }
}

double OrthogonalPoly::EvalDLobatto(int order, double x)
{
  double dL = 0;
  double xsquare = pow(x, 2);
  switch(order) {
  case(0): dL = -0.5; return dL;
  case(1): dL = 0.5; return dL;
  case(2):
    dL = 2 * x;
    dL = dL * 0.5 * pow(3. / 2., 0.5);
    return dL;
  case(3):
    dL = -1 + 3 * xsquare;
    dL = dL * 0.5 * pow(5. / 2., 0.5);
    return dL;
  case(4):
    dL = x * (-12 + 20 * xsquare);
    dL = dL * 1. / 8. * pow(7. / 2., 0.5);
    return dL;
  case(5):
    dL = 3 + xsquare * (-30 + 35. * xsquare);
    dL = dL * 3. / 8. * pow(2., -0.5);
    return dL;
  case(6):
    dL = x * (30 + xsquare * (-140 + 126 * xsquare));
    dL = dL * 1. / 16. * pow(11. / 2., 0.5);
    return dL;
  case(7):
    dL = -5 + xsquare * (105 + xsquare * (-315 + 231 * xsquare));
    dL = dL * 1. / 16. * pow(13. / 2., 0.5);
    return dL;
  case(8):
    dL = x * (-280 + xsquare * (2520 + xsquare * (-5544 + 3432 * xsquare)));
    dL = dL * 1. / 128. * pow(15. / 2., 0.5);
    return dL;
  case(9):
    dL =
      35 + xsquare *
             (-1260 + xsquare * (6930 + xsquare * (-12012 + 6435 * xsquare)));
    dL = dL * 1. / 128. * pow(17. / 2., 0.5);
    return dL;
  case(10):
    dL = x *
         (630 +
          xsquare *
            (-9240 + xsquare * (36036 + xsquare * (-51480 + 24310 * xsquare))));
    dL = dL * 1. / 256. * pow(19. / 2., 0.5);
    return dL;
  case(11):
    dL =
      -63 +
      xsquare *
        (3465 +
         xsquare * (-30030 +
                    xsquare * (90090 + xsquare * (-109395 + 46189 * xsquare))));
    dL = dL * 1. / 256. * pow(21. / 2., 0.5);
    return dL;
  case(12):
    dL =
      x * (-2772 +
           xsquare *
             (60060 +
              xsquare *
                (-360360 +
                 xsquare * (875160 + xsquare * (-923780 + 352716 * xsquare)))));
    dL = dL * 1. / 1024. * pow(23. / 2., 0.5);
    return dL;
  case(13):
    dL =
      231 +
      xsquare *
        (-18018 +
         xsquare *
           (225225 +
            xsquare *
              (-1021020 +
               xsquare * (2078505 + xsquare * (-1939938 + 676039 * xsquare)))));
    dL = dL * 5. / 1024. * pow(2., -0.5);
    return dL;
  case(14):
    dL =
      x *
      (6006 +
       xsquare *
         (-180180 +
          xsquare *
            (1531530 +
             xsquare * (-5542680 +
                        xsquare * (9699690 + xsquare * (-8112468 +
                                                        2600150 * xsquare))))));
    dL = dL * 3. / 2048. * pow(3. / 2., 0.5);
    return dL;
  case(15):
    dL = -429 +
         xsquare *
           (45045 +
            xsquare *
              (-765765 +
               xsquare *
                 (4849845 +
                  xsquare *
                    (-14549535 +
                     xsquare * (22309287 +
                                xsquare * (-16900975 + 5014575 * xsquare))))));
    dL = dL * 1. / 2048. * pow(29. / 2., 0.5);
    return dL;

  default: throw std::runtime_error("Lobatto functions are written for orders =< 15");
  }
}

double OrthogonalPoly::EvalKernelFunction(int order, double x)
{
  double phi = 0;
  double xsquare = pow(x, 2);
  switch(order) {
  case(0): phi = -pow(6, 0.5); return phi;
  case(1): phi = -x * pow(10, 0.5); return phi;
  case(2):
    phi = 1 - 5 * xsquare;
    phi = phi * 0.5 * pow(7. / 2., 0.5);
    return phi;
  case(3):
    phi = x * (3 - 7 * xsquare);
    phi = phi * 3. / 2. * pow(2, -0.5);
    return phi;
  case(4):
    phi = -1 + xsquare * (14 - 21 * xsquare);
    phi = phi * 1. / 4. * pow(11. / 2., 0.5);
    return phi;
  case(5):
    phi = x * (-5 + xsquare * (30 - 33 * xsquare));
    phi = phi * 1. / 4. * pow(13. / 2., 0.5);
    return phi;
  case(6):
    phi = 5 + xsquare * (-135 + xsquare * (495 - 429 * xsquare));
    phi = phi * 1. / 32. * pow(15. / 2., 0.5);
    return phi;
  case(7):
    phi = x * (35 + xsquare * (-385 + xsquare * (1001 - 715 * xsquare)));
    phi = phi * 1. / 32. * pow(17. / 2., 0.5);
    return phi;
  case(8):
    phi = -7 + xsquare *
                 (308 + xsquare * (-2002 + xsquare * (4004 - 2431 * xsquare)));
    phi = phi * 1. / 64. * pow(19. / 2., 0.5);
    return phi;
  case(9):
    phi =
      x *
      (-63 + xsquare *
               (1092 + xsquare * (-4914 + xsquare * (7956 - 4199 * xsquare))));
    phi = phi * 1. / 64. * pow(21. / 2., 0.5);
    return phi;
  case(10):
    phi =
      21 +
      xsquare *
        (-1365 +
         xsquare *
           (13650 + xsquare * (-46410 + xsquare * (62985 - 29393 * xsquare))));
    phi = phi * 1. / 256. * pow(23. / 2., 0.5);
    return phi;
  case(11):
    phi =
      x * (231 +
           xsquare *
             (-5775 +
              xsquare *
                (39270 +
                 xsquare * (-106590 + xsquare * (124355 - 52003 * xsquare)))));
    phi = phi * 5. / 256. * pow(2, -0.5);
    return phi;
  case(12):
    phi =
      -33 +
      xsquare *
        (2970 +
         xsquare *
           (-42075 +
            xsquare *
              (213180 +
               xsquare * (-479655 + xsquare * (490314 - 185725 * xsquare)))));
    phi = phi * 3. / 512. * pow(3. / 2., 0.5);
    return phi;
  case(13):
    phi =
      x *
      (-429 +
       xsquare *
         (14586 +
          xsquare *
            (-138567 +
             xsquare *
               (554268 + xsquare * (-1062347 +
                                    xsquare * (965770 - 334305 * xsquare))))));
    phi = phi * 1. / 512. * pow(29. / 2., 0.5);
    return phi;
  default: throw std::runtime_error("Lobatto functions are written for orders =< 15");
  }
}

double OrthogonalPoly::EvalDKernelFunction(int order, double x)
{
  double dphi = 0;
  double xsquare = pow(x, 2);
  switch(order) {
  case(0): dphi = 0; return dphi;
  case(1): dphi = -pow(10, 0.5); return dphi;
  case(2):
    dphi = -10 * x;
    ;
    dphi = dphi * 0.5 * pow(7. / 2., 0.5);
    return dphi;
  case(3):
    dphi = 3 - 21 * xsquare;
    dphi = dphi * 3. / 2. * pow(2, -0.5);
    return dphi;
  case(4):
    dphi = x * (28 - 84 * xsquare);
    dphi = dphi * 1. / 4. * pow(11. / 2., 0.5);
    return dphi;
  case(5):
    dphi = -5 + xsquare * (90 - 165 * xsquare);
    dphi = dphi * 1. / 4. * pow(13. / 2., 0.5);
    return dphi;
  case(6):
    dphi = x * (-270 + xsquare * (1980 - 2574 * xsquare));
    dphi = dphi * 1. / 32. * pow(15. / 2., 0.5);
    return dphi;
  case(7):
    dphi = 35 + xsquare * (-1155 + xsquare * (5005 - 5005 * xsquare));
    dphi = dphi * 1. / 32. * pow(17. / 2., 0.5);
    return dphi;
  case(8):
    dphi = x * (616 + xsquare * (-8008 + xsquare * (24024 - 19448 * xsquare)));
    dphi = dphi * 1. / 64. * pow(19. / 2., 0.5);
    return dphi;
  case(9):
    dphi =
      -63 + xsquare *
              (3276 + xsquare * (-24570 + xsquare * (55692 - 37791 * xsquare)));
    dphi = dphi * 1. / 64. * pow(21. / 2., 0.5);
    return dphi;
  case(10):
    dphi =
      x *
      (-2730 +
       xsquare *
         (54600 + xsquare * (-278460 + xsquare * (503880 - 293930 * xsquare))));

    dphi = dphi * 1. / 256. * pow(23. / 2., 0.5);
    return dphi;
  case(11):
    dphi = 231 +
           xsquare *
             (-17325 +
              xsquare *
                (196350 +
                 xsquare * (-746130 + xsquare * (1119195 - 572033 * xsquare))));
    dphi = dphi * 5. / 256. * pow(2, -0.5);
    return dphi;
  case(12):
    dphi =
      x * (5940 +
           xsquare *
             (-168300 +
              xsquare * (1279080 +
                         xsquare * (-3837240 +
                                    xsquare * (4903140 - 2228700 * xsquare)))));
    dphi = dphi * 3. / 512. * pow(3. / 2., 0.5);
    return dphi;
  case(13):
    dphi =
      -429 +
      xsquare *
        (43758 +
         xsquare *
           (-692835 +
            xsquare * (3879876 +
                       xsquare * (-9561123 +
                                  xsquare * (10623470 - 4345965 * xsquare)))));
    dphi = dphi * 1. / 512. * pow(29. / 2., 0.5);
    return dphi;
  default: throw std::runtime_error("Lobatto functions are written for orders =< 15");
  }
}

double OrthogonalPoly::EvalLegendre(int order, double x)
{
  double L = 0;
  double xsquare = pow(x, 2);
  switch(order) {
  case(0): L = 1; return L;
  case(1): L = x; return L;
  case(2): L = 3. / 2. * xsquare - 1. / 2.; return L;
  case(3): L = 0.5 * x * (5 * xsquare - 3); return L;
  case(4):
    L = (3 + xsquare * (35 * xsquare - 30));
    L = 1. / 8. * L;
    return L;
  case(5):
    L = x * (xsquare * (63 * xsquare - 70) + 15);
    L = 1. / 8. * L;
    return L;
  case(6):
    L = ((231 * xsquare - 315) * xsquare + 105) * xsquare - 5;
    L = 1. / 16. * L;
    return L;
  case(7):
    L = x * (((429 * xsquare - 693) * xsquare + 315) * xsquare - 35);
    L = 1. / 16. * L;
    return L;
  case(8):
    L =
      (((6435 * xsquare - 12012) * xsquare + 6930) * xsquare - 1260) * xsquare +
      35;
    L = 1. / 128. * L;
    return L;
  case(9):
    L = ((((12155 * xsquare - 25740) * xsquare + 18018) * xsquare - 4620) *
           xsquare +
         315) *
        x;
    L = 1. / 128. * L;
    return L;
  case(10):
    L = ((((46189 * xsquare - 109395) * xsquare + 90090) * xsquare - 30030) *
           xsquare +
         3465) *
          xsquare -
        63;
    L = 1. / 256. * L;
    return L;
  default: throw std::runtime_error("Legendre functions are written for orders =< 10");
  }
}

double OrthogonalPoly::EvalDLegendre(int order, double x)
{
  double dL = 0;
  double xsquare = pow(x, 2);
  switch(order) {
  case(0): dL = 0; return dL;
  case(1): dL = 1; return dL;
  case(2): dL = 3 * x; return dL;
  case(3): dL = 0.5 * (15 * xsquare - 3); return dL;
  case(4):
    dL = x * (140 * xsquare - 60);
    dL = 1. / 8. * dL;
    return dL;
  case(5):
    dL = 15 + xsquare * (315 * xsquare - 210);
    dL = 1. / 8. * dL;
    return dL;
  case(6):
    dL = x * (210 + xsquare * (1386 * xsquare - 1260));
    dL = 1. / 16. * dL;
    return dL;
  case(7):
    dL = ((xsquare * 3003 - 3465) * xsquare + 945) * xsquare - 35;
    dL = 1. / 16. * dL;
    return dL;
  case(8):
    dL = x * (((51480 * xsquare - 72072) * xsquare + 27720) * xsquare - 2520);
    dL = 1. / 128. * dL;
    return dL;
  case(9):
    dL = 315 +
         xsquare * (-13860 +
                    xsquare * (90090 + xsquare * (-180180 + 109395 * xsquare)));
    dL = 1. / 128. * dL;
    return dL;
  case(10):
    dL = x * (6930 +
              xsquare *
                (-120120 +
                 xsquare * (540540 + xsquare * (-875160 + 461890 * xsquare))));
    dL = 1. / 256. * dL;
    return dL;
  default: throw std::runtime_error("Legendre functions are written for orders =< 10");
  }
}
