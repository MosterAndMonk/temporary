from distutils.core import setup
from py2exe.build_exe import py2exe
import matplotlib.backends.backend_tkagg
import glob
import os
import sys

opts = {
    'py2exe': {
        "includes": ["matplotlib.backends",
                     "pylab",
                     "matplotlib.figure",
                     "numpy",
                     "matplotlib.backends.backend_gtkagg"],
        'excludes':['_gtkagg',
                    '_tkagg',
                    '_agg2',
                    '_cairo',
                    '_cocoaagg',
                    '_fltkagg',
                    '_gtk',
                    '_gtkcairo' ],
        'dll_excludes':["MSVCP90.dll",
                        'libgdk-win32-2.0-0.dll',
                        'libgobject-2.0-0.dll']
    }
}

data_files = [(r'mpl-data', glob.glob(r'C:\Python27\Lib\site-packages\matplotlib\mpl-data\*.*')),
              (r'mpl-data', [r'C:\Python27\Lib\site-packages\matplotlib\mpl-data\matplotlibrc']),
              (r'mpl-data\images', glob.glob(r'C:\Python27\Lib\site-packages\matplotlib\mpl-data\images\*.*')),
              (r'mpl-data\fonts', glob.glob(r'C:\Python27\Lib\site-packages\matplotlib\mpl-data\fonts\*.*'))]
'''
parent_path = r"C:\Python27\Lib\site-packages\matplotlib\backends\backend_tkagg.pyc"
if parent_path not in sys.path:
    sys.path.append(parent_path)
'''
setup(windows=[{'script':"pyqtTree.py"}], options = opts, data_files=data_files)