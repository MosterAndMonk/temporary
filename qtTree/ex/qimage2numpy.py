from PyQt4.QtGui import *
import numpy

def qimage2numpy(qimage, dtype = 'array'):
    """Convert QImage to numpy.ndarray.  The dtype defaults to uint8
    for QImage.Format_Indexed8 or `bgra_dtype` (i.e. a record array)
    for 32bit color images.  You can pass a different dtype to use, or
    'array' to get a 3D uint8 array for color images."""
    result_shape = (qimage.height(), qimage.width())
    temp_shape = (qimage.height(),
                  qimage.bytesPerLine() * 8 / qimage.depth())
    if qimage.format() in (QImage.Format_ARGB32_Premultiplied,
                           QImage.Format_ARGB32,
                           QImage.Format_RGB32):
        if dtype == 'rec':
            dtype = numpy.bgra_dtype
        elif dtype == 'array':
            dtype = numpy.uint8
            result_shape += (4, )
            temp_shape += (4, )
    elif qimage.format() == QImage.Format_Indexed8:
        dtype = numpy.uint8
    else:
        raise ValueError("qimage2numpy only supports 32bit and 8bit images")
    # FIXME: raise error if alignment does not match
    buf = qimage.bits().asstring(qimage.numBytes())
    result = numpy.frombuffer(buf, dtype).reshape(temp_shape)
    if result_shape != temp_shape:
        result = result[:,:result_shape[1]]
    if qimage.format() == QImage.Format_RGB32 and dtype == numpy.uint8:
        result = result[...,:3]
    return result

def qpixmap2numpy(inPixmap, dtype = 'array'):
    return qimage2numpy(inPixmap.toImage(), dtype)