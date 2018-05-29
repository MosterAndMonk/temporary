# -*- coding: utf-8 -*-
import numpy as np
import matplotlib
import FileDialog
from matplotlib import pyplot as plt
import math
import cv2
import os
import ConfigParser
import codecs

class Calc():
    listFuntion = [ 'leaf_colorRangeLevel', 'leaf_findGreenPixels', 'crownExcursion', 'leaf_hsvHist']
    dictFuntion1 = {u'树叶诊断（颜色直方图）':'leaf_colorRangeLevel', u'树叶诊断（RGB）':'leaf_findGreenPixels',u'偏冠诊断':'crownExcursion',u'绘制颜色直方图': 'leaf_hsvHist'}
    dictFuntion2 = {'leaf_colorRangeLevel':u'树叶诊断（颜色直方图）', 'leaf_findGreenPixels': u'树叶诊断（RGB）', 'crownExcursion': u'偏冠诊断', 'leaf_hsvHist':u'绘制颜色直方图'}
    def __init__(self):
        self.readConfigParameters()
        self.drawByHist = True
        self.resultTestColor = None
        self.result = None
        self.wrongString = u"No Wrong"
        self.spentTimeString = u"No Spenting Time"

    def readConfigParameters(self):
        #self.config = ConfigParser.ConfigParser()
        #self.config.read(r'./parameters/pixels.ini')
        self.config = ConfigParser.SafeConfigParser()
        with codecs.open(r'./parameters/pixels.ini', 'r', encoding='utf-8') as f:
            self.config.readfp(f)
        '''
        try:
            self.config = ConfigParser.SafeConfigParser()
            with codecs.open(r'./parameters/pixels.ini', 'r', encoding='utf-8') as f:
                self.config.readfp(f)
        except:
            return u"读配置文档错误"
        return u""
        '''

    def leaves(self, img):
        maxx = img.shape[0]
        maxy = img.shape[1]
        pixs = 0
        # print maxx, maxy
        for x in range(0, maxx):
            for y in range(0, maxy):
                if img[x, y, 1] > img[x, y, 0] and img[x, y, 1] > img[x, y, 2]:
                    #img[x, y] = [0, 255, 0]
                    pixs = pixs + 1
        return pixs

    def crown(self, img, backgroundValue=0):
        imgray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        maxx = img.shape[0]
        maxy = img.shape[1]
        pixs = 0
        # print maxx, maxy
        for x in range(0, maxx):
            for y in range(0, maxy):
                if imgray[x, y] != backgroundValue:
                    pixs = pixs + 1
        return pixs

    def grade(self, nu, de, totalv, n):
        curv = float(nu) / de
        mean = float(totalv) / n
        rank = n - math.floor(curv / mean)
        return rank

    def leaf_findGreenPixels(self):
        plt.subplot(111)
        plt.imshow(self.img)

        self.im2 = self.img
        leavesPixels = self.leaves(self.im2)
        crownPixels = self.crown(self.img)
        rank = self.grade(leavesPixels, crownPixels, 1, 5)
        plt.show()
        return leavesPixels, crownPixels, rank

    def crownExcursion(self):
        pass

    def leaf_hsvHist(self, isShowImage=False):
        from color_histogram.core.hist_1d import Hist1D
        import matplotlib.pyplot as plt
        from time import clock

        bgr = self.img
        rgb = cv2.cvtColor(bgr, cv2.COLOR_BGR2RGB)
        try:
            num_bins = self.config.getint("leaf_hsvHist", "num_bins")
        except ConfigParser.Error:
            #print u"Error: 读不到该值"
            self.wrongString = u"Error: 读不到该值"
            num_bins = 16
        self.num_bins = num_bins
        start = clock()
        num_pixels = (self.img.shape[0]*self.img.shape[1])/10
        hist1D = Hist1D(rgb, num_bins=num_bins, color_space='hsv', channel=0, num_pixels=num_pixels, alpha=0.01)
        self.calc_hist_bins = hist1D.calc_hist_bins
        if isShowImage and self.drawByHist:
            fig = plt.figure()
            axx = fig.add_subplot(121)
            axx.imshow(rgb)
            ax = fig.add_subplot(122)
            hist1D.plot(ax)
            plt.show()
        elif self.drawByHist != True:
            self.rgb = rgb
            self.hist1D = hist1D
        finished = clock()
        #print " Spend Time: %f" % (finished - start)
        self.spentTimeString = u" Spend Time: %f" % (finished - start)

    def leaf_colorRangeLevel(self):
        self.leaf_hsvHist()
        try:
            colorRangeMin = self.config.getint("leaf_colorRangeLevel", "colorRangeMin")
            colorRangeMax = self.config.getint("leaf_colorRangeLevel", "colorRangeMax")
            weights = self.config.get("leaf_colorRangeLevel", "weights")
        except ConfigParser.Error:
            #print u"Error: leaf_colorRangeLevel 读不到值"
            self.wrongString = u"Error: leaf_colorRangeLevel 读不到值"
            colorRangeMin = 3
            colorRangeMax = 7
            weights = "default"

        if weights == "default":
            '''
            mean = 1.0/(colorRangeMax-colorRangeMin)
            weightlist = np.arange(1, colorRangeMax-colorRangeMin+1, dtype=np.float32)
            weightlist = weightlist * mean
          '''
            weightlist = np.ones(colorRangeMax-colorRangeMin+1)
        else:
            weightlist = weights.split(',')
            l = []
            for s in weightlist:
                l.append(int(s))
            weightlist = np.array(l)
        greenlist = []
        for i in range(colorRangeMin, colorRangeMax+1):
            greenlist.append(self.calc_hist_bins[i])
        greenlist = np.array(greenlist)
        if len(greenlist) != len(weightlist):
            #print "权重个数和树叶指标数不一致"
            self.wrongString = u"权重个数和树叶指标数不一致"
            return
        leaves_sum = np.sum(greenlist * weightlist)
        crown_sum = np.sum(self.calc_hist_bins) - self.calc_hist_bins[0] - self.calc_hist_bins[self.num_bins - 1]
        rank = self.grade(leaves_sum, crown_sum, 1, 5)

        try:
            ranges = self.config.get("testColor", "ranges")
            names = self.config.get("testColor", "names")
        except ConfigParser.Error:
            #print u"Error:testColor 读不到值"
            self.wrongString = u"Error:testColor 读不到值"
            return

        rangelist = ranges.split(',')
        namelist = names.split(',')
        l = []
        for s in rangelist:
            l.append(int(s))
        rangelist = np.array(l)

        n = len(rangelist) / 2
        resultTestColor = u''
        sum = crown_sum

        for i in range(0, n):
            min = rangelist[2 * i]
            max = rangelist[2 * i + 1]
            csum = 0.0
            for x in range(min, max + 1):
                csum += self.calc_hist_bins[x]
            ratio = csum / sum
            str = "{0} leaves {1}-{2}\nratio: {3}%\n".format(namelist[i], min, max, round(ratio * 100, 2))
            resultTestColor = resultTestColor + str
        self.resultTestColor = resultTestColor
        return leaves_sum, crown_sum, rank

    def testColor(self):
        try:
            imagePath = self.config.get("testColor", "imagePath")
            ranges = self.config.get("testColor", "ranges")
            names = self.config.get("testColor", "names")
        except ConfigParser.Error:
            #print u"Error:testColor 读不到值"
            self.wrongString = u"Error:testColor 读不到值"
        rangelist = ranges.split(',')
        namelist = names.split(',')
        l = []
        for s in rangelist:
            l.append(int(s))
        rangelist = np.array(l)

        self.drawByHist = False
        for src in os.listdir(imagePath):
            if 'bmp' not in src:
                continue
            src = imagePath + '\\' + src
            self.calculate(imgPath=src, function=self.listFuntion[3], img=None)
            n = len(rangelist)/2
            resultTestColor = u''
            sum = np.sum(self.calc_hist_bins)-self.calc_hist_bins[0]-self.calc_hist_bins[self.num_bins-1]

            for i in range(0, n):
                min = rangelist[2*i]
                max = rangelist[2*i+1]
                csum = 0.0
                for x in range(min, max+1):
                    csum += self.calc_hist_bins[x]
                ratio = csum / sum
                str = "{0} leaves {1}-{2}\nratio: {3}%\n".format(namelist[i], min, max, round(ratio*100, 2))
                resultTestColor = resultTestColor + str
            fig = plt.figure()
            axx = fig.add_subplot(121)
            axx.imshow(self.rgb)
            ax = fig.add_subplot(122)
            ax.text(170, 0.8, resultTestColor)
            self.hist1D.plot(ax)
            plt.show()

    def calculate(self, img, function, imgPath=None):
        if imgPath == None:
            self.img = img
        else:
            self.img = cv2.imread(imgPath, cv2.IMREAD_COLOR)
        #if the image is too big, the "MemoryError" will be taken place
        if self.img.shape[0] > 2000 or self.img.shape[1] > 2000:
            self.imgOriginal = self.img.copy()
            size = (int(self.img.shape[0] * 0.05), int(self.img.shape[1] * 0.05))
            self.img = cv2.resize(self.imgOriginal, size, interpolation=cv2.INTER_AREA)

        if function == 'leaf_hsvHist' or function == self.listFuntion[3]:
            self.leaf_hsvHist(True)
        elif function == 'leaf_findGreenPixels' or function == self.listFuntion[1]:
            self.result = self.leaf_findGreenPixels()
        elif function == 'crownExcursion' or function == self.listFuntion[2]:
            self.crownExcursion()
        elif function == 'leaf_colorRangeLevel' or function == self.listFuntion[0]:
            self.result = self.leaf_colorRangeLevel()
        else:
            pass

    def get_original_image(self):
        return self.img

    def get_modified_image(self):
        return self.im2
'''
source = r'D:\wei\1learning\IT\course\grade4\graduationProject\data\img\20170407\leaf'
#source = r'D:\wei\1learning\IT\course\grade4\graduationProject\data\img\result'
for src in os.listdir(source):
    if 'bmp' not in src :
        continue
    src = source +'\\'+src
    c = Calc()
    c.calculate(imgPath=src, function=c.listFuntion[3], img=None)
'''