-module(linkmon).
-compile(export_all).

myproc() ->
    timer:sleep(2000),
    exit(reason).
   
chain(0) ->
  receive
    _ -> ok
  after 2000 ->
    exit("chain dies here")
  end;

chain(N) ->
  Pid = spawn(fun() -> chain(N-1) end),
  link(Pid),
  receive
    _ -> ok
  end.

start_critic2() ->
    spawn(?MODULE, restarter, []).



restarter() ->
    process_flag(trap_exit, true),
    Pid = spawn_link(?MODULE, critic, []),
    io:format("Restarted critic~n~p",[Pid]),
    register(fs_restart, Pid),
    receive
	     {'EXIT', Pid, normal} -> % not a crash
	       ok;
	     {'EXIT', Pid, shutdown} -> % manual termination, not a crash
	       ok;
	     {'EXIT', Pid, _} ->
          begin
            io:format("Spawned a new instance of the factorial Server~n", [])
	          restarter()
          end.
    end.

factServerStart() ->
    spawn_link(fun () -> sleep(rand:uniform(2000)), exit(boom) end),
    factServer().


factServer() ->
    receive
        {From, Num} ->
           From ! {self(), fact(Num)};
    end,
    factServer().

fact(0) ->
    1;

fact(Num) when N>0->
    N* fact(N-1).

rpc(Band, Album) ->
    factServer ! {self(), Num},
    Pid = whereis(factServer),
    receive
  {Pid, Result} -> Result
    after 2000 ->
      timeout
    end.









