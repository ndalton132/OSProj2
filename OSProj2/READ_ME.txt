Kernel Modules and Processes Project
MEMBERS:
* Ivan Sarmiento
* Nicholas Dalton
STATEMENT:
==========
We have neither given nor received unauthorized assistance on this work.
==========
VIRTUAL MACHINE (VM) INFORMATION:
NAME OF VIRTUAL MACHINE (VM): Dues_Ex_Machina USENAME: ivans 
PASSWORD: 1qazxsw2!QAZXSW@
==========
ROOT PASSWORD:
1qazxsw2!QAZXSW@
=========
PART 0.1: Preparation
To prepare for this project, ensure that you boot the newest version of the kernel by selecting it at boot time. Additionally, install the Linux headers for your kernel version by running the following command as root:
# yum install -y kernel-devel kernel-headers 
Please note that due to historic reasons, specific versions of headers may not be available in the repositories. However, you should use the headers for the new kernel version every time when working on kernel modules.
PART 1: Create a helloworld kernel module
Code:
The provided code is a complete helloworld kernel module, which prints "Hello world!" when loaded and "Goodbye world!" when removed.
Compilation:
Use the provided Makefile to compile the module. Run the following commands with root permission:
make 
Loading and Unloading:
* To load the module into the kernel, run (make sure to be in root):
# insmod hello.ko 
* To remove the module from the kernel, run:
# rmmod hello 
Output:
View the module's output using the following command:
bashCopy code
# dmesg -T | tail 
PART 2: Create a print self kernel module
This module identifies the current process and prints various information about it, including its name, id, and state. It also prints information about its parent processes until reaching the init process.
Steps to Load and Remove Module:
* Compile the module using the provided Makefile.
Run command: make
* Load the module into the kernel using insmod.
(If not in root) use command: sudo insmod print_self.ko
Password: 1qazxsw2!QAZXSW@
* View the module's output with dmesg -T | tail.
* Remove the module from the kernel using rmmod.
Questions:
1. The current macro returns a pointer to the task struct of the current running process.
2. In newer kernels, the equivalent of the init process is called systemd.
3. The module's output will include various process states, such as TASK_RUNNING.
PART 3: Create a print other kernel module
This module prints information about an arbitrary process specified by its PID. It outputs the same information as the print self module for the specified process and its parent processes until reaching the init process.
Steps to Load and Remove Module:
* Compile the module using the provided Makefile.
Command: make
* Load the module into the kernel using insmod.
(you can use either way from part 1 or 2: sudo insmod print_other.ko
Password: 1qazxsw2!QAZXSW@
* Provide the PID of the target process as an argument.
* View the module's output with dmesg -T | tail.
* Remove the module from the kernel using rmmod.
PART 4: Kernel Modules and System Calls
Explanation:
A kernel module is a piece of code that can be dynamically loaded and unloaded into the Linux kernel to extend its functionality or add new features. It runs in kernel space, allowing direct interaction with system resources and hardware.
In contrast, a system call is a mechanism used by user-space programs to request services from the kernel. System calls provide an interface for user programs to interact with the kernel and perform privileged operations, such as file I/O, process management, and network communication.
Article Example:
The article may still be relevant, but it's essential to consider potential changes and updates in the Linux kernel over the past 20 years. The example from the article may or may not work in a modern VM environment due to changes in kernel APIs, system configurations, and security mechanisms. Testing the example in a VM allows us to evaluate its compatibility and effectiveness in current Linux environments.

