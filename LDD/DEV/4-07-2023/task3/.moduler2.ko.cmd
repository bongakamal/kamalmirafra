cmd_/home/km/MIRAFRA/kamalmirafra/LDD/DEV/4-07-2023/task3/moduler2.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000 -z noexecstack   --build-id  -T ./scripts/module-common.lds -o /home/km/MIRAFRA/kamalmirafra/LDD/DEV/4-07-2023/task3/moduler2.ko /home/km/MIRAFRA/kamalmirafra/LDD/DEV/4-07-2023/task3/moduler2.o /home/km/MIRAFRA/kamalmirafra/LDD/DEV/4-07-2023/task3/moduler2.mod.o;  true