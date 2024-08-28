#ifndef APPLOGO_H
#define APPLOGO_H

#include <QFrame>
#include <QSvgWidget>
#include <QLabel>

class AppLogo : public QFrame
{
    Q_OBJECT
private:
    QSvgWidget* icon;
    QLabel* logoText;
public:
    explicit AppLogo(QFrame *parent = nullptr);

signals:
};

#endif // APPLOGO_H
