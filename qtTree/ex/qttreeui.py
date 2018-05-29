# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'D:\wei\weiProgramme\projects\graduation\qtTree\qttree.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)


class Ui_qttree(QtGui.QMainWindow):
    def __init__(self):
        super(Ui_qttree, self).__init__()
        self.setupUi(self)
        self.retranslateUi(self)

    def setupUi(self, qttree):
        qttree.setObjectName(_fromUtf8("qttree"))
        qttree.resize(800, 600)
        self.centralwidget = QtGui.QWidget(qttree)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.horizontalLayoutWidget_5 = QtGui.QWidget(self.centralwidget)
        self.horizontalLayoutWidget_5.setGeometry(QtCore.QRect(9, 7, 781, 561))

        self.horizontalLayoutWidget_5.setObjectName(_fromUtf8("horizontalLayoutWidget_5"))

        self.horizontalLayout_6 = QtGui.QHBoxLayout(self.horizontalLayoutWidget_5)
        self.horizontalLayout_6.setSizeConstraint(QtGui.QLayout.SetMinimumSize)
        self.horizontalLayout_6.setObjectName(_fromUtf8("horizontalLayout_6"))
        self.verticalLayout_3 = QtGui.QVBoxLayout()
        self.verticalLayout_3.setObjectName(_fromUtf8("verticalLayout_3"))
        self.label_13 = QtGui.QLabel(self.horizontalLayoutWidget_5)
        self.label_13.setAlignment(QtCore.Qt.AlignLeading|QtCore.Qt.AlignLeft|QtCore.Qt.AlignTop)
        self.label_13.setObjectName(_fromUtf8("label_13"))
        self.verticalLayout_3.addWidget(self.label_13)
        self.tableWidget_3 = QtGui.QTableWidget(self.horizontalLayoutWidget_5)
        self.tableWidget_3.setObjectName(_fromUtf8("tableWidget_3"))
        self.tableWidget_3.setColumnCount(0)
        self.tableWidget_3.setRowCount(0)
        self.verticalLayout_3.addWidget(self.tableWidget_3)
        self.label_14 = QtGui.QLabel(self.horizontalLayoutWidget_5)
        self.label_14.setObjectName(_fromUtf8("label_14"))
        self.verticalLayout_3.addWidget(self.label_14)
        self.horizontalLayout_10 = QtGui.QHBoxLayout()
        self.horizontalLayout_10.setObjectName(_fromUtf8("horizontalLayout_10"))
        self.label_15 = QtGui.QLabel(self.horizontalLayoutWidget_5)
        self.label_15.setObjectName(_fromUtf8("label_15"))
        self.horizontalLayout_10.addWidget(self.label_15)
        self.textBrowser_5 = QtGui.QTextBrowser(self.horizontalLayoutWidget_5)
        self.textBrowser_5.setObjectName(_fromUtf8("textBrowser_5"))
        self.horizontalLayout_10.addWidget(self.textBrowser_5)
        self.toolButton_3 = QtGui.QToolButton(self.horizontalLayoutWidget_5)
        self.toolButton_3.setObjectName(_fromUtf8("toolButton_3"))
        self.horizontalLayout_10.addWidget(self.toolButton_3)
        self.verticalLayout_3.addLayout(self.horizontalLayout_10)
        self.horizontalLayout_11 = QtGui.QHBoxLayout()
        self.horizontalLayout_11.setObjectName(_fromUtf8("horizontalLayout_11"))
        self.label_16 = QtGui.QLabel(self.horizontalLayoutWidget_5)
        self.label_16.setObjectName(_fromUtf8("label_16"))
        self.horizontalLayout_11.addWidget(self.label_16)
        self.comboBox_5 = QtGui.QComboBox(self.horizontalLayoutWidget_5)
        self.comboBox_5.setObjectName(_fromUtf8("comboBox_5"))
        self.horizontalLayout_11.addWidget(self.comboBox_5)
        self.verticalLayout_3.addLayout(self.horizontalLayout_11)
        self.horizontalLayout_12 = QtGui.QHBoxLayout()
        self.horizontalLayout_12.setObjectName(_fromUtf8("horizontalLayout_12"))
        self.label_17 = QtGui.QLabel(self.horizontalLayoutWidget_5)
        self.label_17.setObjectName(_fromUtf8("label_17"))
        self.horizontalLayout_12.addWidget(self.label_17)
        self.comboBox_6 = QtGui.QComboBox(self.horizontalLayoutWidget_5)
        self.comboBox_6.setObjectName(_fromUtf8("comboBox_6"))
        self.horizontalLayout_12.addWidget(self.comboBox_6)
        self.verticalLayout_3.addLayout(self.horizontalLayout_12)
        self.horizontalLayout_13 = QtGui.QHBoxLayout()
        self.horizontalLayout_13.setObjectName(_fromUtf8("horizontalLayout_13"))
        spacerItem = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_13.addItem(spacerItem)
        self.pushButton_3 = QtGui.QPushButton(self.horizontalLayoutWidget_5)
        self.pushButton_3.setObjectName(_fromUtf8("pushButton_3"))
        self.horizontalLayout_13.addWidget(self.pushButton_3)
        self.verticalLayout_3.addLayout(self.horizontalLayout_13)
        self.line_3 = QtGui.QFrame(self.horizontalLayoutWidget_5)
        self.line_3.setFrameShape(QtGui.QFrame.VLine)
        self.line_3.setFrameShadow(QtGui.QFrame.Sunken)
        self.line_3.setObjectName(_fromUtf8("line_3"))
        self.verticalLayout_3.addWidget(self.line_3)
        self.label_18 = QtGui.QLabel(self.horizontalLayoutWidget_5)
        self.label_18.setObjectName(_fromUtf8("label_18"))
        self.verticalLayout_3.addWidget(self.label_18)
        self.textBrowser_6 = QtGui.QTextBrowser(self.horizontalLayoutWidget_5)
        self.textBrowser_6.setObjectName(_fromUtf8("textBrowser_6"))
        self.verticalLayout_3.addWidget(self.textBrowser_6)
        self.verticalLayout_3.setStretch(2, 4)
        self.horizontalLayout_6.addLayout(self.verticalLayout_3)
        self.verticalLayout_4 = QtGui.QVBoxLayout()
        self.verticalLayout_4.setObjectName(_fromUtf8("verticalLayout_4"))
        self.graphicsView = QtGui.QGraphicsView(self.horizontalLayoutWidget_5)
        self.graphicsView.setObjectName(_fromUtf8("graphicsView"))
        self.verticalLayout_4.addWidget(self.graphicsView)
        self.horizontalLayout_14 = QtGui.QHBoxLayout()
        self.horizontalLayout_14.setObjectName(_fromUtf8("horizontalLayout_14"))
        self.pushButton_4 = QtGui.QPushButton(self.horizontalLayoutWidget_5)
        self.pushButton_4.setText(_fromUtf8(""))
        self.pushButton_4.setObjectName(_fromUtf8("pushButton_4"))
        self.horizontalLayout_14.addWidget(self.pushButton_4)
        self.commandLinkButton_2 = QtGui.QCommandLinkButton(self.horizontalLayoutWidget_5)
        self.commandLinkButton_2.setText(_fromUtf8(""))
        self.commandLinkButton_2.setObjectName(_fromUtf8("commandLinkButton_2"))
        self.horizontalLayout_14.addWidget(self.commandLinkButton_2)
        self.commandLinkButton = QtGui.QCommandLinkButton(self.horizontalLayoutWidget_5)
        self.commandLinkButton.setText(_fromUtf8(""))
        self.commandLinkButton.setObjectName(_fromUtf8("commandLinkButton"))
        self.horizontalLayout_14.addWidget(self.commandLinkButton)
        self.pushButton_6 = QtGui.QPushButton(self.horizontalLayoutWidget_5)
        self.pushButton_6.setText(_fromUtf8(""))
        self.pushButton_6.setObjectName(_fromUtf8("pushButton_6"))
        self.horizontalLayout_14.addWidget(self.pushButton_6)
        self.pushButton_8 = QtGui.QPushButton(self.horizontalLayoutWidget_5)
        self.pushButton_8.setText(_fromUtf8(""))
        self.pushButton_8.setObjectName(_fromUtf8("pushButton_8"))
        self.horizontalLayout_14.addWidget(self.pushButton_8)
        self.pushButton_7 = QtGui.QPushButton(self.horizontalLayoutWidget_5)
        self.pushButton_7.setText(_fromUtf8(""))
        self.pushButton_7.setObjectName(_fromUtf8("pushButton_7"))
        self.horizontalLayout_14.addWidget(self.pushButton_7)
        self.verticalLayout_4.addLayout(self.horizontalLayout_14)
        self.horizontalLayout_6.addLayout(self.verticalLayout_4)
        qttree.setCentralWidget(self.centralwidget)
        self.statusbar = QtGui.QStatusBar(qttree)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        qttree.setStatusBar(self.statusbar)

        self.retranslateUi(qttree)
        QtCore.QMetaObject.connectSlotsByName(qttree)

    def retranslateUi(self, qttree):
        qttree.setWindowTitle(_translate("qttree", "Tree Health", None))
        self.label_13.setText(_translate("qttree", "树信息", None))
        self.label_14.setText(_translate("qttree", "图片信息", None))
        self.label_15.setText(_translate("qttree", "图片位置", None))
        self.toolButton_3.setText(_translate("qttree", "...", None))
        self.label_16.setText(_translate("qttree", "TextLabel", None))
        self.label_17.setText(_translate("qttree", "诊断内容", None))
        self.pushButton_3.setText(_translate("qttree", "开始诊断", None))
        self.label_18.setText(_translate("qttree", "当前诊断结果", None))

if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    window = Ui_qttree()
    window.show()
    sys.exit(app.exec_())