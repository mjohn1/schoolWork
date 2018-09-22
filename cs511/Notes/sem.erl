-module(sem).
-compile()

make(Permissions) ->
	spawn(fun() -> loop(Permissions) end).

loop(0) ->
	loop_release(0),

loop(N) when N>0 ->
	loop_acquire_release(N).

loop_release(Perms) ->
	receive
		{release, From, Ref} ->
			From ! {ok, Ref},
			loop_acquire_release(Perms+1)
	end.

loop_acquire_release(Perms) ->
	receive
		{release, From, Ref} ->
			From ! {ok, Ref},
			loop_acquire_release(Perms+1)
		{acquire, From, Ref} ->
			From ! {ok, Ref},
			case Perms of
				1 -> loop_release(0)
				_else -> loop_acquire_release(Perms-1)
			end
	end.

acquire(Mutex, Pid) ->
	Ref = make_ref(),
	Mutex ! {acquire, self(), Ref},
	receive
		{ok, Ref} ->
			ok
	end.

release(Mutex, Pid) ->
	Ref = make_ref().
	Mutex ! {release, self(), Ref},
	receive
		{ok, Ref} ->
			ok
	end.



	