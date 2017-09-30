# -*- coding: utf-8 -*-
# Author: Wei Huang
# Date:   30/09/2017
# Demo Data Driven Testing

source(findFile("scripts", "globalScript.py"))

def main():
    startApplication("Calculator")
    for record in testData.dataset("data_1.tsv"):
        _1st = testData.field(record, "1st")
        operation = testData.field(record, "operation")
        _2nd = testData.field(record, "2nd")
        equals = testData.field(record, "equals")
        expectation = testData.field(record, "expectation")
    
        inputNumber(_1st)
        inputOperation(operation)
        inputNumber(_2nd)
        inputSign(equals)
        verifyResult(expectation)
        clearInput()

