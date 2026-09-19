# Reading and comparing the PNG images written by Gmsh: with Pillow and NumPy
# when they are installed, with the standard library alone otherwise (much
# slower; 8 bit RGB or RGBA, not interlaced)

import struct
import zlib

try:
    import numpy
    from PIL import Image
except ImportError:
    numpy = None


def read(path):
    with open(path, 'rb') as f:
        data = f.read()
    if data[:8] != b'\x89PNG\r\n\x1a\n':
        raise ValueError('%s: not a PNG file' % path)
    pos, idat = 8, []
    while pos < len(data):
        n, kind = struct.unpack('>I4s', data[pos:pos + 8])
        chunk = data[pos + 8:pos + 8 + n]
        if kind == b'IHDR':
            w, h, depth, ctype, _, _, interlace = struct.unpack('>IIBBBBB',
                                                                chunk)
            if depth != 8 or ctype not in (2, 6) or interlace:
                raise ValueError('%s: unsupported PNG format' % path)
        elif kind == b'IDAT':
            idat.append(chunk)
        pos += 12 + n
    bpp = 3 if ctype == 2 else 4
    raw = zlib.decompress(b''.join(idat))
    stride = w * bpp
    out = bytearray(h * stride)
    prev = bytearray(stride)
    for y in range(h):
        ftype = raw[y * (stride + 1)]
        line = bytearray(raw[y * (stride + 1) + 1:(y + 1) * (stride + 1)])
        if ftype == 1:
            for i in range(bpp, stride):
                line[i] = (line[i] + line[i - bpp]) & 255
        elif ftype == 2:
            for i in range(stride):
                line[i] = (line[i] + prev[i]) & 255
        elif ftype == 3:
            for i in range(stride):
                a = line[i - bpp] if i >= bpp else 0
                line[i] = (line[i] + ((a + prev[i]) >> 1)) & 255
        elif ftype == 4:
            for i in range(stride):
                a = line[i - bpp] if i >= bpp else 0
                b = prev[i]
                c = prev[i - bpp] if i >= bpp else 0
                p = a + b - c
                pa, pb, pc = abs(p - a), abs(p - b), abs(p - c)
                pr = a if pa <= pb and pa <= pc else (b if pb <= pc else c)
                line[i] = (line[i] + pr) & 255
        out[y * stride:(y + 1) * stride] = line
        prev = line
    if bpp == 4:  # drop the alpha
        rgb = bytearray(w * h * 3)
        rgb[0::3], rgb[1::3], rgb[2::3] = out[0::4], out[1::4], out[2::4]
        out = rgb
    return w, h, bytes(out)


def diff(path1, path2, tol=8):
    """Number of pixels differing by more than tol in some channel, and the
    total number of pixels (-1 if the sizes differ)."""
    if numpy:
        a = numpy.asarray(Image.open(path1).convert('RGB'), dtype=numpy.int16)
        b = numpy.asarray(Image.open(path2).convert('RGB'), dtype=numpy.int16)
        if a.shape != b.shape:
            return -1, a.shape[0] * a.shape[1]
        return (int((numpy.abs(a - b).max(axis=2) > tol).sum()),
                a.shape[0] * a.shape[1])
    with open(path1, 'rb') as f1, open(path2, 'rb') as f2:
        same = f1.read() == f2.read()
    w1, h1, a = read(path1)
    if same:
        return 0, w1 * h1
    w2, h2, b = read(path2)
    if (w1, h1) != (w2, h2):
        return -1, w1 * h1
    if a == b:
        return 0, w1 * h1
    n = 0
    for i in range(0, len(a), 3):
        if (abs(a[i] - b[i]) > tol or abs(a[i + 1] - b[i + 1]) > tol or
                abs(a[i + 2] - b[i + 2]) > tol):
            n += 1
    return n, w1 * h1
