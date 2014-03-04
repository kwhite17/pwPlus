
# turns a password into a number
def pwHelper(pw):
    pwLen = len(pw)
    newPW = 0
    for val in range(pwLen):
        newPW += (-1)**(val + 2) * ord(pw[val]) * 10 ** (pwLen-val-1)
    return (pw,newPW)

"""The improved password function takes in four parameters:
    pw: the password
    numConv: the number of characters to convert to integers
    atEnd: should these characters be converted at the start or end of the string
    reverse: should we reverse the position of the converted characters with
             the unconverted characters
"""

def improvedPW(pw,numConv,atEnd,reverse):
    if numConv == 0:
        return (pw,pwHelper(pw)[1])
    else:
        if atEnd:
            letters = pw[:len(pw)-numConv]
            numbers = pwHelper(pw[len(pw)-numConv:])[1]
            if not reverse:
                return (pw,letters + str(numbers))
            else:
                return (pw,str(numbers) + letters)
        else:
            letters = pw[numConv:]
            numbers = pwHelper(pw[0:numConv])[1]
            if not reverse:
                return (pw,str(numbers) + letters)
            else:
                return (pw,letters + str(numbers))
