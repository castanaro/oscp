#!/bin/python3


'''
Thanks to TCM's Heath Adams for his Practical Ethical Hacking Course.
TCM's PNPT course can be found here: https://certifications.tcm-sec.com/product/practical-network-penetration-tester-with-training/
'''

import sys
import socket
from datetime import datetime
import time

#Define our target
if len(sys.argv) == 4:
        target = socket.gethostbyname(sys.argv[1]) #Translate hostname to IPv4
        port1 = sys.argv[2]
        port2 = sys.argv[3]
else:
        print("You need arguments for this script ex.: python3 scanner.py <ip> <port 1> <port 2> to create port range")

port1 = int(port1) #cast string to int for the for loop later on
port2 = int(port2) #same thing here

#add a banner

print("-" * 50)
print("Scanning target "+target)
timestart = time.time()
print("Time started: " + str(datetime.now()))
print("-" * 50)

try:
        for port in range(port1,port2):
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


print("-" * 50)
timeend = time.time()
print("Time ended: " + str(datetime.now()))
print("Total Time: " + str(float(timeend - timestart)) + " seconds.")
print("-" * 50)
