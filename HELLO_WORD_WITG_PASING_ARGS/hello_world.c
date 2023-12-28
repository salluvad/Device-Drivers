/***************************************************************************//**
*  \file       hello_world.c
*
*  \details    Simple hello world driver with module parms
*
* *******************************************************************************/
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
 
int value, arr_value[4];
char *name;
int cb_value = 0;
 
module_param(value, int, S_IRUSR|S_IWUSR);                      //integer value
module_param(name, charp, S_IRUSR|S_IWUSR);                     //String
module_param_array(arr_value, int, NULL, S_IRUSR|S_IWUSR);      //Array of integers
 
/*----------------------Module_param_cb()--------------------------------*/
int notify_param(const char *val, const struct kernel_param *kp)
{
        int res = param_set_int(val, kp); // Use helper for write variable
        if(res==0) {
                pr_info("Call back function called...\n");
                pr_info("New value of cb_value = %d\n", cb_value);
                return 0;
        }
        return -1;
}
 
const struct kernel_param_ops my_param_ops = 
{
        .set = &notify_param, //   setter 
        .get = &param_get_int, //  this is standard getter
};
 
module_param_cb(cb_value, &my_param_ops, &cb_value, S_IRUGO|S_IWUSR );
/*-------------------------------------------------------------------------*/

/*
** Module init function
*/
static int __init hello_world_init(void)
{
        int i;
        pr_info("Value = %d  \n", value);
        pr_info("cb_value = %d  \n", cb_value);
        pr_info("Name = %s \n", name);
        for (i = 0; i < (sizeof arr_value / sizeof (int)); i++) {
                pr_info("Arr_value[%d] = %d\n", i, arr_value[i]);
        }
        pr_info("Kernel Module Inserted Successfully...\n");
    return 0;
}

/*
** Module Exit function
*/
static void __exit hello_world_exit(void)
{
    pr_info("Kernel Module Removed Successfully...\n");
}
 
module_init(hello_world_init);
module_exit(hello_world_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Srinivas Kiran");
MODULE_DESCRIPTION("A simple hello world driver with parms");
MODULE_VERSION("1.0");

