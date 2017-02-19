-module(sensor).
-compile(export_all).

sensor_start(Watcher, Ref, Id) ->
	measurement(Watcher, Id),
	sensor_start(Watcher, Ref, Id).

measurement(Watcher, Id) ->
	timer:sleep(rand:uniform(10000)),
	Measurement = rand:uniform(11),
	io:fwrite("Sensor is sending a new measurement.~n"),
	case Measurement of
		11 -> 
			io:fwrite("Sensor died!~n"),
			exit({Id, anamolous_reading});
		_else -> 
			io:fwrite("Sending reading("++ integer_to_list(Measurement) ++")~n"),
			Watcher ! {Id, Measurement}
	end. 