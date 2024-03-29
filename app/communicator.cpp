#include "communicator.h"

bool communicator(int option, int pid){
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

    return result;
}