-module(quiz)
-compile(export_all)

sum([])->
	0;
sum([H|T]) ->
	H+sum(T).

maximum([H]) ->
	H;
maximum((H|T)) ->
	max(H, maximum(T)).

zip([], []) ->
	[];
zip([H1|T1], [H2|T2]) ->
	[{H1, H2}] ++ zip(T1,T2).

append([], L2)->
	L2;
append([H1|T1], L2) ->
	[H1] ++ append(T1, L2).

reverse([]) ->
	[];
reverse([H|T]) ->
	reverse(T) ++ [H].

evenL([]) ->
	[];
even([H|T]) when H rem 2==0->
	[H] ++ evenL(T);
evenL([H|T]) when H rem 2=/=0 ->
	evenL(T).

take([], N) ->
	[];
take([H|T], 0) ->
	[];
take([H|T], N) ->
	[H] ++ take(T, N-1).

drop([], _N) ->
	[];
drop([H|T], 0) ->
	[H|T];	
drop([H|T], N) ->
	drop(T, N-1).








