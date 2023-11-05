;; Auto-generated. Do not edit!


(when (boundp 'show_information::status)
  (if (not (find-package "SHOW_INFORMATION"))
    (make-package "SHOW_INFORMATION"))
  (shadow 'status (find-package "SHOW_INFORMATION")))
(unless (find-package "SHOW_INFORMATION::STATUS")
  (make-package "SHOW_INFORMATION::STATUS"))

(in-package "ROS")
;;//! \htmlinclude status.msg.html


(defclass show_information::status
  :super ros::object
  :slots (_light_mode _battery_voltage _motor_num _linear _angular _motor_current _motor_rpm _motor_pulses _motor_temperature _driver_voltage _driver_state _driver_temperature ))

(defmethod show_information::status
  (:init
   (&key
    ((:light_mode __light_mode) 0)
    ((:battery_voltage __battery_voltage) 0.0)
    ((:motor_num __motor_num) 0)
    ((:linear __linear) 0.0)
    ((:angular __angular) 0.0)
    ((:motor_current __motor_current) 0.0)
    ((:motor_rpm __motor_rpm) 0.0)
    ((:motor_pulses __motor_pulses) 0)
    ((:motor_temperature __motor_temperature) 0.0)
    ((:driver_voltage __driver_voltage) 0.0)
    ((:driver_state __driver_state) 0)
    ((:driver_temperature __driver_temperature) 0.0)
    )
   (send-super :init)
   (setq _light_mode (round __light_mode))
   (setq _battery_voltage (float __battery_voltage))
   (setq _motor_num (round __motor_num))
   (setq _linear (float __linear))
   (setq _angular (float __angular))
   (setq _motor_current (float __motor_current))
   (setq _motor_rpm (float __motor_rpm))
   (setq _motor_pulses (round __motor_pulses))
   (setq _motor_temperature (float __motor_temperature))
   (setq _driver_voltage (float __driver_voltage))
   (setq _driver_state (round __driver_state))
   (setq _driver_temperature (float __driver_temperature))
   self)
  (:light_mode
   (&optional __light_mode)
   (if __light_mode (setq _light_mode __light_mode)) _light_mode)
  (:battery_voltage
   (&optional __battery_voltage)
   (if __battery_voltage (setq _battery_voltage __battery_voltage)) _battery_voltage)
  (:motor_num
   (&optional __motor_num)
   (if __motor_num (setq _motor_num __motor_num)) _motor_num)
  (:linear
   (&optional __linear)
   (if __linear (setq _linear __linear)) _linear)
  (:angular
   (&optional __angular)
   (if __angular (setq _angular __angular)) _angular)
  (:motor_current
   (&optional __motor_current)
   (if __motor_current (setq _motor_current __motor_current)) _motor_current)
  (:motor_rpm
   (&optional __motor_rpm)
   (if __motor_rpm (setq _motor_rpm __motor_rpm)) _motor_rpm)
  (:motor_pulses
   (&optional __motor_pulses)
   (if __motor_pulses (setq _motor_pulses __motor_pulses)) _motor_pulses)
  (:motor_temperature
   (&optional __motor_temperature)
   (if __motor_temperature (setq _motor_temperature __motor_temperature)) _motor_temperature)
  (:driver_voltage
   (&optional __driver_voltage)
   (if __driver_voltage (setq _driver_voltage __driver_voltage)) _driver_voltage)
  (:driver_state
   (&optional __driver_state)
   (if __driver_state (setq _driver_state __driver_state)) _driver_state)
  (:driver_temperature
   (&optional __driver_temperature)
   (if __driver_temperature (setq _driver_temperature __driver_temperature)) _driver_temperature)
  (:serialization-length
   ()
   (+
    ;; int32 _light_mode
    4
    ;; float64 _battery_voltage
    8
    ;; uint8 _motor_num
    1
    ;; float64 _linear
    8
    ;; float64 _angular
    8
    ;; float64 _motor_current
    8
    ;; float64 _motor_rpm
    8
    ;; uint16 _motor_pulses
    2
    ;; float64 _motor_temperature
    8
    ;; float64 _driver_voltage
    8
    ;; uint8 _driver_state
    1
    ;; float64 _driver_temperature
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _light_mode
       (write-long _light_mode s)
     ;; float64 _battery_voltage
       (sys::poke _battery_voltage (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint8 _motor_num
       (write-byte _motor_num s)
     ;; float64 _linear
       (sys::poke _linear (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angular
       (sys::poke _angular (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _motor_current
       (sys::poke _motor_current (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _motor_rpm
       (sys::poke _motor_rpm (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint16 _motor_pulses
       (write-word _motor_pulses s)
     ;; float64 _motor_temperature
       (sys::poke _motor_temperature (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _driver_voltage
       (sys::poke _driver_voltage (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint8 _driver_state
       (write-byte _driver_state s)
     ;; float64 _driver_temperature
       (sys::poke _driver_temperature (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _light_mode
     (setq _light_mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _battery_voltage
     (setq _battery_voltage (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint8 _motor_num
     (setq _motor_num (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _linear
     (setq _linear (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angular
     (setq _angular (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _motor_current
     (setq _motor_current (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _motor_rpm
     (setq _motor_rpm (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint16 _motor_pulses
     (setq _motor_pulses (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float64 _motor_temperature
     (setq _motor_temperature (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _driver_voltage
     (setq _driver_voltage (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint8 _driver_state
     (setq _driver_state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _driver_temperature
     (setq _driver_temperature (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get show_information::status :md5sum-) "9f10f8621a8b3bc22f71a5abaea93181")
(setf (get show_information::status :datatype-) "show_information/status")
(setf (get show_information::status :definition-)
      "int32 light_mode  
float64 battery_voltage
uint8 motor_num
float64 linear
float64 angular
float64 motor_current
float64 motor_rpm
uint16 motor_pulses
float64 motor_temperature
float64 driver_voltage
uint8 driver_state
float64 driver_temperature

")



(provide :show_information/status "9f10f8621a8b3bc22f71a5abaea93181")


