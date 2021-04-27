/* Config.h 
 * A class containing configuration values for main.cpp
 * This will take the place of a settings file.
 */

// System boundary values for conditional controls logic
#define serial_loop_time 1500 // What is this?
#define default_mode 0 // 0 = manual, 1 = auto // we should use an enum for this
#define min_pressure_manual  // Minimum tank pressure in manual mode
#define max_pressure_manual 110 // Maximum tank pressure in manual mode
#define min_pressure_auto 20 // Minimum tank pressure in auto mode
#define max_pressure_auto 110 // Maximum tank pressure in auto mode
#define min_cycle_time 10000 // Can only change charging states every x seconds

// These are not being used in code
#define voltage_lower_bound 7.0 // In discharge mode
#define voltage_upper_bound 12 // In discharge mode

#define pid_window_time 100 // For PID controller
#define pid_voltage_target 11 // For PID controller
#define pid_max_voltage 14.0 //For PID BangBang control

#define pid_p_val 0.6
#define pid_i_val 0.2
#define pid_d_val 10

// Arduino pins
#define solid_state_relay_pin 9 // Arduino digital pin for the ssr
#define valve_open_pin 5 // Arduino digital pin for the motorized valve's "open" circuit
#define valve_close_pin 6 // Arduino digital pin for the motorized valve's "close" circuit
#define pressure_sensor_pin A0 // Arduino analog pin for the pressure sensor (ANALOG)
#define voltage_sensor_pin A2 // Arduino analog pin for the voltage sensor
#define current_sensor_pin A4 // Arduino analog pin for the current sensor
#define mode_switch_pin 8 // High = Auto, Low = manual
#define master_on_off_switch_pin 11 // Arduino digital pin for master on/off system overide
#define manual_switch_discharge_pin 12 // Arduino digital pin for mode switch (discharge)
#define manual_switch_charge_pin 13 // Arduino digital pin for mode switch (charge)

// Debugging level (determines which debugging statements actually end up in the log)
#define debug_level 1 //Debug level list: 0 - none. 1 - error statements. 2 - important statements. 3 - verbose.  Everything out.
