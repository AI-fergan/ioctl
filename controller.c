#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/kallsyms.h>
#include <linux/syscalls.h>
#include <linux/slab.h>

#define MODULE_NAME "controller"

/* Device variables */
static int major_number;
static struct cdev controller_cdev;
static const struct file_operations controller_fops;


/* Driver Description. */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("controller");
MODULE_DESCRIPTION("helper module for proccesses controling");

static bool sendSignalToTask(int target_pid, int sig);
static long controller_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

static int __init init_controller(void){
    printk(KERN_INFO "%s: %s module is lodaing...", MODULE_NAME, MODULE_NAME);

    // Register character device.
    major_number = register_chrdev(0, MODULE_NAME, &controller_fops);
    if (major_number < 0) {
        printk(KERN_ERR "%s: error | log: Failed to register a major number\n", MODULE_NAME);
        return major_number;
    }
    printk(KERN_INFO "%s: msg | log: Major number allocated: %d\n", MODULE_NAME, major_number);

    // Initialize cdev.
    cdev_init(&controller_cdev, &controller_fops);

    // Add cdev to the system.
    if (cdev_add(&controller_cdev, MKDEV(major_number, 0), 1) < 0) {
        printk(KERN_ERR "%s: error | log: Failed to add cdev\n", MODULE_NAME);
        unregister_chrdev(major_number, MODULE_NAME);
        return -1;
    }

    printk(KERN_INFO "%s: %s module is successfully loaded!\n", MODULE_NAME, MODULE_NAME);
    return 0;
}

static void __exit cleanup_controller(void){
    printk(KERN_INFO "%s: %s module successfully unloaded.\n", MODULE_NAME, MODULE_NAME);
}

static long controller_ioctl(struct file *file, unsigned int cmd, unsigned long arg){
    return 0;
}

/* 
This function process the signal sending.
input:
target_pid - the pid of the target process.
sig - the signal that we want to send to the process.
output: if the signale send successfully.
*/
static bool sendSignalToTask(int target_pid, int sig) {
    struct task_struct *target_task;

    // get the process task to kill
    target_task = pid_task(find_vpid(+target_pid), PIDTYPE_PID);
    
    // check if the task exists
    if (target_task) {
        // send the signal to the process
        send_sig(sig, target_task, 0);
        return true;  // Success
    } else {
        return false;  // Failure
    }
}

// File operations structure
static const struct file_operations controller_fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = controller_ioctl,
    // Include other necessary file operations
};

module_init(init_controller);
module_exit(cleanup_controller);
