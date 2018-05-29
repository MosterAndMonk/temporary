import numpy as np
from matplotlib import pyplot as plt
import matplotlib
import math
import cv2
import os
import colorsys

def to32F(img):
    if img.dtype == np.float32:
        return img
    return (1.0 / 255.0) * np.float32(img)

def hsv2rgb(h, s, v):
    h = float(h)
    s = float(s)
    v = float(v)
    h60 = h / 60.0
    h60f = math.floor(h60)
    hi = int(h60f) % 6
    f = h60 - h60f
    p = v * (1 - s)
    q = v * (1 - f * s)
    t = v * (1 - (1 - f) * s)
    r, g, b = 0, 0, 0
    if hi == 0:
        r, g, b = v, t, p
    elif hi == 1:
        r, g, b = q, v, p
    elif hi == 2:
        r, g, b = p, v, t
    elif hi == 3:
        r, g, b = p, q, v
    elif hi == 4:
        r, g, b = t, p, v
    elif hi == 5:
        r, g, b = v, p, q
    r, g, b = int(r * 255), int(g * 255), int(b * 255)
    return r, g, b

def range2ticks(tick_range, decimals=1):
    ticks = np.around(tick_range, decimals=decimals)
    ticks[ticks > 10] = np.rint(ticks[ticks > 10])
    return ticks

def _range2lims(tick_range):
    unit = 0.1 * (tick_range[:, 1] - tick_range[:, 0])
    lim = np.array(tick_range)
    lim[0, 0] += -unit[0]
    lim[0, 1] += unit[0]
    lim[1, 1] += unit[1]
    return lim[0], lim[1]

def _image2pixels(image, num_pixels):
    h, w, cs = image.shape
    step = h * w / num_pixels
    return image.reshape((-1, cs))[::step]

def rgbFunction(img):

    if len(img.shape) == 2:
        h, w = img.shape
        img_rgb = np.zeros((h, w, 3), dtype=img.dtype)
        for ci in range(3):
            img_rgb[:, :, ci] = img
        return img_rgb

    h, w, cs = img.shape
    if cs == 3:
        return img

    img_rgb = np.zeros((h, w, 3), dtype=img.dtype)

    cs = min(3, cs)

    for ci in range(cs):
        img_rgb[:, :, ci] = img[:, :, ci]
    return img_rgb

def colorHist(bgr):
    rgb = cv2.cvtColor(bgr, cv2.COLOR_BGR2RGB)
    rgbf = to32F(rgb)

    num_pixels = 1000
    num_bins = 16
    channel = 0
    alpha = 0.1

    rgbf = np.array(rgbf)
    rgbf = rgbFunction(rgbf)
    lab = cv2.cvtColor(rgbf, cv2.COLOR_RGB2LAB)
    lab_pixels = _image2pixels(lab, num_pixels)[:, channel]
    rgbf_pixels = _image2pixels(rgbf, num_pixels)
    c_min = np.min(lab_pixels)
    c_max = np.max(lab_pixels)

    #compute histogram
    hist_bins = np.zeros((num_bins), dtype=np.float32)
    color_bins = np.zeros((num_bins, 3), dtype=np.float32)

    color_ids = (num_bins - 1) * (lab_pixels - c_min) / (c_max - c_min)
    color_ids = np.int32(color_ids)

    for pi, color_id in enumerate(color_ids):
        hist_bins[color_id] += 1
        color_bins[color_id] += rgbf_pixels[pi]

    hist_positive = hist_bins > 0.0

    for ci in xrange(3):
        color_bins[hist_positive, ci] /= hist_bins[hist_positive]

    density_mean = np.mean(hist_bins)
    low_density = hist_bins < density_mean * alpha
    hist_bins[low_density] = 0.0

    for ci in xrange(3):
        color_bins[low_density, ci] = 0.0

    # draw histogram
    fig = plt.figure()
    ax = fig.add_subplot(111)

    color_ids = np.where(hist_bins > 0.0)
    color_ids = np.array(color_ids).T
    color_samples = c_min + (color_ids * (c_max - c_min)) / float(num_bins - 1.0)

    color_densities = np.float32(hist_bins[hist_positive])
    density_max = np.max(color_densities)
    color_densities = color_densities / density_max

    colors = color_bins[hist_positive, :]
    colors = np.clip(colors, 0.0, 1.0)

    width = (c_max - c_min) / float(num_bins)

    ax.bar(color_samples, color_densities, width=width, color=colors)

    ax.set_xlabel("Lab"[channel])
    ax.set_ylabel("Density")

    tick_range = np.array([[c_min, c_max], [0.0, 1.0]])
    xticks, yticks = range2ticks(tick_range)

    ax.set_xticks(xticks)
    ax.set_yticks(yticks)

    xlim, ylim = _range2lims(tick_range)

    ax.set_xlim(xlim)
    ax.set_ylim(ylim)

    plt.imshow(rgb)
    plt.show()

    xlim, ylim = _range2lims(tick_range)

    ax.set_xlim(xlim)
    ax.set_ylim(ylim)
    plt.show()