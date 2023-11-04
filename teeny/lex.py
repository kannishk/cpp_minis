class Lexer:
    def __init__(self,source):
        self.source='source'+ '\n'
        self.curChar=''
        self.curPos=-1
        self.nextChar()

    def nextChar(self):
        pass

    def peek(self):
        pass

    def abort(self,message):
        pass

    def skipWhitespace(self):
        pass

    def skipComment(self):
        pass

    def getToken(self):
        pass
