import PIL
from PIL import Image
from matplotlib import pyplot as plt

im = Image.open(r'C:\Users\Administrator\Desktop\ttttt.jpg')
w, h = im.size
colors = im.getcolors(w*h)

def hexencode(rgb):
    r=rgb[0]
    g=rgb[1]
    b=rgb[2]
    return '#%02x%02x%02x' % (r,g,b)

for idx, c in enumerate(colors):
    plt.bar(idx, c[0], color=hexencode(c[1]), edgecolor = hexencode(c[1]))

plt.show()