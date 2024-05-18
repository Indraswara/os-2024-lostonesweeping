#include "exec.h"
#include "header/process/process.h"
#include "user-shell.h"
#include "util.h"

void exec(char* arg){

    if(arg == NULL){
        put_chars("exec: argumen kurang desu", BIOS_RED); 
        put_char('\n');
        return;
    }

    if(findEntryName(arg) == -1){
        put_chars("exec: program tidak ada desu", BIOS_RED);
        put_char('\n');
        return;
    }

    struct ProcessInfo process_info[PROCESS_COUNT_MAX];

    int total;
    syscall(17, (uint32_t)&process_info, (uint32_t)&total, 0); 
    for(int i = 0; i < total; i++){
        if(memcmp(process_info[i].name, arg, 8) == 0){
            put_chars("exec: proses sudah ada desu!", BIOS_RED);
            put_char('\n');
            return;
        }
    }

    int retcode;
    struct FAT32DriverRequest request = {
        .buf                   = (uint8_t*) 0,
        .name                  = {0},
        .ext                   = "\0\0\0",
        .parent_cluster_number = ROOT_CLUSTER_NUMBER,
        .buffer_size           = 0x100000,
    };
    memcpy(request.name, arg, 8);
    syscall(15, (uint32_t)&request, (uint32_t)&retcode, 0);
}