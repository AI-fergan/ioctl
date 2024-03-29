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

using std::cout;
using std::cin;
using std::endl;