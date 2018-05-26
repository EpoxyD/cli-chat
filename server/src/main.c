#include <signal.h>
#include <stdbool.h>

#include "controller.h"

void stop_program()
{
    controller_stop();
    return;
}

int main(void)
{
    signal(SIGINT, stop_program);

    controller_init();
    controller_run();
    controller_cleanup();
}