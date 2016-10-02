#!/usr/bin/python
"""
totalhosts -> no. of hosts which will send the data
To make sure that congestion builds up at the router, 
we may also change the initial congestion windows size.
For graphs, we have used GNUPLOT.
TCP congestion control algorithm -> cubic
"""

import time
from mininet.topo import Topo
from mininet.topolib import TreeTopo
from mininet.net import Mininet
from mininet.node import CPULimitedHost
from mininet.link import TCLink
from mininet.util import custom, quietRun, dumpNetConnections
from mininet.log import setLogLevel, lg
from mininet.node import UserSwitch, OVSKernelSwitch
from multiprocessing import Process
from subprocess import Popen
from time import sleep
import argparse
import sys
import os

flush = sys.stdout.flush

#Makes required Topology
class SwitchHubTopo(Topo):
	def build (self,n):
		receiver = self.addHost('h_rec')
		temp = receiver
		for h in range(n):
			host = self.addHost('h%s' %(h+1))
			switch = self.addSwitch('s%s' %(h+1))
			self.addLink(host, switch, bw=10, delay='10ms')
			self.addLink(temp, switch, bw=10, delay='10ms')
			temp = switch

#starts TCP_Probe
def start_tcpprobe():
	os.system("rmmod tcp_probe 1>/dev/null 2>&1; modprobe tcp_probe")
	Popen("cat /proc/net/tcpprobe > tcp_probe.data", shell=True)

#stops TCP_Probe
def stop_tcpprobe():
	os.system("killall -9 cat; rmmod tcp_probe")

#waits while server (the receiver) starts to listen the hosts
def waitListening(server, port):
	"Wait until server is listening on port"
	print 'waiting for', server.IP(),'to listen on port', port
	sleep(1)

#main program
def simpleTest():
	totalhosts = int(raw_input("Number of hosts: ").split()[0])						#total number of hosts
	topo = SwitchHubTopo(n=totalhosts)
	net = Mininet(topo=topo, link=TCLink)
	net.start()
	ttt = raw_input("Topology created,proceed? ")
	IPERFPATH = 'iperf'
	start_tcpprobe()
	ttt = raw_input("tcp_probe strted,proceed?")
	
	PORT = 5555

	print "Network connections:"
	dumpNetConnections(net)

	print "Testing connectivity:"
	net.pingAll()
	dst = net.hosts[totalhosts]
	dst.sendCmd( IPERFPATH + ' -s -p ' + str(PORT) + ' > receiver.data', printPid=True)
	print dst.name,
	print 'is host number',totalhosts,'and it is listening'
	waitListening(dst, PORT)
	for i in range(totalhosts):
		print net.hosts[i].IP()+ " <-> " +dst.IP()
		net.hosts[i].sendCmd( IPERFPATH + ' -c '+dst.IP()+' -p '+str(PORT)+' -i 1 -t 300 -Z cubic > host'+str(i+1)+'.data', printPid=True)
	for i in range(totalhosts):
		net.hosts[i].waitOutput(verbose=True)
		print 'sending traffic completed at ',i
	sleep(60)
	net.hosts[totalhosts].stop()
	#net.hosts[2].waitOutput(verbose=True)
	#while 3 > 2:
	#	if dst.waiting:
	#		print 'not done'
	#	else:
	#		break
	#sleep(2)
	#dst.cmd('killall')
	#dst.sendCmd('sudo kill %'+IPERFPATH)
	stop_tcpprobe()
	net.stop()
	del net
	del topo

#initiate
setLogLevel('info')
simpleTest()

"""
awk code:

{sum += $4} 
(NR ==1) {time = $1; next}
(NR%75==0) {print NR/75, sum/($1-time); sum=0; time=$1}


gnuplot code:

set style data linespoints
show timestamp
set term png size 800,600
set output "datarate_final.png"
set xlabel "time (seconds)"
set ylabel "datarate (Bytes/sec)"
filenames = "1 2 3 4 5 6 7 8"
plot for [file in filenames] "data".file."_bw" using 1:2 smooth csplines title "datarate".file

"""