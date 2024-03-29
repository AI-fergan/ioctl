#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/ioctl.h>

#define DEVICE_FILE "/dev/controller"
#define CONTROLLER_IOC_MAGIC 'k'
#define CONTROLLER_IOC_SEND _IOWR(CONTROLLER_IOC_MAGIC, 1, int[2])
#define CONTROLLER_IOC_RECV _IOWR(CONTROLLER_IOC_MAGIC, 1, bool)

void communicator(int option, int pid);

int main(void){
    communicator(0, 2235);
    return 0;
}

void communicator(int option, int pid){
    int fd = open(DEVICE_FILE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
    }

	int args[2] = {option, pid};
	int result = 0;
	//send the action and pid
	ioctl(fd, CONTROLLER_IOC_SEND, args);
	//get the result from the driver(success - 1, fail - 0);
	ioctl(fd, CONTROLLER_IOC_RECV, &result);
    close(fd);
}