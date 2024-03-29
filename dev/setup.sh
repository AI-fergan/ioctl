#!/bin/bash
sudo mknod /dev/controller c 510 0
make
sudo insmod controller.ko

rm modules.order
rm .modules.order.cmd

rm controller.mod
rm .controller.mod.cmd

rm controller.o
rm .controller.o.cmd

rm Module.symvers
rm .Module.symvers.cmd

rm controller.mod.c

rm .controller.ko.cmd

rm controller.mod.o
rm .controller.mod.o.cmd
