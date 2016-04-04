from mininet.topo import Topo
from mininet.net import Mininet
from mininet.util import dumpNodeConnections
from mininet.log import setLogLevel
from collections import deque



class SingleSwitchTopo(Topo):
	"Single switch connected to n hosts."
	def build(self,m=6,n=2):
		children = dict()
		Nodetype = dict()

		Q = deque()
		Q.append(1)
		alloted = 1
		
		#mark the nodes as switch or host
		while len(Q) > 0:
			cur = Q.popleft()
			if alloted < m:
				Nodetype[cur] = "switch"
				curchildren = []
				for x in xrange(0,n):
					if alloted < m:
						curchildren.append(alloted+1)
						Q.append(alloted+1)
						alloted += 1
				children[cur] = curchildren
			else:
				curchildren = []
				Nodetype[cur] = "host"
				children[cur] = curchildren

		#create nodes
		CoresspNode = dict()
		Hosts = 0
		Switches = 0
		for x in xrange(1,m+1):
			if Nodetype[x] == "switch":
				tmp = self.addSwitch('s%s' %(Switches+1))
				Switches += 1
				CoresspNode[x] = tmp
			else:
				tmp = self.addHost('h%s' %(Hosts+1))
				Hosts += 1
				CoresspNode[x] = tmp

		#create links
		for x in xrange(1,m+1):
			for y in children[x]:
				self.addLink(CoresspNode[x],CoresspNode[y])


def simpleTest():
	"Create and test a simple network"
	nary = int(raw_input("enter the value of n(ary): ").split()[0])
	m = int(raw_input("enter the value of m: ").split()[0])
	topo = SingleSwitchTopo(m,nary)
	net = Mininet(topo)
	net.start()
	print "Dumping host connections"
	dumpNodeConnections(net.hosts)
	print "Testing network connectivity"
	net.pingAll()
	net.stop()

if __name__ == '__main__':
	# Tell mininet to print useful information
	setLogLevel('info')
	simpleTest()