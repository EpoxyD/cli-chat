#include <stdbool.h>

#include "controller.h"
#include "connection.h"

static bool alive;

void controller_init()
{
    connection_create_socket();
}

void controller_run()
{
    alive = true;
    while(alive)
    {
        sleep(1000);
    }
}

void controller_cleanup()
{

}

void controller_stop()
{
    alive = false;
}