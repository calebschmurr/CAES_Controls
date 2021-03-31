/* Config.h 
 * A class containing configuration values for main.cpp
 * This will take the place of a settings file.
 */


// System boundary values for conditional controls logic
#define serial_loop_time 1500 // What is this?
#define default_mode 0 // 0 = manual, 1 = auto // we should use an enum for this
#define min_pressure_manual 60 // Minimum tank pressure in manual mode
#define max_pressure_manual 120 // Maximum tank pressure in manual mode
#define min_pressure_auto 60 // Minimum tank pressure in auto mode
#define max_pressure_auto 120 // Maximum tank pressure in auto mode
#define min_cycle_time 20 // Can only change charging states every x seconds
#define voltage_lower_bound 4.8 // In discharge mode
#define voltage_upper_bound 5.6 // In discharge mode

// Arduino pins
#define solid_state_relay_pin 9 // Arduino digital pin for the ssr
#define valve_open_pin 2 // Arduino digital pin for the motorized valve's "open" circuit
#define valve_close_pin 3 // Arduino digital pin for the motorized valve's "close" circuit
#define pressure_sensor_pin 0 // Arduino analog pin for the pressure sensor (ANALOG)
#define voltage_sensor_pin 1 // Arduino analog pin for the voltage sensor
#define current_sensor_pin 2 // Arduino analog pin for the current sensor
#define mode_switch_pin 8 // High = Auto, Low = manual
#define master_on_off_switch_pin // Arduino digital pin for master on/off system overide
    // If both manual switch pins are low, mode is "Off"
#define manual_switch_discharge_pin 12 // Arduino digital pin for mode switch (discharge)
#define manual_switch_charge_pin 13 // Arduino digital pin for mode switch (charge)

// Debugging level (determines which debugging statements actually end up in the log)
#define debug_level 3 //Debug level list: 0 - none. 1 - error statements. 2 - important statements. 3 - verbose.  Everything out.
