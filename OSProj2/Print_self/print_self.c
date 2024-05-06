#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

void print_process_info(struct task_struct* task) {
    if (task != NULL) {
        printk(KERN_INFO "Process: %s (PID: %d, State: %ld)\n", task->comm, task->pid, task->state);
        print_process_info(task->parent);
    }
}

int init_module(void) {
    printk(KERN_INFO "=== Print Self Module ===\n");
    printk(KERN_INFO "Printing current process and its parent processes:\n");
    print_process_info(current);
    return 0;
}

void cleanup_module(void) {
    printk(KERN_INFO "Print Self Module removed.\n");
}

MODULE_LICENSE("GPL");
