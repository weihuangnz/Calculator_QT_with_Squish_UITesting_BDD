source(findFile("scripts", "globalScript.py"))

def main():
    startApplication("Calculator")
    inputNumber("123.456789")
    inputOperation('*')
    inputNumber("-0.369")
    inputSign('=')
    verifyResult("-45.5556")
    clearInput()
