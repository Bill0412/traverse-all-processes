#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/fcntl.h>

int init_module(void)
{
    int count = 0;
    struct task_struct *task;
    int count_each[15] = {0};
    int i;

    char states[] = "RSDTtXZPI";

    for_each_process(task)
    {
        count++;
        count_each[task_state_index(task)]++;
        printk("%s [%d] %c %s\n",task->comm , task->pid, task_state_to_char(task), task->parent->comm);
    }

    printk("Total # of proceses: %d", count);
    // printk("RSD\tT\tt\tX\tZ\tP\tI\n");

    for(i = 0; i < 9; i++)
    {
        printk("%c: %d", states[i], count_each[i]);
    }

    return 0;
}

void cleanup_module(void)
{
    printk(KERN_INFO "Cleaning Up.\n");
}

MODULE_LICENSE("GPL");
// module_init(init_module);
// module_exit(cleanup_module);
