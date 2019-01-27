class MainClass:
    x = 128

    def setX(self, x):
        self.x = x

    def getX(self):
        return self.x

obj = MainClass()
print(obj.getX())
obj.setX(256)
print(obj.getX())

