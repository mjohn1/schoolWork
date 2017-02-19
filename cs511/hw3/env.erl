-module(env).
-compile(export_all).
-include("types.hrl").


-spec new()-> envType().
new() ->
    dict:new().

-spec add(envType(),atom(),valType())-> envType().
add(E, K, V) ->
    dict:store(K, V, E).

-spec lookup(envType(),atom())-> valType().
lookup(E, K) -> 
   dict:find(K, E).

