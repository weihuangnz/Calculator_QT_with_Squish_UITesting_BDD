# -*- coding: utf-8 -*-
source(findFile("scripts", "globalScript.py"))

@Given("the Calculator is running")
def step(context):
    startApplication("Calculator")

@When("I input number 100")
def step(context):
    inputNumber("100")

@When("I input sign addition")
def step(context):
    inputOperation('+')

@When("I input number 200")
def step(context):
    inputNumber("200")

@When("I input sign equal")
def step(context):
    inputSign('=')

@Then("the results should be 300")
def step(context):
    verifyResult("300")
    clearInput()
