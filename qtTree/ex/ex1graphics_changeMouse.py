# -*- coding: utf-8 -*-
from PyQt4.QtGui import *
from PyQt4.QtCore import *
import sys

QTextCodec.setCodecForTr(QTextCodec.codecForName("utf8"))


class EventFilter(QDialog):
    def __init__(self, parent=None):
        super(EventFilter, self).__init__(parent)
        self.setWindowTitle(self.tr("改变鼠标形状"))

        self.ArrowButton = QPushButton(self.tr("Arrow"))
        self.upArrowButton = QPushButton(self.tr("upArrow"))
        self.CrossButton = QPushButton(self.tr("upArrow"))

        layout = QGridLayout(self)
        layout.addWidget(self.ArrowButton, 0, 0)
        layout.addWidget(self.upArrowButton, 0, 1)
        layout.addWidget(self.CrossButton, 0, 2)

        self.connect(self.ArrowButton, SIGNAL("clicked()"), self.slotArrow)
        self.connect(self.upArrowButton, SIGNAL("clicked()"), self.slotupArrow)
        self.connect(self.CrossButton, SIGNAL("clicked()"), self.slotCross)

        self.resize(300, 200)

    def slotArrow(self):
        self.setCursor(Qt.ArrowCursor)

    def slotupArrow(self):
        self.setCursor(Qt.UpArrowCursor)

    def slotCross(self):
        self.setCursor(Qt.CrossCursor)


app = QApplication(sys.argv)
dialog = EventFilter()
dialog.show()
app.exec_()


