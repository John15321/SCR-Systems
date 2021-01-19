import time
import signal
import sys
import os

def reciveSignalUsr1(signalNumber, frame):
    pass

def reciveSignalUsr2(signalNumber, frame):
    pass

def terminateProcess(signalNumber, frame):
    pass

def reciveSignal(signalNumber, frame):
    pass



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
