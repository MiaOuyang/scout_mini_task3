# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from show_information/status.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class status(genpy.Message):
  _md5sum = "9f10f8621a8b3bc22f71a5abaea93181"
  _type = "show_information/status"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """int32 light_mode  
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
"""
  __slots__ = ['light_mode','battery_voltage','motor_num','linear','angular','motor_current','motor_rpm','motor_pulses','motor_temperature','driver_voltage','driver_state','driver_temperature']
  _slot_types = ['int32','float64','uint8','float64','float64','float64','float64','uint16','float64','float64','uint8','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       light_mode,battery_voltage,motor_num,linear,angular,motor_current,motor_rpm,motor_pulses,motor_temperature,driver_voltage,driver_state,driver_temperature

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(status, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.light_mode is None:
        self.light_mode = 0
      if self.battery_voltage is None:
        self.battery_voltage = 0.
      if self.motor_num is None:
        self.motor_num = 0
      if self.linear is None:
        self.linear = 0.
      if self.angular is None:
        self.angular = 0.
      if self.motor_current is None:
        self.motor_current = 0.
      if self.motor_rpm is None:
        self.motor_rpm = 0.
      if self.motor_pulses is None:
        self.motor_pulses = 0
      if self.motor_temperature is None:
        self.motor_temperature = 0.
      if self.driver_voltage is None:
        self.driver_voltage = 0.
      if self.driver_state is None:
        self.driver_state = 0
      if self.driver_temperature is None:
        self.driver_temperature = 0.
    else:
      self.light_mode = 0
      self.battery_voltage = 0.
      self.motor_num = 0
      self.linear = 0.
      self.angular = 0.
      self.motor_current = 0.
      self.motor_rpm = 0.
      self.motor_pulses = 0
      self.motor_temperature = 0.
      self.driver_voltage = 0.
      self.driver_state = 0
      self.driver_temperature = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_idB4dH2dBd().pack(_x.light_mode, _x.battery_voltage, _x.motor_num, _x.linear, _x.angular, _x.motor_current, _x.motor_rpm, _x.motor_pulses, _x.motor_temperature, _x.driver_voltage, _x.driver_state, _x.driver_temperature))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 72
      (_x.light_mode, _x.battery_voltage, _x.motor_num, _x.linear, _x.angular, _x.motor_current, _x.motor_rpm, _x.motor_pulses, _x.motor_temperature, _x.driver_voltage, _x.driver_state, _x.driver_temperature,) = _get_struct_idB4dH2dBd().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_idB4dH2dBd().pack(_x.light_mode, _x.battery_voltage, _x.motor_num, _x.linear, _x.angular, _x.motor_current, _x.motor_rpm, _x.motor_pulses, _x.motor_temperature, _x.driver_voltage, _x.driver_state, _x.driver_temperature))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 72
      (_x.light_mode, _x.battery_voltage, _x.motor_num, _x.linear, _x.angular, _x.motor_current, _x.motor_rpm, _x.motor_pulses, _x.motor_temperature, _x.driver_voltage, _x.driver_state, _x.driver_temperature,) = _get_struct_idB4dH2dBd().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_idB4dH2dBd = None
def _get_struct_idB4dH2dBd():
    global _struct_idB4dH2dBd
    if _struct_idB4dH2dBd is None:
        _struct_idB4dH2dBd = struct.Struct("<idB4dH2dBd")
    return _struct_idB4dH2dBd