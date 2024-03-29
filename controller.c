#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched/signal.h>

#define MODULE_NAME "controller"

/* Driver Description. */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("controller");
MODULE_DESCRIPTION("helper module for proccesses controling");

static bool sendSignalToTask(int target_pid, int sig);

static int __init init_controller(void){
    printk(KERN_INFO "%s: %s module is lodaing...", MODULE_NAME, MODULE_NAME);
    sendSignalToTask(24333, SIGKILL);
    printk(KERN_INFO "%s: %s module is successfully loaded!\n", MODULE_NAME, MODULE_NAME);
    return 0;
}

static void __exit cleanup_controller(void){
    printk(KERN_INFO "%s: %s module successfully unloaded.\n", MODULE_NAME, MODULE_NAME);
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

module_init(init_controller);
module_exit(cleanup_controller);
