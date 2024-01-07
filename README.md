# XIAO-ESP32C3 bluetooth keyboard/keypad
Creating a simple circuit for detecting a single button press is straightforward. This involves setting a signal to transition from **high** to **low** using one output pin and an input pin to register if the button is pressed. For more detailed information, explore the Arduino documentation on button circuits: https://docs.arduino.cc/built-in-examples/digital/Button

However, this method becomes impractical when expanding to a full keyboard or keypad, as it requires an excessive number of wires and digital pins. Instead of dedicating two pins per button, a more efficient approach is to use a matrix configuration. This design involves arranging several output pins vertically, directly connected to the ground, and input pins horizontally. The only connection between them is a combination of a switch and a diode.

<p align="center">
    <img src="https://pcbheaven.com/wikipages/images/howkeymatricesworks_1277655319.gif">
</p>

So when a button is pressed down it will be registred by the input pin on the same level. We can then differenciate which button was pressed by which output was on. So by cycling between mutliple outputs we can create a code that can registrate and then do a keystroke. You can read more in depth about the logic behid the matrix here: https://pcbheaven.com/wikipages/How_Key_Matrices_Works/

The library used to do the keystorkes are here: https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
