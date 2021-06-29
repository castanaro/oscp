#!/bin/python3

import sys
import socket
from datetime import datetime
import time

#Define our target
if len(sys.argv) == 2:
        target = socket.gethostbyname(sys.argv[1]) #Translate hostname to IPv4
else:
        print("You need 2 arguments for this script ex.: python3 scanner.py <ip>")


#add a banner

print("-" * 50)
print("Scanning target "+target)
timestart = time.time()
print("Time started: " + str(datetime.now()))
print("-" * 50)

try:
        for port in range(50,55):
                s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                socket.setdefaulttimeout(1)
                result = s.connect_ex((target,port)) #returns an error indicator
                if result == 0:
                        print("port {} is open".format(port))
                else:
                        print("port {} is closed".format(port))
        s.close()

except KeyboardInterrupt:
        print("\nExiting program.")
        sys.exit()

except socket.gaierror:
        print("Hostname could not be resolved.")
        sys.exit()

except socket.error:
        print("Couldn't connect to server.")
        sys.exit()


print("*" * 50)
timeend = time.time()
print("Time ended: " + str(datetime.now()))
print("Total Time: " + str(float(timeend - timestart)) + " seconds.")
print("*" * 50)
