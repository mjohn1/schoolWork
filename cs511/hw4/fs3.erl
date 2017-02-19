-module(fs3).
-compile(export_all).

start() ->
    spawn(?MODULE, restarter, []).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% Server machine
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

restarter() ->
    process_flag(trap_exit, true),
    Pid = spawn_link(?MODULE, factServerStart, []),
    register(factServer, Pid),
    receive
	   {'EXIT', Pid, normal} -> % not a crash
	       ok;
	   {'EXIT', Pid, shutdown} -> % manual termination, not a crash
	       ok;
	   {'EXIT', Pid, _} ->
	       begin
	           io:format("Restarted a new factorial server~n",[]),
		       restarter()
	       end
    end.

factServerStart() ->
    %% spawn and link to a process that dies after a random amount of time (rand:uniform(3000))  %%% this is missing %%
    spawn_link(fun () -> timer:sleep(rand:uniform(3000)), exit(boom) end),
    factServer().

factServer() ->
    receive
    	{From, Ref, N} ->
    	    From ! {self(), Ref, fact(N)}
    end,
    factServer().

fact(0) ->
    1;
fact(N) when N>0 ->
    N * fact(N-1).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%% Local machine
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 
rpc(N) ->
    Ref = make_ref(),
    factServer ! {self(), Ref, N},
    receive
	   {From, Ref, Result_of_Factorial} -> Result_of_Factorial
        after 2000 ->
	       timeout
    end.
