import gmsh
import math
import sys

gmsh.initialize(sys.argv)

gmsh.model.add("torus")

class Q3D_Point(object):

    def __init__(self, xyz):
        self.__x = xyz[0]
        self.__y = xyz[1]
        self.__z = xyz[2]

    def x(self):
        return self.__x

    def y(self):
        return self.__y

    def z(self):
        return self.__z

class Q3D_Vector(object):

    def x(self):
        return self.__x

    def y(self):
        return self.__y

    def z(self):
        return self.__z

    def __init__(self, dx, dy, dz):
        self.__x = dx
        self.__y = dy
        self.__z = dz
        self.__length = (self.__x**2 + self.__y**2 + self.__z**2)**0.5

    def scale_vector(self, scalar):
        return Q3D_Vector(self.__x * scalar, self.__y * scalar, self.__z * scalar)

    def unit(self):
        self.__x /= self.__length
        self.__y /= self.__length
        self.__z /= self.__length
        self.__length = 1.0
        return self

    def add(self, rhs_vector, rhs_scale=1.0): # new vector = self + rhs_vector * rhs_scale
        return Q3D_Vector(self.__x + rhs_vector.x() * rhs_scale,
                          self.__y + rhs_vector.y() * rhs_scale,
                          self.__z + rhs_vector.z() * rhs_scale)

class Q3D_NURBS_Data(object):
    def __init__(self, degree, control_points, weights, knots, multiplicities, periodic):
        self.deg = degree
        self.kts = knots
        self.mps = multiplicities
        self.cps = control_points
        self.wts = weights
        self.per = periodic

    def is_surface(self):
        return type(self.deg) is tuple

class Q3D_Frame(object):
    def local_to_global(self, l123):
        l1, l2, l3 = l123
        gx = self.__Og.x() + l1 * self.__e1.x() + l2 * self.__e2.x() + l3 * self.__e3.x()
        gy = self.__Og.y() + l1 * self.__e1.y() + l2 * self.__e2.y() + l3 * self.__e3.y()
        gz = self.__Og.z() + l1 * self.__e1.z() + l2 * self.__e2.z() + l3 * self.__e3.z()
        return Q3D_Point((gx, gy, gz))

    def local_translate(self, l123):
        self.__Og = self.local_to_global(l123)

    def e1_rotate(self, theta):
        c = math.cos(theta)
        s = math.sin(theta)
        b2 = self.__e2.scale_vector(c).add(self.__e3,  s).unit()
        b3 = self.__e3.scale_vector(c).add(self.__e2, -s).unit()
        self.__e2 = b2
        self.__e3 = b3

    def e2_rotate(self, theta):
        c = math.cos(theta)
        s = math.sin(theta)
        b3 = self.__e3.scale_vector(c).add(self.__e1,  s).unit()
        b1 = self.__e1.scale_vector(c).add(self.__e3, -s).unit()
        self.__e3 = b3
        self.__e1 = b1

    def e3_rotate(self, theta):
        c = math.cos(theta)
        s = math.sin(theta)
        b1 = self.__e1.scale_vector(c).add(self.__e2,  s).unit()
        b2 = self.__e2.scale_vector(c).add(self.__e1, -s).unit()
        self.__e1 = b1
        self.__e2 = b2

    def __init__(self, Oxyz, vec_e1, vec_e2, vec_e3):
        self.__Og = Oxyz
        self.__e1 = vec_e1
        self.__e2 = vec_e2
        self.__e3 = vec_e3

    def copy(self):
        return Q3D_Frame(self.__Og, self.__e1, self.__e2, self.__e3)

    def sketch_reset(orientation='XY', origin=(0,0,0)):
        O = Q3D_Point(origin)

        if orientation == 'YX':
            B1 = Q3D_Vector( 0.0, 1.0, 0.0)
            B2 = Q3D_Vector( 1.0, 0.0, 0.0)
            B3 = Q3D_Vector( 0.0, 0.0,-1.0)
        elif orientation == 'YZ':
            B1 = Q3D_Vector( 0.0, 1.0, 0.0)
            B2 = Q3D_Vector( 0.0, 0.0, 1.0)
            B3 = Q3D_Vector( 1.0, 0.0, 0.0)
        elif orientation == 'ZY':
            B1 = Q3D_Vector( 0.0, 0.0, 1.0)
            B2 = Q3D_Vector( 0.0, 1.0, 0.0)
            B3 = Q3D_Vector(-1.0, 0.0, 0.0)
        elif orientation == 'XZ':
            B1 = Q3D_Vector( 1.0, 0.0, 0.0)
            B2 = Q3D_Vector( 0.0, 0.0, 1.0)
            B3 = Q3D_Vector( 0.0,-1.0, 0.0)
        elif orientation == 'ZX':
            B1 = Q3D_Vector( 0.0, 0.0, 1.0)
            B2 = Q3D_Vector( 1.0, 0.0, 0.0)
            B3 = Q3D_Vector( 0.0, 1.0, 0.0)
        else: #if orientation == 'XY':
            B1 = Q3D_Vector( 1.0, 0.0, 0.0)
            B2 = Q3D_Vector( 0.0, 1.0, 0.0)
            B3 = Q3D_Vector( 0.0, 0.0, 1.0)

        return Q3D_Frame(O, B1, B2, B3)

    def __angles(self, theta, bPeriodic):
        # split range into angles of 120 degrees or less, and half-angles
        # also return: cha  the cosine of the half-angle
        #              Ncp  number of control points for degree 2 curve
        if theta is not None:
            t1, t2 = theta
        else:
            t1 = 0.0
            t2 = 2.0 * math.pi
        Narc = int(math.ceil(math.fabs(t2 - t1) * 1.5 / math.pi))
        cha = math.cos(math.fabs(t2 - t1) * 0.5 / Narc)
        angles = []
        Ncp = 2 * Narc
        for a in range(Ncp):
            angles.append(t1 + (t2 - t1) * a * 1.0 / Ncp)
        if not bPeriodic:
            Ncp += 1
            angles.append(t2)
        return angles, cha, Ncp

    def __kts_mps(self, Ncp, bPeriodic):
        # knots and multiplicities for degree 2 curve
        kts = []
        if bPeriodic:
            mps = [2]
        else:
            mps = [3]
        Narc = int(Ncp / 2)
        for a in range(Narc):
            kts.append(a * 1.0 / Narc)
            if a:
                mps.append(2)
        mps.append(mps[0])
        kts.append(1.0)
        return kts, mps

    def nurbs_ellipse(self, major, minor, base_weight=1.0):
        angles, cha, Ncp = self.__angles(None, True)
        kts, mps = self.__kts_mps(Ncp, True)

        # The initial control point and weight need to be added
        # at the end by the caller to close the loop
        cps = []
        wts = [] # weights get scaled by base_weight

        ha = False
        for a in angles:
            if ha:
                rs = 1.0 / cha
                ha = False
            else:
                rs = 1.0
                ha = True
            x = rs * math.cos(a) * major
            y = rs * math.sin(a) * minor
            cps.append(self.local_to_global((x, y, 0)))
            wts.append(base_weight / rs)
        return Q3D_NURBS_Data(2, cps, wts, kts, mps, True)

    def nurbs_torus(self, radius, major, minor, pitch=0.0, theta=None):
        # the initial control points and weights need to be
        # added at the end by the caller to close the surface
        deg1 = None
        kts1 = None
        mps1 = None
        per1 = None
        deg2 = 2
        cps = []
        wts = []

        if pitch == 0.0 and theta is not None:
            t1, t2 = theta
            if math.fabs(t2 - t1) >= 2.0 * math.pi:
                theta = None # we have a full torus
        if pitch == 0.0 and theta is None:
            per2 = True      # doubly periodic surface
        else:
            per2 = False

        angles, cha, Ncp = self.__angles(theta, per2)
        kts2, mps2 = self.__kts_mps(Ncp, per2)

        ha = False
        for a in angles:
            if ha:
                rs = 1.0 / cha
                ha = False
            else:
                rs = 1.0
                ha = True

            frame = self.copy()
            frame.e1_rotate(a)
            frame.local_translate((pitch * a * 0.5 / math.pi, rs * radius, 0))

            data = frame.nurbs_ellipse(major, rs * minor, 1.0 / rs)
            cps.append(data.cps)
            wts.append(data.wts)

            if deg1 is None:
                deg1 = data.deg
                kts1 = data.kts
                mps1 = data.mps
                per1 = data.per

        return Q3D_NURBS_Data((deg1, deg2), cps, wts, (kts1, kts2), (mps1, mps2), (per1, per2))

class Q3D_Draw(object):

    __counter = 0

    def __new_expr_id(self):
        Q3D_Draw.__counter += 1
        return Q3D_Draw.__counter

    def __init__(self, mesh_default=0.1):
        self.mesh = mesh_default

    def __draw_point(self, point):
        p = self.__new_expr_id()
        x = point.x()
        y = point.y()
        z = point.z()
        gmsh.model.occ.addPoint(x, y, z, self.mesh, p)
        return p

    def __draw_loop(self, segments):
        n = self.__new_expr_id()
        gmsh.model.occ.addCurveLoop(segments, n)
        return n

    def __pp_surface(self, name, loops): # create physical planar surface
        n = self.__new_expr_id()
        gmsh.model.occ.addPlaneSurface(loops, n)
        gmsh.model.occ.synchronize()
        m = self.__new_expr_id()
        gmsh.model.addPhysicalGroup(2, [n], tag=m, name=name)
        return m

    def __draw_nurbs_curve(self, name, data):
        cps = []
        wts = data.wts
        for cp in data.cps:
            cps.append(self.__draw_point(cp))
        if data.per: # periodic; need to add the beginning in as the end
            cps.append(cps[0])
            wts.append(wts[0])

        p = self.__new_expr_id()
        gmsh.model.occ.addBSpline(cps, tag=p, degree=data.deg, weights=wts,
                                  knots=data.kts, multiplicities=data.mps)
        if data.per:
            p = self.__draw_loop([p])
            p = self.__pp_surface(name, [p])
        return p

    def __draw_nurbs_surface(self, name, data):
        face_f = None
        face_b = None

        deg1, deg2 = data.deg
        kts1, kts2 = data.kts
        mps1, mps2 = data.mps
        per1, per2 = data.per
        dim1 = len(data.cps[0])
        dim2 = len(data.cps)
        cps = []
        wts = []
        for i2 in range(dim2):
            cpsf = []
            wtsf = []
            cp_list = data.cps[i2]
            wt_list = data.wts[i2]
            for i1 in range(dim1):
                cp = cp_list[i1]
                wt = wt_list[i1]
                cp_id = self.__draw_point(cp)
                cps.append(cp_id)
                wts.append(wt)
                if per1 and i1 == 0:
                    cp_wt_1st = (cp_id, wt)
                if per1 and not per2:
                    if i2 == 0 or i2 == dim2 - 1:
                        cpsf.append(cp_id)
                        wtsf.append(wt)
            if per1:
                cp_id, wt = cp_wt_1st
                cps.append(cp_id)
                wts.append(wt)
                if not per2:
                    if i2 == 0 or i2 == dim2 - 1:
                        cpsf.append(cp_id)
                        wtsf.append(wt)

                        p = self.__new_expr_id()
                        gmsh.model.occ.addBSpline(cpsf, tag=p, degree=deg1, weights=wtsf,
                                                  knots=kts1, multiplicities=mps1)
                    if i2 == 0:
                        face_f = self.__draw_loop([p])
                    elif i2 == dim2 - 1:
                        face_b = self.__draw_loop([p])
        if per1:
            dim1 += 1
        if per2:
            for i1 in range(dim1):
                cps.append(cps[i1])
                wts.append(wts[i1])
            dim2 += 1

        p = self.__new_expr_id()
        gmsh.model.occ.addBSplineSurface(cps, dim1, tag=p, degreeU=deg1, degreeV=deg2,
                                         weights=wts, knotsU=kts1, knotsV=kts2,
                                         multiplicitiesU=mps1, multiplicitiesV=mps2)
        gmsh.model.occ.synchronize()

        m = self.__new_expr_id()
        gmsh.model.addPhysicalGroup(2, [p], tag=m, name=name)

        if face_f is not None:
            face_f = self.__pp_surface(name + "-f", [face_f])
        if face_b is not None:
            face_b = self.__pp_surface(name + "-b", [face_b])

        return (m, face_f, face_b)

    def draw_nurbs(self, name, data):
        if data.is_surface():
            return self.__draw_nurbs_surface(name, data)
        return self.__draw_nurbs_curve(name, data)


Geo = Q3D_Draw()

def test_ellipse(orientation, origin, major, minor):
    frame = Q3D_Frame.sketch_reset(orientation, origin)
    data = frame.nurbs_ellipse(major, minor)
    return Geo.draw_nurbs("ellipse-" + orientation, data)

def test_torus(orientation, origin, radius, major, minor, pitch=0.0, theta=None):
    frame = Q3D_Frame.sketch_reset(orientation, origin)
    data = frame.nurbs_torus(radius, major, minor, pitch, theta)
    return Geo.draw_nurbs("torus-" + orientation, data)

C1 = test_ellipse('XY', (-1.0, 0.0, 0.0), 1.0, 1.0)
C2 = test_ellipse('YZ', ( 0.0,-1.0, 0.0), 0.8, 0.3)
C3 = test_ellipse('ZX', ( 0.0, 0.0,-1.0), 0.2, 0.9)

S1 = test_torus('XY', ( 1.0, 0.0, 0.0),   1, 0.2, 0.2)
S2 = test_torus('YZ', ( 0.5, 0.0, 1.0),   1, 0.2, 0.2, 0.0, (-0.25*math.pi,1.25*math.pi))
S3 = test_torus('ZX', ( 0.0, 0.0, 0.5), 0.6, 0.1, 0.3, 0.5, ( 0.25*math.pi,4.25*math.pi))

gmsh.model.mesh.generate(2)

if "-nopopup" not in sys.argv:
    gmsh.fltk.run()

gmsh.finalize()
