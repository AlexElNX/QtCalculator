#include <QString>
#include <QObject>

class Calculator : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString display READ display NOTIFY displayChanged)
private:
    QString currentValue_;
    double firstValue_;
    QString operation_;

public:
    explicit Calculator(QObject *parent = nullptr);

    QString display() const;

    Q_INVOKABLE void addDigit(const QString &number);
    Q_INVOKABLE void setOperation(const QString &operation);
    Q_INVOKABLE void toggleSign();
    Q_INVOKABLE void calculate();
    Q_INVOKABLE void percentage();
    Q_INVOKABLE void reciprocal();
    Q_INVOKABLE void square();
    Q_INVOKABLE void squareRoot();
    Q_INVOKABLE void clearAll();
    Q_INVOKABLE void clearEntry();
    Q_INVOKABLE void backspace();

signals:
    void displayChanged();
};
