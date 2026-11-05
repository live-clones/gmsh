// A check of the JavaScript API (api/gmsh.mjs, copied into ./build next to
// libgmsh.mjs and libgmsh.wasm by ./build.sh), which is also an example of its
// use: tutorial t1 built through the API, meshed, and read back.
//
// Usage: node api_test.mjs (with the node of emsdk, for example)

import createGmsh from './build/gmsh.mjs';

const gmsh = await createGmsh({ print: () => {}, printErr: () => {} });
const check = (what, ok) => console.log((ok ? 'ok   ' : 'FAIL ') + what);

gmsh.initialize();
gmsh.option.setNumber('General.Terminal', 0);
gmsh.model.add('t1');
const lc = 1e-2;
gmsh.model.geo.addPoint(0, 0, 0, lc, 1);
gmsh.model.geo.addPoint(.1, 0, 0, lc, 2);
gmsh.model.geo.addPoint(.1, .3, 0, lc, 3);
const p4 = gmsh.model.geo.addPoint(0, .3, 0, lc);
check('int return (addPoint) = 4', p4 === 4);
gmsh.model.geo.addLine(1, 2, 1);
gmsh.model.geo.addLine(3, 2, 2);
gmsh.model.geo.addLine(3, p4, 3);
gmsh.model.geo.addLine(4, 1, p4);
gmsh.model.geo.addCurveLoop([4, 1, -2, 3], 1);          // ivectorint
gmsh.model.geo.addPlaneSurface([1], 1);
gmsh.model.geo.synchronize();
gmsh.model.addPhysicalGroup(2, [1], -1, 'My surface');  // istring
check('string round trip (getPhysicalName)',
      gmsh.model.getPhysicalName(2, 1) === 'My surface');

const ents = gmsh.model.getEntities();                   // ovectorpair
check('vectorpair output (getEntities: 4 points, 4 curves, 1 surface)',
      ents.length === 9 && ents[8][0] === 2 && ents[8][1] === 1);
const bnd = gmsh.model.getBoundary([[2, 1]]);            // ivectorpair in and out
check('vectorpair input (getBoundary of the surface: 4 curves)',
      bnd.length === 4 && bnd.every(([d]) => d === 1));

gmsh.model.mesh.generate(2);
const [nodeTags, coord, param] = gmsh.model.mesh.getNodes();
check('typed arrays (getNodes): ' + nodeTags.length + ' nodes, coord x3',
      nodeTags instanceof Uint32Array && coord instanceof Float64Array &&
      coord.length === 3 * nodeTags.length && nodeTags.length > 100);
const [types, elTags, elNodes] = gmsh.model.mesh.getElements(2);  // ovectorvector*
check('vector of vectors (getElements: triangles, 3 nodes each)',
      types.length === 1 && types[0] === 2 &&
      elNodes[0].length === 3 * elTags[0].length);
check('double output (option.getNumber Mesh.NbNodes)',
      gmsh.option.getNumber('Mesh.NbNodes') === nodeTags.length);
check('string output (option.getString)',
      typeof gmsh.option.getString('General.DefaultFileName') === 'string');
const [name, dim, order, numNodes, localCoord, numPrim] =
  gmsh.model.mesh.getElementProperties(2);               // several outputs
check('several outputs (getElementProperties: ' + name + ')',
      dim === 2 && numNodes === 3 && localCoord.length === 6);

let threw = false;
try { gmsh.model.mesh.getNodes(2, 42); } catch(e) { threw = e.message; }
check('errors thrown with the last error (' + threw + ')', !!threw);

let calls = 0;
gmsh.model.mesh.setSizeCallback((d, t, x, y, z, lc) => { calls++; return lc / 2; });
gmsh.model.mesh.clear();
gmsh.model.mesh.generate(2);
const n2 = gmsh.model.mesh.getNodes()[0].length;
check('size callback (' + calls + ' calls, ' + n2 + ' nodes)', calls > 0 && n2 > 2 * nodeTags.length);

gmsh.finalize();
