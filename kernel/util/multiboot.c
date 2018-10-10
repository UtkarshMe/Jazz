#include <multiboot.h>
#include <logger.h>

void multiboot_dump_info(multiboot_info_t *info)
{
  klog(LOG_DEBUG, "------------ MULTIBOOT DUMP ------------\n");
  klog(LOG_DEBUG, "multiboot header: 0x%x\n", info);
  klog(LOG_DEBUG, "flags           : 0x%x\n", info -> flags);
  klog(LOG_DEBUG, "mem lower       : 0x%x\n", info -> mem_lower);
  klog(LOG_DEBUG, "mem upper       : 0x%x\n", info -> mem_upper);
  klog(LOG_DEBUG, "boot device     : 0x%x\n", info -> boot_device);
  klog(LOG_DEBUG, "cmdline         : %s\n",   info -> cmdline);
  klog(LOG_DEBUG, "module count    : %d\n",   info -> mods_count);
  klog(LOG_DEBUG, "module address  : 0x%x\n", info -> mods_addr);
  klog(LOG_DEBUG, "mem map len     : 0x%x\n", info -> mmap_len);
  klog(LOG_DEBUG, "mem map addr    : 0x%x\n", info -> mmap_addr);
  klog(LOG_DEBUG, "config table    : 0x%x\n", info -> config_table);
  klog(LOG_DEBUG, "bootloader name : %s\n",   info -> bootloader_name);
  klog(LOG_DEBUG, "----------------------------------------\n");
}