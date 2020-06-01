#!/bin/bash/python

import subprocess

for i in range(1,255):
    address = "10.11.0." + str(i)
    subprocess.cal(['ping', '-c', '1', address])
