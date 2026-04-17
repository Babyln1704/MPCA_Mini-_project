# UV Sterilization Box for Mobile Phones

##  Project Overview

This project is a UV Sterilization Box designed to disinfect mobile phones using ultraviolet (UV) light. The system is controlled using an Arduino Uno and ensures safe and automated operation using sensors and a relay module.

---

##  Objectives

* To reduce germs on mobile phones using UV light
* To create a low-cost and efficient sterilization system
* To automate the process using sensors and microcontroller

---

##  Components Used

* Arduino Uno
* UV LED Strip (12V)
* Relay Module (5V)
* Limit Switch
* IR Sensor
* Buzzer
* Push Button
* 12V Power Adapter
* Jumper Wires
* Enclosure (Box)

---

## ⚙️ Working Principle

1. The phone is placed inside the box.
2. The lid is closed (detected using limit switch).
3. IR sensor checks for object presence.
4. User presses the button to start.
5. Arduino activates the relay.
6. UV LED strip turns ON and emits UV light.
7. Sterilization runs for a fixed time (30–60 seconds).
8. UV turns OFF automatically.
9. Buzzer alerts completion.

---

##  Circuit Connections

* Arduino Pin 8 → Relay IN

* 5V → Relay VCC

* GND → Relay GND

* Adapter (+) → Relay COM

* Relay NO → UV (+)

* Adapter (–) → UV (–)

* Limit Switch → Pin 4

* IR Sensor → Pin 3

* Buzzer → Pin 9

---

##  Code Logic (Summary)

* Check if box is closed
* Check if phone is present
* Wait for button press
* Turn ON UV using relay
* Run timer (60 seconds)
* Turn OFF UV
* Activate buzzer

---

## 🔒 Safety Features

* UV operates only when box is closed
* Timer prevents overexposure
* Relay ensures controlled switching

---

##  Advantages

* Contactless sterilization
* Safe for electronics
* Low cost and simple design
* Automatic operation

---

##  Limitations

* Does not guarantee 100% sterilization
* Requires proper exposure time
* UV should not be exposed to eyes/skin

---

##  Future Scope

* IoT-based control
* Mobile app integration
* LCD display
* Improved UV coverage

---

##  Result

The system successfully disinfects mobile phones using UV light in a safe and automated manner.

---

##  Conclusion

This project demonstrates the practical application of UV sterilization using embedded systems. It provides a simple and effective solution for maintaining hygiene.

---

##  Acknowledgment

We thank our faculty and institution for supporting this project.

---

##  Note

Avoid direct exposure to UV light. Always operate the system with the box closed.
