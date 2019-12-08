#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/fcntl.h>
#include <asm/uaccess.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/uaccess.h>
#include <linux/buffer_head.h>

static void write_file(char *filename, char *data, loff_t* pos)
{
  struct file *file = NULL;
  // loff_t pos = 0;
  //int fd;

  mm_segment_t old_fs = get_fs();
  set_fs(get_ds());

  file = filp_open(filename, O_WRONLY | O_CREAT | O_SYNC | O_APPEND, 0777);
  // set_fs(old_fs);

    if (file) {
        vfs_write(file, data, strlen(data), pos);
        //fput(file);
    }
    filp_close(file, NULL);

  set_fs(old_fs);
}



int init_module(void)
{
    int count = 0;
    struct task_struct *task;
    int count_each[15] = {0};
    int i;
    char states[] = "RSDTtXZPI";

    char data[128];

    char filename[] = "/home/fenghe/Desktop/traverse-all-processes/traverse_res.txt";

    loff_t pos = 0;

    for_each_process(task)
    {
        count++;
        count_each[task_state_index(task)]++;
        sprintf(data, "%s [%d] %c %s\n",task->comm , task->pid, task_state_to_char(task), task->parent->comm);
        write_file(filename, data, &pos);
    }

    sprintf(data, "Total # of proceses: %d", count);
    write_file(filename, data, &pos);
    // printk("R\tS\tD\tT\tt\tX\tZ\tP\tI\n");

    for(i = 0; i < 9; i++)
    {
        sprintf(data, "%c: %d\n", states[i], count_each[i]);
        write_file(filename, data, &pos);
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