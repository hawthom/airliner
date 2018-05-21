from os.path import join, dirname, abspath

from pyliner import Pyliner, FlightMode

# Initialize pyliner object
from util import read_json

rocky = Pyliner(
    airliner_map=read_json(join(dirname(abspath(__file__)), "cookiecutter.json")),
    ci_port=5009,
    to_port=5012,
    script_name="FT7_Onboard",
    log_dir=join(dirname(abspath(__file__)), "logs"))

vehicle_arm(rocky)
vehicle_takeoff(rocky)
vehicle_flight_mode(rocky, FlightMode.PosCtl)

vehicle_move(rocky, Direction.Up, speed=1.0, time=2, stop=True, stop_wait=3)
vehicle_move(rocky, Direction.Forward, speed=.75, time=2, stop=True,
             stop_wait=3)
vehicle_move(rocky, Direction.Left, speed=.75, time=2, stop=True, stop_wait=3)
vehicle_move(rocky, Direction.Backward, speed=.75, time=2, stop=True,
             stop_wait=3)
vehicle_move(rocky, Direction.Right, speed=.75, time=2, stop=True, stop_wait=3)
vehicle_rtl(rocky)
