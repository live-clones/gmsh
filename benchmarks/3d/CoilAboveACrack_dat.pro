// DIMENSIONS
// ----------

mm = 1.e-3;
deg = Pi/180.;


// Plate

dxPlate = 6.*mm;
dyPlate = 8.*mm;
dzPlate = 2.*mm;

zPlate = 3.*mm;

rPlate = 15.e-3/2.;
rPlateInt = rPlate-dzPlate;
aPlate = 30.*deg;


zCentre = zPlate + rPlate;


// Probe

dzGap = 0.1*mm;

xProbe = dxPlate/2.-1.7e-3;
yProbe = 0.;

zCore = zPlate + dzPlate + dzGap;

rCore = 0.5*mm;
dzCore = 3.*mm;
rExtCoil = 0.9*mm;

zCoil = zCore + 0.1*mm;
dzCoil = 1.6*mm;


// Crack

lengthCrack = 0.8*mm;
depthCrack = 0.2*mm;
widthCrack = 0.1*mm;

yCrack = -0.6*mm;

xCrack = dxPlate/2. - lengthCrack - 0.5e-3;


// Box

dxBox0 = dxPlate*0.5;
dxBox1 = dxPlate*1.;
dyBox = dyPlate*1.5;

zBox0 = 0.;
dzBox2 = 4.*mm;
zBox1 = zCore + dzCore +dzBox2;


// PHYSICAL REGIONS

COIL = 100;
CORE = 101;
CORE0 = 102;
PLATE = 110;
CRACK = 120;
AIR = 130;

SKINCOIL = 1100;
SKINCORE = 1101;
SKINPLATE = 1110;
SKINPLATEWCRACK = 1111;

CUTCOIL = 2100;
SKINCOIL2 = 3100;

SURFACEGH0 = 1150;
