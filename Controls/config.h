/*
 * Config.h - hold all the parameters we are looking to modify
 * This will take the place of a settings file.
 * 
 * 
*/


#define serial_loop_time 1500

#define desired_tank_pressure 100 //Desired tank pressure.

#define pressure_low_end 60 //Low end - when the tank hits this kick

#define pressure_high_end 120 //High end - when the tank hits this when on, shutoff compressor.

#define Min_Cycle_Off_Time 40 //Can only cycle on and off x times per 2 minutes.

#define Min_Cycle_On_Time 20 //Minimum time compressor is in seconds.

//If 
#define Charge_Mode 0 //0 = Manual, 1 = Auto

