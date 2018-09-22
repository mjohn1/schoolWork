-module(bEx).
-compile(export_all).



run() ->
	barrier:start(3),
	spawn(fun() -> p() end),
	spawn(fun() -> q() end),
	spawn(fun() -> r() end).
	

p() ->
	timer:sleep(500),
	io:format("P has reached the Barrier~n"),
	barrier:reach_wait(coordinator),
	io:format("P is through~n").

q() ->
	timer:sleep(2000),
	io:format("Q has reached the Barrier~n"),
	barrier:reach_wait(coordinator),
	io:format("Q is through~n").

r() ->
	timer:sleep(4000),
	io:format("R has reached the Barrier~n"),
	barrier:reach_wait(coordinator),
	io:format("R is through~n").



