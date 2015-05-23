## Introduction

A simple Kernel Module to check whether the given triangle is a right angle triangle or not.

### Next Step?

- Download both the files and save them in the same folder.
- In the terminal, move to that folder and execute the following commands:
  1. make
  2. insmod right.ko a=(value) b=(value) c=(value)
  3. dmesg | tail -1
  4. rmmod right.ko

