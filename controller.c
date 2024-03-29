#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/syscalls.h>

#define MODULE_NAME "controller"

/* Driver Description. */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("controller");
MODULE_DESCRIPTION("helper module for proccesses controling");

static int __init init_controller(void){
    printk(KERN_INFO "%s: %s module is lodaing...", MODULE_NAME, MODULE_NAME);

    printk(KERN_INFO "%s: %s module is successfully loaded!\n", MODULE_NAME, MODULE_NAME);
    return 0;
}

static void __exit cleanup_controller(void){
    printk(KERN_INFO "%s: %s module successfully unloaded.\n", MODULE_NAME, MODULE_NAME);
}

module_init(init_controller);
module_exit(cleanup_controller);
