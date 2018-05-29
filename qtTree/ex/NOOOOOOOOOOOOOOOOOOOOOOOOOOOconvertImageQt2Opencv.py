# -*- coding: utf-8 -*-

from PyQt4.QtGui import *
from PyQt4.QtCore import *
import cv2

def qimage2CvMat(inImage, inCloneImageData = True):
    if inImage.format() == QImage.Format_ARGB32 or inImage.format() == QImage.Format_ARGB32_Premultiplied:
        m = cv2.Mat(inImage.height(), inImage.width(),cv2.CV_8UC4, inImage.bits(), inImage.bytesPerLine())
        return (m.clone() if inCloneImageData else m)
    elif inImage.format() == QImage.Format_RGB32 or inImage.format() == QImage.Format_RGB888:
        if inCloneImageData == False:
            qWarning("QImageToCvMat() - Conversion requires cloning because we use a temporary QImage")
        swapped = inImage
        if inImage.format() == QImage.Format_RGB32:
            swapped = swapped.convertToFormat(QImage.Format_RGB888)
        swapped = swapped.rgbSwapped()
        return cv2.Mat(swapped.height, swapped.width(), cv2.CV_8UC3, swapped.bits(), swapped.bytePerLine()).clone()
    elif inImage.format() == QImage.Format_Indexed8:
        mat = cv2.Mat(inImage.height(), inImage.width(), cv2.CV_8UCl, inImage.bits(), inImage.bytePerLine())
        return (mat.clone() if inCloneImageData else mat)
    else:
        qWarning("QImageToCvMat() - QImage format not handled in switch:"+inImage.format())

    return cv2.Mat()

def qpixmap2CvMat(inPixmap, inCloneImageData = True):
    return qimage2CvMat(inPixmap.toImage(), inCloneImageData)
