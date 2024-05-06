#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

int pid_to_print = -1; // Global variable to store the PID to print

void print_process_info(struct task_struct* task) {
    if (task != NULL) {
        printk(KERN_INFO "Process: %s (PID: %d, State: %ld)\n", task->comm, task->pid, task->state);
        print_process_info(task->parent);
    }
}

int init_module(void) {
    struct task_struct* task;

    printk(KERN_INFO "=== Print Other Module ===\n");

    // Check if a PID is specified
    if (pid_to_print == -1) {
        printk(KERN_INFO "No PID specified.\n");
        return -1;
    }

    // Look up the task_struct for the specified PID
    task = pid_task(find_vpid(pid_to_print), PIDTYPE_PID);

    if (task == NULL) {
        printk(KERN_INFO "Process with PID %d not found.\n", pid_to_print);
        return -1;
    }

    printk(KERN_INFO "Printing process information for PID: %d\n", pid_to_print);
    print_process_info(task);

    return 0;
}

void cleanup_module(void) {
    printk(KERN_INFO "Print Other Module removed.\n");
}

// Module parameter for specifying the PID
module_param(pid_to_print, int, 0);

MODULE_LICENSE("GPL");
