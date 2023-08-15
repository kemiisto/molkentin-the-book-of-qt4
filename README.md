# The Book of Qt 4

Code samples from [The Book of Qt 4](http://web.archive.org/web/20161113144125/https://www.nostarch.com/qt4.htm) ported to Qt 5/6.

Changes from Qt 4:
- Qt now offers [two ways to write signal-slot connections](https://doc.qt.io/qt-6/signalsandslots-syntaxes.html): the string-based syntax and the functor-based one.
- Most of the things from `<QtGui>` header are now in `<QtWidgets>` header.
- `QRegExp` was deprecated in Qt 5 and replaced in Qt 6 by a Perl compatible `QRegularExpression`.
- Similarly, `QRegExpValidator` was replaced by `QRegularExpressionValidator`.
