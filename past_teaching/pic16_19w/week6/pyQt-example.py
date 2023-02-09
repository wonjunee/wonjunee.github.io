"""

Give hint about offset

"""

from PyQt5.QtWidgets import QApplication, QWidget, QColorDialog
from PyQt5.QtGui import QPainter, QColor 
from PyQt5.QtCore import QTimer

class ClickDrag(QWidget):
    
    def __init__(self):
        super(ClickDrag,self).__init__()
        self.initUI()
        
        
    def initUI(self):
        
        self.a = 0
        self.x = 0
        self.y = 0
        self.l = 50

        self.mouseX = 0
        self.mouseY = 0

        self.offsetX = 0
        self.offsetY = 0
        
        self.setGeometry(300, 300, 601, 400)
        self.setWindowTitle("Click Drag")
        
        self.clicked = False
        
        self.show()

        self.t = QTimer(self)
        self.t.timeout.connect(self.update)
        self.t.start(5)
        
    def paintEvent(self,e):
        qp = QPainter()
        qp.begin(self)
        self.drawRectangles(qp)
        qp.end()

    def drawRectangles(self, qp):
        qp.setPen(QColor(0, 0, 0, 255))
        qp.setBrush(QColor(255, 255, 255))
        qp.drawRect(0, 0, self.width(), self.height())
        
        qp.setBrush(QColor(200, 0, 0))

        self.x = self.mouseX - self.l/2
        self.y = self.mouseY - self.l/2
        qp.drawRect(self.x, self.y, self.l, self.l)

            
    def mousePressEvent(self,e):
        self.clicked = self.inSquare(e)
        if self.clicked:
            self.mouseX = e.x()
            self.mouseY = e.y()
            print "Clicked"
        
    def mouseMoveEvent(self,e):
        print e.x(), e.y()
        if self.clicked:
            self.mouseX = e.x()
            self.mouseY = e.y()
    
    def mouseReleaseEvent(self,e):
        self.clicked = False
        self.a = 0
        
    def inSquare(self,e):
        return self.x <= e.x() <= self.x+self.l and self.y <= e.y() <= self.y+self.l

         
def main():
    app = QApplication([])
    cd = ClickDrag()
    app.exec_()    
    
if __name__ == "__main__":
    main()