//Lexer
#include<string>
#include<iostream>

using namespace std;

class Token{
    public:
    enum class Kind{
    Number,
    Identifier,
    LeftParen,
    RightParen,
    LeftSquare,
    RightSquare,
    LeftCurly,
    RightCurly,
    LessThan,
    GreaterThan,
    Equal,
    Plus,
    Minus,
    Asterisk,
    Slash,
    Hash,
    Dot,
    Comma,
    Colon,
    Semicolon,
    SingleQuote,
    DoubleQuote,
    Comment,
    Pipe,
    End,
    Unexpected,
    };

    Token(Kind kind) noexcept : m_kind{kind}{}

    Token(Kind kind, const char *beg, size_t len) noexcept : m_kind{kind}, m_lexeme(beg, len){}

    Token(Kind kind, const char *beg, const char *end) noexcept: m_kind{kind}, m_lexeme(beg, distance(beg,end)){}

    Kind kind() const noexcept { return m_kind; }

    

};
