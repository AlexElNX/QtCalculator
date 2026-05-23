#include "include/Calculator.h"
#include <QString>
#include <cmath>


Calculator::Calculator(QObject *parent) : QObject(parent)
{
    currentValue_ = "0";
    firstValue_ = 0;
    operation_ = "";
}

void Calculator::addDigit(const QString &number)
{

    if(currentValue_.contains(".") && number == ".")
    {
        return;
    }
    if(currentValue_ == "0" && number == ".")
    {
        currentValue_ += number;
    }
    else if(currentValue_ == "0")
    {
        currentValue_ = number;
    }
    else
    {
        currentValue_ += number;
    }
    emit displayChanged();
}

void Calculator::setOperation(const QString &operation)
{
    this->operation_ = operation;
    firstValue_ = currentValue_.toDouble();
    clearEntry();
}
void Calculator::toggleSign()
{
    double value = currentValue_.toDouble();
    if(value < 0)
    {
        currentValue_.remove(0, 1);
    }
    else if(value > 0)
    {
        currentValue_.prepend("-");
    }
    emit displayChanged();
}

void Calculator::calculate()
{

    if(operation_ == "+")
    {
        currentValue_ = QString::number(firstValue_ + currentValue_.toDouble());
    }
    else if(operation_ == "-")
    {
        currentValue_ = QString::number(firstValue_ - currentValue_.toDouble());
    }
    else if(operation_ == "*")
    {
        currentValue_ = QString::number(firstValue_ * currentValue_.toDouble());
    }
    else if(operation_ == "/")
    {
        if(currentValue_.toDouble() != 0)
        {
            currentValue_ = QString::number(firstValue_ / currentValue_.toDouble());
        }
        else
        {
            currentValue_ = "Cannot divide by zero";
        }
    }
    emit displayChanged();
}

void Calculator::percentage()
{
    if(operation_ == "+" || operation_ == "-")
    {
        currentValue_ = QString::number(firstValue_ * currentValue_.toDouble() / 100);
    }
    else if(operation_ == "*" || operation_ == "/")
    {
        currentValue_ = QString::number(currentValue_.toDouble() / 100);
    }
    emit displayChanged();
}

void Calculator::reciprocal()
{
    if(currentValue_.toDouble() != 0)
    {
        currentValue_ = QString::number(1 / currentValue_.toDouble());
    }
    else
    {
        currentValue_ = "Cannot divide by zero";
    }
    emit displayChanged();
}

void Calculator::square()
{
    currentValue_ = QString::number(currentValue_.toDouble() * currentValue_.toDouble());
    emit displayChanged();
}

void Calculator::squareRoot()
{
    if(currentValue_.toDouble() > 0)
    {
        currentValue_ = QString::number(sqrt(currentValue_.toDouble()));
    }
    else
    {
        currentValue_ = "Invalid input";
    }
    emit displayChanged();
}


void Calculator::clearAll()
{
    currentValue_ = "0";
    firstValue_ = 0;
    operation_ = "";
    emit displayChanged();
}
void Calculator::clearEntry()
{
    currentValue_ = "0";
    emit displayChanged();
}

void Calculator::backspace()
{
    if(currentValue_.size() > 1)
    {
        currentValue_.chop(1);
        emit displayChanged();

    }
    else if(currentValue_.size() == 1 && currentValue_ != "0")
    {
        clearEntry();
    }
}

QString Calculator::display() const
{
    return currentValue_;
}