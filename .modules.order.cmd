cmd_/home/quan/projects/HDH-2/modules.order := {   echo /home/quan/projects/HDH-2/kernel_module.ko; :; } | awk '!x[$$0]++' - > /home/quan/projects/HDH-2/modules.order
