-module(watcher).
-compile(export_all).
-import(sensor, [sensor_start/3]).

setup() ->
 {ok, [ N ]} = io:fread("enter number of sensors> ", "~d") ,
 if N =< 1 ->
   io:fwrite("setup: range must be at least 2~n", []) ;
 true ->
   Num_watchers = 1 + ((N-1) div 10) ,
   setup_loop(N, Num_watchers) 
 end .

start_watcher(N, S, L, WPid) ->
	spawn(?MODULE, sensor_loop, [N, S, L, WPid]).

sensor_loop(N, S, L, WPid) ->
%sets up the sensors for each watcher
	case S of
		1 ->
			io:fwrite("Creating sensor "++ integer_to_list(N) ++"~n"),
			Pid = startSensor(N, WPid),
			watch([{N, Pid}] ++ L),
			ok;
		_else ->
			io:fwrite("Creating sensor "++ integer_to_list(N) ++"~n"),
			Pid = startSensor(N, WPid),
			sensor_loop(N-1, S-1, [{N, Pid}] ++ L, WPid)
	end.

setup_loop(N, NumWatchers) ->
	%io:fwrite(integer_to_list(NumWatchers)),
	case NumWatchers of 
		1 ->
			io:fwrite("Creating watcher!~n"),
			start_watcher(N, N, [], self());
    	_else ->
    		io:fwrite("Creating watcher!~n"),
	    	start_watcher(N, 10, [], self()),
	    	setup_loop(N-10, NumWatchers-1)
	end.	

startSensor(Id, W) ->
%spawns the sensor and returns the Pid
    process_flag(trap_exit, true),
    Ref = make_ref(),
    {Pid,_} = spawn_monitor(sensor, sensor_start, [W, Ref, Id]),
    Pid.

watch(L)->
    receive
        {Id, Measurement} -> 
            io:fwrite("Measurement received from " ++ integer_to_list(Id) ++" with a value of " ++ integer_to_list(Measurement) ++"~n",[]);
        {'DOWN', _, _, _, normal} ->
            ok;
        {'DOWN', _, _, _, shutdown} ->
            ok;
        {'DOWN', _, _, _, {Id, _}} ->
            begin
            io:fwrite("Restarted sensor("++ integer_to_list(Id) ++").~n"),
            lists:keyreplace(Id, 1, L, {Id, startSensor(Id, self())})
            end;
        _ ->
            io:fwrite("Invalid Receive!")
    end,
    watch(L).