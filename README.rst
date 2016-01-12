Steps in setting up kernel
==========================

#. Download ``mini.iso`` x86_64 for Ubuntu 14.04

#. Install `Virtualbox` ::

	sudo apt-get install Virtualbox
	
#. Create a virtual disk with sensible size(anyway its dynamic), install 
   Ubuntu minimal netinstall version in Virtualbox(search online if you fail)

#. Set up a static IP in /etc/network/interfaces (if you're accessing it over
   network)

#. Install few more packages inside VM ::

	sudo apt-get install vim libncurses5-dev gcc make git exuberant-ctags bc libssl-dev

#. You may use following command to start VM next time ::

	VBoxManage startvm <your-VM-name> --type headless

#. Browse ``docs`` directory for step by step instructions.

Resources
---------

#. http://www.cse.iitb.ac.in/~puru/courses/spring16/index.html (main page)

#. http://arjunsreedharan.org/post/82710718100/kernel-101-lets-write-a-kernel (kernel examples)

#. http://www.brokenthorn.com/Resources/OSDevIndex.html
