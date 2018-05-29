import numpy as np
from matplotlib import pyplot as plt
#from scipy.cluster.vq import *
#from sklearn.cluster import KMeans
import math
import cv2
import os

def calculate(imgPath):
    tree = cv2.imread(imgPath)
    treeHSV = cv2.cvtColor(tree, cv2.COLOR_BGR2HSV)
    tree = cv2.cvtColor(tree, cv2.COLOR_BGR2RGB)
    treeH = treeHSV[:, :, 0]
    histTreeH = cv2.calcHist([treeH], [0], None, [180], [0, 180])

    plt.subplot(121)
    plt.imshow(tree)
    plt.subplot(122)
    plt.plot(histTreeH)
    plt.xlim([0, 180])
    plt.show()

    #"C:\Users\Administrator\Desktop\timg.jpg"
source = r'D:\wei\1learning\IT\course\grade4\graduationProject\data\img\result'
for src in os.listdir(source):
    if 'png' not in src:
        continue
    src = source +'\\'+src
    calculate(src)
