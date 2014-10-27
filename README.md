joystick
========

Code for interfacing with a gamepad/joystick to get axis values.
Returns values in the range -32767 - +32767
In the format NxV where N is the number of the joystick (numbers in diagram below)
and V is the value of the joystick's position, positive or negative (as in diagram).


           -1                 -2
            ^                  ^
            |                  |
      -0 <--x--> +0      -3 <--x--> +3
            |                  |
            v                  v
           +1                 +2
      
            L                  R
