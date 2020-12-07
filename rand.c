#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/random.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>

static ssize_t dev_read(struct file *f, char __user *buf, size_t len, loff_t *off) {
  int rnd_val;

  get_random_bytes(&rnd_val, 4);
  if (copy_to_user(buf, &rnd_val, 4))
    return -EFAULT;
  *off += 4;
  return 4;
}

static ssize_t dev_write(struct file *f, const char __user *buf, size_t len, loff_t *off) {
  return len;
}

static struct file_operations rand_fops = {
  .owner = THIS_MODULE,
  .read = dev_read,
  .write = dev_write
};

struct miscdevice rand_device = {
  .minor = MISC_DYNAMIC_MINOR,
  .name = "rand",
  .fops = &rand_fops,
  .mode = S_IRWXUGO,
};

static int __init rand_init(void)
{
  int error;

  error = misc_register(&rand_device);
  if (error) {
    pr_err("Can't misc_register\n");
    return error;
  }
  return 0;
}

static void __exit rand_exit(void)
{
  misc_deregister(&rand_device);
}

module_init(rand_init);
module_exit(rand_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Random Number Generator");
