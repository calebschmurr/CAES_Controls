/* Config.h 
 * A class containing configuration values for main.cpp
 * This will take the place of a settings file.
 */



#define serial_loop_time 1500 // What is this?
#define default_mode 0 // 0 = manual, 1 = auto // we should use an enum for this
#define min_pressure_manual 60 // Minimum tank pressure in manual mode
#define max_pressure_manual 120 // Maximum tank pressure in manual mode
#define min_pressure_auto 60 // Minimum tank pressure in auto mode
#define max_pressure_auto 120 // Maximum tank pressure in auto mode
#define min_cycle_time 20 // Can only change charging states every x seconds.
#define solid_state_relay_pin 1 // Arduino gpio pin for the ssr
#define valve_open_pin 2 // Arduino gpio pin for the motorized valve's "open" circuit
#define valve_close_pin 3 // Arduino gpio pin for the motorized valve's "close" circuit
#define pressure_sensor_pin 4 // Arduino gpio pin for the pressure sensor
#define voltage_sensor_pin 5 // Arduino gpio pin for the voltage sensor
#define current_sensor_pin 6 // Arduino gpio pin for the current sensor

#define manual_switch_discharge 7 // Arduino GPIO pin for the switch modes.
#define manual_switch_charge 8 // No pin for 'off' state, assumed no voltage.
#define mode_switch 9 //On = Auto, off = manual.



#define voltage_lower_bound 4.8
#define voltage_upper_bound 5.6

#define debug_level 3 //Debug level list: 0 - none. 1 - error statements. 2 - important statements. 3 - verbose.  Everything out.
