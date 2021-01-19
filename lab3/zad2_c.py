import time
import signal
import sys
import os

def reciveSignalUsr1(signalNumber, frame):
    i = 0
    while i<1000:
        i = i + 1
    print(f'Recived: {signalNumber}')
    return

    
def reciveSignalUsr2(signalNumber, frame):
    i = 0
    while i<1000:
        i = i + 1
    print(f'Recived: {signalNumber}')
    return

def terminateProcess(signalNumber, frame):
    i = 0
    while i<1000:
        i = i + 1
    print(f'Recived: {signalNumber}')
    return


def reciveSignal(signalNumber, frame):
    i = 0
    while i<1000:
        i = i + 1
    print("Recived:", signalNumber)
    return



if __name__ == '__main__':
    print("PID: "+ str(os.getpid()))
    signal.signal(signal.SIGALRM, reciveSignal)
    signal.signal(signal.SIGTERM, terminateProcess)
    signal.signal(signal.SIGUSR1, reciveSignalUsr1)
    signal.signal(signal.SIGUSR2, reciveSignalUsr2)

    i = 0

    while True:
        i = i + 1
        time.sleep(1)
