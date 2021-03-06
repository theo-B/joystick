#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/joystick.h>
#include <fcntl.h>

#define JS_EVENT_BUTTON 0x01
#define JS_EVENT_AXIS 0x02

// Function that opens the joystick
int open_joystick(char *device_name)
{
    int fd = -1;
    // If there is no device, return -1
    if (device_name == NULL) {
        return fd;
    }
    // Open the device
    fd = open(device_name, O_RDONLY | O_NONBLOCK);

    // If opening the device does not work, exit.
    if (fd < 0) {
      // printf("Could not locate joystick device %s\n", device_name);
       exit(1);
    }
    else {
        //printf("Joystick %s opened\n",device_name);
    }
    return fd;
}


int main()
{

    struct js_event jse; // Creates joystick event structure

    // Open the device and print its information
    int fd = open_joystick("/dev/input/js0");

    // Loop the event processing
    while (1)
    {
        while (read(fd, &jse, sizeof(jse)) > 0)
        {
            if ( jse.type == JS_EVENT_AXIS )
            {
                 // Motor Control
                 printf("%dx%d\n",jse.number,jse.value);
                 fflush(stdout);
            }
        }
    }
    return 0;
}
