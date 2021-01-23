import serial
import time
import signal


import threading # bo kho biet dung bo dung; ne bo dung method fast input trong game 

port = '/dev/ttyACM0'
arduino = serial.Serial(port, 9600, timeout = 1)

def processUserValue(controlInput):
    if (controlInput == 's'):
        arduino.write('s')
    elif (controlInput == 'f'):
        arduino.write('f')
    elif (controlInput == 'b'):
        arduino.write('b')

def processSensorValue(text) :
    if ( "P 2 1 #" in text ):
        print("res")
        arduino.write('b')
    if ( "P 0 0 #" in text ):
        arduino.write('s')


valid_chars = "# P L 0 1 2 3 4 5 6 7 8 9 A"
def realMode():
    while(1) :
        time.sleep(1)
        arduino.flush()
        msg = arduino.read(arduino.inWaiting()) 
        text = msg.decode().strip()

        if text != '':
            subString = ""
            
            # text = str(text)
            
            for i in range(0, len(text)): 
                if (text[i] in valid_chars):
                    
                    subString += text[i]
                    if (text[i] == '#'):
                        subString += '\n'
            print(subString)
            processSensorValue(subString)

def testMode() :
    while(1) :
        controlInput = raw_input('f or b or s, e exit: ')
        processUserValue(controlInput)
    
    

def robotMode(userInput) :
    # t test mode control by keyboard
    # r real mode control with sensor
    if (userInput == 't') : 
        testMode()
    elif (userInput == 'r'):
        realMode()
        

if __name__ == '__main__':
    print("This is the master node")
    userInput = raw_input('t or r: ')
    robotMode(userInput)
    


   