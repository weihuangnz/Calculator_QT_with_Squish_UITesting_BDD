# -*- coding: utf-8 -*-
# Author: Wei Huang
# Date:   30/09/2017

def inputSign(sign):
    if (sign == '.') : 
        clickButton(waitForObject(":MainWindow.btnDecimalPoint_QPushButton"))
        return
    if (sign == '-') : 
        clickButton(waitForObject(":MainWindow.btnNegativity_QPushButton"))
        return
    if (sign == '=') :
        clickButton(waitForObject(":MainWindow.btnEvaluation_QPushButton"))
        return
    btnNum = ":MainWindow.btnNum" + sign + "_QPushButton"
    clickButton(waitForObject(btnNum))

def inputOperation(sign):
    if (sign == '+') : 
        clickButton(waitForObject(":MainWindow.btnAddition_QPushButton"))
        return
    if (sign == '-') : 
        clickButton(waitForObject(":MainWindow.btnSubtraction_QPushButton"))
        return
    if (sign == '*') : 
        clickButton(waitForObject(":MainWindow.btnMultiplication_QPushButton"))
        return
    if (sign == '/') : 
        clickButton(waitForObject(":MainWindow.btnDivision_QPushButton"))
        return

def inputNumber(value):
    var = value
    nag = False
    if (var[0] == '-') : 
        nag = True
        var = var[1:len(var)]
    for char in var:
        inputSign(char)
    if (nag == True) : inputSign('-')
    verifyResult(value)  

def verifyResult(value):
    test.compare(str(waitForObjectExists(":MainWindow.label_QLabel").text), value)

def clearInput():
    clickButton(waitForObject(":MainWindow.btnClear_QPushButton"))