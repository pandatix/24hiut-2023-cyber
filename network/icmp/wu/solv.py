from scapy.all import *

pcap_flow = rdpcap('icmp.pcap')

solv = list()
for packet in pcap_flow:
    
    if 'ICMP' in packet and packet.ttl <= 20: 
        payload = packet[ICMP].payload
        solv.append(payload.load.decode("utf-8"))


print("Base64 : ", end = '')
print(''.join(solv))
