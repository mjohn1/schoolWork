-module(barrier).
-compile([start/1, reach_wait/1]).

start(N) ->
	Pid = spawn(fun () -> coordinator(N, N,[]) end),
	register(coordinator, Pid).

coordinator(N, 0, Ps) ->
	[From ! {ok, Ref} || {From, Ref} <- Ps],
	coordinator(N, N, []).
	
coordinator(N, M, Ps) ->
	receive
		{reach, From, Ref} ->
			coordinator(N, M-1, [{From, Ref}|Ps])
	end.

reach_wait() ->
	Ref = make_ref(),
	coordinator ! {reach, self(), Ref},
	receive
		{ok, Ref} ->
			ok
	end.

