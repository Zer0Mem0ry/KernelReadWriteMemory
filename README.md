# KernelReadWriteMemory
Simple proof of concept -code to manipulate the memory of a usermode process from kernelmode of a windows NT
operating system. This is complished by using the undocumented
NT API "MmCopyVirtualMemory" function in ntoskrnl.exe.

This works for both x64 & x86 processes.
