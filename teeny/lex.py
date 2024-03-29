import enum

class Lexer:
    def __init__(self,source):
        self.source= source+ '\n'
        self.curChar=''
        self.curPos=-1
        self.nextChar()

    def nextChar(self):
        self.curPos += 1
        if self.curPos >= len(self.source):
            slef.curChar='\0'
        else:
            self.curChar=self.source[self.curPos]

    def peek(self):
        if self.curPos +1 >= len(self.source):
            return '\0'
        return self.source[self.curPos+1]

    def abort(self,message):
        pass

    def skipWhitespace(self):
        pass

    def skipComment(self):
        pass

    def getToken(self):

        token = None


        if self.curChar == '+':
            token = Token(self.curChar, TokenType.PLUS)
        elif self.curChar == '-':
            token = Token(self.curChar, TokenType.MINUS)
        elif self.curChar == '*':
            token = Token(self.curChar, TokenType.ASTERISK)
        elif self.curChar == '/':
            token = Token(self.curChar, TokenType.SLASH)
        elif self.curChar == '\n':
            token = Token(self.curChar, TokenType.NEWLINE)
        elif self.curChar == '\0':
            token = Token(self.curChar, TokenType.EOF)
        else:
            pass

        self.nextChar()


class Token:
    def __init__(self,tokenText, tokenKind):
        self.text=tokenText
        self.kind=tokenKind



class TokenType(enum.Enum):
	EOF = -1
	NEWLINE = 0
	NUMBER = 1
	IDENT = 2
	STRING = 3
	# Keywords.
	LABEL = 101
	GOTO = 102
	PRINT = 103
	INPUT = 104
	LET = 105
	IF = 106
	THEN = 107
	ENDIF = 108
	WHILE = 109
	REPEAT = 110
	ENDWHILE = 111
	# Operators.
	EQ = 201  
	PLUS = 202
	MINUS = 203
	ASTERISK = 204
	SLASH = 205
	EQEQ = 206
	NOTEQ = 207
	LT = 208
	LTEQ = 209
	GT = 210
	GTEQ = 211


