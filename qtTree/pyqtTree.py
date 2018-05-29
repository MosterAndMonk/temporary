# -*- coding: utf-8 -*-
from PyQt4 import QtCore, QtGui, uic
from PyQt4.QtGui import *
from PyQt4.QtCore import *

import os
from qimage2numpy import qpixmap2numpy
from pixels import Calc
import sqlite3
import win32api
from qttreeui import *

#qtCreatorFile = "qttree.ui" # Enter file here.

#Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)

def dict_factory(cursor, row):
    d = {}
    for idx, col in enumerate(cursor.description):
        d[col[0]] = row[idx]
    return d

#QGraphics
class CustomPolygonItem(QGraphicsPolygonItem):
    def __init__(self, polygon):
        QGraphicsPolygonItem.__init__(self)
        self.setPolygon(polygon)
        pen = QPen()
        pen.setWidth(3)

    def scaleView(self, scaleFactor):
        self.scale(scaleFactor, scaleFactor)

class CustomLineItem(QGraphicsLineItem):
    def __init__(self):
        QGraphicsLineItem.__init__(self)
    def startDraw(self, e):
        self.setLine(QLineF(e.scenePos(), e.scenePos()))
    def drawing(self, e):
        newLine = QLineF(self.line().p1(), e.scenePos())
        self.setLine(newLine)

class CustomRectItem(QGraphicsRectItem):
    def __init__(self, w, h):
        QGraphicsRectItem.__init__(self)
        self.setRect(w/2, h/2, w/5, h/5)
        pen = QPen()
        pen.setWidth(3)
    '''
    def mousePressEvent(self, e):#*args, **kwargs):

        p1 = self.mapFromItem(self, QPointF(0, 0))
        p2 = self.mapToItem(self, QPointF(0, 0))
        p3 = self.mapFromScene(QPointF(0, 0))
        print 'item mapFromItem',p1.x(), p1.y()
        print 'item mapToItem', p2.x(), p2.y()
        print 'item mapFromScene', p3.x(), p3.y()

        #self.update()
        #pass
    '''
    def scaleView(self, scaleFactor):
        factor = self.matrix().scale(scaleFactor, scaleFactor).mapRect(QtCore.QRectF(0, 0, 1, 1)).width()
        if factor < 0.07 or factor > 100:
            return
        self.scale(scaleFactor, scaleFactor)

class CustomScence(QGraphicsScene):
    noShape, rect, polygon = range(3)
    def __init__(self):
        QGraphicsScene.__init__(self)

        self.shapeCase = self.noShape
        self.isFirstPoint = True
        self.pointList = None

        self.lineList = None
        self.objectPolygon = None
        self.np = None
        self.qpm = None
        self.clipImage = None

    def setShapeCase(self, n):
        self.shapeCase = n
    '''
    def setBackImagePath(self, path):
        self.path = path

    def drawBackground(self, painter, rectF):
        image = QImage(self.path)
        source = QRectF(0.0, 0.0, image.width(), image.height())
        painter.drawImage(rectF, image, source)
    '''
    def keyPressEvent(self, e):
        key = e.key()
        if key == Qt.Key_Backspace | key == Qt.Key_Delete:
            while self.selectedItems():
                self.removeItem(self.selectedItems()[0])
            self.isFirstPoint = True
            self.pointList = None
            self.lineList = None
        if key == QtCore.Qt.Key_PageDown:
            if self.selectedItems():
                self.selectedItems()[0].scaleView(1.2)
        elif key == QtCore.Qt.Key_PageUp:
            if self.selectedItems():
                self.selectedItems()[0].scaleView(1/1.2)
        else:
            QGraphicsScene.keyPressEvent(self,e)

    def mousePressEvent(self, e):
        if self.shapeCase == self.polygon:
            linePainter = CustomLineItem()
            self.currItem = linePainter
            self.addItem((self.currItem))

            if self.currItem != None:
                self.currItem.startDraw(e)
            #print "press", e.scenePos()
            if self.isFirstPoint:
                self.pointList = [e.scenePos()]
                self.lineList = [self.currItem]
                self.isFirstPoint = False
            else:
                self.pointList.append(e.scenePos())
                self.lineList.append(self.currItem)

        QGraphicsScene.mousePressEvent(self, e)

    def mouseMoveEvent(self, e):
        if self.shapeCase == self.polygon:
            if self.currItem != None:
                    self.currItem.drawing(e)
        QGraphicsScene.mouseMoveEvent(self, e)

    def isSamePoint(self, p1, p2, v):
        x = p1.x() - p2.x()
        y = p1.y() - p2.y()
        return x*x+y*y < v*v

    def clipPolygonObject(self):
        if self.objectPolygon is None:
            return
        objectRect = self.objectPolygon.boundingRect()
        map = self.qpm.copy(objectRect.topLeft().x(), objectRect.topLeft().y(), objectRect.bottomRight().x(), objectRect.bottomRight().y())
        polygonPath= QPainterPath()
        polygonPath.addPolygon(self.objectPolygon)
        polygonPath = polygonPath.translated(0-objectRect.topLeft().x(), 0-objectRect.topLeft().y())
        tempImage = QPixmap(objectRect.width(), objectRect.height())
        tempImage.fill(QColor(0, 0, 0))

        tempPaint = QPainter(tempImage)
        tempPaint.setClipping(True)
        tempPaint.setClipPath(polygonPath)
        tempPaint.drawPixmap(0,0, map)
        tempPaint.setClipping(False)
        tempPaint.end()

        self.clipImage = qpixmap2numpy(tempImage)

        #tempImage.save(QString(r"C:\Users\Administrator\Desktop\cutTree.jpg"))

    def mouseReleaseEvent(self, e):
        if self.shapeCase == self.polygon:
            #print "release", e.scenePos()
            if self.pointList is not None:
                if self.isSamePoint(e.scenePos(), self.pointList[0], 105) and len(self.pointList) > 2:
                    while self.lineList:
                        self.removeItem(self.lineList[0])
                        self.lineList = self.lineList[1:]
                    self.pointList.append(self.pointList[0])
                    self.objectPolygon = QPolygonF(self.pointList)
                    item = CustomPolygonItem(self.objectPolygon)
                    self.addItem(item)
                    item.setFlag(QGraphicsItem.ItemIsMovable)
                    item.setFlag(QGraphicsItem.ItemIsSelectable)
                    self.setShapeCase(self.noShape)
        QGraphicsScene.mouseReleaseEvent(self, e)

    def setTreePixmap(self, path):
        self.clear()

        self.shapeCase = self.noShape
        self.isFirstPoint = True
        self.pointList = None

        self.lineList = None
        self.objectPolygon = None
        self.np = None
        self.qpm = None
        self.clipImage = None
        item = None
        if path != "":
            self.qpm = QPixmap(path)
            item = self.addPixmap(self.qpm)
        return item

class MyApp(QMainWindow, Ui_qttree):
    def __init__(self, root):
        QMainWindow.__init__(self)
        super(MyApp, self).__init__()
        self.setupUi(self)

        self.root = root
        self.init_sqlite3()

        self.scene = CustomScence()
        self.graphicsView.setScene(self.scene)
        self.initMyUI()
        self.graphicsView.show()

    def initMyUI(self):

        self.createButtonConnect()

        self.treeTableUI()

        self.graphicsView.setAlignment(Qt.AlignLeft)
        self.graphicsView.setAlignment(Qt.AlignTop)

        self.graphicsView.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.graphicsView.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        
        self.imagePath = "image/timg.jpg"
        self.slotSetTreeImage()

        self.painterClickTimes = 0

    def init_sqlite3(self):
        self.conn = sqlite3.connect("%s/TreeHealth.db" % (self.root))
        self.conn.row_factory = dict_factory
        self.conn.text_factory = lambda x: unicode(x, "utf-8")
        self.cursor = self.conn.cursor()

    #treeTable
    def treeTableUI(self):
        self.createTreeTableActions()

        self.cursor.execute("SELECT * FROM treeTable")
        self.tree_table = self.cursor.fetchall()

        self.treeInfoRows = len(self.tree_table)
        self.treeInfoColumns = 5
        self.tableWidget_3.setRowCount(self.treeInfoRows)

        self.comboBox_5.clear()
        for row, treeRow in enumerate(self.tree_table):
            self.tableWidget_3.setItem(row, 0, QTableWidgetItem('%d'%treeRow['treeID']))
            self.tableWidget_3.setItem(row, 1, QTableWidgetItem(treeRow['species']))
            self.tableWidget_3.setItem(row, 2, QTableWidgetItem('%d'%treeRow['age']))
            self.tableWidget_3.setItem(row, 3, QTableWidgetItem(treeRow['place']))
            self.tableWidget_3.setItem(row, 4, QTableWidgetItem(treeRow['protectLevel']))

            self.comboBox_5.addItem('%d'%treeRow['treeID'])

        self.tableWidget_3.horizontalHeader().setResizeMode(QHeaderView.Stretch)
        self.tableWidget_3.setSelectionBehavior(QAbstractItemView.SelectRows)
        self.tableWidget_3.setSelectionMode(QAbstractItemView.SingleSelection)

    def treeTableAddRow(self):
        #self.tableWidget_3.insertRow(self.tableWidget_3, 1)
        self.treeInfoRows = self.treeInfoRows + 1
        self.tableWidget_3.setRowCount(self.treeInfoRows)

    def treeTableDelRow(self):
        self.treeInfoRows = self.treeInfoRows - 1
        rowIndex = self.tableWidget_3.currentRow()
        self.tableWidget_3.removeRow(rowIndex)

    def treeTableSave(self):
        self.cursor.execute("DELETE FROM treeTable")

        for i in range(self.treeInfoRows):
            self.cursor.execute(
                "insert into treeTable(treeID,species,age,place,protectLevel) values (?,?,?,?,?)",
                (unicode(self.tableWidget_3.item(i, 0).data(Qt.DisplayRole).toString()),
                 unicode(self.tableWidget_3.item(i, 1).data(Qt.DisplayRole).toString()),
                 unicode(self.tableWidget_3.item(i, 2).data(Qt.DisplayRole).toString()),
                 unicode(self.tableWidget_3.item(i, 3).data(Qt.DisplayRole).toString()),
                 unicode(self.tableWidget_3.item(i, 4).data(Qt.DisplayRole).toString())))

        self.conn.commit()
        self.treeTableUI()

    def diagnoseTableInsert(self, treeID,imagePath,diagnosePart, recommendLevel,diagnoseData, diagnoseTime):
        self.cursor.execute(
                "insert into imageTable(treeID,imagePath,diagnosePart, recommendLevel,diagnoseData, diagnoseTime) values (?,?,?,?,?,?)",
                (treeID,imagePath,diagnosePart, recommendLevel,diagnoseData, diagnoseTime))
        self.conn.commit()
    #右键菜单
    def contextMenuEvent(self, event):
        menu = QtGui.QMenu(self)
        menu.addAction(self.addRow)
        menu.addAction(self.delRow)
        menu.addAction(self.Save)
        menu.exec_(event.globalPos())

    def createTreeTableActions(self):
        self.addRow = QtGui.QAction(u"&添加行", self,
                                    shortcut=QtGui.QKeySequence.New,
                                    statusTip=u"树木信息添加行",
                                    triggered=self.treeTableAddRow)
        self.delRow = QtGui.QAction(u"&删除行", self,
                                    shortcut=QtGui.QKeySequence.Delete,
                                    statusTip=u"树木信息删除选中行",
                                    triggered=self.treeTableDelRow)
        self.Save = QtGui.QAction(u"&保存", self,
                                    shortcut=QtGui.QKeySequence.Save,
                                    statusTip=u"保存树木信息",
                                    triggered=self.treeTableSave)


    #all buttons of qgraphics
    noShape, rect, polygon = range(3)
    def createButtonConnect(self):
        self.pushButton_6.clicked.connect(self.slotAddPolygonItem)
        self.pushButton_4.clicked.connect(self.slotAddRectItem)
        self.toolButton_3.clicked.connect(self.slotOpenImageButton)
        self.pushButton_3.clicked.connect(self.slotCoreCalc)
        self.action_6.triggered.connect(self.testColorRange)
        self.action_7.triggered.connect(self.testParameters)

        self.c = Calc()
        for s in self.c.listFuntion:
            ss = self.c.dictFuntion2[s]
            self.comboBox_6.addItem(ss)

        #color range test

    def testParameters(self):
        command = "notepad.exe %s/parameters/pixels.ini" % self.root
        os.system(command)

    def testColorRange(self):
        self.c.testColor()
        if self.c.resultTestColor != None:
            self.textBrowser_6.setText(self.c.resultTestColor)

    def slotCoreCalc(self):
        self.statusBar().showMessage(u"修改函数参数，可打开当前目录下的parameters文件夹下的pixels.ini文档修改", 5000)
        if self.scene.clipImage is None:
            self.scene.clipPolygonObject()
        functionName = unicode(self.comboBox_6.currentText())
        functionName = self.c.dictFuntion1[functionName]
        self.c.resultTestColor = u""
        pointString = u""
        if self.scene.objectPolygon is not None:
            self.c.calculate(self.scene.clipImage, functionName)
            pl = self.scene.pointList
            for p in pl:
                pointString += "(%f,%f)"%(p.x(), p.y())
        elif self.scene.qpm is not None:
            self.c.calculate(qpixmap2numpy(self.scene.qpm), functionName)
        else:
            self.statusBar().showMessage(u"图片未打开，无法诊断", 2000)
        str = u""
        if self.c.result != "" and self.c.resultTestColor != "":
            str = u"leaves pixels：{0},\nhealthy crown pixels：{1},\nrecommended levels：{2}".format(self.c.result[0], self.c.result[1], self.c.result[2])
            str = self.c.resultTestColor + str
        import time
        ISOTIMEFORMAT = '%Y-%m-%d %X'
        timestring = time.strftime(ISOTIMEFORMAT, time.localtime())
        #print len(unicode(self.comboBox_5.currentText())), len(timestring), len(str)
        #print len(self.imagePath), len(pointString), len(self.c.result[2])
        self.diagnoseTableInsert(unicode(self.comboBox_5.currentText()), self.imagePath, pointString, "%d"%self.c.result[2], str, timestring)
        self.textBrowser_6.setText(str)

    def slotAddPolygonItem(self):
        self.painterClickTimes = self.painterClickTimes + 1
        if self.painterClickTimes % 2 == 1:
            self.setCursor(Qt.CrossCursor)
            self.scene.setShapeCase(self.polygon)
        else:
            self.setCursor(Qt.ArrowCursor)
            self.scene.setShapeCase(self.noShape)

    def slotOpenImageButton(self):
        s = QFileDialog.getOpenFileName(self, u"打开图片","/", "Image Files(*.png *.jpg *.bmp)")
        self.lineEdit.setText(s)
        self.slotSetTreeImage()

    def slotAddRectItem(self):
        self.scene.setShapeCase(self.rect)
        item = CustomRectItem(500, 500)
        self.scene.addItem(item)
        self.graphicsView.ensureVisible(item)
        item.setFlag(QGraphicsItem.ItemIsMovable)
        item.setFlag(QGraphicsItem.ItemIsSelectable)

    def slotSetTreeImage(self):
        s = unicode(self.lineEdit.text())
        if s != '':
            self.imagePath = s
        #item = self.scene.setTreePixmap(self.imagePath)
        item = self.scene.setTreePixmap(s)
        if item is not None:
            self.graphicsView.fitInView(item, Qt.KeepAspectRatio)
        #self.scene.setBackImagePath(self.imagePath)

if __name__ == "__main__":
    import sys

    if len(sys.argv) > 0:
        root_path = sys.argv[0]
        root_path = os.path.dirname(root_path)

    app = QtGui.QApplication(sys.argv)
    window = MyApp(root_path)
    window.show()
    sys.exit(app.exec_())