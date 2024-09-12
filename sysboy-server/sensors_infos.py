import psutil

class SensorsInfos:
    def __init__(self):
        pass

    def sensors_info(self):
        try:
            if hasattr(psutil, 'sensors_temperatures'):
                print("Temperature Sensors:", psutil.sensors_temperatures())
            else:
                print("Temperature Sensors: Not supported on this system")

            if hasattr(psutil, 'sensors_fans'):
                print("Fan Sensors:", psutil.sensors_fans())
            else:
                print("Fan Sensors: Not supported on this system")

            if hasattr(psutil, 'sensors_battery'):
                print("Battery Status:", psutil.sensors_battery())
            else:
                print("Battery Status: Not supported on this system")
        except Exception as e:
            print(f"An error occurred while retrieving sensors info: {e}")
