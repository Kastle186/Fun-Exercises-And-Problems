%% Name: 136. Single Number
%% Topics: Array, Bit Manipulation
%% Companies:
%% - Palantir Technologies
%% - Airbnb
%% - Qualcomm
%% - Zoho
%% - Google
%% - Nvidia
%% - Yandex
%% - tcs
%% - Cisco

-module("SingleNumberI")
-export([main/0])

%% For this problem, we have to find the only number that appears only one time
%% in an array of pairs. However, we have the constraint of having to do it in
%% linear time, and constant extra space (if any). To do this, we will enlist
%% the help of the good ol' trustworthy XOR operator. Any number XOR'd with
%% itself yields 0. If we XOR the entire array, all the pairs will cancel each
%% other out, and leaving the single number in our result variable.

single_number(Nums) ->
    single_number(Nums, 0).

single_number([], Result) ->
    Result;

single_number([H | T], Result) ->
    single_number(T, Result bxor H).
